#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Необходимо для отправки типа QPair QMap<int, QString> с использованием сигналов
    qRegisterMetaType< QPair<QString, quint16> >( "QPair<QString, quint16>" );
    qRegisterMetaType< QMap<int, QString> >( "QMap<int, QString>" );
    qRegisterMetaType< QVector<int> >( "QVector<int>" );

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    //~~~~~~~~~~~ Объявление потока чтения данных из TcpSocket ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
        QThread *thread_TcpSocketReader = new QThread;                                                             //Создаем поток для порта платы
        SocketReader->moveToThread(thread_TcpSocketReader);                                                        //Помещаем класс в поток

        //Соединяем все нужные сигналы и слоты
        connect(thread_TcpSocketReader, SIGNAL(started()), SocketReader, SLOT(process_SocketReader()));            //Переназначения метода run
        connect(SocketReader, SIGNAL(finished_SocketReader()), thread_TcpSocketReader, SLOT(quit()));              //Переназначение метода выход

        connect(thread_TcpSocketReader, SIGNAL(finished()), SocketReader, SLOT(deleteLater()));                    //Удаление потока
        connect(SocketReader, SIGNAL(finished_SocketReader()), thread_TcpSocketReader, SLOT(deleteLater()));       //Удаление потока

        //Получение номера-дескриптора клиента
        connect(SocketReader, SIGNAL(gotSelfDescriptionNumber(int)), SocketWriter, SLOT(CaughtSelfDescriptionNumber(int)));
        connect(SocketReader, SIGNAL(gotSelfDescriptionNumber(int)), this, SLOT(CaughtSelfDescriptionNumber(int)));

        //Получение словаря дескриптор-адресов
        connect(SocketReader, SIGNAL(gotDescriptionsOfGuests(QMap<int, QString>)),
                SocketWriter, SLOT(CaughtDescriptionsOfGuests(QMap<int, QString>)));

        connect(SocketReader, SIGNAL(gotDescriptionsOfGuests(QMap<int, QString>)),
                this, SLOT(CaughtDescriptionsOfGuests(QMap<int, QString>)));


        //Запуск потока
        thread_TcpSocketReader->start();

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    //~~~~~~~~~~~ Объявление потока записи данных в TcpSokcet ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
        QThread *thread_TcpSocketWriter = new QThread;                                                             //Создаем поток для порта платы
        SocketWriter->moveToThread(thread_TcpSocketWriter);                                                        //Помещаем класс в поток

        //Соединяем все нужные сигналы и слоты
        connect(thread_TcpSocketWriter, SIGNAL(started()), SocketWriter, SLOT(process_SocketReader()));            //Переназначения метода run
        connect(SocketWriter, SIGNAL(finished_SocketWriter()), thread_TcpSocketWriter, SLOT(quit()));              //Переназначение метода выход

        connect(thread_TcpSocketWriter, SIGNAL(finished()), SocketWriter, SLOT(deleteLater()));                    //Удаление потока
        connect(SocketWriter, SIGNAL(finished_SocketWriter()), thread_TcpSocketWriter, SLOT(deleteLater()));       //Удаление потока

        //Запуск потока
        thread_TcpSocketWriter->start();

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    //~~~~~~~~~~~ Работы LogTerminal окна ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
        LogTerminal *TermNew = new LogTerminal();

        //Соединяем все нужные сигналы и слоты
        connect(ui->termButton, SIGNAL(clicked()), TermNew, SLOT(showLogTerminal()));                              //Вызов окна по нажатию кнопки
        connect(SocketReader, SIGNAL(outSocket(QString)), TermNew, SLOT(printReceivedData(QString)));              //Печать полученных даных в консоль
        connect(SocketWriter, SIGNAL(exportData(QString)), TermNew, SLOT(printSentData(QString)));                 //Печать отправленных даных в консоль
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    //~~~~~~~~~~~ Работы SettingsDialog окна ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
        SettingsDialogNew = new SettingsDialog();

        //Соединяем все нужные сигналы и слоты
        connect(ui->set_of_conButton, SIGNAL(clicked()), SettingsDialogNew, SLOT(showSettingsDialog()));           //Вызов окна по нажатию кнопки
        connect(SettingsDialogNew, SIGNAL(setConnectionParameters(QPair<QString, quint16>, QPair<QString, quint16>)),
                SocketWriter, SLOT(SetConnectionParameters(QPair<QString, quint16>, QPair<QString, quint16>)));
        connect(SettingsDialogNew, SIGNAL(paymentSignal(bool)), this, SLOT(ChangeIsPayerValue(bool)));
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

        connect(ui->startProtocolButton, SIGNAL(clicked()), SocketWriter,   SLOT(GetNumber()));                    //Запуск протокола начинается с
                                                                                                                   //запроса номера от сервера
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ChangeIsPayerValue(bool state)
{
    isPayer = state;
    qDebug() << "is Payer = " << state;

}

void MainWindow::PrintInfoToTheSreen(QString text)
{
    ui->protocolStagesTextEdit->textCursor().insertText(SERVICE_STR + text);
    ui->protocolStagesTextEdit->textCursor().insertText("\n");
    ui->protocolStagesTextEdit->moveCursor(QTextCursor::End);
}

void MainWindow::CaughtSelfDescriptionNumber(int numberDescriptor)
{
    QString step_descriptor_str = " Your place at the table: ";
    PrintInfoToTheSreen(step_descriptor_str + QString::number(numberDescriptor));
    this->selfDescriptionNumber = numberDescriptor;
}

void MainWindow::CaughtDescriptionsOfGuests(QMap<int, QString> users_descriptions)
{
    descriptors_adresses = users_descriptions;
    QString step_descriptor_str = " Server falls asleep: Cryptographers wake up!";
    PrintInfoToTheSreen(step_descriptor_str);

    this->delay(1000);

    QThread *thread_ProtocolStages = new QThread;
    PSMaker = new ProtocolStages(selfDescriptionNumber, descriptors_adresses, isPayer);
    PSMaker->moveToThread(thread_ProtocolStages);

    //~~~~~~~~~~~ Объявление потока исполнителя протокола ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    //Соединяем все нужные сигналы и слоты
    connect(thread_ProtocolStages, SIGNAL(started()), PSMaker, SLOT(process_ProtocolStages()));         //Переназначения метода run
    connect(PSMaker, SIGNAL(finished_PSMaker()), thread_ProtocolStages, SLOT(quit()));                  //Переназначение метода выход

    connect(thread_ProtocolStages, SIGNAL(finished()), PSMaker, SLOT(deleteLater()));                   //Удаление потока
    connect(PSMaker, SIGNAL(finished_PSMaker()), thread_ProtocolStages, SLOT(deleteLater()));           //Удаление потока

    connect(PSMaker, SIGNAL(sendSecrets(QVector<int>)), SocketWriter, SLOT(SecretsFrindlyBroadcast(QVector<int>)));
    connect(PSMaker, SIGNAL(sendProtocolAnswer(QString)), SocketWriter, SLOT(ProcessWritingMessage(QString)));
    connect(PSMaker, SIGNAL(sendXORorNXOR_Result(QString)), SocketWriter, SLOT(ProcessWritingMessage(QString)));

    connect(SettingsDialogNew, SIGNAL(paymentSignal(bool)), PSMaker, SLOT(ChangeIsPayerValue(bool)));

    //Получение стороннего секрета
    connect(SocketReader, SIGNAL(gotSideSecret(int, int)), PSMaker, SLOT(CatchMissingSecrets(int, int)));
    //Получение стороннего результата
    connect(SocketReader, SIGNAL(gotSideXorResult(int, int)), PSMaker, SLOT(CatchOthersXORorNXOR(int, int)));
    //Получении всех секретов
    connect(PSMaker, SIGNAL(allSecretsWasGained()), this, SLOT(CaughtAllSecrets()));
    //Генерация XOR результата
    connect(PSMaker, SIGNAL(sendXORorNXOR_Result(QString)), this, SLOT(CaughtSelfXorResult(QString)));
    //Получение всех XOR результатов
    connect(PSMaker, SIGNAL(allXorResultsWasGained()), this, SLOT(CaughtAllXorResults()));
    //Получение главного ответа данного протокола
    connect(PSMaker, SIGNAL(gotMainProtocolAnswer(int)), this, SLOT(CaughtProtocolAnswer(int)));

    //Запуск потока
    thread_ProtocolStages->start();
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

    PSMaker->SendSecrets();
}

void MainWindow::CaughtAllSecrets()
{
    QString step_descriptor_str = " All secrets was exchanged!";
    PrintInfoToTheSreen(step_descriptor_str);
    this->isAllSecretsGainned = true;
}
void MainWindow::CaughtProtocolAnswer(int answer){
    if(answer){
        QString friend_scenario = " You have great friends, keep them in life!";
        PrintInfoToTheSreen(friend_scenario);
    }
    else {
        QString job_scenario = " You have a great job, hold on to it in life!";
        PrintInfoToTheSreen(job_scenario);
    }
}

void MainWindow::CaughtSelfXorResult(QString data)
{
    QString command_code = data.left(data.indexOf(' '));
    QString command_data = data.mid(data.indexOf( command_code )
                           + command_code.length() + 1, data.length());

    if(command_code.toInt() == 3141){
        QString message = " Your generated XOR result is " + command_data;
        PrintInfoToTheSreen(message);
    }
    else{
        qDebug() << "Error! Not valid use of this method!";
    }
}

void MainWindow::CaughtAllXorResults()
{
    QString step_descriptor_str = " All others XOR results was obtained!";
    PrintInfoToTheSreen(step_descriptor_str);
    this->isAllSecretsGainned = true;
}


//-----------------Временной интервал--------------------------------------//
void MainWindow::delay(int millisecondsToWait)
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}
//-------------------------------------------------------------------------//

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

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    //~~~~~~~~~~~ Объявление потока чтения данных из TcpSocket ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
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

    //Получение номера в очереди широковещания
    connect(SocketReader, SIGNAL(gotSelfBroadcastNumber(int)), SocketWriter, SLOT(CaughtSelfBroadcastNumber(int)));
    connect(SocketReader, SIGNAL(gotSelfBroadcastNumber(int)), this, SLOT(CaughtSelfBroadcastNumber(int)));

    //Получение количества слов широковещания
    connect(SocketReader, SIGNAL(gotNumberOfMessages(int)), this, SLOT(CaughtNumberOfMessages(int)));

    //Получение словаря дескриптор-адресов
    connect(SocketReader, SIGNAL(gotDescriptionsOfGuests(QMap<int, QString>)),
            SocketWriter, SLOT(CaughtDescriptionsOfGuests(QMap<int, QString>)));

    connect(SocketReader, SIGNAL(gotDescriptionsOfGuests(QMap<int, QString>)),
            this, SLOT(CaughtDescriptionsOfGuests(QMap<int, QString>)));


    //Запуск потока
    thread_TcpSocketReader->start();

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    //~~~~~~~~~~~ Объявление потока записи данных в TcpSokcet ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    QThread *thread_TcpSocketWriter = new QThread;                                                             //Создаем поток для порта платы
    SocketWriter->moveToThread(thread_TcpSocketWriter);                                                        //Помещаем класс в поток

    //Соединяем все нужные сигналы и слоты
    connect(thread_TcpSocketWriter, SIGNAL(started()), SocketWriter, SLOT(process_SocketReader()));            //Переназначения метода run
    connect(SocketWriter, SIGNAL(finished_SocketWriter()), thread_TcpSocketWriter, SLOT(quit()));              //Переназначение метода выход

    connect(thread_TcpSocketWriter, SIGNAL(finished()), SocketWriter, SLOT(deleteLater()));                    //Удаление потока
    connect(SocketWriter, SIGNAL(finished_SocketWriter()), thread_TcpSocketWriter, SLOT(deleteLater()));       //Удаление потока

    //Запуск потока
    thread_TcpSocketWriter->start();

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    //~~~~~~~~~~~ Работы LogTerminal окна ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    TermNew = new LogTerminal();

    //Соединяем все нужные сигналы и слоты
    connect(ui->termButton, SIGNAL(clicked()), TermNew, SLOT(showLogTerminal()));                              //Вызов окна по нажатию кнопки
    connect(SocketReader, SIGNAL(outSocket(QString)), TermNew, SLOT(printReceivedData(QString)));              //Печать полученных даных в консоль
    connect(SocketWriter, SIGNAL(exportData(QString)), TermNew, SLOT(printSentData(QString)));                 //Печать отправленных даных в консоль
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    //~~~~~~~~~~~ Работы SettingsDialog окна ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    SettingsDialogNew = new SettingsDialog();

    //Соединяем все нужные сигналы и слоты
    connect(ui->set_of_conButton, SIGNAL(clicked()), SettingsDialogNew, SLOT(showSettingsDialog()));           //Вызов окна по нажатию кнопки
    connect(SettingsDialogNew, SIGNAL(setConnectionParameters(QPair<QString, quint16>, QPair<QString, quint16>)),
            SocketWriter, SLOT(SetConnectionParameters(QPair<QString, quint16>, QPair<QString, quint16>)));
    connect(SettingsDialogNew, SIGNAL(broadcastingSignal(bool)), SocketWriter, SLOT(ChangeStateOfBroacasting(bool)));
    connect(SettingsDialogNew, SIGNAL(broadcastingSignal(bool)), this, SLOT(ChangeStateOfBroacasting(bool)));
    connect(SettingsDialogNew, SIGNAL(gotEncodeBinWord(QString)), this, SLOT(CatchBroadcastingWord(QString)));

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    //~~~~~~~~~~~ Объявление потока исполнителя протокола ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    QThread *thread_ProtocolStages = new QThread;
    PSMaker = new ProtocolStages();
    PSMaker->moveToThread(thread_ProtocolStages);

    //Соединяем все нужные сигналы и слоты
    connect(thread_ProtocolStages, SIGNAL(started()), PSMaker, SLOT(process_ProtocolStages()));         //Переназначения метода run
    connect(PSMaker, SIGNAL(finished_PSMaker()), thread_ProtocolStages, SLOT(quit()));                  //Переназначение метода выход

    connect(thread_ProtocolStages, SIGNAL(finished()), PSMaker, SLOT(deleteLater()));                   //Удаление потока
    connect(PSMaker, SIGNAL(finished_PSMaker()), thread_ProtocolStages, SLOT(deleteLater()));           //Удаление потока

    connect(PSMaker, SIGNAL(sendSecrets(QVector<int>)), SocketWriter, SLOT(SecretsFrindlyBroadcast(QVector<int>)));
    connect(PSMaker, SIGNAL(sendProtocolAnswer(QString)), SocketWriter, SLOT(ProcessWritingMessage(QString)));
    connect(PSMaker, SIGNAL(sendXORorNXOR_Result(QString)), SocketWriter, SLOT(ProcessWritingMessage(QString)));

    //Получение стороннего секрета
    connect(SocketReader, SIGNAL(gotSideSecret(int)), PSMaker, SLOT(CatchMissingSecrets(int)));
    //Получение стороннего результата
    connect(SocketReader, SIGNAL(gotSideXorResult(int)), PSMaker, SLOT(CatchOthersXORorNXOR(int)));
    //Получении всех секретов
    connect(PSMaker, SIGNAL(allSecretsWasGained()), this, SLOT(CaughtAllSecrets()));
    //Генерация XOR результата
    connect(PSMaker, SIGNAL(sendXORorNXOR_Result(QString)), this, SLOT(CaughtSelfXorResult(QString)));
    //Получение всех XOR результатов
    connect(PSMaker, SIGNAL(allXorResultsWasGained()), this, SLOT(CaughtAllXorResults()));
    //Получение главного ответа данного протокола
    connect(PSMaker, SIGNAL(gotMainProtocolAnswer(int)), this, SLOT(CaughtProtocolAnswer(int)));
    connect(PSMaker, SIGNAL(gotMainProtocolAnswer(int)), SocketWriter, SLOT(ProtocolAnswerBroadcastMessage(int)));
    //Получение слова
    connect(PSMaker, SIGNAL(gotAnswerWord(QString)), this, SLOT(PrintInfoToTheSreen(QString)));
    //Получение сторонего результата
    connect(SocketReader, SIGNAL(gotSideProtocolAnswer(int)), PSMaker, SLOT(CatchSideAnswerResult(int)));
    //Черта после очередного цикла
    connect(PSMaker, SIGNAL(lineSignal()), this, SLOT(writeLine()));
    connect(PSMaker, SIGNAL(lineSignal()), TermNew, SLOT(WriteLine()));

    //Получение количества слов широковещания
    connect(SocketReader, SIGNAL(gotNumberOfMessages(int)), PSMaker, SLOT(CaughtNumberOfMessages(int)));
    //Получение словаря дескриптор-адресов
    connect(SocketReader, SIGNAL(gotDescriptionsOfGuests(QMap<int, QString>)), PSMaker, SLOT(CaughtDescriptionsOfGuests(QMap<int, QString>)));
    //Получение номера-дескриптора клиента
    connect(SocketReader, SIGNAL(gotSelfDescriptionNumber(int)), PSMaker, SLOT(CaughtSelfDescriptionNumber(int)));
    //Получение номера в очереди широковещания
    connect(SocketReader, SIGNAL(gotSelfBroadcastNumber(int)), PSMaker, SLOT(CaughtSelfBroadcastNumber(int)));
    //Получение слова для широковещания
    connect(SettingsDialogNew, SIGNAL(gotEncodeBinWord(QString)), PSMaker, SLOT(CatchBroadcastingWord(QString)));

    //Получение сигнала об окончании протокола
    connect(PSMaker, SIGNAL(endOfProtocol()), this, SLOT(EndOfProtocolStrPrint()));

    //Запуск потока
    thread_ProtocolStages->start();
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

    connect(ui->startProtocolButton, SIGNAL(clicked()), SocketWriter,   SLOT(GetNumbers()));                   //Запуск протокола начинается с
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

void MainWindow::PrintProtocolStageToTheSreen(QString text)
{
    ui->protocolStagesTextEdit->textCursor().insertText(PROT_SERVICE_STR + text);
    ui->protocolStagesTextEdit->textCursor().insertText("\n");
    ui->protocolStagesTextEdit->moveCursor(QTextCursor::End);
}

void MainWindow::CaughtSelfDescriptionNumber(int numberDescriptor)
{
    this->selfDescriptionNumber = numberDescriptor;
    QString step_descriptor_str = "Your place at the table: ";
    PrintProtocolStageToTheSreen(step_descriptor_str + QString::number(numberDescriptor));
}
void MainWindow::CaughtSelfBroadcastNumber(int broadcastNumber)
{
    this->selfBroacastNumber = broadcastNumber;
    QString step_broadcast_str = "Your broacast position: ";
    PrintProtocolStageToTheSreen(step_broadcast_str + QString::number(selfBroacastNumber));
}

void MainWindow::CaughtNumberOfMessages(int numOfMes)
{
    this->numberOfMessage = numOfMes;
}

void MainWindow::CaughtDescriptionsOfGuests(QMap<int, QString> users_descriptions)
{
    descriptors_adresses = users_descriptions;
    QString step_descriptor_str = "Server falls asleep: Cryptographers wake up!";
    PrintProtocolStageToTheSreen(step_descriptor_str);

    PSMaker->FirstProtocolStage();
}

void MainWindow::CaughtAllSecrets()
{
    QString step_descriptor_str = "All secrets was exchanged!";
//    PrintProtocolStageToTheSreen(step_descriptor_str);
    this->isAllSecretsGainned = true;
}

void MainWindow::CaughtSelfXorResult(QString data)
{
    QString command_code = data.left(data.indexOf(' '));
    QString command_data = data.mid(data.indexOf( command_code )
                           + command_code.length() + 1, data.length());

    if(command_code.toInt() == 3141){
        QString message = "Your generated XOR result is " + command_data;
  //      PrintProtocolStageToTheSreen(message);
    }
    else{
        qDebug() << "Error! Not valid use of this method!";
    }
}

void MainWindow::CaughtAllXorResults()
{
    QString step_descriptor_str = "All others XOR results was obtained!";
    //PrintProtocolStageToTheSreen(step_descriptor_str);
    this->isAllSecretsGainned = true;
}

void MainWindow::CaughtProtocolAnswer(int answer){
    if(answer){
        QString friend_scenario = " 1";
      //  PrintProtocolStageToTheSreen(friend_scenario);
    }
    else {
        QString job_scenario = " 0";
        //PrintProtocolStageToTheSreen(job_scenario);
    }
}

//Получение слова для рассылки
void MainWindow::CatchBroadcastingWord(QString word){
    this->brodcastingWord = word;
}

//Изменение состояния рассылки
void MainWindow::ChangeStateOfBroacasting(bool state)
{
    this->stateOfBroacasting = state;
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

void MainWindow::writeLine()
{
    QString text = "---------------------------------------";
    //PrintProtocolStageToTheSreen(text);
}

void MainWindow::EndOfProtocolStrPrint()
{
    PrintProtocolStageToTheSreen("Программа завершилась с кодом 0 ...");
}

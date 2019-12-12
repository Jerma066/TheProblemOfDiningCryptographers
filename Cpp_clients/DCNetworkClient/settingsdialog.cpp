#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("Settings of protocol");

    //-----Дефолтные значения-----//
    const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
    for (const QHostAddress &address: QNetworkInterface::allAddresses())
    {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != localhost){
            // Собственный IP адрес
            ui->selfIpAddressLineEdit->setText(address.toString());
        }
    }


    ui->selfPortLineEdit->setText(QString::number(DEFAULT_SELF_PORT));          // Собственный номер порта:
    ui->serverIpAddressLineEdit->setText(LOOP_BACK_ADDRESS);                    // Cерверный IP адресс
    ui->serverPortLineEdit->setText(QString::number(DEFAULT_SERVER_PORT));      // Серверный номер порта

    SetScoreParameters();

    //Пачка connect
    connect(this, SIGNAL(showTransmittedWordDoalog()), TrWrDialog, SLOT(showTransmittedWordDialog()));
    connect(TrWrDialog, SIGNAL(gotTransmittedWord(QString)), this, SLOT(processTransmitedWord(QString)));
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::SetScoreParameters()
{
    ui->scoreComboBox->addItem("NO");
    ui->scoreComboBox->addItem("YES");
}

void SettingsDialog::on_scoreComboBox_activated(const QString &arg1)
{
    if(arg1.contains("YES"))
    {
        stateOfBroadcasting = true;
        emit broadcastingSignal(true);
    }
    else if (arg1.contains("NO"))
    {
        stateOfBroadcasting = false;
        emit broadcastingSignal(false);
    }
}


void SettingsDialog::showSettingsDialog()
{
    SettingsDialog::show();
}

void SettingsDialog::on_applyButton_clicked()
{
    //Вызовы проверок на корректность вписанных данных//
    /*~~~~~~~~~~~~~~~~~~YOUR CODE HERE~~~~~~~~~~~~~~~~*/

    //Заполнение атрибутов собственого сокета и серерного сокета
    selfSocket.first = ui->selfIpAddressLineEdit->text();
    selfSocket.second = quint16(std::atoi(ui->selfPortLineEdit->text().toLocal8Bit()));
    serverSocket.first = ui->serverIpAddressLineEdit->text();
    serverSocket.second =quint16(std::atoi(ui->serverPortLineEdit->text().toLocal8Bit()));

    setConnectionParameters(selfSocket, serverSocket);

    SettingsDialog::hide();

    if(stateOfBroadcasting){
        emit showTransmittedWordDoalog();
    }
}

//Обработка полученного слова для анонимного ширококвещания
void SettingsDialog::processTransmitedWord(QString data)
{
    QString encode_bin_word = parce.encode(data);
    qDebug() << "encoded data: " << encode_bin_word;
    emit gotEncodeBinWord(encode_bin_word);
}

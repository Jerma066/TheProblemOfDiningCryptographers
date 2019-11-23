#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("Settings of connection");

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

}

SettingsDialog::~SettingsDialog()
{
    delete ui;
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
}

#include "logterminal.h"
#include "ui_logterminal.h"

LogTerminal::LogTerminal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogTerminal)
{
    ui->setupUi(this);
}

LogTerminal::~LogTerminal()
{
    delete ui;
}

//Метод открывающий терминальное окно
void LogTerminal::showLogTerminal()
{
    LogTerminal::show();
}

//Метод обраотки кнопки close
void LogTerminal::on_closeButton_clicked()
{
    LogTerminal::hide();
}

//Метод вывода отправленных данных в консоль
void LogTerminal::printSendedData(QByteArray data)
{
    ui->sendingTextEdit->textCursor().insertText(data);
    ui->sendingTextEdit->textCursor().insertText("\n");
    ui->sendingTextEdit->moveCursor(QTextCursor::End);
}

//Метод вывода принятых данных в консоль
void LogTerminal::printReceivedData(QString data)
{
    ui->receivingTextEdit->textCursor().insertText(data);
    ui->receivingTextEdit->textCursor().insertText("\n");
    ui->receivingTextEdit->moveCursor(QTextCursor::End);
}

//Oчищеия консолей
void LogTerminal::on_cls1Button_clicked()
{
    ui->sendingTextEdit->clear();
}

void LogTerminal::on_cls2Button_clicked()
{
    ui->receivingTextEdit->clear();
}

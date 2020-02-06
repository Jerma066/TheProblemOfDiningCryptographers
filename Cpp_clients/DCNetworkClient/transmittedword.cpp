#include "transmittedword.h"
#include "ui_transmittedword.h"

TransmittedWord::TransmittedWord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransmittedWord)
{
    ui->setupUi(this);

    this->setWindowTitle("Broadcasting dialog");
}

TransmittedWord::~TransmittedWord()
{
    delete ui;
}

void TransmittedWord::showTransmittedWordDialog()
{
    this->show();
}

void TransmittedWord::on_okButton_clicked()
{
    QString data = ui->wordLineEdit->text();

    if(IsBinaryOnly(data)){
        gotTransmittedWord(data);
        this->hide();
    }
}

// Функции
bool IsBinaryOnly(QString str){
    foreach(QChar c, str){
        if(c < '0' || c > '1')
            return false;
    }

    return true;
}

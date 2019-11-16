#ifndef LOGTERMINAL_H
#define LOGTERMINAL_H

#include <QDialog>

namespace Ui {
class LogTerminal;
}

class LogTerminal : public QDialog
{
    Q_OBJECT

public:
    explicit LogTerminal(QWidget *parent = nullptr);
    ~LogTerminal();

public slots:
    void showLogTerminal();

private slots:
    void on_closeButton_clicked();                 //Слот обработки нажатия кнопки close
    void printSendedData(QByteArray data);         //Слот отображения отправленных данных в поле терминала
    void printReceivedData(QString data);          //Слот отображения принятых данных в поле терминала


    void on_cls1Button_clicked();

    void on_cls2Button_clicked();

private:
    Ui::LogTerminal *ui;
};

#endif // LOGTERMINAL_H

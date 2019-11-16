#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    //~~~~~~~~~~~ Объявление потока чтения данных из TcpSocet ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
         QThread *thread_TcpSocketReader = new QThread;                                                  //Создаем поток для порта платы
         SocketReader->moveToThread(thread_TcpSocketReader);                                          //Помещаем класс в поток

         //Соединяем все нужные сигналы и слоты
         connect(thread_TcpSocketReader, SIGNAL(started()), SocketReader, SLOT(process_SocketReader()));            //Переназначения метода run
         connect(SocketReader, SIGNAL(finished_SocketReader()), thread_TcpSocketReader, SLOT(quit()));              //Переназначение метода выход

         connect(thread_TcpSocketReader, SIGNAL(finished()), SocketReader, SLOT(deleteLater()));                    //Удаление потока
         connect(SocketReader, SIGNAL(finished_SocketReader()), thread_TcpSocketReader, SLOT(deleteLater()));       //Удаление потока

         //Запуск потока
         thread_TcpSocketReader->start();
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    //~~~~~~~~~~~ Работы LogTerminal окна ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
         LogTerminal *TermNew = new LogTerminal();

         //Соединяем все нужные сигналы и слоты
         connect(ui->termButton, SIGNAL(clicked()), TermNew, SLOT(showLogTerminal()));                                 //Вызов окна по нажатию кнопки
         connect(SocketReader, SIGNAL(outSocket(QString)), TermNew, SLOT(printReceivedData(QString)));                 //Печать полученнных даных в консоль
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    //~~~~~~~~~~~ Работы LogTerminal окна ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
         SettingsDialog *SettingsDialogNew = new SettingsDialog();

         //Соединяем все нужные сигналы и слоты
         connect(ui->set_of_conButton, SIGNAL(clicked()), SettingsDialogNew, SLOT(showSettingsDialog()));                 //Вызов окна по нажатию кнопки

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


}

MainWindow::~MainWindow()
{
    delete ui;
}

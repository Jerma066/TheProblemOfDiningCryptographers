#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>

#include "tcpsocketreader.h"
#include "tcpsocketwriter.h"
#include "logterminal.h"
#include "settingsdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void CaughtSelfDescriptionNumber(int);

signals:

private:
    Ui::MainWindow *ui;
    TcpSocketReader *SocketReader = new TcpSocketReader();
    TcpSocketWriter *SocketWriter = new TcpSocketWriter();
};

#endif // MAINWINDOW_H

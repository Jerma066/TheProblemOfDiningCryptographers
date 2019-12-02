#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>

#include "tcpsocketreader.h"
#include "tcpsocketwriter.h"
#include "logterminal.h"
#include "settingsdialog.h"
#include "protocolstages.h"

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
    void CaughtDescriptionsOfGuests(QMap<int, QString> users_descriptions);
    void CaughtAllSecrets();
    void CaughtSelfXorResult(QString);
    void CaughtAllXorResults();
    void CaughtProtocolAnswer(int answer);
    void PrintInfoToTheSreen(QString text);
    void ChangeIsPayerValue(bool state);
    void delay(int millisecondsToWait);

private slots:

signals:

private:
    Ui::MainWindow *ui;
    TcpSocketReader* SocketReader = new TcpSocketReader();
    TcpSocketWriter* SocketWriter = new TcpSocketWriter();
    ProtocolStages* PSMaker;
    SettingsDialog *SettingsDialogNew;
    int selfDescriptionNumber;
    QMap<int, QString> descriptors_adresses;
    bool isPayer = false;
    bool isAllSecretsGainned = false;
};

#endif // MAINWINDOW_H

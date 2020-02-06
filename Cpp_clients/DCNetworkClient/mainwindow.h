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
    void CaughtSelfBroadcastNumber(int);
    void CaughtNumberOfMessages(int);
    void CaughtDescriptionsOfGuests(QMap<int, QString> users_descriptions);
    void CaughtAllSecrets();
    void CaughtSelfXorResult(QString);
    void CaughtAllXorResults();
    void CaughtProtocolAnswer(int answer);
    void PrintInfoToTheSreen(QString text);
    void PrintProtocolStageToTheSreen(QString text);
    void ChangeIsPayerValue(bool state);
    void CatchBroadcastingWord(QString word);
    void ChangeStateOfBroacasting(bool state);
    void delay(int millisecondsToWait);
    void writeLine();
    void EndOfProtocolStrPrint();

signals:
    void startProtocolSignal();
    void resetProtocolSignal();

private slots:
    void on_startProtocolButton_clicked();

private:
    Ui::MainWindow *ui;
    TcpSocketReader* SocketReader = new TcpSocketReader();
    TcpSocketWriter* SocketWriter = new TcpSocketWriter();
    ProtocolStages* PSMaker;
    SettingsDialog *SettingsDialogNew;
    LogTerminal * TermNew;

    int selfDescriptionNumber;
    int selfBroacastNumber = -1;
    int numberOfMessage = 0;

    QMap<int, QString> descriptors_adresses;

    bool isPayer = false;
    bool wantToBroadCast = false;
    bool isAllSecretsGainned = false;
    bool stateOfBroacasting = false;

    QString brodcastingWord = "";
};

#endif // MAINWINDOW_H

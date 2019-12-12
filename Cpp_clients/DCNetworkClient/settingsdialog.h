#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include "transmittedword.h"
#include <QNetworkInterface>
#include <tuple>
#include <parcer.h>

#include <generic.h>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog();

public slots:
    void showSettingsDialog();
    void processTransmitedWord(QString data);

private slots:
    void on_applyButton_clicked();
    void SetScoreParameters();
    void on_scoreComboBox_activated(const QString &arg1);

signals:
    void setConnectionParameters(QPair<QString, quint16> selfSettings, QPair<QString, quint16> serverSettings);
    void broadcastingSignal(bool);
    void showTransmittedWordDoalog();
    void gotEncodeBinWord(QString);

private:
    Ui::SettingsDialog *ui;
    QPair<QString,  quint16> selfSocket;
    QPair<QString,  quint16> serverSocket;
    TransmittedWord* TrWrDialog = new TransmittedWord();
    Parcer parce = Parcer();
    bool stateOfBroadcasting = false;

};

#endif // SETTINGSDIALOG_H

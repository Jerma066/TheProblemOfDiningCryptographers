#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QNetworkInterface>
#include <tuple>

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

private slots:
    void on_applyButton_clicked();
    void SetScoreParameters();

    void on_scoreComboBox_activated(const QString &arg1);

signals:
    void setConnectionParameters(QPair<QString, quint16> selfSettings, QPair<QString, quint16> serverSettings);
    void paymentSignal(bool);

private:
    Ui::SettingsDialog *ui;
    QPair<QString,  quint16> selfSocket;
    QPair<QString,  quint16> serverSocket;

};

#endif // SETTINGSDIALOG_H

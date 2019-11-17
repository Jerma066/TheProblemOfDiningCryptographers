#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QNetworkInterface>

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

private:
    Ui::SettingsDialog *ui;
    QPair<QString,  int> selfSocket;
    QPair<QString,  int> serverSocket;


};

#endif // SETTINGSDIALOG_H

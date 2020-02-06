#ifndef TRANSMITTEDWORD_H
#define TRANSMITTEDWORD_H

#include <QDialog>
#include "generic.h"

namespace Ui {
class TransmittedWord;
}

class TransmittedWord : public QDialog
{
    Q_OBJECT

public:
    explicit TransmittedWord(QWidget *parent = nullptr);
    ~TransmittedWord();

public slots:
    void showTransmittedWordDialog();

private slots:
    void on_okButton_clicked();

signals:
    void gotTransmittedWord(QString);

private:
    Ui::TransmittedWord *ui;
};

bool IsBinaryOnly(QString str);

#endif // TRANSMITTEDWORD_H

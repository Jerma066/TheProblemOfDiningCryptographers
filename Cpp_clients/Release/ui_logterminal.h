/********************************************************************************
** Form generated from reading UI file 'logterminal.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGTERMINAL_H
#define UI_LOGTERMINAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_LogTerminal
{
public:
    QGridLayout *gridLayout;
    QPlainTextEdit *receivingTextEdit;
    QPushButton *cls1Button;
    QPlainTextEdit *sendingTextEdit;
    QPushButton *cls2Button;
    QPushButton *closeButton;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *LogTerminal)
    {
        if (LogTerminal->objectName().isEmpty())
            LogTerminal->setObjectName(QString::fromUtf8("LogTerminal"));
        LogTerminal->resize(766, 558);
        gridLayout = new QGridLayout(LogTerminal);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        receivingTextEdit = new QPlainTextEdit(LogTerminal);
        receivingTextEdit->setObjectName(QString::fromUtf8("receivingTextEdit"));
        receivingTextEdit->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(receivingTextEdit, 4, 0, 1, 4);

        cls1Button = new QPushButton(LogTerminal);
        cls1Button->setObjectName(QString::fromUtf8("cls1Button"));

        gridLayout->addWidget(cls1Button, 0, 3, 1, 1);

        sendingTextEdit = new QPlainTextEdit(LogTerminal);
        sendingTextEdit->setObjectName(QString::fromUtf8("sendingTextEdit"));
        sendingTextEdit->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(sendingTextEdit, 1, 0, 1, 4);

        cls2Button = new QPushButton(LogTerminal);
        cls2Button->setObjectName(QString::fromUtf8("cls2Button"));

        gridLayout->addWidget(cls2Button, 3, 3, 1, 1);

        closeButton = new QPushButton(LogTerminal);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        gridLayout->addWidget(closeButton, 5, 3, 1, 1);

        label = new QLabel(LogTerminal);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 1, 1, 1);

        label_2 = new QLabel(LogTerminal);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 0, 1, 2);


        retranslateUi(LogTerminal);

        QMetaObject::connectSlotsByName(LogTerminal);
    } // setupUi

    void retranslateUi(QDialog *LogTerminal)
    {
        LogTerminal->setWindowTitle(QApplication::translate("LogTerminal", "Dialog", nullptr));
        cls1Button->setText(QApplication::translate("LogTerminal", "clear first screen", nullptr));
        cls2Button->setText(QApplication::translate("LogTerminal", "clear second screen", nullptr));
        closeButton->setText(QApplication::translate("LogTerminal", "close", nullptr));
        label->setText(QApplication::translate("LogTerminal", "Sent data", nullptr));
        label_2->setText(QApplication::translate("LogTerminal", "Received data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogTerminal: public Ui_LogTerminal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGTERMINAL_H

/********************************************************************************
** Form generated from reading UI file 'transmittedword.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSMITTEDWORD_H
#define UI_TRANSMITTEDWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TransmittedWord
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *textLabel;
    QLineEdit *wordLineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;

    void setupUi(QDialog *TransmittedWord)
    {
        if (TransmittedWord->objectName().isEmpty())
            TransmittedWord->setObjectName(QString::fromUtf8("TransmittedWord"));
        TransmittedWord->resize(416, 119);
        TransmittedWord->setMinimumSize(QSize(416, 119));
        TransmittedWord->setMaximumSize(QSize(416, 119));
        verticalLayout = new QVBoxLayout(TransmittedWord);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textLabel = new QLabel(TransmittedWord);
        textLabel->setObjectName(QString::fromUtf8("textLabel"));
        textLabel->setMaximumSize(QSize(394, 30));

        verticalLayout->addWidget(textLabel);

        wordLineEdit = new QLineEdit(TransmittedWord);
        wordLineEdit->setObjectName(QString::fromUtf8("wordLineEdit"));

        verticalLayout->addWidget(wordLineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okButton = new QPushButton(TransmittedWord);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(TransmittedWord);

        QMetaObject::connectSlotsByName(TransmittedWord);
    } // setupUi

    void retranslateUi(QDialog *TransmittedWord)
    {
        TransmittedWord->setWindowTitle(QApplication::translate("TransmittedWord", "Dialog", nullptr));
        textLabel->setText(QApplication::translate("TransmittedWord", "Write the word sent to the rest:", nullptr));
        okButton->setText(QApplication::translate("TransmittedWord", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransmittedWord: public Ui_TransmittedWord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSMITTEDWORD_H

/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *ipAddressLabel;
    QLineEdit *selfIpAddressLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *portNumberLabel;
    QLineEdit *selfPortLineEdit;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *serverIpAddressLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *serverPortLineEdit;
    QGroupBox *payGroupBox;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QComboBox *scoreComboBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *applyButton;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QString::fromUtf8("SettingsDialog"));
        SettingsDialog->resize(700, 163);
        SettingsDialog->setMaximumSize(QSize(700, 163));
        gridLayout = new QGridLayout(SettingsDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(SettingsDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        ipAddressLabel = new QLabel(groupBox);
        ipAddressLabel->setObjectName(QString::fromUtf8("ipAddressLabel"));

        horizontalLayout_5->addWidget(ipAddressLabel);

        selfIpAddressLineEdit = new QLineEdit(groupBox);
        selfIpAddressLineEdit->setObjectName(QString::fromUtf8("selfIpAddressLineEdit"));
        selfIpAddressLineEdit->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_5->addWidget(selfIpAddressLineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        portNumberLabel = new QLabel(groupBox);
        portNumberLabel->setObjectName(QString::fromUtf8("portNumberLabel"));

        horizontalLayout_2->addWidget(portNumberLabel);

        selfPortLineEdit = new QLineEdit(groupBox);
        selfPortLineEdit->setObjectName(QString::fromUtf8("selfPortLineEdit"));
        selfPortLineEdit->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_2->addWidget(selfPortLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(SettingsDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        serverIpAddressLineEdit = new QLineEdit(groupBox_2);
        serverIpAddressLineEdit->setObjectName(QString::fromUtf8("serverIpAddressLineEdit"));

        horizontalLayout_4->addWidget(serverIpAddressLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        serverPortLineEdit = new QLineEdit(groupBox_2);
        serverPortLineEdit->setObjectName(QString::fromUtf8("serverPortLineEdit"));
        serverPortLineEdit->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(serverPortLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_3);


        gridLayout->addWidget(groupBox_2, 0, 1, 1, 1);

        payGroupBox = new QGroupBox(SettingsDialog);
        payGroupBox->setObjectName(QString::fromUtf8("payGroupBox"));
        verticalLayout_3 = new QVBoxLayout(payGroupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(payGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setPointSize(9);
        font.setUnderline(true);
        label_3->setFont(font);

        verticalLayout_3->addWidget(label_3);

        scoreComboBox = new QComboBox(payGroupBox);
        scoreComboBox->setObjectName(QString::fromUtf8("scoreComboBox"));

        verticalLayout_3->addWidget(scoreComboBox);


        gridLayout->addWidget(payGroupBox, 0, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(7);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        applyButton = new QPushButton(SettingsDialog);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));

        horizontalLayout->addWidget(applyButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 3);


        retranslateUi(SettingsDialog);

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("SettingsDialog", "Self Settings", nullptr));
        ipAddressLabel->setText(QApplication::translate("SettingsDialog", "IP Address: ", nullptr));
        portNumberLabel->setText(QApplication::translate("SettingsDialog", "Port:          ", nullptr));
        groupBox_2->setTitle(QApplication::translate("SettingsDialog", "Server Settings", nullptr));
        label->setText(QApplication::translate("SettingsDialog", "IP Address: ", nullptr));
        label_2->setText(QApplication::translate("SettingsDialog", "Port:          ", nullptr));
        payGroupBox->setTitle(QApplication::translate("SettingsDialog", "Score", nullptr));
        label_3->setText(QApplication::translate("SettingsDialog", "Broadcast?", nullptr));
        applyButton->setText(QApplication::translate("SettingsDialog", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'viewmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWMENU_H
#define UI_VIEWMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QPushButton *PapaJohns;
    QPushButton *Subway;
    QPushButton *KFC;
    QPushButton *Dominos;
    QPushButton *Chipotle;
    QPushButton *MacDonalds;
    QPushButton *ElPolloLoco;
    QPushButton *InNOut;
    QPushButton *Wendys;
    QPushButton *JackInTheBox;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(656, 577);
        formLayoutWidget = new QWidget(Dialog);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(190, 150, 271, 211));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        PapaJohns = new QPushButton(formLayoutWidget);
        PapaJohns->setObjectName(QString::fromUtf8("PapaJohns"));

        formLayout->setWidget(0, QFormLayout::LabelRole, PapaJohns);

        Subway = new QPushButton(formLayoutWidget);
        Subway->setObjectName(QString::fromUtf8("Subway"));

        formLayout->setWidget(0, QFormLayout::FieldRole, Subway);

        KFC = new QPushButton(formLayoutWidget);
        KFC->setObjectName(QString::fromUtf8("KFC"));

        formLayout->setWidget(1, QFormLayout::LabelRole, KFC);

        Dominos = new QPushButton(formLayoutWidget);
        Dominos->setObjectName(QString::fromUtf8("Dominos"));

        formLayout->setWidget(1, QFormLayout::FieldRole, Dominos);

        Chipotle = new QPushButton(formLayoutWidget);
        Chipotle->setObjectName(QString::fromUtf8("Chipotle"));

        formLayout->setWidget(2, QFormLayout::LabelRole, Chipotle);

        MacDonalds = new QPushButton(formLayoutWidget);
        MacDonalds->setObjectName(QString::fromUtf8("MacDonalds"));

        formLayout->setWidget(2, QFormLayout::FieldRole, MacDonalds);

        ElPolloLoco = new QPushButton(formLayoutWidget);
        ElPolloLoco->setObjectName(QString::fromUtf8("ElPolloLoco"));

        formLayout->setWidget(3, QFormLayout::LabelRole, ElPolloLoco);

        InNOut = new QPushButton(formLayoutWidget);
        InNOut->setObjectName(QString::fromUtf8("InNOut"));

        formLayout->setWidget(5, QFormLayout::FieldRole, InNOut);

        Wendys = new QPushButton(formLayoutWidget);
        Wendys->setObjectName(QString::fromUtf8("Wendys"));

        formLayout->setWidget(5, QFormLayout::LabelRole, Wendys);

        JackInTheBox = new QPushButton(formLayoutWidget);
        JackInTheBox->setObjectName(QString::fromUtf8("JackInTheBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, JackInTheBox);

        plainTextEdit = new QPlainTextEdit(Dialog);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(230, 30, 171, 81));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(490, 490, 93, 28));

        retranslateUi(Dialog);
        QObject::connect(Wendys, SIGNAL(clicked()), Dialog, SLOT(open()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        PapaJohns->setText(QCoreApplication::translate("Dialog", "Papa John's", nullptr));
        Subway->setText(QCoreApplication::translate("Dialog", "Subway", nullptr));
        KFC->setText(QCoreApplication::translate("Dialog", "KFC", nullptr));
        Dominos->setText(QCoreApplication::translate("Dialog", "Domino's Pizza", nullptr));
        Chipotle->setText(QCoreApplication::translate("Dialog", "Chipotle", nullptr));
        MacDonalds->setText(QCoreApplication::translate("Dialog", "MacDonald's", nullptr));
        ElPolloLoco->setText(QCoreApplication::translate("Dialog", "El Pollo Loco", nullptr));
        InNOut->setText(QCoreApplication::translate("Dialog", "In-N-Out", nullptr));
        Wendys->setText(QCoreApplication::translate("Dialog", "Wendy's", nullptr));
        JackInTheBox->setText(QCoreApplication::translate("Dialog", "Jack In The Box", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("Dialog", "Select the restaurant whose menu you would like to view", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWMENU_H

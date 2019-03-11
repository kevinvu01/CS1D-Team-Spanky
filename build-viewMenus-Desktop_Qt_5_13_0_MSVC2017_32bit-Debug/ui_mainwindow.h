/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPlainTextEdit *plainTextEdit;
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
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(740, 639);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(280, 130, 171, 81));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(240, 250, 271, 211));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
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

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 740, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("MainWindow", "Select the restaurant whose menu you would like to view", nullptr));
        PapaJohns->setText(QCoreApplication::translate("MainWindow", "Papa John's", nullptr));
        Subway->setText(QCoreApplication::translate("MainWindow", "Subway", nullptr));
        KFC->setText(QCoreApplication::translate("MainWindow", "KFC", nullptr));
        Dominos->setText(QCoreApplication::translate("MainWindow", "Domino's Pizza", nullptr));
        Chipotle->setText(QCoreApplication::translate("MainWindow", "Chipotle", nullptr));
        MacDonalds->setText(QCoreApplication::translate("MainWindow", "MacDonald's", nullptr));
        ElPolloLoco->setText(QCoreApplication::translate("MainWindow", "El Pollo Loco", nullptr));
        InNOut->setText(QCoreApplication::translate("MainWindow", "In-N-Out", nullptr));
        Wendys->setText(QCoreApplication::translate("MainWindow", "Wendy's", nullptr));
        JackInTheBox->setText(QCoreApplication::translate("MainWindow", "Jack In The Box", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

#ifndef PLANTRIP_H
#define PLANTRIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    //QWidget *formLayoutWidget;
    QPushButton *ShortestTrip;
    QPushButton *SelectNumberOfRestaurants;
    QPushButton *CustomTrip;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(656, 577);
//        formLayoutWidget = new QWidget(Dialog);
//        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
//        formLayoutWidget->setGeometry(QRect(190, 150, 271, 211));
//        formLayout = new QFormLayout(formLayoutWidget);
//        formLayout->setObjectName(QString::fromUtf8("formLayout"));
//        formLayout->setContentsMargins(0, 0, 0, 0);
        ShortestTrip = new QPushButton();
        ShortestTrip->setObjectName(QString::fromUtf8("ShortestTrip"));

//        formLayout->setWidget(0, QFormLayout::LabelRole, PapaJohns);

        SelectNumberOfRestaurants = new QPushButton();
        SelectNumberOfRestaurants->setObjectName(QString::fromUtf8("Select Number of Restaurants"));

//        formLayout->setWidget(0, QFormLayout::FieldRole, Subway);

        CustomTrip = new QPushButton();
        CustomTrip->setObjectName(QString::fromUtf8("Custom Trip"));

        textBrowser = new QTextBrowser(Dialog);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(230, 30, 171, 81));
//        pushButton = new QPushButton(Dialog);
//        pushButton->setObjectName(QString::fromUtf8("pushButton"));
//        pushButton->setGeometry(QRect(490, 490, 93, 28));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        ShortestTrip->setText(QCoreApplication::translate("Dialog", "Shortest Trip", nullptr));
        SelectNumberOfRestaurants->setText(QCoreApplication::translate("Dialog", "Select Number of Restaurants", nullptr));
        CustomTrip->setText(QCoreApplication::translate("Dialog", "Custom Trip", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PLANTRIP_H

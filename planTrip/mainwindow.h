#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    QWidget *centralWidget;
    QPushButton *ShortestTrip;
    QPushButton *SelectNumberOfRestaurants;
    QPushButton *CustomTrip;
    QTextBrowser *textBrowser;

    void setupUi(QMainWindow *MainWindow)
        {
            if (MainWindow->objectName().isEmpty())
                MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
            MainWindow->resize(740, 639);
            centralWidget = new QWidget(MainWindow);
            centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
            textBrowser = new QTextBrowser(centralWidget);
            textBrowser->setObjectName(QString::fromUtf8("plainTextEdit"));
            textBrowser->setGeometry(QRect(280, 130, 171, 81));
//            formLayoutWidget = new QWidget(centralWidget);
//            formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
//            formLayoutWidget->setGeometry(QRect(240, 250, 271, 211));
//            formLayout = new QFormLayout(formLayoutWidget);
//            formLayout->setSpacing(6);
//            formLayout->setContentsMargins(11, 11, 11, 11);
//            formLayout->setObjectName(QString::fromUtf8("formLayout"));
//            formLayout->setContentsMargins(0, 0, 0, 0);
            ShortestTrip=new QPushButton();
            ShortestTrip->setObjectName(QString::fromUtf8("Shortest Trip"));

            SelectNumberOfRestaurants=new QPushButton();
            SelectNumberOfRestaurants->setObjectName(QString::fromUtf8("Select Number of Restaurants"));

            CustomTrip= new QPushButton();
            CustomTrip->setObjectName(QString::fromUtf8("Custom Trip"));
        }

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        textBrowser->setText(QCoreApplication::translate("MainWindow", "Select an Option", nullptr));
        ShortestTrip->setText(QCoreApplication::translate("MainWindow","Shortest Trip", nullptr));
        SelectNumberOfRestaurants->setText(QCoreApplication::translate("MainWindow","Select Number of Restaurants", nullptr));
        CustomTrip->setText(QCoreApplication::translate("MainWindow","Custom Trip", nullptr));
    }

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

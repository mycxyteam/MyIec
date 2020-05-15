/********************************************************************************
** Form generated from reading UI file 'myiec.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYIEC_H
#define UI_MYIEC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <newcombobox.h>

QT_BEGIN_NAMESPACE

class Ui_MyIec
{
public:
    QAction *actionA;
    QAction *actionB;
    QAction *actionQ;
    QWidget *centralWidget;
    NewComboBox *comboBox;
    QComboBox *comboBox_Baud;
    QLineEdit *lineEdit_Password;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QProgressBar *progressBar;
    QTableView *tableView;
    QPushButton *pushButton_OpenOrCloseSerial;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyIec)
    {
        if (MyIec->objectName().isEmpty())
            MyIec->setObjectName(QStringLiteral("MyIec"));
        MyIec->resize(800, 600);
        actionA = new QAction(MyIec);
        actionA->setObjectName(QStringLiteral("actionA"));
        actionB = new QAction(MyIec);
        actionB->setObjectName(QStringLiteral("actionB"));
        actionQ = new QAction(MyIec);
        actionQ->setObjectName(QStringLiteral("actionQ"));
        centralWidget = new QWidget(MyIec);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        comboBox = new NewComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(90, 90, 69, 22));
        comboBox_Baud = new QComboBox(centralWidget);
        comboBox_Baud->setObjectName(QStringLiteral("comboBox_Baud"));
        comboBox_Baud->setGeometry(QRect(90, 130, 69, 22));
        lineEdit_Password = new QLineEdit(centralWidget);
        lineEdit_Password->setObjectName(QStringLiteral("lineEdit_Password"));
        lineEdit_Password->setGeometry(QRect(90, 180, 113, 20));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(270, 140, 75, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 180, 75, 23));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(50, 240, 700, 200));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(50, 440, 700, 20));
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(480, 30, 256, 192));
        pushButton_OpenOrCloseSerial = new QPushButton(centralWidget);
        pushButton_OpenOrCloseSerial->setObjectName(QStringLiteral("pushButton_OpenOrCloseSerial"));
        pushButton_OpenOrCloseSerial->setGeometry(QRect(270, 90, 75, 23));
        MyIec->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MyIec);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MyIec->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyIec);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MyIec->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MyIec);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyIec->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(actionA);
        menu->addAction(actionB);
        menu_2->addAction(actionQ);

        retranslateUi(MyIec);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MyIec);
    } // setupUi

    void retranslateUi(QMainWindow *MyIec)
    {
        MyIec->setWindowTitle(QApplication::translate("MyIec", "MyIec", 0));
        actionA->setText(QApplication::translate("MyIec", "\344\270\262\345\217\243\350\256\276\347\275\256", 0));
        actionB->setText(QApplication::translate("MyIec", "\351\200\232\350\256\257\350\256\276\347\275\256", 0));
        actionQ->setText(QApplication::translate("MyIec", "\346\211\223\345\274\200log.txt", 0));
        comboBox_Baud->clear();
        comboBox_Baud->insertItems(0, QStringList()
         << QApplication::translate("MyIec", "300", 0)
         << QApplication::translate("MyIec", "600", 0)
         << QApplication::translate("MyIec", "1200", 0)
         << QApplication::translate("MyIec", "2400", 0)
         << QApplication::translate("MyIec", "4800", 0)
         << QApplication::translate("MyIec", "9600", 0)
         << QApplication::translate("MyIec", "19200", 0)
        );
        pushButton->setText(QApplication::translate("MyIec", "\350\257\273", 0));
        pushButton_2->setText(QApplication::translate("MyIec", "\345\206\231", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MyIec", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MyIec", "Tab 2", 0));
        pushButton_OpenOrCloseSerial->setText(QApplication::translate("MyIec", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
        menu->setTitle(QApplication::translate("MyIec", "\350\256\276\347\275\256", 0));
        menu_2->setTitle(QApplication::translate("MyIec", "\346\227\245\345\277\227", 0));
    } // retranslateUi

};

namespace Ui {
    class MyIec: public Ui_MyIec {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYIEC_H

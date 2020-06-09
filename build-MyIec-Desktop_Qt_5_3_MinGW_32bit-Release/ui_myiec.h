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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
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
    QAction *actionC;
    QAction *actionRF;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QPushButton *pushButton_clear;
    QLabel *label_3;
    QProgressBar *progressBar;
    QPushButton *pushButton_clear2;
    QPushButton *pushButton_OpenOrCloseSerial;
    QRadioButton *radioButton;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_4;
    QLabel *label_2;
    QTextBrowser *textBrowser_3;
    NewComboBox *comboBox;
    QLabel *label;
    QComboBox *comboBox_Baud;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *textBrowser;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_2;
    QTextBrowser *textBrowser_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLabel *label_7;
    QLabel *label_6;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_Password;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_8;
    QLineEdit *lineEdit_4;
    QRadioButton *radioButton_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_RF;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyIec)
    {
        if (MyIec->objectName().isEmpty())
            MyIec->setObjectName(QStringLiteral("MyIec"));
        MyIec->resize(920, 618);
        actionA = new QAction(MyIec);
        actionA->setObjectName(QStringLiteral("actionA"));
        actionB = new QAction(MyIec);
        actionB->setObjectName(QStringLiteral("actionB"));
        actionQ = new QAction(MyIec);
        actionQ->setObjectName(QStringLiteral("actionQ"));
        actionC = new QAction(MyIec);
        actionC->setObjectName(QStringLiteral("actionC"));
        actionRF = new QAction(MyIec);
        actionRF->setObjectName(QStringLiteral("actionRF"));
        centralWidget = new QWidget(MyIec);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1, Qt::AlignRight);

        pushButton_clear = new QPushButton(centralWidget);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));
        pushButton_clear->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pushButton_clear, 9, 0, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1, Qt::AlignRight);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(progressBar, 11, 0, 1, 8);

        pushButton_clear2 = new QPushButton(centralWidget);
        pushButton_clear2->setObjectName(QStringLiteral("pushButton_clear2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_clear2->sizePolicy().hasHeightForWidth());
        pushButton_clear2->setSizePolicy(sizePolicy);
        pushButton_clear2->setMinimumSize(QSize(0, 40));
        pushButton_clear2->setMaximumSize(QSize(90, 16777215));
        pushButton_clear2->setLayoutDirection(Qt::LeftToRight);
        pushButton_clear2->setAutoFillBackground(false);

        gridLayout->addWidget(pushButton_clear2, 0, 7, 2, 1, Qt::AlignRight);

        pushButton_OpenOrCloseSerial = new QPushButton(centralWidget);
        pushButton_OpenOrCloseSerial->setObjectName(QStringLiteral("pushButton_OpenOrCloseSerial"));
        pushButton_OpenOrCloseSerial->setMinimumSize(QSize(75, 23));
        pushButton_OpenOrCloseSerial->setMaximumSize(QSize(75, 23));

        gridLayout->addWidget(pushButton_OpenOrCloseSerial, 0, 5, 1, 1);

        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setChecked(false);
        radioButton->setAutoExclusive(false);

        gridLayout->addWidget(radioButton, 5, 5, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 23, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 8, 1, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1, Qt::AlignRight);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1, Qt::AlignRight);

        textBrowser_3 = new QTextBrowser(centralWidget);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));
        textBrowser_3->setMinimumSize(QSize(300, 192));

        gridLayout->addWidget(textBrowser_3, 2, 7, 8, 1);

        comboBox = new NewComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(69, 22));
        comboBox->setMaximumSize(QSize(69, 22));

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1, Qt::AlignRight);

        comboBox_Baud = new QComboBox(centralWidget);
        comboBox_Baud->setObjectName(QStringLiteral("comboBox_Baud"));
        comboBox_Baud->setMinimumSize(QSize(69, 22));
        comboBox_Baud->setMaximumSize(QSize(69, 22));

        gridLayout->addWidget(comboBox_Baud, 1, 1, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QFont font;
        font.setPointSize(12);
        tabWidget->setFont(font);
        tabWidget->setFocusPolicy(Qt::WheelFocus);
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout = new QHBoxLayout(tab);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(tab);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        horizontalLayout->addWidget(textBrowser);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalLayout_2 = new QHBoxLayout(tab_2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        textBrowser_2 = new QTextBrowser(tab_2);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        textBrowser_2->setMouseTracking(false);
        textBrowser_2->setFocusPolicy(Qt::TabFocus);
        textBrowser_2->setContextMenuPolicy(Qt::DefaultContextMenu);
        textBrowser_2->setLayoutDirection(Qt::LeftToRight);
        textBrowser_2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);

        horizontalLayout_2->addWidget(textBrowser_2);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 10, 0, 1, 8);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(75, 23));
        pushButton_2->setMaximumSize(QSize(75, 23));

        gridLayout->addWidget(pushButton_2, 3, 5, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(75, 23));
        pushButton->setMaximumSize(QSize(75, 23));

        gridLayout->addWidget(pushButton, 2, 5, 1, 1);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 6, 2, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 6, 0, 1, 1, Qt::AlignRight);

        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setMinimumSize(QSize(60, 0));
        lineEdit_3->setMaximumSize(QSize(60, 16777215));

        gridLayout->addWidget(lineEdit_3, 6, 1, 1, 1);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(199, 0));
        lineEdit_2->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(lineEdit_2, 5, 1, 1, 4);

        lineEdit_Password = new QLineEdit(centralWidget);
        lineEdit_Password->setObjectName(QStringLiteral("lineEdit_Password"));
        sizePolicy.setHeightForWidth(lineEdit_Password->sizePolicy().hasHeightForWidth());
        lineEdit_Password->setSizePolicy(sizePolicy);
        lineEdit_Password->setMinimumSize(QSize(125, 20));
        lineEdit_Password->setMaximumSize(QSize(125, 20));

        gridLayout->addWidget(lineEdit_Password, 2, 1, 1, 3);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMinimumSize(QSize(125, 20));
        lineEdit->setMaximumSize(QSize(125, 20));

        gridLayout->addWidget(lineEdit, 3, 1, 1, 2);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(75, 16777215));

        gridLayout->addWidget(pushButton_3, 6, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 6, 1, 1);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 4, 0, 1, 1, Qt::AlignRight);

        lineEdit_4 = new QLineEdit(centralWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setMinimumSize(QSize(125, 0));
        lineEdit_4->setMaximumSize(QSize(125, 16777215));

        gridLayout->addWidget(lineEdit_4, 4, 1, 1, 2);

        radioButton_2 = new QRadioButton(centralWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        gridLayout->addWidget(radioButton_2, 1, 5, 1, 1);

        MyIec->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MyIec);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 920, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_RF = new QMenu(menuBar);
        menu_RF->setObjectName(QStringLiteral("menu_RF"));
        MyIec->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyIec);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MyIec->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MyIec);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyIec->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_RF->menuAction());
        menu->addAction(actionA);
        menu->addAction(actionB);
        menu->addAction(actionC);
        menu_2->addAction(actionQ);
        menu_RF->addAction(actionRF);

        retranslateUi(MyIec);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MyIec);
    } // setupUi

    void retranslateUi(QMainWindow *MyIec)
    {
        MyIec->setWindowTitle(QApplication::translate("MyIec", "MyIec", 0));
        actionA->setText(QApplication::translate("MyIec", "\344\270\262\345\217\243\350\256\276\347\275\256", 0));
        actionB->setText(QApplication::translate("MyIec", "\351\200\232\350\256\257\350\256\276\347\275\256", 0));
        actionQ->setText(QApplication::translate("MyIec", "\346\211\223\345\274\200*.txt", 0));
        actionQ->setIconText(QApplication::translate("MyIec", "\346\211\223\345\274\200.txt", 0));
#ifndef QT_NO_TOOLTIP
        actionQ->setToolTip(QApplication::translate("MyIec", "\346\211\223\345\274\200.txt", 0));
#endif // QT_NO_TOOLTIP
        actionC->setText(QApplication::translate("MyIec", "\346\227\266\351\227\264\345\217\202\346\225\260", 0));
        actionRF->setText(QApplication::translate("MyIec", "\346\211\223\345\274\200\350\256\276\347\275\256\350\275\257\344\273\266", 0));
        actionRF->setIconText(QApplication::translate("MyIec", "RF", 0));
#ifndef QT_NO_TOOLTIP
        actionRF->setToolTip(QApplication::translate("MyIec", "RF", 0));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("MyIec", "\345\257\206\347\240\201\357\274\232", 0));
        pushButton_clear->setText(QApplication::translate("MyIec", "\346\270\205\347\251\272\346\225\260\346\215\256", 0));
        label_3->setText(QApplication::translate("MyIec", "\350\241\250\345\217\267\357\274\232", 0));
        pushButton_clear2->setText(QApplication::translate("MyIec", "\346\270\205\347\251\272\350\247\243\346\236\220\346\225\260\346\215\256", 0));
        pushButton_OpenOrCloseSerial->setText(QApplication::translate("MyIec", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
        radioButton->setText(QApplication::translate("MyIec", "\350\257\273\346\223\215\344\275\234\345\270\246\346\225\260\346\215\256", 0));
        label_4->setText(QApplication::translate("MyIec", "\345\206\231\345\205\245\346\225\260\346\215\256\357\274\232", 0));
        label_2->setText(QApplication::translate("MyIec", "\346\263\242\347\211\271\347\216\207\357\274\232", 0));
        label->setText(QApplication::translate("MyIec", "\344\270\262\345\217\243\357\274\232", 0));
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
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MyIec", "ASCII", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MyIec", "HEX", 0));
        pushButton_2->setText(QApplication::translate("MyIec", "\345\206\231", 0));
        pushButton->setText(QApplication::translate("MyIec", "\350\257\273", 0));
        label_7->setText(QApplication::translate("MyIec", "s", 0));
        label_6->setText(QApplication::translate("MyIec", "\345\276\252\347\216\257\346\212\204\350\257\273\357\274\232", 0));
        pushButton_3->setText(QApplication::translate("MyIec", "\346\211\247\350\241\214", 0));
        label_8->setText(QApplication::translate("MyIec", "\346\225\260\346\215\256ID\357\274\232", 0));
        lineEdit_4->setText(QString());
        radioButton_2->setText(QApplication::translate("MyIec", "RF", 0));
        menu->setTitle(QApplication::translate("MyIec", "\350\256\276\347\275\256", 0));
        menu_2->setTitle(QApplication::translate("MyIec", "\346\227\245\345\277\227", 0));
        menu_RF->setTitle(QApplication::translate("MyIec", "\350\256\276\347\275\256RF\345\267\245\350\243\205", 0));
    } // retranslateUi

};

namespace Ui {
    class MyIec: public Ui_MyIec {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYIEC_H

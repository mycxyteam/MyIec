/********************************************************************************
** Form generated from reading UI file 'communicationset.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMUNICATIONSET_H
#define UI_COMMUNICATIONSET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_CommunicationSet
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QComboBox *comboBox_FrameWay;
    QLabel *label_2;
    QComboBox *comboBox_Baud;
    QLabel *label_3;
    QLineEdit *lineEdit_Password;

    void setupUi(QDialog *CommunicationSet)
    {
        if (CommunicationSet->objectName().isEmpty())
            CommunicationSet->setObjectName(QStringLiteral("CommunicationSet"));
        CommunicationSet->resize(400, 300);
        CommunicationSet->setMinimumSize(QSize(400, 300));
        CommunicationSet->setMaximumSize(QSize(400, 300));
        buttonBox = new QDialogButtonBox(CommunicationSet);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(CommunicationSet);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 80, 91, 22));
        comboBox_FrameWay = new QComboBox(CommunicationSet);
        comboBox_FrameWay->setObjectName(QStringLiteral("comboBox_FrameWay"));
        comboBox_FrameWay->setGeometry(QRect(200, 80, 91, 22));
        label_2 = new QLabel(CommunicationSet);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 30, 91, 22));
        comboBox_Baud = new QComboBox(CommunicationSet);
        comboBox_Baud->setObjectName(QStringLiteral("comboBox_Baud"));
        comboBox_Baud->setGeometry(QRect(200, 30, 61, 22));
        label_3 = new QLabel(CommunicationSet);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(100, 130, 91, 22));
        lineEdit_Password = new QLineEdit(CommunicationSet);
        lineEdit_Password->setObjectName(QStringLiteral("lineEdit_Password"));
        lineEdit_Password->setGeometry(QRect(200, 130, 100, 22));

        retranslateUi(CommunicationSet);
        QObject::connect(buttonBox, SIGNAL(accepted()), CommunicationSet, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CommunicationSet, SLOT(reject()));

        QMetaObject::connectSlotsByName(CommunicationSet);
    } // setupUi

    void retranslateUi(QDialog *CommunicationSet)
    {
        CommunicationSet->setWindowTitle(QApplication::translate("CommunicationSet", "Dialog", 0));
        label->setText(QApplication::translate("CommunicationSet", "\351\200\232\350\256\257\346\226\271\345\274\217\357\274\232", 0));
        comboBox_FrameWay->clear();
        comboBox_FrameWay->insertItems(0, QStringList()
         << QApplication::translate("CommunicationSet", "\345\256\214\346\225\264\345\215\217\350\256\256\345\270\247", 0)
         << QApplication::translate("CommunicationSet", "\345\215\225\344\270\252\345\215\217\350\256\256\345\270\247", 0)
        );
        label_2->setText(QApplication::translate("CommunicationSet", "\346\263\242\347\211\271\347\216\207\357\274\232", 0));
        comboBox_Baud->clear();
        comboBox_Baud->insertItems(0, QStringList()
         << QApplication::translate("CommunicationSet", "300", 0)
         << QApplication::translate("CommunicationSet", "600", 0)
         << QApplication::translate("CommunicationSet", "1200", 0)
         << QApplication::translate("CommunicationSet", "2400", 0)
         << QApplication::translate("CommunicationSet", "4800", 0)
         << QApplication::translate("CommunicationSet", "9600", 0)
         << QApplication::translate("CommunicationSet", "19200", 0)
        );
        label_3->setText(QApplication::translate("CommunicationSet", "\345\257\206\347\240\201\357\274\232", 0));
        lineEdit_Password->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CommunicationSet: public Ui_CommunicationSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMUNICATIONSET_H

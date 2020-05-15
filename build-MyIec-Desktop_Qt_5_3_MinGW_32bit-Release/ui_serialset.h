/********************************************************************************
** Form generated from reading UI file 'serialset.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALSET_H
#define UI_SERIALSET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <newcombobox.h>

QT_BEGIN_NAMESPACE

class Ui_SerialSet
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    NewComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;

    void setupUi(QDialog *SerialSet)
    {
        if (SerialSet->objectName().isEmpty())
            SerialSet->setObjectName(QStringLiteral("SerialSet"));
        SerialSet->resize(400, 300);
        SerialSet->setMinimumSize(QSize(400, 300));
        SerialSet->setMaximumSize(QSize(400, 300));
        SerialSet->setLayoutDirection(Qt::LeftToRight);
        buttonBox = new QDialogButtonBox(SerialSet);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(SerialSet);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 90, 54, 22));
        label_2 = new QLabel(SerialSet);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 130, 54, 22));
        label_3 = new QLabel(SerialSet);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(100, 170, 71, 22));
        label_4 = new QLabel(SerialSet);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(100, 50, 54, 22));
        comboBox = new NewComboBox(SerialSet);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(210, 50, 69, 22));
        comboBox->setMouseTracking(false);
        comboBox->setContextMenuPolicy(Qt::DefaultContextMenu);
        comboBox->setAcceptDrops(false);
        comboBox_2 = new QComboBox(SerialSet);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(210, 90, 69, 22));
        comboBox_2->setLayoutDirection(Qt::LeftToRight);
        comboBox_2->setAutoFillBackground(false);
        comboBox_3 = new QComboBox(SerialSet);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(210, 130, 69, 22));
        comboBox_4 = new QComboBox(SerialSet);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setGeometry(QRect(210, 170, 69, 22));

        retranslateUi(SerialSet);
        QObject::connect(buttonBox, SIGNAL(accepted()), SerialSet, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SerialSet, SLOT(reject()));

        QMetaObject::connectSlotsByName(SerialSet);
    } // setupUi

    void retranslateUi(QDialog *SerialSet)
    {
        SerialSet->setWindowTitle(QApplication::translate("SerialSet", "\344\270\262\345\217\243\350\256\276\347\275\256", 0));
        label->setText(QApplication::translate("SerialSet", "\346\225\260\346\215\256\344\275\215", 0));
        label_2->setText(QApplication::translate("SerialSet", "\345\201\234\346\255\242\344\275\215", 0));
        label_3->setText(QApplication::translate("SerialSet", "\345\245\207\345\201\266\346\240\241\351\252\214\344\275\215", 0));
        label_4->setText(QApplication::translate("SerialSet", "\344\270\262\345\217\243", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("SerialSet", "8", 0)
         << QApplication::translate("SerialSet", "7", 0)
         << QApplication::translate("SerialSet", "6", 0)
         << QApplication::translate("SerialSet", "5", 0)
        );
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("SerialSet", "1", 0)
         << QApplication::translate("SerialSet", "2", 0)
        );
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("SerialSet", "Even", 0)
         << QApplication::translate("SerialSet", "No", 0)
         << QApplication::translate("SerialSet", "Odd", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class SerialSet: public Ui_SerialSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALSET_H

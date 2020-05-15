/********************************************************************************
** Form generated from reading UI file 'timeset.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMESET_H
#define UI_TIMESET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimeSet
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QFormLayout *formLayout_5;
    QLabel *label_2;
    QFormLayout *formLayout_2;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QWidget *widget1;
    QFormLayout *formLayout_4;
    QLabel *label;
    QFormLayout *formLayout;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QWidget *widget2;
    QFormLayout *formLayout_6;
    QLabel *label_3;
    QFormLayout *formLayout_3;
    QLineEdit *lineEdit_3;
    QLabel *label_6;

    void setupUi(QDialog *TimeSet)
    {
        if (TimeSet->objectName().isEmpty())
            TimeSet->setObjectName(QStringLiteral("TimeSet"));
        TimeSet->resize(400, 300);
        TimeSet->setMinimumSize(QSize(400, 300));
        TimeSet->setMaximumSize(QSize(400, 300));
        buttonBox = new QDialogButtonBox(TimeSet);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(TimeSet);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(90, 100, 245, 24));
        formLayout_5 = new QFormLayout(widget);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        formLayout_5->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(84, 21));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_2);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMaximumSize(QSize(60, 16777215));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, lineEdit_2);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, label_5);


        formLayout_5->setLayout(0, QFormLayout::FieldRole, formLayout_2);

        widget1 = new QWidget(TimeSet);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(90, 50, 301, 24));
        formLayout_4 = new QFormLayout(widget1);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(84, 21));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        lineEdit = new QLineEdit(widget1);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaximumSize(QSize(60, 20));

        formLayout->setWidget(0, QFormLayout::LabelRole, lineEdit);

        label_4 = new QLabel(widget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_4);


        formLayout_4->setLayout(0, QFormLayout::FieldRole, formLayout);

        widget2 = new QWidget(TimeSet);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(90, 150, 251, 24));
        formLayout_6 = new QFormLayout(widget2);
        formLayout_6->setObjectName(QStringLiteral("formLayout_6"));
        formLayout_6->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(84, 21));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, label_3);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        lineEdit_3 = new QLineEdit(widget2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setMaximumSize(QSize(60, 16777215));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, lineEdit_3);

        label_6 = new QLabel(widget2);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, label_6);


        formLayout_6->setLayout(0, QFormLayout::FieldRole, formLayout_3);


        retranslateUi(TimeSet);
        QObject::connect(buttonBox, SIGNAL(accepted()), TimeSet, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TimeSet, SLOT(reject()));

        QMetaObject::connectSlotsByName(TimeSet);
    } // setupUi

    void retranslateUi(QDialog *TimeSet)
    {
        TimeSet->setWindowTitle(QApplication::translate("TimeSet", "Dialog", 0));
        label_2->setText(QApplication::translate("TimeSet", "\345\210\207\346\263\242\347\211\271\347\216\207\345\273\266\346\227\266\357\274\232", 0));
        label_5->setText(QApplication::translate("TimeSet", "ms", 0));
        label->setText(QApplication::translate("TimeSet", "\345\217\221\351\200\201\345\273\266\346\227\266\357\274\232", 0));
        label_4->setText(QApplication::translate("TimeSet", "ms", 0));
        label_3->setText(QApplication::translate("TimeSet", "\350\266\205\346\227\266\357\274\232", 0));
        label_6->setText(QApplication::translate("TimeSet", "ms", 0));
    } // retranslateUi

};

namespace Ui {
    class TimeSet: public Ui_TimeSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMESET_H

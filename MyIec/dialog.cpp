#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include "myiec.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    receiveData();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::receiveData()
{
    int i = 0;
    MyIec *ptr = (MyIec*)parentWidget();//获取父窗口的指针
    QString rec = ptr->rr;
    qDebug() <<"rrrr"<< rec.split(',').count() << rec.split(',').at(0);
    switch(rec.split(',').count())
    {
    case 4:
        ui->lineEdit_4->setText(rec.split(',').at(3));
    case 3:
        ui->lineEdit_3->setText(rec.split(',').at(2));
    case 2:
        ui->lineEdit_2->setText(rec.split(',').at(1));
    case 1:
        ui->lineEdit->setText(rec.split(',').at(0));
        break;
    default :
        break;
    }
}

void Dialog::on_lineEdit_textChanged(const QString &arg1)
{
    CRC_1 = 0;
    for(int i = 0;i < arg1.count();i++)
    {
        CRC_1 = CRC_1 + (arg1.at(i)).toLatin1();
        qDebug() << CRC_1;
    }
    CRC = CRC_1+CRC_2+CRC_3;
    qDebug() << "CRC: "<<CRC;
    ui->lineEdit_4->setText(QString::number(CRC,16).toUpper());
}

void Dialog::on_lineEdit_2_textChanged(const QString &arg1)
{
    CRC_2 = 0;
    for(int i = 0;i < arg1.count();i++)
    {
        CRC_2 = CRC_2 + (arg1.at(i)).toLatin1();
    }
    qDebug() << CRC_2;
    CRC = CRC_1+CRC_2+CRC_3;
    qDebug() << "CRC: "<<CRC;
    ui->lineEdit_4->setText(QString::number(CRC,16).toUpper());
}

void Dialog::on_lineEdit_3_textChanged(const QString &arg1)
{
    CRC_3 = 0;
    for(int i = 0;i < arg1.count();i++)
    {
        CRC_3 = CRC_3 + (arg1.at(i)).toLatin1();
    }
    qDebug() << CRC_3;
    CRC = CRC_1+CRC_2+CRC_3;
    qDebug() << "CRC: "<<CRC;
    ui->lineEdit_4->setText(QString::number(CRC,16).toUpper());
}

void Dialog::on_buttonBox_accepted()
{
    QString returnData = "";
    returnData = ui->lineEdit->text();
    returnData += ",";
    returnData += ui->lineEdit_2->text();
    returnData += ",";
    returnData += ui->lineEdit_3->text();
    returnData += ",";
    returnData += ui->lineEdit_4->text();
    emit sendData_3(returnData);
}

#include "timeset.h"
#include "ui_timeset.h"
#include "myiec.h"

TimeSet::TimeSet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimeSet)
{
    ui->setupUi(this);

    receiveData();

    ui->lineEdit->setText(QString::number(sendTimeVar.txDelay,10));
    ui->lineEdit_2->setText(QString::number(sendTimeVar.changeBaudDelay,10));
    ui->lineEdit_3->setText(QString::number(sendTimeVar.timeOutDelay,10));

}

TimeSet::~TimeSet()
{
    delete ui;
}

void TimeSet::receiveData()
{
    int i = 0;
    MyIec *ptr = (MyIec*)parentWidget();//获取父窗口的指针
    sendTimeVar.txDelay = ptr->myTimeVar.txDelay;
    sendTimeVar.changeBaudDelay = ptr->myTimeVar.changeBaudDelay;
    sendTimeVar.timeOutDelay = ptr->myTimeVar.timeOutDelay;
}

void TimeSet::on_buttonBox_accepted()
{
    sendTimeVar.txDelay = ui->lineEdit->text().toInt();
    sendTimeVar.changeBaudDelay = ui->lineEdit_2->text().toInt();
    sendTimeVar.timeOutDelay = ui->lineEdit_3->text().toInt();
    emit sendData_2(sendTimeVar);
}

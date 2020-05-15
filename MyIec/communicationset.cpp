#include "communicationset.h"
#include "ui_communicationset.h"
#include "myiec.h"
#include <QMessageBox>

CommunicationSet::CommunicationSet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CommunicationSet)
{
    ui->setupUi(this);
    receiverParentData();

}

CommunicationSet::~CommunicationSet()
{
    delete ui;
}

void CommunicationSet::receiverParentData()
{
    MyIec *ptr = (MyIec*)parentWidget();//获取父窗口的指针

    ui->comboBox_Baud->setCurrentIndex(ptr->ComInit_Var.baud);
    ui->comboBox_FrameWay->setCurrentIndex(ptr->ComInit_Var.FrameWay);
    ui->lineEdit_Password->setText(ptr->ComInit_Var.Password);
}

void CommunicationSet::on_buttonBox_accepted()
{
/*
    if(ui->lineEdit_Password->text().count() == 8){
        switch(QMessageBox::information(this,tr("提示"),tr("密码长度有误"),tr("OK"),tr("Cancel"),0,1)){
            case 0:
            case 1:
            default:
                break;
        }
    }
  */
    CommunicationVar SendComVar;
    SendComVar.baud = ui->comboBox_Baud->currentIndex();
    SendComVar.FrameWay = ui->comboBox_FrameWay->currentIndex();
    SendComVar.Password = ui->lineEdit_Password->text();
    emit sendData_1(SendComVar);

}

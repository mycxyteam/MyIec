#include "serialset.h"
#include "ui_serialset.h"
#include "myiec.h"

SerialSet::SerialSet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SerialSet)
{
    ui->setupUi(this);
    GetSerialPortName();
    receiverData();
//    Timer = new QTimer(this);
//    Timer->stop();
//    Timer->setInterval(5000);
//    connect(Timer,SIGNAL(timeout()),this,SLOT(On_Timer_TimeOut()));
//    Timer->start();
//    connect(ui->comboBox,SIGNAL(clicked()),this,SLOT(GetSerialPortName()));
}

SerialSet::~SerialSet()
{
    delete ui;
}

void SerialSet::On_Timer_TimeOut(void)
{
    GetSerialPortName();
}

void SerialSet::GetSerialPortName(void)
{
    int ComIndex = 0;
    int i = 0;
    QString commNumTemp = ui->comboBox->currentText();
//    if(ui->comboBox->is==false)
//        return;
    this->ui->comboBox->clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        this->ui->comboBox->addItem(info.portName());
        if(info.portName() == commNumTemp){
            ComIndex = i;
        }
        i++;
    }
    this->ui->comboBox->setCurrentIndex(ComIndex);
}

void SerialSet::on_buttonBox_accepted()
{
    SerialVar SendSerialVar;
    SendSerialVar.ComNum = ui->comboBox->currentText();
    SendSerialVar.DataNum = ui->comboBox_2->currentIndex();
    SendSerialVar.NumStop = ui->comboBox_3->currentIndex();
    SendSerialVar.ParityWay = ui->comboBox_4->currentIndex();
    emit sendData(SendSerialVar);
}

void SerialSet::receiverData()
{
    int i = 0;
    MyIec *ptr = (MyIec*)parentWidget();//获取父窗口的指针

    for(i=0;i<ui->comboBox->count();i++){
        if(ui->comboBox->itemText(i) == ptr->SerialInit_var.ComNum)
            break;
    }
    ui->comboBox->setCurrentIndex(i);
    ui->comboBox_2->setCurrentIndex(ptr->SerialInit_var.DataNum);
    ui->comboBox_3->setCurrentIndex(ptr->SerialInit_var.NumStop);
    ui->comboBox_4->setCurrentIndex(ptr->SerialInit_var.ParityWay);
}

void SerialSet::on_comboBox_clicked()
{
    GetSerialPortName();
}

void SerialSet::on_pushButton_clicked()
{
    OpenDocument op;
    QString suffix = "ini file(*.ini)";
    QString filePath = op.OpenDocumentsFun(this,suffix);

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

    int i;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        if(line.contains("DataBits")){
            QList<QByteArray> listline = line.split('=');

            for(i = 0; i<ui->comboBox_2->count();i++){
                ui->comboBox_2->setCurrentIndex(i);
                QString temp = " "+ui->comboBox_2->currentText()+'\n';

                if(listline[1] == temp.toLatin1())
                    break;
            }
            if(i >= ui->comboBox_2->count()){
                ui->comboBox_2->setCurrentIndex(0);
            }
        }else if(line.contains("Parity")){
            QList<QByteArray> listline = line.split('=');
            for(i = 0; i<ui->comboBox_4->count();i++){
                ui->comboBox_4->setCurrentIndex(i);
                QString temp = " "+ui->comboBox_4->currentText()+'\n';

                if(listline[1] == temp.toLatin1())
                    break;
            }
            if(i >= ui->comboBox_4->count()){
                ui->comboBox_4->setCurrentIndex(0);
            }
        }else if(line.contains("StopBits")){
            QList<QByteArray> listline = line.split('=');
            for(i = 0; i<ui->comboBox_3->count();i++){
                ui->comboBox_3->setCurrentIndex(i);
                QString temp = " "+ui->comboBox_3->currentText()+'\n';

                if(listline[1] == temp.toLatin1())
                    break;
            }
            if(i >= ui->comboBox_3->count()){
                ui->comboBox_3->setCurrentIndex(0);
            }
        }
    }
}

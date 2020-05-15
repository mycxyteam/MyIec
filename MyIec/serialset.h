#ifndef SERIALSET_H
#define SERIALSET_H

#include <QDialog>
#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QString>
#include <QTimer>
#include <QTimerEvent>
#include "newcombobox.h"

namespace Ui {
class SerialSet;
}

typedef struct
{
    QString ComNum;
    int DataNum;
    int ParityWay;
    int NumStop;
}SerialVar;

class SerialSet : public QDialog
{
    Q_OBJECT

public:
    explicit SerialSet(QWidget *parent = 0);
    ~SerialSet();

    void GetSerialPortName(void);


private slots:

    void on_buttonBox_accepted();

    void On_Timer_TimeOut();//定时器溢出函数

    void on_comboBox_clicked();//新建类NewComboBox添加点击事件

    void receiverData();

    void on_pushButton_clicked();

signals:
    void sendData(SerialVar);

private:
    Ui::SerialSet *ui;
//    QTimer *Timer; //定义一个定时器
};

#endif // COMSET_H

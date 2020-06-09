#ifndef MYIEC_H
#define MYIEC_H

#include <QMainWindow>
#include "serialset.h"
#include "communicationset.h"
#include <QMessageBox>
#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "opendocument.h"
#include "timeset.h"
#include "dialog.h"
#include <QTextBrowser>
#include <mutex>
#include "processiec.h"

#define myRead 0
#define myWrite 1
#define timeOut 0x01//超时
#define cirExecution 0x02//循环


namespace Ui {
class MyIec;
}

class MyIec : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyIec(QWidget *parent = 0);
    ~MyIec();

    SerialVar SerialInit_var;
    CommunicationVar ComInit_Var;
    QString rr;

    void InitDisplay();
    void InitRamData();
    bool OpenSerial();
    void init_100ms_timer();
    void InitTextBrowser();

    bool eventFilter(QObject *, QEvent *);
    void keyPressEvent(QKeyEvent *e);
    void mousePressEvent(QMouseEvent *);

    void plainText(QTextBrowser *myTextBrowser,QString str,const QColor & c);
    void startSerialCom(int ReadOrWrite);
    int processReceiveInfo(QByteArray Allinfo);

 //   bool textFalg = false;
    std::mutex mtx;
    TimeVar myTimeVar;

private slots:

    void on_actionA_triggered();

    void on_comboBox_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_actionB_triggered();

    void on_comboBox_Baud_currentIndexChanged(int index);

    void on_lineEdit_Password_textChanged(const QString &arg1);

    void receiverData(SerialVar data);
    void receiverData_1(CommunicationVar data);
    void receiverData_2(TimeVar data);
    void receiverData_3(QString data);
    void GetSerialPortName(void);
    void on_pushButton_OpenOrCloseSerial_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_actionQ_triggered();

    void on_pushButton_clear_clicked();

    void on_pushButton_clear2_clicked();

    void on_actionC_triggered();

    void my_100ms_timer_timeout();

    void on_lineEdit_2_textChanged(const QString &arg1);
    void inputLine_textChanged();

    void mReceiveIecInfo();

    void on_pushButton_3_clicked();

    void on_radioButton_clicked();

    void on_actionRF_triggered();

signals:

private:
    Ui::MyIec *ui;
    SerialSet *dialog;
    CommunicationSet *dialog_1;
    TimeSet *dialog_2;
    Dialog *dialog_3;
    QSerialPort *myserial;

    QTimer *fTimer;//定义定时器

    QTextBrowser *inputLine;

    ProcessIec *proIec;

    int mReadOrWrite;
    QString FrameWayStr;
    QString ComStageName;
    int timeFlag = 0;
    int cirExecutionTime;
    int timeOutTime;

};

#endif // MYIEC_H

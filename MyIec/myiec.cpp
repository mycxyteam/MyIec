#include "myiec.h"
#include "ui_myiec.h"

#include "QFileDialog"
#include "QInputDialog"

#define Red QColor(255,0,0,127)
#define Green QColor(34, 139, 34, 127)

MyIec::MyIec(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyIec)
{
    ui->setupUi(this);

    QFile file("../myiec.qss");
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    this->setStyleSheet(stylesheet);
    file.close();

    GetSerialPortName();
    InitRamData();
    InitDisplay();
    InitTextBrowser();
    init_100ms_timer();//开启100ms定时器

    myTimeVar.changeBaudDelay = 300;
    myTimeVar.txDelay = 100;
    myTimeVar.timeOutDelay = 3000;

    proIec = new ProcessIec();//新建一个Iec处理函数类指针
    myserial = new QSerialPort(this);

    inputLine = new QTextBrowser(this);
    inputLine->resize(200,50);
    inputLine->setReadOnly(false);
    inputLine->hide();
    connect(inputLine,SIGNAL(textChanged()),this,SLOT(inputLine_textChanged()));
    connect(myserial,SIGNAL(readyRead()),this,SLOT(mReceiveIecInfo()));

    ui->lineEdit->installEventFilter(this);
    ui->lineEdit_2->installEventFilter(this);//控件注册近事件过滤器中
    ui->lineEdit_4->installEventFilter(this);
    inputLine->installEventFilter(this);
//    ui->radioButton->installEventFilter(this);
//    ui->radioButton_2->installEventFilter(this);

//    ui->radioButton->setHidden(0);
//    inputLine->setFocusPolicy(Qt::StrongFocus);
//    ui->lineEdit_2->setFocusPolicy(Qt::StrongFocus);

    ui->progressBar->setRange(0,5000-1);
    ui->progressBar->setValue(0);
    ui->progressBar->setFormat("");
    ui->progressBar->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
//    QString qq = ui->progressBar->format();
//    qDebug()<< qq;
//    ui->action22->setShortcut(QKeySequence::Copy);
//    ui->action22->setShortcut(tr("Ctrl+C"));
//      ui->action1->ActionEvent(Triggered)
//    connect(ui->action1,SIGNAL(triggered()),this,SLOT(ComSetDisplay()));

//    ui->textBrowser->insertPlainText("wwww\n");

//    ui->textBrowser_2->insertPlainText("wwww\n");

}

MyIec::~MyIec()
{
    delete ui;
}

//接收单片机的数据
int MyIec::processReceiveInfo(QByteArray Allinfo)
{
    int flag = 0;

    //打印数据
//    textCursor=ui->textBrowser->textCursor();//得到当前的光标
//    textCursor.movePosition(QTextCursor::End);
//    textCursor.insertText(current_date+"   -->>"+Allinfo+'\n');

    //打开文件操作   /////////////////////////////////////////////////////////////////////////
//    QFile file("DEBUGLOG.txt");
//    QString StringFile = current_date+"   -->>"+Allinfo+'\n';
//    file.open(QIODevice::Append |QIODevice::Text);
//    QByteArray ByteArrayFile = StringFile.toUtf8();
//    file.write(ByteArrayFile);
//    file.close();

//    textCursor.insertText(current_date+"   -->>"+hexData+'\n');
    QByteArray recinfo;
    int recinfolen = 0;
    if(mReadOrWrite == myRead){
        for(int i = 0;i<Allinfo.count();i++){
            if(Allinfo[i] == 0x28){
                flag = 1;
            }
            if(Allinfo[i] == 0x29){
                flag = 0;
            }
            if(flag == 1 && Allinfo[i] != 0x28){
                recinfo[recinfolen++] = Allinfo[i];
            }
        }
        plainText(ui->textBrowser_3,recinfo,Green);
        plainText(ui->textBrowser_3,"\n",Green);
    }else{
        for(int i = 0;i<Allinfo.count();i++){
            if(Allinfo[i] == 0x06){
                QByteArray re_data;
                re_data[0] = 0x4F;
                re_data[1] = 0x4B;
                plainText(ui->textBrowser_3,re_data,Green);
                plainText(ui->textBrowser_3,"\n",Green);
                break;
            }
        }
    }
    return 1;
}

void MyIec::mReceiveIecInfo()
{
    QByteArray info = myserial->readAll();
    if(info.isEmpty())return ;
    static int Fg_info = 0;
    static bool IsAllinfo = false;
    static QByteArray Allinfo;
    int i;
    for(i=0;i<info.count();i++){
       if(info[i] == 0x2F){
           Fg_info = 1;
           break;
       }
        if(info[i] == 0x01){
           Fg_info = 2;
           break;
       }
       if(info[i] == 0x06){
           Fg_info = 3;
           IsAllinfo = 1;
           break;
       }
       if(info[i] == 0x15){
           Fg_info = 4;
           IsAllinfo = 1;
           break;
       }
       if(info[i] == 0x02){//STX
           Fg_info = 5;
           break;
       }
    }
    if(Fg_info == 1){
        for(i=0;i<info.count();i++){
            if(info[i] == 0x0A){
                IsAllinfo = 1;
                break;
            }
        }
    }
    if(Fg_info == 2){
        for(i=0;i<info.count();i++){
            if(info[i] == 0x03 || info[i] == 0x06){
                IsAllinfo = 1;
                break;
            }
        }
    }
    if(Fg_info == 5){
        for(i=0;i<info.count();i++){
            if(info[i] == 0x03 || info[i] == 0x06){
                IsAllinfo = 1;
                break;
            }
        }
    }

    Allinfo.append(info);


    if(IsAllinfo == 0 || Fg_info == 0)//是否接受完整
    {
        return ;
    }
    IsAllinfo = 0;
    Fg_info = 0;

    timeOutTime = myTimeVar.timeOutDelay;

    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz");

    QByteArray tempArray;
    for(int i=0;i<Allinfo.count();i++){
        if(Allinfo[i] != '\n' && Allinfo[i] != '\r'){
            tempArray[i] = Allinfo[i];
        }
    }
    //接受数据显示
    plainText(ui->textBrowser,current_date,Green);
    plainText(ui->textBrowser," ==> ",Green);
    plainText(ui->textBrowser_2,current_date,Green);
    plainText(ui->textBrowser_2," ==> ",Green);

    plainText(ui->textBrowser,tempArray,Green);
    plainText(ui->textBrowser,"\n",Green);
    //为了hex显示效果做空格处理
    QByteArray p = Allinfo.toHex().toUpper();
    QByteArray p1;
    int j = 0;
    for(int i = 0;i < p.count();){
        p1[j++] = p[i++];
        p1[j++] = p[i++];
        p1[j++] = 0x7F;
    }
    plainText(ui->textBrowser_2,p1,Green);
    plainText(ui->textBrowser_2,"\n",Green);

    QString dateName =current_date_time.toString("yyyy.MM.dd");
    //打开文件操作   /////////////////////////////////////////////////////////////////////////
    QFile file(dateName+".txt");
    QString StringFile = current_date+" ==> "+p1+" | "+tempArray+'\n';
    file.open(QIODevice::Append |QIODevice::Text);
    QByteArray ByteArrayFile = StringFile.toUtf8();
    file.write(ByteArrayFile);
    file.close();

    //打开文件操作   /////////////////////////////////////////////////////////////////////////
//    QFile file("DEBUGLOG.txt");
//    QString StringFile = current_date+"   -->>"+Allinfo+'\n';
//    file.open(QIODevice::Append |QIODevice::Text);
//    QByteArray ByteArrayFile = StringFile.toUtf8();
//    file.write(ByteArrayFile);
//    file.close();

//    QTextCursor textCursor;
    bool baud_flag = false;
    QString z;
    QByteArray TxQbyteArry;
    QString sendDataIdStr = ui->lineEdit_4->text();//获取id框选中的数据
    bool isWriteData = ui->radioButton->isChecked();
    QString sendDataStr = ui->lineEdit_2->text();
    for(i=0;i<Allinfo.count();i++){
        if(Allinfo[i] != 0x7F){
            if(Allinfo[i] == 0x2F){
                //握手返回帧，发送波特率切换帧
                z = Allinfo[i+4];
//                TxQbyteArry = GetTxString(z,1);
                TxQbyteArry = proIec->getTxString(FrameWayStr,z,mReadOrWrite,1,isWriteData,sendDataStr);
                baud_flag = true;
                ComStageName = "IEC_COMM_ACKNOWLEDGEMENT";
                break;
            }
            if(Allinfo[i] == 0x01){
                if(ComStageName == "IEC_COMM_ACKNOWLEDGEMENT"){
                    //密码认证
    //                QString possword = "00000000";
                    QString possword = ui->lineEdit_Password->text();
                    TxQbyteArry = proIec->getTxString(FrameWayStr,possword,mReadOrWrite,2,isWriteData,sendDataStr);
                    ComStageName = "IEC_COMM_COMMAND_P";//指令命令  密码认证
                    break;
                }else{
                    //抄读数据返回
//                    processReceiveInfo(Allinfo);
                }
            }
            if(Allinfo[i] == 0x02){
                processReceiveInfo(Allinfo);
                TxQbyteArry.clear();
                ComStageName = "IEC_COMM_COMMAND_B";//指令命令结束
                //进度条
                ui->progressBar->setMaximum(0);
                ui->progressBar->setMinimum(1);

                timeFlag &= ~timeOut;

                TxQbyteArry[0] = 0x7F;
                TxQbyteArry[1] = 0x01;
                TxQbyteArry[2] = 0x42;
                TxQbyteArry[3] = 0x30;
                TxQbyteArry[4] = 0x03;
                int i=0;
                bool flag = 0;
                TxQbyteArry[5] = 0;
                for(i=0;i<5;i++)
                {
                    if((TxQbyteArry)[i] == 0x01)
                    {
                        flag = 1;
                    }
                    if((TxQbyteArry)[i] == 0x03)
                    {
                        flag = 0;
                    }
                    if(flag ==1)
                    {
                        (TxQbyteArry)[5] = (TxQbyteArry)[5]^(TxQbyteArry)[i+1];
                    }
                }
                break;
            }
            if(Allinfo[i] == 0x06){
                if(ComStageName == "IEC_COMM_COMMAND_P"){
                    //准备发送请求命令帧
                    TxQbyteArry = proIec->getTxString(FrameWayStr,sendDataIdStr,mReadOrWrite,3,isWriteData,sendDataStr);
                    ComStageName = "IEC_COMM_COMMAND";//指令命令
                }else if(ComStageName == "IEC_COMM_COMMAND"){
                    ComStageName = "IEC_COMM_COMMAND_B";//指令命令结束
                    //进度条
                    ui->progressBar->setMaximum(0);
                    ui->progressBar->setMinimum(1);

                    timeFlag &= ~timeOut;

                    processReceiveInfo(Allinfo);
                    TxQbyteArry[0] = 0x7F;
                    TxQbyteArry[1] = 0x01;
                    TxQbyteArry[2] = 0x42;
                    TxQbyteArry[3] = 0x30;
                    TxQbyteArry[4] = 0x03;
                    int i=0;
                    bool flag = 0;
                    TxQbyteArry[5] = 0;
                    for(i=0;i<5;i++)
                    {
                        if((TxQbyteArry)[i] == 0x01)
                        {
                            flag = 1;
                        }
                        if((TxQbyteArry)[i] == 0x03)
                        {
                            flag = 0;
                        }
                        if(flag ==1)
                        {
                            (TxQbyteArry)[5] = (TxQbyteArry)[5]^(TxQbyteArry)[i+1];
                        }
                    }

                }else if(ComStageName == "IEC_COMM_COMMAND_B"){
                    Allinfo.clear();
                    return;
                }
                break;
            }
            if(Allinfo[i] == 0x15){
                if(ComStageName == "IEC_COMM_COMMAND_P"){
                    plainText(ui->textBrowser_3,"密码认证错误\n",Red);
                }else if(ComStageName == "IEC_COMM_COMMAND"){
                    plainText(ui->textBrowser_3,"输入数据或ID错误\n",Red);
                }

                timeFlag &= ~timeOut;
                Allinfo.clear();
                //进度条
                ui->progressBar->setMaximum(0);
                ui->progressBar->setMinimum(1);
                return ;
            }
        }
    }
    Allinfo.clear();
    int delay = myTimeVar.txDelay;
    QThread::msleep(delay);

    current_date_time =QDateTime::currentDateTime();
    current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz");

    tempArray.clear();
    for(int i=0;i<TxQbyteArry.count();i++){
        if(TxQbyteArry[i] != '\n' && TxQbyteArry[i] != '\r'){
            tempArray[i] = TxQbyteArry[i];
        }
    }
    //显示
    plainText(ui->textBrowser,current_date,Red);
    plainText(ui->textBrowser," <== ",Red);
    plainText(ui->textBrowser,tempArray,Red);
    plainText(ui->textBrowser,"\n",Red);

    plainText(ui->textBrowser_2,current_date,Red);
    plainText(ui->textBrowser_2," <== ",Red);
    //为了hex显示效果做空格处理
    p.clear();
    p1.clear();
    p = TxQbyteArry.toHex().toUpper();
    j = 0;
    for(int i = 0;i < p.count();){
        p1[j++] = p[i++];
        p1[j++] = p[i++];
        p1[j++] = 0x7F;
    }
    plainText(ui->textBrowser_2,p1,Red);
    plainText(ui->textBrowser_2,"\n",Red);

    QString dateName_1 =current_date_time.toString("yyyy.MM.dd");
    //打开文件操作   /////////////////////////////////////////////////////////////////////////
    QFile file_1(dateName_1+".txt");
    QString StringFile_1 = current_date+" <== "+p1+" | "+tempArray+'\n';
    file_1.open(QIODevice::Append |QIODevice::Text);
    QByteArray ByteArrayFile_1 = StringFile_1.toUtf8();
    file_1.write(ByteArrayFile_1);
    file_1.close();


    myserial->write(TxQbyteArry);
    myserial->waitForBytesWritten(1000);

    if((baud_flag)&& !(ui->radioButton_2->isChecked()))
    {
        baud_flag = false;
        delay = myTimeVar.changeBaudDelay;
        QThread::msleep(delay);
        switch(z.toInt())
        {
            case 1:
                myserial->setBaudRate(600);
                break;
            case 2:
                myserial->setBaudRate(1200);
                break;
            case 3:
                myserial->setBaudRate(2400);
                break;
            case 4:
                myserial->setBaudRate(4800);
                break;
            case 5:
                myserial->setBaudRate(9600);
                break;
            case 6:
                myserial->setBaudRate(19200);
                break;
            default:
                myserial->setBaudRate(300);
                break;
        }

    }
    return ;
}
void MyIec::plainText(QTextBrowser *myTextBrowser,QString str,const QColor & c)
{
//    ui->textBrowser->setTextColor(QColor(255, 0, 0, 127));//red
    myTextBrowser->moveCursor(QTextCursor::End);
    myTextBrowser->setTextColor(c);
    myTextBrowser->insertPlainText(str);
//    ui->textBrowser->setTextColor(c);
//    ui->textBrowser->insertPlainText(str);
//    ui->textBrowser->setTextColor(Green));//
//    ui->textBrowser->insertPlainText("wwww\n");
}

void MyIec::mousePressEvent(QMouseEvent *e)
{
    QWidget *TemWidget = focusWidget();//获取当前控件
//    qDebug()<<TemWidget<<" "<<inputLine;
    inputLine->hide();
}
void MyIec::keyPressEvent(QKeyEvent *e)
{
//    qDebug()<<e->key()<<" "<<Qt::Key_Enter;
    QWidget *TemWidget = focusWidget();//获取当前控件
//    qDebug()<<TemWidget<<" "<<inputLine;
//    QString inputString;
    if(TemWidget == inputLine){
        switch(e->key())
        {
        case Qt::Key_Enter:
        case Qt::Key_Return:
            inputLine->hide();
//            inputString = inputLine->toPlainText();
//            ui->lineEdit_2->setText(inputString);
            ui->lineEdit_2->setFocus();
            break;
        default:
            break;
        }
    }
}

bool MyIec::eventFilter(QObject *o, QEvent *e)
{
    //控件点击事件
    if((e->type()==QEvent::MouseButtonPress)&&(o == ui->lineEdit_2))
    {
        if(inputLine->isHidden()){
            QWidget *TemWidget = focusWidget();//获取当前控件
            if(!TemWidget)
                return false;
            QRect widgetRect = TemWidget->rect();
//          qDebug()<< widgetRect.bottom() << "  "<<widgetRect.left();
            widgetRect.setBottom(55);//进行位置微调  19 -> 55
            QPoint panelpos = QPoint(widgetRect.left(),widgetRect.bottom());
            panelpos = TemWidget->mapToParent(panelpos);

            inputLine->move(panelpos);
            inputLine->show();

            inputLine->setFocus();
            return true;
        }else{
            ui->lineEdit_2->setFocus();
            return false;
        }
    }else if((e->type()==QEvent::MouseButtonPress)&&((o == ui->lineEdit)||(o == ui->lineEdit_4))){
//        qDebug()<<"111";
        inputLine->hide();
        return false;
    }else if((e->type()==QEvent::KeyPress)&&(o == inputLine)){
//        qDebug()<<e->type();
        QKeyEvent *key_e = static_cast<QKeyEvent *>(e);
        qDebug()<<key_e->key() << Qt::Key_Enter << Qt::Key_Return << Qt::Key_Space;
        if(key_e->key()==Qt::Key_Enter||key_e->key()==Qt::Key_Return||key_e->key()==Qt::Key_Space)
        {
            return QWidget::event(e);
        }else{
            return false;
        }
    }else if((e->type()==QEvent::KeyPress)&&((o == ui->lineEdit)||(o == ui->lineEdit_2)||(o == ui->lineEdit_4))){
    //        qDebug()<<e->type();
        QKeyEvent *key_e = static_cast<QKeyEvent *>(e);
        qDebug()<<key_e->key() << Qt::Key_Enter << Qt::Key_Return << Qt::Key_Space;
        if(key_e->key()==Qt::Key_Enter||key_e->key()==Qt::Key_Return||key_e->key()==Qt::Key_Space)
        {
            return QWidget::event(e);
        }else{
            return false;
        }
    }else if(o == ui->radioButton || o == ui->radioButton_2){
        qDebug()<<e->type();
        return true;
    }else
        return false;
}

void MyIec::init_100ms_timer(void)
{
    fTimer = new QTimer(this);
    fTimer->stop();
    fTimer->setInterval(100);
    connect(fTimer,SIGNAL(timeout()),this,SLOT(my_100ms_timer_timeout()));
    fTimer->start();
}
void MyIec::my_100ms_timer_timeout()
{
    //100ms定时执行函数
    //ui->textBrowser->insertPlainText("wwww\n");
    if(timeFlag&cirExecution){
        //执行循环抄读
        if(cirExecutionTime <= 0){
            cirExecutionTime = 1000*(ui->lineEdit_3->text().toInt());
            on_pushButton_clicked();
        }else{
            cirExecutionTime -= 100;
        }
    }
    if(timeFlag&timeOut){
        //超时机制
        if(timeOutTime <= 0){
            timeFlag &= ~timeOut;
            //进度条
            ui->progressBar->setMaximum(0);
            ui->progressBar->setMinimum(1);

            plainText(ui->textBrowser_3,"No Response\n",Red);
        }else{
            timeOutTime -= 100;
        }
    }
}
void MyIec::InitTextBrowser()
{
    QFont font;
    font.setPointSize(14);//文字大小设为12
    font.setBold(true);//文字设为粗体
    ui->textBrowser->setFont(font);
    ui->textBrowser_2->setFont(font);
    ui->textBrowser_3->setFont(font);
    ui->textBrowser->setReadOnly(false);//修改权限
    ui->textBrowser_2->setReadOnly(false);
    ui->textBrowser_3->setReadOnly(false);

    ui->tabWidget->setCurrentIndex(0);

    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->comboBox->setEnabled(true);
    ui->comboBox_Baud->setEnabled(true);

    ui->lineEdit_3->setText("10");
}
void MyIec::InitDisplay()
{
    ui->comboBox_Baud->setCurrentIndex(ComInit_Var.baud);
    ui->lineEdit_Password->setText(ComInit_Var.Password);
    ui->lineEdit_Password->setEnabled(false);
    ui->pushButton_OpenOrCloseSerial->setText("打开串口");
}
void MyIec::InitRamData()
{
    //默认串口参数
    SerialInit_var.ComNum = ui->comboBox->currentText();
    SerialInit_var.DataNum = 1;//"Data7";
    SerialInit_var.NumStop = 0;//"OneStop";
    SerialInit_var.ParityWay = 0;//"EvenParity";
    //通讯参数默认
    ComInit_Var.baud = 0; //"300"
    ComInit_Var.FrameWay = 0;//"完整通讯协议";
    ComInit_Var.Password = "00000000";
}

void MyIec::GetSerialPortName(void)
{
    int ComIndex = 0;
    int i = 0;
    QString commNumTemp = ui->comboBox->currentText();

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

void MyIec::receiverData(SerialVar data)
{
    int commIndex = 0;
    int i = 0;
    this->ui->comboBox->clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        this->ui->comboBox->addItem(info.portName());
        if(data.ComNum == info.portName()){
            commIndex = i;
        }
        i++;
    }
    ui->comboBox->setCurrentIndex(commIndex);
    //刷新串口方面的信息
    SerialInit_var.ComNum = data.ComNum;
    SerialInit_var.DataNum = data.DataNum;
    SerialInit_var.NumStop = data.NumStop;
    SerialInit_var.ParityWay = data.ParityWay;
}

void MyIec::receiverData_1(CommunicationVar data)
{
    ComInit_Var.baud = data.baud;
    ComInit_Var.FrameWay = data.FrameWay;
    ComInit_Var.Password = data.Password;

    ui->comboBox_Baud->setCurrentIndex(ComInit_Var.baud);
    ui->lineEdit_Password->setText(ComInit_Var.Password);
}
void MyIec::receiverData_2(TimeVar data)
{
    myTimeVar.txDelay = data.txDelay;
    myTimeVar.timeOutDelay = data.timeOutDelay;
    myTimeVar.changeBaudDelay = data.changeBaudDelay;

}


void MyIec::on_actionA_triggered()
{
    //显示串口设置界面
    dialog = new SerialSet(this);
    dialog->setModal(false);
    connect(dialog,SIGNAL(sendData(SerialVar)),this,SLOT(receiverData(SerialVar)));
//    connect(dialog,SIGNAL(sendData(QString)),this,SLOT(receiveData(QString)));
//    connect(dialog,SIGNAL(sendData_1(QString)),this,SLOT(receiveData_1(QString)));
    dialog->show();
}
void MyIec::on_actionB_triggered()
{
    //显示通讯设置界面
    dialog_1 = new CommunicationSet(this);
    dialog_1->setModal(false);

    connect(dialog_1,SIGNAL(sendData_1(CommunicationVar)),this,SLOT(receiverData_1(CommunicationVar)));
    dialog_1->show();
}
void MyIec::on_actionC_triggered()
{
  dialog_2 = new TimeSet(this);
  dialog_2->setModal(false);

  connect(dialog_2,SIGNAL(sendData_2(TimeVar)),this,SLOT(receiverData_2(TimeVar)));
  dialog_2->show();

}

void MyIec::on_comboBox_clicked()
{//串口下拉
    int commIndex = 0;
    int i = 0;
    QString commNumTemp = ui->comboBox->currentText();
    this->ui->comboBox->clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        this->ui->comboBox->addItem(info.portName());
        if(commNumTemp == info.portName()){
            commIndex = i;
        }
        i++;
    }
    ui->comboBox->setCurrentIndex(commIndex);

    SerialInit_var.ComNum = ui->comboBox->currentText();//刷新串口信息
}

void MyIec::on_comboBox_currentIndexChanged(const QString &arg1)
{
    SerialInit_var.ComNum = arg1;//ui->comboBox->currentText();//刷新串口信息
}

void MyIec::on_comboBox_Baud_currentIndexChanged(int index)
{
    ComInit_Var.baud = index;//刷新串口波特率
}

void MyIec::on_lineEdit_Password_textChanged(const QString &arg1)
{
    ComInit_Var.Password = arg1;//刷新密码
}

void MyIec::on_pushButton_OpenOrCloseSerial_clicked()
{
    if(ui->pushButton_OpenOrCloseSerial->text() == "打开串口"){
        if(OpenSerial() == true){
            ui->pushButton_OpenOrCloseSerial->setText("关闭串口");

            ui->pushButton->setEnabled(true);
            ui->pushButton_2->setEnabled(true);
            ui->pushButton_3->setEnabled(true);
            ui->comboBox->setEnabled(false);
            ui->comboBox_Baud->setEnabled(false);
        }
    }else{
        ui->pushButton_OpenOrCloseSerial->setText("打开串口");

        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->comboBox->setEnabled(true);
        ui->comboBox_Baud->setEnabled(true);

        myserial->close();
//        delete myserial;
    }

    inputLine->hide();
}

bool MyIec::OpenSerial()
{
    //设置串口名
    myserial->setPortName(ui->comboBox->currentText());
//    serial.open(QIODevice::ReadWrite);
    //设置波特率
    myserial->setBaudRate(ui->comboBox_Baud->currentText().toInt());
    //设置数据位数
    switch(SerialInit_var.DataNum){
        case 1:
            myserial->setDataBits(QSerialPort::Data7);
            break;
        case 2:
            myserial->setDataBits(QSerialPort::Data6);
            break;
        case 3:
            myserial->setDataBits(QSerialPort::Data5);
            break;
        default:
            myserial->setDataBits(QSerialPort::Data8);
            break;
    }
    //设置奇偶校验
    switch(SerialInit_var.ParityWay){
        case 2:
            myserial->setParity(QSerialPort::OddParity);
            break;
        case 1:
            myserial->setParity(QSerialPort::NoParity);
            break;
        default :
            myserial->setParity(QSerialPort::EvenParity);
            break;
    }
    //设置停止位
    myserial->setStopBits(QSerialPort::OneStop);
    //设置流控制
    myserial->setFlowControl(QSerialPort::NoFlowControl);
    //打开串口
    if(!myserial->open(QIODevice::ReadWrite))
    {
        QMessageBox::about(NULL, "提示", "无法打开串口！");
        return false;
    }

    return true;
}

void MyIec::startSerialCom(int ReadOrWrite)
{
    QString sendDataIdStr = ui->lineEdit_4->text();//获取id框选中的数据
    QString meterIDStr = ui->lineEdit->text();//获取表号
    bool isWriteData = ui->radioButton->isChecked();
    QString sendDataStr = ui->lineEdit_2->text();

    QByteArray TxQbyteArry;
//    Allinfo.clear();
    switch(ComInit_Var.FrameWay){
    case 0:
        FrameWayStr = "完整通讯协议";
        break;
    case 1:
        FrameWayStr = "单帧通讯协议";
        break;
    default:
        break;
    }

    //设置波特率
    myserial->setBaudRate(ui->comboBox_Baud->currentText().toInt());

    if(FrameWayStr == "完整通讯协议"){
        ComStageName = "IEC_COMM_REQUEST";//请求命令
        TxQbyteArry = proIec->getTxString(FrameWayStr,meterIDStr,ReadOrWrite,0,isWriteData,sendDataStr);
    }else{
        ComStageName = "IEC_COMM_COMMAND";//指令命令
        TxQbyteArry = proIec->getTxString(FrameWayStr,sendDataIdStr,ReadOrWrite,3,isWriteData,sendDataStr);
    }

    QByteArray tempArray;
    for(int i=0;i<TxQbyteArry.count();i++){
        if(TxQbyteArry[i] != '\n' && TxQbyteArry[i] != '\r'){
            tempArray[i] = TxQbyteArry[i];
        }
    }
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz");
//显示
    plainText(ui->textBrowser,current_date,Red);
    plainText(ui->textBrowser," <== ",Red);
    plainText(ui->textBrowser,tempArray,Red);
    plainText(ui->textBrowser,"\n",Red);

    plainText(ui->textBrowser_2,current_date,Red);
    plainText(ui->textBrowser_2," <== ",Red);

    //为了hex显示效果做空格处理
    QByteArray p = TxQbyteArry.toHex().toUpper();
    QByteArray p1;
    int j = 0;
    for(int i = 0;i < p.count();){
        p1[j++] = p[i++];
        p1[j++] = p[i++];
        p1[j++] = 0x7F;
    }
    plainText(ui->textBrowser_2,p1,Red);
    plainText(ui->textBrowser_2,"\n",Red);

    QString dateName =current_date_time.toString("yyyy.MM.dd");
    //打开文件操作   /////////////////////////////////////////////////////////////////////////
    QFile file(dateName+".txt");
    QString StringFile = current_date+" <== "+p1+" | "+tempArray+'\n';
    file.open(QIODevice::Append |QIODevice::Text);
    QByteArray ByteArrayFile = StringFile.toUtf8();
    file.write(ByteArrayFile);
    file.close();

    myserial->write(TxQbyteArry);//串口发送数据
    return;
}

void MyIec::on_pushButton_clicked() //read
{
    inputLine->hide();
    mReadOrWrite = myRead;

    timeFlag |= timeOut;
    timeOutTime = myTimeVar.timeOutDelay;

    startSerialCom(myRead);
    ui->progressBar->setMaximum(0);
    ui->progressBar->setMinimum(0);

}

void MyIec::on_pushButton_2_clicked()//write
{
    inputLine->hide();
    mReadOrWrite = myWrite;

    timeFlag |= timeOut;
    timeOutTime = myTimeVar.timeOutDelay;

    startSerialCom(myWrite);
    ui->progressBar->setMaximum(0);
    ui->progressBar->setMinimum(0);
}

void MyIec::on_actionQ_triggered()//打开日志
{
    OpenDocument op;
    QString suffix = "txt file(*.txt);;All files(*.*)";
    op.OpenDocumentsFun(this,suffix);

    inputLine->hide();
}

void MyIec::on_pushButton_clear_clicked()//清除数据通讯过程
{
    QTextCursor textCursor;

    textCursor=ui->textBrowser->textCursor();
    textCursor.select(QTextCursor::Document);
    textCursor.removeSelectedText();

    textCursor=ui->textBrowser_2->textCursor();
    textCursor.select(QTextCursor::Document);
    textCursor.removeSelectedText();

    inputLine->hide();
}

void MyIec::on_pushButton_clear2_clicked()//清除解析数据
{
    QTextCursor textCursor;

    textCursor=ui->textBrowser_3->textCursor();
    textCursor.select(QTextCursor::Document);
    textCursor.removeSelectedText();

    inputLine->hide();
}


void MyIec::on_lineEdit_2_textChanged(const QString &arg1)
{
    //断开信号槽，避免在清除操作产生信号反应
    disconnect(inputLine,SIGNAL(textChanged()),this,SLOT(inputLine_textChanged()));
    QTextCursor textCursor = inputLine->textCursor();
    int pos = textCursor.anchor();
    textCursor.select(QTextCursor::Document);
    textCursor.removeSelectedText();
    textCursor.insertText(arg1);
    //移动输入光标，保持原位置
    inputLine->moveCursor(QTextCursor::Start,QTextCursor::MoveAnchor);
    for(int i=0;i<pos;i++)
        inputLine->moveCursor(QTextCursor::Right,QTextCursor::MoveAnchor);

    connect(inputLine,SIGNAL(textChanged()),this,SLOT(inputLine_textChanged()));
}
void MyIec::inputLine_textChanged()
{
    QString inputString = inputLine->toPlainText();
    ui->lineEdit_2->setText(inputString);
}

void MyIec::on_pushButton_3_clicked()
{
    if(ui->pushButton_3->text() == "执行"){
        ui->pushButton_3->setText("停止");
        timeFlag |= cirExecution;
        on_pushButton_clicked();
        cirExecutionTime = 1000*(ui->lineEdit_3->text().toInt());
    }else{
        ui->pushButton_3->setText("执行");
        timeFlag &= ~cirExecution;
        ui->progressBar->setMaximum(0);
        ui->progressBar->setMinimum(1);
    }
}

void MyIec::on_radioButton_clicked()
{
}

#include "processiec.h"
#include <QDateTime>
#include <QTextCursor>
#include <myiec.h>
ProcessIec::ProcessIec()
{
}

int ProcessIec::convertStringToHex(const QString &str, QByteArray &byteData)
{
    int hexdata = 0;
    int hexdatalen = 0;
    int len = str.length();
    int i = 0;
    (byteData).resize(len);
    char hstr = 0;
    for(i=0; i<len; )
    {
        hstr=str[i].toLatin1();
        if(hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        hexdata = convertCharToHex(hstr);
        (byteData)[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }

    return len;
}


char ProcessIec::convertCharToHex(char ch)
{

    if((ch >= '0') && (ch <= '9'))
         return ch;//-0x30;

     else return ch;
}

QByteArray ProcessIec::getTxString(QString ComModel,QString str,int ReadOrWrite,int fg,bool isWriteData,QString write_data)
{
    QByteArray byteData;
    QByteArray byteDataTemp;
//    QTextCursor textCursor;
    int byteDataLen = 0;
    int i = 0;int flag = 0;
    int byteDataOffset = 0;
    for(int i=0;i<3;i++)//三个前导符
    {
      byteData[byteDataLen] = 0x7F;
      byteDataLen++;
    }

    if(ComModel == "完整通讯协议")
    {
        if(fg == 0)
        {
            //握手命令组帧
            byteData[byteDataLen++] = 0x2F;//"/"
            byteData[byteDataLen++] = 0x3F;//"?"
            byteDataOffset = convertStringToHex(str, byteDataTemp);
            for(i=0;i<byteDataOffset;i++)//表号
            {
                byteData[byteDataLen++] = byteDataTemp[i];
            }
            byteData[byteDataLen++] = 0x21;//"!"
            byteData[byteDataLen++] = 0x0D;//CL
            byteData[byteDataLen++] = 0x0A;//RL
        }
        if(fg == 1)
        {
            byteData[byteDataLen++] = 0x06;//"-"
            byteData[byteDataLen++] = 0x30;//0
            byteDataOffset = convertStringToHex(str, byteDataTemp);
            for(i=0;i<byteDataOffset;i++)//波特率
            {
                byteData[byteDataLen++] = byteDataTemp[i];
            }
            byteData[byteDataLen++] = 0x31;//1
            byteData[byteDataLen++] = 0x0D;//CL
            byteData[byteDataLen++] = 0x0A;//RL
        }
        if(fg == 2)
        {
            byteData[byteDataLen++] = 0x01;//
            byteData[byteDataLen++] = 0x50;//
            byteData[byteDataLen++] = 0x31;//
            byteData[byteDataLen++] = 0x02;//
            byteData[byteDataLen++] = 0x28;//
            byteDataOffset = convertStringToHex(str, byteDataTemp);
            for(i=0;i<byteDataOffset;i++)//密码
            {
                byteData[byteDataLen++] = byteDataTemp[i];
            }
            byteData[byteDataLen++] = 0x29;//
            byteData[byteDataLen++] = 0x03;//
            //求校验值
            for(i=0;i<byteDataLen;i++)
            {
                if((byteData)[i] == 0x01)
                {
                    flag = 1;
                }
                if((byteData)[i] == 0x03)
                {
                    flag = 0;
                }
                if(flag ==1)
                {
                    (byteData)[byteDataLen] = (byteData)[byteDataLen]^(byteData)[i+1];
                }
            }
        }
    }
    if((ComModel == "单帧通讯协议")||(fg == 3))
    {
        //数据请求命令
        byteData[byteDataLen++] = 0x01;//"SOH"标题开始
        if(ReadOrWrite == myRead)
            byteData[byteDataLen++] = 0x52;//R
        else
            byteData[byteDataLen++] = 0x57;//W
        byteData[byteDataLen++] = 0x32;//2
        byteData[byteDataLen++] = 0x02;//"STX"正文开始
        byteDataOffset = convertStringToHex(str, byteDataTemp);
        for(i=0;i<byteDataOffset;i++)//数据ID
        {
            byteData[byteDataLen++] = byteDataTemp[i];
        }
        byteData[byteDataLen++] = 0x28;//"("
    //        if(ReadOrWrite == 1)
        if(isWriteData || ReadOrWrite)//
        {
            byteDataOffset = convertStringToHex(write_data, byteDataTemp);
            for(i=0;i<byteDataOffset;i++)
            {
                byteData[byteDataLen++] = byteDataTemp[i];
            }
        }
        byteData[byteDataLen++] = 0x29;//")"
        byteData[byteDataLen++] = 0x03;//"ETX"正文结束
        //求校验值
        for(i=0;i<byteDataLen;i++)
        {
            if((byteData)[i] == 0x01)
            {
                flag = 1;
            }
            if((byteData)[i] == 0x03)
            {
                flag = 0;
            }
            if(flag ==1)
            {
                (byteData)[byteDataLen] = (byteData)[byteDataLen]^(byteData)[i+1];
            }
        }
//        connect(myserial,SIGNAL(readyRead()),this,SLOT(receiveInfo()));
//        disconnect(myserial,SIGNAL(readyRead()),this,SLOT(receiveIecInfo()));
    }

/*    //打印数据
    textCursor=ui->textBrowser->textCursor();//得到当前的光标
    textCursor.movePosition(QTextCursor::End);
    textCursor.insertText(current_date+"   <<--"+byteData+'\n');

    //打开文件操作   /////////////////////////////////////////////////////////////////////////
    QFile file("DEBUGLOG.txt");
    QString StringFile(current_date+"   <<--"+byteData+'\n');
    file.open(QIODevice::Append |QIODevice::Text);
    QByteArray ByteArrayFile = StringFile.toUtf8();
    file.write(ByteArrayFile);
    file.close();
*/
    return byteData;
}
void ProcessIec::ReceiveIecInfo()
{

}



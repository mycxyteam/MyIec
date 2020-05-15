#ifndef PROCESSIEC_H
#define PROCESSIEC_H
#include <QString>
#include <QSerialPort>
class ProcessIec
{
public:
    ProcessIec();

    QByteArray getTxString(QString,QString,int,int,bool,QString);
    int convertStringToHex(const QString &, QByteArray &);
    char convertCharToHex(char );
    void ReceiveIecInfo();
};

#endif // PROCESSIEC_H

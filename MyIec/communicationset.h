#ifndef COMMUNICATIONSET_H
#define COMMUNICATIONSET_H

#include <QDialog>

namespace Ui {
class CommunicationSet;
}

typedef struct
{
    int baud;
    int FrameWay;
    QString Password;
}CommunicationVar;

class CommunicationSet : public QDialog
{
    Q_OBJECT

public:
    explicit CommunicationSet(QWidget *parent = 0);
    ~CommunicationSet();

    void receiverParentData();

signals:
    void sendData_1(CommunicationVar);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::CommunicationSet *ui;

};

#endif // COMMUNICATIONSET_H

#ifndef TIMESET_H
#define TIMESET_H

#include <QDialog>

namespace Ui {
class TimeSet;
}

typedef struct
{
    int txDelay;
    int changeBaudDelay;
    int timeOutDelay;
}TimeVar;

class TimeSet : public QDialog
{
    Q_OBJECT

public:
    explicit TimeSet(QWidget *parent = 0);
    ~TimeSet();

private slots:
    void receiveData();

    void on_buttonBox_accepted();

signals:
    void sendData_2(TimeVar);

private:
    Ui::TimeSet *ui;

    TimeVar sendTimeVar;
};

#endif // TIMESET_H

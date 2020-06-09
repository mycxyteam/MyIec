#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    int CRC_1 = 0;
    int CRC_2 = 0;
    int CRC_3 = 0;
    int CRC;
    void receiveData();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_buttonBox_accepted();
signals:
    void sendData_3(QString);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H

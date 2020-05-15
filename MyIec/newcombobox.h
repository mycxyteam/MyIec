#ifndef NEWCOMNOBOX_H
#define NEWCOMNOBOX_H

#include <QMainWindow>
#include <QComboBox>
#include <QMouseEvent>

class NewComboBox : public QComboBox
{
    Q_OBJECT

public:
    explicit NewComboBox(QWidget *parent = 0);
    ~NewComboBox();
protected:
    virtual void mousePressEvent(QMouseEvent *event);

signals:
    void clicked();

};

#endif // NEWCOMNOBOX_H

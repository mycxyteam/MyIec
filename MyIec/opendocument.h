#ifndef OPENDOCUMENT_H
#define OPENDOCUMENT_H

#include <QObject>
#include "myiec.h"

class OpenDocument : public QObject
{
    Q_OBJECT
public:
    explicit OpenDocument(QObject *parent = 0);


    QString OpenDocumentsFun(QWidget *parent, QString suffix);

signals:

public slots:

};

#endif // OPENDOCUMENT_H

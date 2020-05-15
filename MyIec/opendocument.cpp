#include "opendocument.h"
#include "QFileDialog"
#include "QMessageBox"
#include "QDebug"

OpenDocument::OpenDocument(QObject *parent) :
    QObject(parent)
{
}


QString OpenDocument::OpenDocumentsFun(QWidget *parent,QString suffix)
{
    QString fileName = QFileDialog::getOpenFileName(\
        parent,\
        tr("open a file."),\
        "./",\
        suffix);
//        tr("images(*.png *jpeg *bmp);;video files(*.avi *.mp4 *.wmv);;All files(*.*)"));
    if (fileName.isEmpty()) {
        QMessageBox::warning(parent, "Warning!", "Failed to open the file!");
    }
    else {
//        qDebug()<<fileName;
        QProcess *OpenTxt = new QProcess;
        if(fileName.contains(".txt")){
            OpenTxt->start("notepad.exe "+fileName);
        }
    }
    return fileName;
}

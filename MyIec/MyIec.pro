#-------------------------------------------------
#
# Project created by QtCreator 2020-04-15T10:58:46
#
#-------------------------------------------------

QT       += core gui
QT       += serialport

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyIec
TEMPLATE = app


SOURCES += main.cpp\
        myiec.cpp \
    newcombobox.cpp \
    communicationset.cpp \
    serialset.cpp \
    opendocument.cpp \
    timeset.cpp \
    processiec.cpp \
    dialog.cpp

HEADERS  += myiec.h \
    newcombobox.h \
    communicationset.h \
    serialset.h \
    opendocument.h \
    timeset.h \
    processiec.h \
    dialog.h

FORMS    += myiec.ui \
    communicationset.ui \
    serialset.ui \
    timeset.ui \
    dialog.ui

RC_FILE = MyIec.rc #添加图标MyIec.ico

OTHER_FILES += \
    ../myiec.qss

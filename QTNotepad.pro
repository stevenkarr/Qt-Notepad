#-------------------------------------------------
#
# Project created by QtCreator 2016-10-26T10:46:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTNotepad
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    findandreplace.cpp

HEADERS  += mainwindow.h \
    findandreplace.h

FORMS    += mainwindow.ui \
    findandreplace.ui

RESOURCES += \
    resource.qrc

RC_ICONS = img\notepad.ico

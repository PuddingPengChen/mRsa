#-------------------------------------------------
#
# Project created by QtCreator 2016-05-19T11:33:31
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GenerateAPI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    rsa.cpp

HEADERS  += mainwindow.h \
    rsa.h

FORMS    += mainwindow.ui

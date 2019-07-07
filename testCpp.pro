#-------------------------------------------------
#
# Project created by QtCreator 2017-09-09T10:48:27
#
#-------------------------------------------------

QT       += core gui network
CONFIG+=c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testCpp
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui


#windows mingw
#LIBS += -L$$PWD/../lib/windows/ -lplcQtLib -lws2_32
#PRE_TARGETDEPS += $$PWD/../lib/windows/libplcQtLib.a
#android
LIBS += -L$$PWD/../lib/android/ -lplcQtLib
PRE_TARGETDEPS += $$PWD/../lib/android/libplcQtLib.a
#RaszberyPI
#LIBS += -L$$PWD/../lib/RPI/ -lplcQtLib
#PRE_TARGETDEPS += $$PWD/../lib/RPI/libplcQtLib.a
#linux86
#LIBS += -L$$PWD/../lib/linux/ -lplcQtLib
#PRE_TARGETDEPS += $$PWD/../lib/linux/libplcQtLib.a
INCLUDEPATH += $$PWD/../lib
DEPENDPATH += $$PWD/../lib


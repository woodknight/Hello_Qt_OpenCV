#-------------------------------------------------
#
# Project created by QtCreator 2018-06-28T23:33:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Hello_Qt_OpenCV
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
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

# OpenCV Related
INCLUDEPATH += $$(OpenCV_Path)/include

LIBS += -L$$(OpenCV_Path)/x64/vc15/lib/ -lopencv_core400
LIBS += -L$$(OpenCV_Path)/x64/vc15/lib/ -lopencv_core400d

LIBS += -L$$(OpenCV_Path)/x64/vc15/lib/ -lopencv_highgui400
LIBS += -L$$(OpenCV_Path)/x64/vc15/lib/ -lopencv_highgui400d

LIBS += -L$$(OpenCV_Path)/x64/vc15/lib/ -lopencv_imgcodecs400
LIBS += -L$$(OpenCV_Path)/x64/vc15/lib/ -lopencv_imgcodecs400d

LIBS += -L$$(OpenCV_Path)/x64/vc15/lib/ -lopencv_imgproc400
LIBS += -L$$(OpenCV_Path)/x64/vc15/lib/ -lopencv_imgproc400d

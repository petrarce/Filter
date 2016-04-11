#-------------------------------------------------
#
# Project created by QtCreator 2016-04-06T16:46:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Filter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    my_graphicsview.cpp \
    MyOwnFramework/BackPropagation-master/src/Backpropagation.cpp \
    MyOwnFramework/BackPropagation-master/src/Layer.cpp \
    MyOwnFramework/BackPropagation-master/src/Neuron.cpp \
    MyOwnFramework/BackPropagation-master/src/Pattern.cpp \
    MyNetRpresentation/net.cpp

HEADERS  += mainwindow.h \
    my_graphicsview.h \
    MyOwnFramework/BackPropagation-master/src/Backpropagation.h \
    MyOwnFramework/BackPropagation-master/src/Layer.h \
    MyOwnFramework/BackPropagation-master/src/Neuron.h \
    MyOwnFramework/BackPropagation-master/src/Pattern.h \
    MyOwnFramework/BackPropagation-master/src/Sigmoid.h \
    MyNetRpresentation/net.h

FORMS    += mainwindow.ui

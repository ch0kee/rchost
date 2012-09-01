#-------------------------------------------------
#
# Project created by QtCreator 2012-07-22T17:14:39
#
#-------------------------------------------------

QT       += core xml

QT       -= gui

TARGET = rchost
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11
SOURCES += main.cpp \
    application.cpp \
    configuration.cpp \
    server.cpp \
    lambdafunction.cpp

LIBS += -lboost_thread
LIBS += -lboost_system

HEADERS += \
    application.h \
    configuration.h \
    server.h \
    lambdafunction.h

OTHER_FILES += \
    run.sh \
    rchost.xml

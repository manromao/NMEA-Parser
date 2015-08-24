#-------------------------------------------------
#
# Project created by QtCreator 2015-08-21T23:32:37
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = GPS-Tester
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../Include/gtest/
INCLUDEPATH += ../GPS/



SOURCES += \
../Include/gtest/src/gtest-all.cc \
    testing.cpp \
    testmain.cpp \
    ../GPS/gps.cpp \


HEADERS += \
    ../GPS/gps.h \



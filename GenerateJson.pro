QT += core
QT -= gui

CONFIG += c++11

TARGET = GenerateJson
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    functions.cpp \
    scenarioitem.cpp \
    vmixitem.cpp

HEADERS += \
    functions.h \
    scenarioitem.h \
    vmixitem.h

QT += core
QT -= gui

CONFIG += c++11

TARGET = TIC_TAC_TOE
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Game.cpp \
    Player.cpp \
    Board.cpp

HEADERS += \
    Game.h \
    Player.h \
    Board.h

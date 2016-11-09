#-------------------------------------------------
#
# Project created by QtCreator 2016-11-07T08:33:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chess
TEMPLATE = app
CONFIG += debug


SOURCES += main.cpp\
        mainview.cpp \
    Persistents/Pieces/pieceentity.cpp \
    Tests/chesstester.cpp \
    Tests/basetest.cpp \
    Persistents/Pieces/pawnentity.cpp \
    Persistents/MovePatterns/basepattern.cpp \
    Persistents/MovePatterns/pawnpattern.cpp \
    Tests/pawntest.cpp \
    Persistents/chesstab.cpp \
    Persistents/chesscell.cpp \
    Tests/chesstabtest.cpp \
    Persistents/Pieces/kingentity.cpp \
    Persistents/MovePatterns/kingpattern.cpp \
    Tests/kingtest.cpp

HEADERS  += \
    Persistents/Pieces/pieceentity.h \
    Persistents/Utils/position.h \
    Tests/chesstester.h \
    Tests/basetest.h \
    Persistents/Pieces/pawnentity.h \
    Persistents/MovePatterns/basepattern.h \
    Persistents/MovePatterns/pawnpattern.h \
    Tests/pawntest.h \
    Persistents/chesstab.h \
    Persistents/chesscell.h \
    Tests/chesstabtest.h \
    Persistents/Pieces/kingentity.h \
    Persistents/MovePatterns/kingpattern.h \
    Tests/kingtest.h

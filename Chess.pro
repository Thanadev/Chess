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
    Tests/kingtest.cpp \
    Views/tabview.cpp \
    Views/mainwindow.cpp \
    Views/cellview.cpp \
    Controllers/tabcontroller.cpp \
    Controllers/maincontroller.cpp \

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
    Tests/kingtest.h \
    Persistents/tabview.h \
    Views/tabview.h \
    Views/mainwindow.h \
    Views/cellview.h \
    Controllers/tabcontroller.h \
    Controllers/maincontroller.h

DISTFILES += \
    Resources/icons/bishop-black.png \
    Resources/icons/bishop-white.png \
    Resources/icons/king-black.png \
    Resources/icons/king-white.png \
    Resources/icons/knight-black.png \
    Resources/icons/knight-white.png \
    Resources/icons/pawn-black.png \
    Resources/icons/pawn-white.png \
    Resources/icons/queen-black.png \
    Resources/icons/queen-white.png \
    Resources/icons/rok-black.png \
    Resources/icons/rok-white.png

#-------------------------------------------------
#
# Project created by QtCreator 2016-05-05T18:04:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtSmartWord
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    src/Dictionary.cpp \
    src/Word.cpp \
    src/Recite.cpp \
    src/History.cpp \
    src/Translation.cpp \
    src/ChineseTest.cpp \
    src/EnglishTest.cpp \
    src/SpellTest.cpp \
    src/Test.cpp \
    src/TestList.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    src/Dictionary.h \
    src/Word.h \
    src/Random.h \
    src/Recite.h \
    src/History.h \
    src/Translation.h \
    src/ChineseTest.h \
    src/EnglishTest.h \
    src/SpellTest.h \
    src/Test.h \
    src/TestList.h

FORMS    += mainwindow.ui \
    logindialog.ui

RESOURCES += icons.qrc \


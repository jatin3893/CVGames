#-------------------------------------------------
#
# Project created by QtCreator 2015-09-12T09:36:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CVGames
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    src/cv/cvImageWidget.cpp \
    src/games/GamesManager.cpp \
    src/cv/cvDisplayWidget.cpp \
    src/games/GameListWidget.cpp \
    src/cv/cvFeatureExtractor.cpp

LIBS += `pkg-config --libs opencv`

INCLUDEPATH += -I/usr/include/opencv

HEADERS  += mainwindow.h \
    src/cv/cvImageWidget.h \
    src/games/GamesManager.h \
    src/cv/cvDisplayWidget.h \
    src/games/GameListWidget.h \
    src/cv/cvFeatureExtractor.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources/resources.qrc

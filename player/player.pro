#-------------------------------------------------
#
# Project created by QtCreator 2018-03-02T14:47:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets \
    multimedia \
    multimediawidgets \

TARGET = player
TEMPLATE = app
DESTDIR = ../bin

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
        player.cpp

HEADERS += \
        player.h

FORMS += \
        player.ui

INCLUDEPATH += $$PWD/../playerControls
LIBS += -L$$OUT_PWD/../bin -lplayerControls

INCLUDEPATH += $$PWD/../playlistModel
LIBS += -L$$OUT_PWD/../bin -lplaylistModel

INCLUDEPATH += $$PWD/../videoWidget
LIBS += -L$$OUT_PWD/../bin -lvideoWidget

INCLUDEPATH += $$PWD/../histogramWidget
LIBS += -L$$OUT_PWD/../bin -lhistogramWidget

RC_ICONS += $$PWD/Music_player.ico

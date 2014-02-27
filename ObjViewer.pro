#-------------------------------------------------
#
# Project created by QtCreator 2014-02-27T07:59:01
#
#-------------------------------------------------

QT       += core gui opengl

LIBS     += -LGLU

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ObjViewer
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += src/ ui/ include/

SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/glwidget.cpp \
    src/windowabout.cpp

HEADERS  += include/mainwindow.h \
    include/glwidget.h \
    include/windowabout.h

FORMS    += ui/mainwindow.ui \
    ui/windowabout.ui

#-------------------------------------------------
#
# Project created by QtCreator 2016-05-12T20:00:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = microEdit
TEMPLATE = app


SOURCES += main.cpp \
        editorwindow.cpp \
    syntaxhighlighter.cpp \
    microedittextedit.cpp \
    editorstatusbar.cpp \
    linecountwidget.cpp \
    filerecord.cpp

HEADERS  += editorwindow.h \
    syntaxhighlighter.h \
    microedittextedit.h \
    editorstatusbar.h \
    linecountwidget.h \
    filerecord.h

FORMS    += editorwindow.ui

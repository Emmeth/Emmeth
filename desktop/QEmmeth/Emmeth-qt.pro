#-------------------------------------------------
#
# Project created by QtCreator 2015-01-15T21:54:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Emmeth-qt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    xmlreader.cpp \
    libary.cpp \
    bookstore.cpp \
    htmlreader.h \
    htmlreader.cpp \
    aboutDialog.cpp \
    pdfreader.cpp \
    jsonreader.cpp

FORMS    += mainwindow.ui \
    bookstore.ui

HEADERS += \
    bookstore.h \
    libary.h \
    mainwindow.h \
    xmlreader.h \
    aboutDialog.h \
    pdfreader.h \
    jsonreader.h

RESOURCES += \
    icons.qrc \
    de-de.qrc \
    en-us.qrc \
    strings.qrc

DISTFILES += \
    Assets/icons/128.png \
    Assets/icons/16.png \
    Assets/icons/24.png \
    Assets/icons/32.png \
    Assets/icons/48.png \
    Assets/icons/256.png \
    Assets/icons/512.png \
    README.md \
    GPL3.txt \
    GPL3.html \
    Assets/XMLSchemas/tanach-xml.xsd \
    Assets/XMLSchemas/tanach-xml.json \
    XMLHandlers.md \
    Assets/abbreviations/info.md \
    Assets/abbreviations/en-US.json

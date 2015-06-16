#-------------------------------------------------
#
# Project created by QtCreator 2015-01-15T21:54:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qEmmeth
DESTDIR = ../../build
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    xmlreader.cpp \
    libary.cpp \
    bookstore.cpp \
    htmlreader.cpp \
    aboutDialog.cpp \
    txteditor.cpp \
    jsonparser.cpp \
    pdfreader.cpp

FORMS    += mainwindow.ui \
    bookstore.ui

HEADERS += \
    bookstore.h \
    libary.h \
    htmlreader.h \
    mainwindow.h \
    xmlreader.h \
    aboutDialog.h \
    txteditor.h \
    jsonparser.h \
    pdfreader.h

RESOURCES += \
    icons.qrc \
    de-de.qrc \
    en-us.qrc \
    strings.qrc \
    gpl.qrc

DISTFILES += \
    README.md \
    GPL3.txt \
    GPL3.html \
    assets/xmlschemas/tanach-xml.xsd \
    assets/xmlschemas/tanach-xml.json \
    XMLHandlers.md \
    assets/abbreviations/info.md \
    assets/abbreviations/en-US.json \

DEPLOYMENT += \

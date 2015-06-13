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
    htmlreader.cpp \
    aboutDialog.cpp \
    txteditor.cpp \
    jsonparser.cpp

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
    jsonparser.h

RESOURCES += \
    icons.qrc \
    de-de.qrc \
    en-us.qrc \
    strings.qrc

DISTFILES += \
    assets/icons/128.png \
    assets/icons/16.png \
    assets/icons/24.png \
    assets/icons/32.png \
    assets/icons/48.png \
    assets/icons/256.png \
    assets/icons/512.png \
    README.md \
    GPL3.txt \
    GPL3.html \
    assets/xmlschemas/tanach-xml.xsd \
    assets/xmlschemas/tanach-xml.json \
    XMLHandlers.md \
    assets/abbreviations/info.md \
    assets/abbreviations/en-US.json

#-------------------------------------------------
#
# Project created by QtCreator 2015-01-15T21:54:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Emmeth
win32:DESTDIR = ../../windows/release
unix:DESTDIR = ../../linux/release
osx:DESTDIR = ../../osx/release
TEMPLATE = app
VERSION = 0.1

SOURCES += main.cpp\
        mainwindow.cpp \
    xmlreader.cpp \
    libary.cpp \
    bookstore.cpp \
    htmlreader.cpp \
    aboutDialog.cpp \
    txteditor.cpp \
    jsonparser.cpp \
    settingsdialog.cpp \
    logindialog.cpp

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
    settingsdialog.h \
    logindialog.h

RESOURCES += \
    icons.qrc \
    de-de.qrc \
    en-us.qrc \
    strings.qrc \
    gpl.qrc \
    files.qrc

DISTFILES += \
    README.md \
    GPL3.txt \
    GPL3.html \
    assets/xmlschemas/tanach-xml.xsd \
    assets/xmlschemas/tanach-xml.json \
    XMLHandlers.md \
    assets/abbreviations/info.md \
    assets/abbreviations/en-US.json \
    TODO.md \
    assets/splashscreen.jpg

DEPLOYMENT += \

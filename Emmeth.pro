#-------------------------------------------------
#
# Project created by QtCreator 2015-01-15T21:54:23
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Emmeth
win32:DESTDIR = ../windows/release
unix:DESTDIR = ../linux/release
osx:DESTDIR = ../osx/release
TEMPLATE = app
VERSION = 0.1

#for the icons
RC_FILE = emmethapp.rc
ICON = moleskine.icns

SOURCES += main.cpp\
        mainwindow.cpp \
    xmlreader.cpp \
    bookstore.cpp \
    #htmlreader.cpp \
    aboutDialog.cpp \
    jsonparser.cpp \
    settingsdialog.cpp \
    logindialog.cpp \
    pdfreader.cpp \
    library.cpp \
    texteditor.cpp \
    sqldatabase.cpp \
    reference.cpp \
    search.cpp

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
    assets/splashscreen.jpg \
    Doxyfile \
    emmethapp.rc

DEPLOYMENT += \

INCLUDEPATH +=

HEADERS += \
    aboutDialog.h \
    bookstore.h \
    #htmlreader.h \
    jsonparser.h \
    logindialog.h \
    mainwindow.h \
    pdfreader.h \
    settingsdialog.h \
    xmlreader.h \
    library.h \
    texteditor.h \
    sqldatabase.h \
    reference.h \
    search.h

FORMS += \
    mainwindow.ui \
    bookstore.ui

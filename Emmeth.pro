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
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.12
CONFIG   += x86_64
CONFIG   += stl
CONFIG   += c++14

#TODO: configure for win 64 build

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
    search.cpp \
    searchresultitem.cpp

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
    search.h \
    searchresultitem.h

FORMS += \
    mainwindow.ui \
    bookstore.ui

#include the PDF-Writer Library (PDF Hummus)
#TODO: include win 64 libraries
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libraries/PDF-Writer/PDFWriter/release/ -lPDFWriter
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libraries/PDF-Writer/PDFWriter/debug/ -lPDFWriter
else:unix: LIBS += -L$$PWD/../libraries/PDF-Writer/PDFWriter/ -lPDFWriter

INCLUDEPATH += $$PWD/../libraries/PDF-Writer/PDFWriter
DEPENDPATH += $$PWD/../libraries/PDF-Writer/PDFWriter

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libraries/PDF-Writer/PDFWriter/release/libPDFWriter.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libraries/PDF-Writer/PDFWriter/debug/libPDFWriter.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libraries/PDF-Writer/PDFWriter/release/PDFWriter.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libraries/PDF-Writer/PDFWriter/debug/PDFWriter.lib
else:unix: PRE_TARGETDEPS += $$PWD/../libraries/PDF-Writer/PDFWriter/libPDFWriter.a

/*********************************
 *
 * main.cpp
 *
 * (C) Benjamin Schnabel, 2016
 *
 * LGPL
 *
 * The main class.
 *
 **********************************/
#include "mainwindow.h"
#include <QApplication>
#include <QString>

int main(int argc, char *argv[])
{

    QApplication emmeth(argc, argv);
    MainWindow w;

    //deactivate splash screen for faster testing
    //w.splashscreen();
    w.show();

    return emmeth.exec();
}

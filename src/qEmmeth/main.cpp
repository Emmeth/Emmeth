#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include "xmlreader.h"

int main(int argc, char *argv[])
{

    QApplication emmeth(argc, argv);
    MainWindow w;

    //deactivate splash screen for faster testing
    //w.splashscreen();
    w.show();

    return emmeth.exec();
}

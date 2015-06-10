#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication emmeth(argc, argv);
    MainWindow w;

    w.show();

    return emmeth.exec();
}

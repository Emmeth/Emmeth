#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include "xmlreader.h"

int main(int argc, char *argv[])
{
    QString fileName = "C:/Users/Benni/Programmierung/Emmeth/desktop/tanach-xml/Amos.xml";
    xmlReader::load(fileName);

    QApplication emmeth(argc, argv);
    MainWindow w;

    w.show();

    return emmeth.exec();
}

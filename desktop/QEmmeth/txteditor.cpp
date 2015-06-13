#include "txteditor.h"
#include <QString>
#include <QFile>
#include <QDebug>
#include <QTextStream>

txteditor::txteditor()
{

}


txteditor::~txteditor()
{

}
QString txteditor::read(QString fileName)
{
        qDebug() << fileName;
        QString content;

        QFile file(fileName);
        if(!file.exists()){
            qDebug() << "File not found";
            return content;
        }
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Error file open";
            return content;
        }
        content = file.readAll();
        file.close();
        qDebug() << "content: " + content;
        return content;
}

bool txteditor::write() {
    return 0;
}

void txteditor::display(){

}

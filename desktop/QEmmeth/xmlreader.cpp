/*********************
 * xmlReader Library *
 * Benjamin Schnabel *
 * (c) 2015          *
 * The xmlReader is  *
 * based on QXMLStreamReader   *
 *********************/

#include "xmlreader.h"
#include <QFile>
//#include <QtXml>
#include <QXmlStreamReader>
#include <QMessageBox>
#include <QDebug>
#include <QFileInfo>


xmlReader::xmlReader()
{

}

xmlReader::~xmlReader()
{

}

void xmlReader::load(QString fileName){
    QFileInfo fi(fileName);
    QFile xmlFile(fi.completeBaseName());
    xmlFile.open(QIODevice::ReadOnly);
    QXmlStreamReader xml;
    xml.setDevice(&xmlFile);

    QString result;

    //while (!xml.atEnd()) {
    //      xml.readNext();
          // do processing
     //     result += xml.text();
    //    if (xml.hasError()) {
              // do error handling
    //        qDebug() << xml.error();
     //     }
   // }
    if (xml.tokenType() == QXmlStreamReader::Invalid)
            qDebug() << xml.readNext();

        if (xml.hasError()) {
            xml.raiseError();
            qDebug() << xml.errorString();
        }

    qDebug() << result;
}

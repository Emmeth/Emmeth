/********************
 * xmlParser
 * newer version for parsing xml files, for QT 5.10
 *
 *
 */

#include "xmlparser.h"
#include <QtXml>
#include <QDebug>
#include <QMessageBox>
#include <QFile>

xmlParser::xmlParser()
{


}

xmlParser::load(QFile &file){
    QXmlInputSource inputSource = new QXmlInputSource(file);
    Handler *handler = new Handler;
    xmlReader.setContentHandler(handler);
    xmlReader.setErrorHandler(handler);

    bool res = xmlReader.parse(inputSource);

    if(!res){
        qDebug << "Error parsing.";
    }
}

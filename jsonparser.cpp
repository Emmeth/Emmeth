/*********************************
 *
 * jsonparser.cpp
 *
 * (C) Benjamin Schnabel, 2016
 *
 * LGPL
 *
 * parses a json file
 *
 **********************************/

#include "jsonparser.h"
#include <QDebug>
#include <QString>
#include <QFile>
#include <QFileInfo>
#include <QStringList>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>
#include <QJsonValuePtr>
#include <QJsonValueRef>
#include <QJsonValueRefPtr>

jsonParser::jsonParser()
{

}

jsonParser::~jsonParser()
{

}

void jsonParser::load(QString const fileName)
{
    //reads a json file returns the content
    qDebug()<< "jsonParser started";

    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly| QIODevice::Text))
    {
        qDebug() << "Error reading json file";
        //return 0;
     }
    QString content;
    content = file.readAll();
    file.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(content.toUtf8());
    qWarning() << jsonDocument.isNull();

    QJsonObject jsonObject = jsonDocument.object();
    QStringList result;
    //jsonDocument.fromRawData(content);
    qDebug() << content;
    //qDebug() << jsonObject["tanach"].toString();

}

void jsonParser::write(QString fileName)
{
    //writes a json file
}

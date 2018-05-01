#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QFile>

class xmlParser
{
public:
    QXmlReader xmlReader;
    xmlParser();
    load(QFile);
    read();

};

#endif // XMLPARSER_H

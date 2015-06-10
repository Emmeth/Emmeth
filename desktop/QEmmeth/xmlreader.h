#ifndef XMLREADER_H
#define XMLREADER_H
#include <QFile>
#include <QXmlStreamReader>


class xmlReader
{
public:
    xmlReader();
    ~xmlReader();
    static void load(QString fileName);

private:
    QXmlStreamReader xml;
};

#endif // XMLREADER_H

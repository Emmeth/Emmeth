#ifndef XMLREADER_H
#define XMLREADER_H
#include <QFile>
#include <QXmlStreamReader>
#include <QString>


class xmlReader
{
public:
    xmlReader();
    ~xmlReader();
    QString load(QString fileName);
    QString loadInfo(QString fileName);
    bool validate(QString fileName);
    QStringList readChapterVerses(QString fileName);
    QString readBookTitle(QString fileName);

private:
    QXmlStreamReader xml;
};

#endif // XMLREADER_H

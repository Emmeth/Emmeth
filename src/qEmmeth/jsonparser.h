#ifndef JSONPARSER_H
#define JSONPARSER_H
#include <QString>
#include <QStringList>


class jsonParser
{
public:
    jsonParser();
    ~jsonParser();
    void load(QString fileName);
    void write(QString fileName);
private:
};

#endif // JSONPARSER_H

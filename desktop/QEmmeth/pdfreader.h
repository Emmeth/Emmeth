#ifndef PDFREADER_H
#define PDFREADER_H

#include <QImage>
#include <QString>
#include <QFile>

class pdfReader
{
public:
    pdfReader();
    ~pdfReader();
    static QImage load(QString);
    static QString search(QString value);

private:
    QFile fileName;
    QImage image;
};

#endif // PDFREADER_H

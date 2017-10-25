#ifndef PDFREADER_H
#define PDFREADER_H

#include <QImage>
#include <QString>
#include <QFile>
#include "PDFParser.h"

/**
 * @brief
 *
 */
class pdfReader
{
public:
    /**
     * @brief
     *
     */
    pdfReader();
    /**
     * @brief
     *
     */
    ~pdfReader();
    /**
     * @brief
     *
     * @param QString
     * @return QImage
     */
    PDFHummus::EStatusCode load(QString);
    /**
     * @brief
     *
     * @param value
     * @return QString
     */
    static QString search(QString value);

    unsigned long pagesCount(QString file);
private:
    QFile fileName; /**< TODO: describe */
    QImage image; /**< TODO: describe */
};

#endif // PDFREADER_H

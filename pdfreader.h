#ifndef PDFREADER_H
#define PDFREADER_H

#include <QImage>
#include <QString>
#include <QFile>

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
    static void load(QString);
    /**
     * @brief
     *
     * @param value
     * @return QString
     */
    static QString search(QString value);

private:
    QFile fileName; /**< TODO: describe */
    QImage image; /**< TODO: describe */
};

#endif // PDFREADER_H

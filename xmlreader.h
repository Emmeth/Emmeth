#ifndef XMLREADER_H
#define XMLREADER_H
#include <QFile>
#include <QXmlStreamReader>
#include <QString>


/**
 * @brief
 *
 */
class xmlReader
{
public:
    /**
     * @brief
     *
     */
    xmlReader();
    /**
     * @brief
     *
     */
    ~xmlReader();
    /**
     * @brief
     *
     * @param fileName
     * @return QString
     */
    QString load(QString fileName);
    /**
     * @brief
     *
     * @param fileName
     * @return QString
     */
    QString loadInfo(QString fileName);
    /**
     * @brief
     *
     * @param fileName
     * @return bool
     */
    bool validate(QString fileName);
    /**
     * @brief
     *
     * @param fileName
     * @return QStringList
     */
    QStringList readChapterVerses(QString fileName);
    /**
     * @brief
     *
     * @param fileName
     * @return QString
     */
    QString readBookTitle(QString fileName);

private:
    QXmlStreamReader xml; /**< TODO: describe */
};

#endif // XMLREADER_H

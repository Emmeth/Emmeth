#ifndef JSONPARSER_H
#define JSONPARSER_H
#include <QString>
#include <QStringList>


/**
 * @brief
 *
 */
class jsonParser
{
public:
    /**
     * @brief
     *
     */
    jsonParser();
    /**
     * @brief
     *
     */
    ~jsonParser();
    /**
     * @brief
     *
     * @param fileName
     */
    void load(QString fileName);
    /**
     * @brief
     *
     * @param fileName
     */
    void write(QString fileName);
private:
};

#endif // JSONPARSER_H

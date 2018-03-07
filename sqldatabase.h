#ifndef SQLDATABASE_H
#define SQLDATABASE_H
#include <QString>
#include <QSqlDatabase>

class SQLDatabase
{
    const QSqlDatabase m_database;
public:
    SQLDatabase(const QString& file);
    ~SQLDatabase();

    void readDB(const QString& file, const QString& book, const QString& chapter, const QString & verse);
    void writeDB(const QString& content);
    void searchDB(const QString& query);

};

#endif // SQLDATABASE_H

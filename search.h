#ifndef SEARCH_H
#define SEARCH_H
#include <QString>


class Search
{
private:
    Search(QString searchTerm);
    Search(QString searchTerm, QString language );
    Search(QString searchTern,  QString language, QString file);
};

#endif // SEARCH_H

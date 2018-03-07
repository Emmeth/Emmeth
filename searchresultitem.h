#ifndef SEARCHRESULTITEM_H
#define SEARCHRESULTITEM_H
#include <QString>

class SearchResultItem
{
     QString book;
     int chapter;
     int verse;
public:
    SearchResultItem(QString book, int chapter, int verse);
};

#endif // SEARCHRESULTITEM_H

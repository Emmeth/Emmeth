#include "reference.h"

#include <QString>
/*****************
/ class for  referencing the bible and texts
/
/ Benjamin Schnabel (2017)
/
/ Structure as follows:
/  translation | book number* | book name | chapter | verse
/ * optional
/ | divider
/ Dividers are different for different languages, e.g.
/        English: 1 Chr 2:16 <-- colon for chapter and verse.
/        German: 1. Chr 2,16 <-- optional dot for book number, comma for chapter and verse.
/
/ Additional declarations for verse ranges.
/ From-To: chapter | verse - chapter | verse eg.: Rom 1-3 (chapters only), Rom 3:1-Rom 3:3 (chapter and verse), Rom 1-3:25 (mixed)
/ (instance + ) | verse: additional verse. Rom 3.5
/ (instance + ) | chapter: additional chapter. Rom 3:4.7
/ (instance +) |
/
/ Addional German syntax:
/    f. -> one aditional verse.
/   ff.> two additional verses.
/
/ Missing information:
/ Top-to-bottom (first instances):
/ start from first instance, if it is a range, then go to first instance of the range.
/
/ Only chapter and verse (later instances):
/ Use autocomplete to add missing information, if possible
/ verse only : go to the vers in this book and chapter.
/ chapter only: go the chapter in this book
/ verse and chapter: go to the first instance of this book.
/
/
/ Other literature:
/  If the there is others ways of af referencing a book.
/ e.g. Talmud:
/ babylonian or palaestinean Talmud (b,y/p) | book name | folio number | folio page (a,b)
/
/ Basically use ase follows:
/ A* B* C* D* E* ... F*
/ max. 6 Instaces in an array.
/ Which can be defined in a JsonFile, using Emmeth standard (see documentation).
/ Also the separators (including verse ranges) can be definded in the Json FIle.
/
**********************/


Reference::Reference()
{
    QString BookNumber;
    QString Book;
    QString Chapter;
    QString Verse;
}

Reference::Reference(const QString &s)
{

}

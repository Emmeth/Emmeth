/*********************************
 *
 * pdfreader.cpp
 *
 * (C) Benjamin Schnabel, 2016
 *
 * LGPL
 *
 * reads and displays pdf by the use of poppler
 * doc: http://people.freedesktop.org/~aacid/docs/qt5/index.html.
 *
 **********************************/
#include "pdfreader.h"
#include "QMessageBox"
#include "QImage"
#include <QString>
#include "PDFParser.h"
#include "PDFDocumentHandler.h"
#include "PDFDictionary.h"


#include <QDebug>

pdfReader::pdfReader()
{
    //constructor
}

pdfReader::~pdfReader()
{
    //destructor
}

EStatusCode pdfReader::load(QString fileName)
{
    //loads the file

    InputFile pdfFile;
    PDFParser parser;
    PDFHummus::EStatusCode result;

    pdfFile.OpenFile(fileName.toStdString());
    result = parser.StartPDFParsing(pdfFile.GetInputStream());


    return result;
}

unsigned long pdfReader::pagesCount(QString fileName){
    //counts the pages of the pdf

    InputFile pdfFile;
    PDFParser parser;
    pdfFile.OpenFile(fileName.toStdString());
    return parser.GetPagesCount();
}

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


#include <QDebug>

pdfReader::pdfReader()
{
    //constructor
}

pdfReader::~pdfReader()
{
    //destructor
}

void pdfReader::load(QString fileName)
{
    //loads the file

    //poppler version
//    QImage image;
//    int pageNumber = 1;
//    double 	xres = 72.0;
//    double 	yres = 72.0;
//    int 	x = -1;
//    int 	y = -1;
//    int 	width = -1;
//    int 	height = -1;

//    Poppler::Document *document = Poppler::Document::load(fileName);
//    if (!document || document->isLocked()) {
//        qDebug() << "Cannot read pdf.";
//        QMessageBox::critical(0, QObject::tr("Error loading pdf"), QObject::tr("Could not load pdf document"));
//        delete document;
//        return image;
//    }else{
//        // Paranoid safety check
//        if (document == 0) {
//        // ... error message ...
//        return image;
//        }
//        // Access page of the PDF file
//        Poppler::Page* pdfPage = document->page(pageNumber); // Document starts at page 0
//        if (pdfPage == 0) {
//        // ... error message ...
//        return image;
//        }
//        // Generate a QImage of the rendered page
//        QImage image = pdfPage->renderToImage(xres, yres, x, y, width, height);
//        if (image.isNull()) {
//        // ... error message ...
//        return image;
//        }
//        // ... use image ...
//        // after the usage, the page must be deleted
//        delete pdfPage;
//        delete document;
//        return image;
//    }

}

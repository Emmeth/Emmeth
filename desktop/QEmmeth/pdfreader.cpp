#include "pdfreader.h"
#include "QMessageBox"
#include "QImage"
#include <QString>

//#include <poppler/qt5/src/poppler-qt5.h>
//#include <poppler/qt5/src/poppler-embeddedfile-private.h>
//#include <poppler/qt5/src/poppler-form.h>
//#include <poppler/qt5/src/poppler-link.h>
//#include <poppler/qt5/src/poppler-media.h>
//#include <poppler/qt5/src/poppler-optcontent-private.h>
//#include <poppler/qt5/src/poppler-page-transition-private.h>
//#include <poppler/qt5/src/poppler-page-transition.h>
#include <QDebug>

// Benjamin Schnabel 2015
//reads and displays pdf by the use of poppler (doc: http://people.freedesktop.org/~aacid/docs/qt5/index.html).


pdfReader::pdfReader()
{

}

pdfReader::~pdfReader()
{

}

QImage pdfReader::load(QString fileName)
{
    QImage image;
    int pageNumber = 1;
    double 	xres = 72.0;
    double 	yres = 72.0;
    int 	x = -1;
    int 	y = -1;
    int 	width = -1;
    int 	height = -1;

    Poppler::Document *document = Poppler::Document::load(fileName);
    if (!document || document->isLocked()) {
        qDebug() << "Cannot read pdf.";
        QMessageBox::critical(0, QObject::tr("Error loading pdf"), QObject::tr("Could not load pdf document"));
        delete document;
        return image;
    }else{
        // Paranoid safety check
        if (document == 0) {
        // ... error message ...
        return image;
        }
        // Access page of the PDF file
        Poppler::Page* pdfPage = document->page(pageNumber); // Document starts at page 0
        if (pdfPage == 0) {
        // ... error message ...
        return image;
        }
        // Generate a QImage of the rendered page
        QImage image = pdfPage->renderToImage(xres, yres, x, y, width, height);
        if (image.isNull()) {
        // ... error message ...
        return image;
        }
        // ... use image ...
        // after the usage, the page must be deleted
        delete pdfPage;
        delete document;
        return image;
    }
}

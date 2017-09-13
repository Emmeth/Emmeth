/*********************
 * xmlReader Library *
 * Benjamin Schnabel *
 * (c) 2015          *
 * The xmlReader is  *
 * based on QXMLStreamReader   *
 *********************/

#include "xmlreader.h"
#include <QFile>
#include <QXmlStreamReader>
#include <QMessageBox>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QIcon>
#include <QTextDocument>
#include <QVector>
#include "set"
//#include <QtXmlPatterns/QXmlSchema>
//#include <QtXmlPatterns/QXmlSchemaValidator>

#include "jsonparser.h"



xmlReader::xmlReader()
{

}

xmlReader::~xmlReader()
{

}

QString xmlReader::load(QString fileName){
    /******************
     * loads a xml file
     ******************
     *
     * Returns the parsed content or an error if the loading fails.
     */

    //try to load the file
    try {
        qDebug() << "Reading xml file: " << fileName;
        QFile xmlFile(fileName);
        xmlFile.open(QIODevice::ReadOnly|QIODevice::Text);

        QXmlStreamReader xml;
        xml.setDevice(&xmlFile);

        if(xml.hasError() == true) {
            xml.raiseError("Error handling xml document");
            return NULL;
        }

        //XXX qDebug() << "Encoding: " + xml.documentEncoding().toString();

        //TODO: read through the json parser.
        //XXX qDebug() << "jsonParser started...";
        //XXX jsonParser *jsonParse = new jsonParser();
        //XXX jsonParse->load(":/assets/xmlschemas/assets/xmlschemas/tanach-xml.json");

        QString result;
        QTextDocument *document = new QTextDocument;
        //TODO: make this a rtf document, formatted
        //while(xml.readNextStartElement()){
        xml.readNext();
        while(!xml.atEnd() ){ //&& !xml.hasError()){
            //qDebug() << xml.name();
            xml.readNextStartElement();
            if(xml.isStartElement()){
                // if(xml.name() == "book"){ //look for the beginning of the document
                //qDebug() << xml.name();
                //result += xml.text().toString();
                //}

                if(xml.name()== "w"){ //read without new line
                    QString w = xml.readElementText(QXmlStreamReader::SkipChildElements);
                    //remove slashes from the text
                    result += w.remove("/");
                    //remove space after Linae Mappekh
                    if(!w.endsWith("־")){
                        result += " ";
                    }
                }
                //}

                //TODO: declare color in user theme file and load it
                QString chapterColor  = "#68C3A3";
                QString verseColor    = "#66CC99";
                QString parashahColor = "#6C7A89";
                int currentBook = 0;
                int currentChapter = 0;
                int currentVerse = 0;

                //for tanach xml
                if(xml.name() == "c"){ //if chapter found, display it
                    QXmlStreamAttributes attr = xml.attributes();
                    result += "<a id=\"ch_";
                    result += attr.first().value().toString();
                    result += "\"><h1 dir=\"rtl\" style=\"color:";
                    result += chapterColor;
                    result += ";\">";
                    result += attr.first().value().toString();
                    result += "</h1></a>";
                    result += "\n";
                    currentChapter++;
                }

                //for tanach xml
                if(xml.name() == "v"){
                    QXmlStreamAttributes attr = xml.attributes();
                    result += "<a id=\"c";
                    result += currentChapter + "_v";
                    result += attr.first().value().toString();
                    result += "\"><b style=\"color:";
                    result += verseColor;
                    result += ";\">";
                    result += attr.first().value().toString();
                    result += "</b></a>";
                    result += " ";
                }

                //for tanach xml
                if(xml.name() == "pe"){
                    result += " <b style=\"color:";
                    result += parashahColor;
                    result += ";\">פ</b><br />";
                }
                if(xml.name() == "samekh"){
                    result += "<b style=\"color:";
                    result += parashahColor;
                    result += ";\">ס</b> ";
                }

                //for sblgnt
                if(xml.name()== "title"){
                    result += "<h1 style=\"color:"+chapterColor+"; \">" + xml.readElementText(QXmlStreamReader::SkipChildElements) + "</h1>";
                }
                if(xml.name()== "verse-number"){
                    result += "<a><b style=\"color:"+ verseColor +";\">"+ xml.readElementText(QXmlStreamReader::SkipChildElements)+"</b></a> ";
                }
                if(xml.name()== "w"){ //read without new line
                    result += xml.readElementText(QXmlStreamReader::SkipChildElements);
                }
                if(xml.name()== "suffix"){
                    result += xml.readElementText(QXmlStreamReader::SkipChildElements);
                }

            } else { xml.readNext();}
        }

        if (xml.hasError()) {
            // do error handling
            QMessageBox::critical(0, "Error",xml.errorString(),QMessageBox::Close);
            xml.raiseError();
            qDebug() << "Error string: " << xml.errorString();
            qDebug() << "Error: " << xml.error();
            return NULL;
        }

        //qDebug() << "Result: " + result;
        xmlFile.close();
        qDebug() << "Reading done.";
        return result;


    } catch (...) { //FIXME: find right exception handler.
        qDebug() << "Error reading file: ";

        return NULL;
    }

}

QString xmlReader::loadInfo(QString fileName){
    //book info, displays the additional content & information for a book
    qDebug() << "Load Info";

    //QFileInfo fi(fileName);
    qDebug() << fileName;
    QFile xmlFile(fileName);
    //() << fi.completeBaseName();
    xmlFile.open(QIODevice::ReadOnly|QIODevice::Text);

    QXmlStreamReader xml;
    xml.setDevice(&xmlFile);

    QString result;
    qDebug() << "Encoding: " + xml.documentEncoding().toString();

    while( !xml.atEnd() && !xml.hasError()){
        xml.readNext();

        //qDebug() << xml.name();
        //qDebug() << xml.tokenString().toUtf8();
        //qDebug() << xml.text().toString();
        //qDebug() << xml.tokenString();
        if(xml.isStartDocument()){
            if(xml.name() == "teiHeader"){
                //result += xml.name().toString();
                result += xml.readElementText();
                //qDebug() << xml.tokenString();

                //qDebug() << "teiHeader found.";
                //Debug() << xml.tokenString().toUtf8();
            }
        }
    }
    if(xml.hasError()){
        xml.raiseError();
        qDebug() << "Error in xml file";
    }
    return result;

}

bool xmlReader::validate(QString fileName){
    //validates a xml file
    bool result = false;
    //QXmlSchema schema;
    //schema.load(QUrl(fileName));

    //if ( schema.isValid() ) {
    //    QXmlSchemaValidator validator( schema );
    //    if ( validator.validate( QUrl(fileName) ) ) {
    //        qDebug() << "instance is valid";
    //        result = true;
    //    } else {
    //        qDebug() << "instance is invalid";
    //    }
    //} else {
    //    qDebug() << "schema is invalid";
    //}
    return result;

}

QStringList xmlReader::readChapterVerses(QString fileName){
    qDebug() << "reading chapter and verses";

    //QFileInfo fi(fileName);
    QFile xmlFile(fileName);
    xmlFile.open(QIODevice::ReadOnly|QIODevice::Text);

    //initiate multiset
    std::multiset<QString> bookChapterVerses();


    QXmlStreamReader xml;
    xml.setDevice(&xmlFile);

    QStringList result;
    //QString resChapter;
    QString resVerse;

    while( !xml.atEnd() && !xml.hasError()){
        xml.readNext();
        if(xml.isStartElement()){
            // do processing
            if(xml.name() == "c"){
                QXmlStreamAttributes chapter = xml.attributes();
                //XXX qDebug() << "chapter: " + chapter.first().value().toString();
            }
            if(xml.name() == "v"){
                QXmlStreamAttributes verse = xml.attributes();
                //XXX qDebug() << "Verse: " + verse.first().value().toString();
                resVerse = verse.first().value().toString();
            }
        }
        if(xml.isEndElement()){
            if(xml.name() == "c"){
                result << resVerse;
            }
        }
    }

    if (xml.hasError()) {
        // do error handling
        xml.raiseError();
        qDebug() << xml.error();
    }

    qDebug() << result;
    return result;
}

QString xmlReader::readBookTitle(QString fileName){
    qDebug() << "reading book title";

    QFile xmlFile(fileName);
    xmlFile.open(QIODevice::ReadOnly|QIODevice::Text);

    QXmlStreamReader xml;
    xml.setDevice(&xmlFile);

    QString result;

    while( !xml.atEnd() && !xml.hasError()){
        xml.readNext();
        if(xml.isStartElement()){
            // do processing
            if(xml.name() == "title"){
                QXmlStreamAttributes attr = xml.attributes();
                QString level = attr.value("level").toString();
                QString type = attr.value("type").toString();

                if((level == "a") && (type == "main")){
                    result = xml.readElementText();
                }else { xml.readElementText(QXmlStreamReader::SkipChildElements);}
            }
        }

    }

    if (xml.hasError()) {
        // do error handling
        xml.raiseError();
        qDebug() << xml.error();
    }

    qDebug() << "Book title result: " + result;
    return result;
}
//TODO: tanach-xml full
//TODO: read multiple XML Versions
//TODO: Zefania XML
//TODO: XSEM from SIL
//TODO: OSIS http://www.bibletechnologies.net/ http://www.crosswire.org/study/
//TODO: ThML http://www.ccel.org/ThML/
//TODO: http://ebible.org/bible/gbf.htm http://ebible.org/translation/
//TODO: Mechon Mamre as html
//TODO: Develop Emmeth XML Markup language
//TODO: Unified Scripture Format XML (USFX)
//TODO: TEI http://www.tei-c.org/index.xml
//TODO: SWORD Project http://www.crosswire.org/sword/index.jsp
//TODO: STEP https://www.stepbible.org/
//TODO: XML format for Hebrew Bible



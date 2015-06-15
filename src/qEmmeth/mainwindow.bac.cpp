#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QFileDialog>
#include <QDebug>
#include <QFileInfo>
#include <QImage>
#include <QScrollArea>
#include <QPalette>
#include <QLabel>
//#include "pdfreader.h"
#include <QFile>
#include "xmlreader.h"
#include "aboutDialog.h"
#include "txteditor.h"
#include <QFile>
#include <QString>
#include <QTextEdit>
#include <QtGui>
#include <QtCore>
#include <QSpacerItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Load file"), "", tr("Emmeth Files (*.emt);; XML Files (*.xml);; PDF Files (*.pdf);; TXT Files (*.txt)"));
    if(!fileName.isEmpty()){
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
              QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
          }
        qDebug() << "Open:"  + fileName;
        MainWindow::loadFile(fileName);
    }
}

void MainWindow::save()
{

}

void MainWindow::about()
{
    qDebug() <<"About";
    aboutDialog::open();
}

void MainWindow::on_actionOpen_triggered()
{
    MainWindow::open();
}

void MainWindow::loadFile(QFile fileName)
{
    //get File ending info
    QFileInfo fi(fileName);
    QString base = fi.completeBaseName(); //Filename without memory address
    QString ending = fi.completeSuffix();  //only Ending
    //qDebug() << fi(fileName);
    qDebug() << "base: " + base;
    qDebug() << "ending: " + ending;

    //open according to the ending
    //TODO change to switch
    if(ending == "pdf"){ //load reader classes and render by the reader.
        //QImage pdfImage = new QImage();
        QMessageBox::critical(this, tr("Error"), tr("Pdf not implemented yet."));
        // QImage pdfImage = pdfReader::load(fileName.fileName());
      }
    if(ending == "xml"){
        qDebug() << "reading xml file.";
        qDebug() << fileName.fileName();
        xmlReader::load(fileName.fileName());
        }
    if(ending == "txt"){
        qDebug() << "reading txt file";
        txteditor text;
        QString content;
        content = text.read(fileName.fileName());
        display(content);
    }
}

void MainWindow::on_actionQuit_triggered()
{
    this->close();
}
void MainWindow::imageLabel()
{ //class used to display pdf Files in a scroll Area
    QLabel *imageLabel = new QLabel(this);
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Base);
    scrollArea->setWidget(imageLabel);
    setCentralWidget(scrollArea);
}

void MainWindow::on_actionAbout_triggered()
{
    MainWindow::about();
}

void MainWindow::display(QString string){

    QGridLayout *gridLayout = new QGridLayout();
    QHBoxLayout *hBoxLayout = new QHBoxLayout();
    QPushButton *btnSearch = new QPushButton("&Search");
    btnSearch->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/find.png"));
    QComboBox *cmbSearch = new QComboBox();
    QComboBox *cmbBook = new QComboBox();
    QComboBox *cmbChapter = new QComboBox();
    QComboBox *cmbVerse = new QComboBox();
    QSpacerItem *spacerItem = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hBoxLayout->addWidget(cmbSearch);
    hBoxLayout->addWidget(btnSearch);
    hBoxLayout->addWidget(cmbBook);
    hBoxLayout->addWidget(cmbChapter);
    hBoxLayout->addWidget(cmbVerse);
    hBoxLayout->addSpacerItem(spacerItem);

    gridLayout->addLayout(hBoxLayout,0,0);
    QWidget *widget = new QWidget();
    widget->setLayout(gridLayout);
    setCentralWidget(widget);

    QTextEdit *textedit = new QTextEdit();
    textedit->setAcceptRichText(true);
    textedit->setAutoFillBackground(true);
    textedit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    textedit->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    textedit->setWordWrapMode(QTextOption::WordWrap);

    textedit->setText(string);
    textedit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    textedit->setCursor(Qt::IBeamCursor);
    gridLayout->addWidget(textedit);


    //QLabel *label = new QLabel(string);
    //label->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    //QScrollArea *scrollArea = new QScrollArea();
    //scrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //scrollArea->setWidget(textedit);
    //scrollArea->setWidget(label);
    //scrollArea->setParent(ui->mainWidget);
    //ui->gridLayout->addWidget(textedit);
    //ui->mdiArea->addSubWindow(textedit);
    //ui->gridLayout->addWidget(scrollArea);
    //layout()->addWidget(scrollArea);
    //mainWidget->addWidget(scrollArea);
    //setCentralWidget(scrollArea);
    //this->centralWidget()->showMaximized();
}

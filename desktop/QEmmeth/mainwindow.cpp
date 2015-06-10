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
    QString fileName = QFileDialog::getOpenFileName(this, tr("Load file"), "", tr("Emmeth Files (*.emt);; XML Files (*.xml);; PDF Files (*.pdf)"));
    if(!fileName.isEmpty()){
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
              QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
          }
        qDebug() << fileName;
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
    qDebug() << base;
    qDebug() << ending;
    //open according to the ending
    if(ending == "pdf"){ //load reader classes and render by the reader.
        //QImage pdfImage = new QImage();
        QMessageBox::critical(this, tr("Error"), tr("Pdf not implemented yet."));
        // QImage pdfImage = pdfReader::load(fileName.fileName());
      }
    if(ending == "xml"){
        qDebug() << "reading xml file.";
        qDebug() << fileName.fileName();
        xmlReader::load(fi.completeBaseName());
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

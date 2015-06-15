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
#include <QPushButton>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

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

    //hbox content
    QGridLayout *gridLayout = new QGridLayout();
    QHBoxLayout *hBoxLayout = new QHBoxLayout();
    QPushButton *btnSearch = new QPushButton("&Search");
    btnSearch->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/find.png"));
    QComboBox *cmbSearch = new QComboBox();
    cmbSearch->setEditable(true);
    QComboBox *cmbBook = new QComboBox();
    QComboBox *cmbChapter = new QComboBox();
    QComboBox *cmbVerse = new QComboBox();
    QSpacerItem *spacerItem = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    //hboxlayout
    hBoxLayout->addWidget(cmbSearch);
    hBoxLayout->addWidget(btnSearch);
    hBoxLayout->addWidget(cmbBook);
    hBoxLayout->addWidget(cmbChapter);
    hBoxLayout->addWidget(cmbVerse);
    hBoxLayout->addSpacerItem(spacerItem);

    //editor icons
    QHBoxLayout *hBoxLayoutTextedit = new QHBoxLayout(); //new HBoxLayout for Pushbuttons

    QComboBox *cmbFont = new QComboBox();
    cmbFont->setEditable(true);
    cmbFont->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    QStringList fonts;
    fonts << "Arial" <<"Courier"<<"Times New Roman"<<"Tahoma";
    cmbFont->setInsertPolicy(QComboBox::InsertAlphabetically);
    cmbFont->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    cmbFont->insertItems(0,fonts);
    QComboBox *cmbFontSize = new QComboBox();
    cmbFontSize->setEditable(true);
    cmbFontSize->setInsertPolicy(QComboBox::InsertAlphabetically);
    cmbFontSize->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    cmbFontSize->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    QStringList fontSizes;
    fontSizes << "8" << "9" << "10" << "11" << "12" << "14" << "16" << "18" << "20" << "22" << "24" << "26" << "28" << "36" << "48" << "72";
    cmbFontSize->insertItems(0,fontSizes);
    QPushButton *btnBold = new QPushButton();
    btnBold->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/format-text-bold.png"));
    btnBold->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    QPushButton *btnItalic = new QPushButton();
    btnItalic->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/format-text-italic.png"));
    btnItalic->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    QPushButton *btnUnderline = new QPushButton();
    btnUnderline->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/format-text-underline.png"));
    btnUnderline->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    QPushButton *btnStrikethrough = new QPushButton();
    btnStrikethrough->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/format-text-strikethrough.png"));
    btnStrikethrough->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    QPushButton *btnAlignLeft = new QPushButton();
    btnAlignLeft->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/format-justify-left.png"));
    btnAlignLeft->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    QPushButton *btnAlignCenter = new QPushButton();
    btnAlignCenter->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/format-justify-center.png"));
    btnAlignCenter->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    QPushButton *btnAlignFill = new QPushButton();
    btnAlignFill->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/format-justify-fill.png"));
    btnAlignFill->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    QPushButton *btnAlignRight = new QPushButton();
    btnAlignRight->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/format-justify-right.png"));
    btnAlignRight->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    QPushButton *btnLTR = new QPushButton();
    btnLTR->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/format-text-direction-ltr.png"));
    btnLTR->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    QPushButton *btnRTL = new QPushButton();
    btnRTL->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/format-text-direction-rtl.png"));
    btnRTL->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    QPushButton *btnIndentMore = new QPushButton();
    btnIndentMore->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/format-indent-more.png"));
    btnIndentMore->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    QPushButton *btnIndentLess = new QPushButton();
    btnIndentLess->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/format-indent-less.png"));
    btnIndentLess->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    QPushButton *btnList = new QPushButton();
    btnList->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/view-list-compact.png"));
    btnList->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    QPushButton *btnSpellcheck = new QPushButton();
    btnSpellcheck->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/gtk-spell-check.png"));
    btnSpellcheck->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    hBoxLayoutTextedit->addWidget(cmbFont);
    hBoxLayoutTextedit->addWidget(cmbFontSize);
    hBoxLayoutTextedit->addWidget(btnBold);
    hBoxLayoutTextedit->addWidget(btnItalic);
    hBoxLayoutTextedit->addWidget(btnUnderline);
    hBoxLayoutTextedit->addWidget(btnStrikethrough);
    hBoxLayoutTextedit->addWidget(btnAlignLeft);
    hBoxLayoutTextedit->addWidget(btnAlignCenter);
    hBoxLayoutTextedit->addWidget(btnAlignFill);
    hBoxLayoutTextedit->addWidget(btnAlignRight);
    hBoxLayoutTextedit->addWidget(btnLTR);
    hBoxLayoutTextedit->addWidget(btnRTL);
    hBoxLayoutTextedit->addWidget(btnIndentMore);
    hBoxLayoutTextedit->addWidget(btnIndentLess);
    hBoxLayoutTextedit->addWidget(btnList);
    hBoxLayoutTextedit->addWidget(btnSpellcheck);
    hBoxLayoutTextedit->addSpacerItem(spacerItem);

    //add all hBoxlayouts to gridlayout
    gridLayout->addLayout(hBoxLayout,0,0);
    gridLayout->addLayout(hBoxLayoutTextedit,1,0);


    //Widget als central widget
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

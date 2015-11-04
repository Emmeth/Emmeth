#include "txteditor.h"
#include <QString>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QWidget>
#include <QSpacerItem>
#include <QTextEdit>
#include <QTextOption>

txteditor::txteditor()
{

}


txteditor::~txteditor()
{

}
QString txteditor::read(QString fileName)
{
        qDebug() << fileName;
        QString content;

        QFile file(fileName);
        if(!file.exists()){
            qDebug() << "File not found";
            return content;
        }
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Error file open";
            return content;
        }
        content = file.readAll();
        file.close();
        qDebug() << "content: " + content;
        return content;
}

bool txteditor::write() {
    //TODO: Put the save here.
    return 0;
}

void txteditor::display(QString string){
    //TODO: Put the display and the reading of the file to the MainWindow here.
    //hbox content
    QGridLayout *gridLayout = new QGridLayout();
    QSpacerItem *spacerItem;

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
    gridLayout->addLayout(hBoxLayoutTextedit,0,0);


    //Widget als central widget
    QWidget *widget = new QWidget();
    widget->setLayout(gridLayout);


    //add Textedit
   QTextEdit *textEdit = new QTextEdit();
    textEdit->setAcceptRichText(true);
    textEdit->setAutoFillBackground(true);
    textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    textEdit->setWordWrapMode(QTextOption::WordWrap);

    textEdit->setText(string);
    textEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    textEdit->setCursor(Qt::IBeamCursor);
    gridLayout->addWidget(textEdit);
}

//TODO: Read and write docx Files
//TODO: read html files
//TODO: change the textfile in the editor


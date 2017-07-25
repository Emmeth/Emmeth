/*********************************
 *
 * texteditor.cpp
 *
 * (C) Benjamin Schnabel, 2016
 *
 * LGPL
 *
 * The Texteditor class.
 *
 **********************************/

#include "texteditor.h"

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
#include <QVBoxLayout>
#include <QFileDialog>
#include <QObject>
#include <QMessageBox>
#include <QAction>
#include <QFontDatabase>
#include <QAction>
#include <QApplication>
#include <QClipboard>
#include <QColorDialog>
#include <QComboBox>
#include <QFontComboBox>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QFontDatabase>
#include <QMenu>
#include <QMenuBar>
#include <QTextCodec>
#include <QTextEdit>
#include <QStatusBar>
#include <QToolBar>
#include <QTextCursor>
#include <QTextDocumentWriter>
#include <QTextList>
#include <QtDebug>
#include <QCloseEvent>
#include <QMessageBox>
#include <QMimeData>


TextEditor::TextEditor(QWidget *parent): QWidget(parent)
{
    //creates the GUI
    //TODO: add toolbar instead of a layout.

    //layouts
    vBoxLayout = new QVBoxLayout(this);
    hBoxLayoutActions = new QHBoxLayout(); //new HBoxLayout for Pushbuttons for Actions, frist row.
    hBoxLayoutFormat = new QHBoxLayout();  //new HBoxLayout for Pushbuttons for Formating, second row.

    //editor icons

    /* FIXME: declutter
    fonts << "Arial" << "Courier"<< "Times New Roman" << "Tahoma" << "Helvetica" << "Georgia";
    typedef void (QComboBox::*QComboStringSignal)(const QString &);
    comboFont = new QFontComboBox();
    comboFont->setEditable(true);
    comboFont->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    comboFont->setInsertPolicy(QComboBox::InsertAlphabetically);
    comboFont->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    comboFont->insertItems(0,fonts);

    typedef void (QComboBox::*QComboStringSignal)(const QString &);
    comboSize = new QComboBox();
    comboSize->setEditable(true);
    comboSize->setInsertPolicy(QComboBox::InsertAlphabetically);
    comboSize->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    comboSize->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    fontSizes << "8" << "9" << "10" << "11" << "12" << "14" << "16" << "18" << "20" << "22" << "24" << "26" << "28" << "36" << "48" << "72";
    comboSize->insertItems(0,fontSizes);
    */

    //the comboboxes
    typedef void (QComboBox::*QComboIntSignal)(int);
    //XXX QObject::connect(comboStyle, static_cast<QComboIntSignal>(&QComboBox::activated), this, &TextEditor::textStyle);

    typedef void (QComboBox::*QComboStringSignal)(const QString &);
    comboFont = new QFontComboBox();
    //XXX QObject::connect(comboFont, static_cast<QComboStringSignal>(&QComboBox::activated), this, &TextEditor::textFamily);

    comboSize = new QComboBox();
    comboSize->setObjectName("comboSize");
    comboSize->setEditable(true);

    const QList<int> standardSizes = QFontDatabase::standardSizes();
    foreach (int size, standardSizes)
        comboSize->addItem(QString::number(size));
    comboSize->setCurrentIndex(standardSizes.indexOf(QApplication::font().pointSize()));

    //XXX QObject::connect(comboSize, static_cast<QComboStringSignal>(&QComboBox::activated), this, &TextEditor::textSize);

    //Bold
    btnBold = new QPushButton();
    btnBold->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/format-text-bold.png"));
    btnBold->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    btnBold->setToolTip(tr("Bold"));
    btnBold->setCheckable(true);
    btnBold->setShortcut(QKeySequence::Bold);
    btnBold->setStatusTip(tr("bold text"));

    //Italic
    btnItalic = new QPushButton();
    btnItalic->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/format-text-italic.png"));
    btnItalic->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    btnItalic->setToolTip(tr("Italic"));
    btnItalic->setCheckable(true);
    btnItalic->setShortcut(QKeySequence::Italic);

    //Underline
    btnUnderline = new QPushButton();
    btnUnderline->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/format-text-underline.png"));
    btnUnderline->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    btnUnderline->setToolTip(tr("Underline"));
    btnUnderline->setCheckable(true);
    btnUnderline->setShortcut(QKeySequence::Underline);

    //Strikethrough
    btnStrikethrough = new QPushButton();
    btnStrikethrough->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/format-text-strikethrough.png"));
    btnStrikethrough->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    btnStrikethrough->setToolTip(tr("Striketrough"));
    btnStrikethrough->setCheckable(true);

    //Align Left
    btnAlignLeft = new QPushButton();
    btnAlignLeft->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/format-justify-left.png"));
    btnAlignLeft->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    btnAlignLeft->setToolTip(tr("Align Left"));
    btnAlignLeft->setCheckable(true);

    //Align Center
    btnAlignCenter = new QPushButton();
    btnAlignCenter->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/format-justify-center.png"));
    btnAlignCenter->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    btnAlignCenter->setToolTip(tr("Align Center"));
    btnAlignCenter->setCheckable(true);

    //Align Fill
    btnAlignJustify = new QPushButton();
    btnAlignJustify->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/format-justify-fill.png"));
    btnAlignJustify->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    btnAlignJustify->setToolTip(tr("Align Fill"));
    btnAlignJustify->setCheckable(true);

    //Align Right
    btnAlignRight = new QPushButton();
    btnAlignRight->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/format-justify-right.png"));
    btnAlignRight->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    btnAlignRight->setToolTip(tr("Align Right"));
    btnAlignRight->setCheckable(true);

    //Direction LTR
    btnLTR = new QPushButton();
    btnLTR->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/format-text-direction-ltr.png"));
    btnLTR->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    btnLTR->setToolTip(tr("Direction LTR"));
    btnLTR->setCheckable(true);

    //Direction RTL
    btnRTL = new QPushButton();
    btnRTL->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/format-text-direction-rtl.png"));
    btnRTL->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    btnRTL->setToolTip(tr("Direction RTL"));
    btnRTL->setCheckable(true);

    //More intent
    btnIndentMore = new QPushButton();
    btnIndentMore->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/format-indent-more.png"));
    btnIndentMore->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    //Less intent
    btnIndentLess = new QPushButton();
    btnIndentLess->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/format-indent-less.png"));
    btnIndentLess->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    //List
    btnList = new QPushButton();
    btnList->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/view-list-compact.png"));
    btnList->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    //Spellcheck
    btnSpellcheck = new QPushButton();
    btnSpellcheck->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/gtk-spell-check.png"));
    btnSpellcheck->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    //Button new file
    btnNewFile = new QPushButton();
    btnNewFile->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/document-new.png"));
    btnNewFile->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnNewFile->setToolTip(tr("New file"));

    //Button open file
    btnOpenFile = new QPushButton();
    btnOpenFile->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/document-open.png"));
    btnOpenFile->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnOpenFile->setToolTip(tr("Open file"));

    //Button save file
    btnSaveFile = new QPushButton();
    btnSaveFile->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/filesave.png"));
    btnSaveFile->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnSaveFile->setToolTip(tr("Save File"));

    //Button save as file
    btnSaveAsFile = new QPushButton();
    btnSaveAsFile->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/filesaveas.png"));
    btnSaveAsFile->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnSaveAsFile->setToolTip(tr("Save As"));

    //Button undo
    btnUndo = new QPushButton();
    btnUndo->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/edit-undo.png"));
    btnUndo->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnUndo->setToolTip(tr("Undo"));
    btnUndo->setShortcut(QKeySequence::Undo);

    //Button redo
    btnRedo = new QPushButton();
    btnRedo->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/edit-redo.png"));
    btnRedo->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnRedo->setToolTip(tr("Redo"));
    btnRedo->setShortcut(QKeySequence::Redo);

    //Button copy
    btnCopy = new QPushButton();
    btnCopy->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/edit-copy.png"));
    btnCopy->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnCopy->setToolTip(tr("Copy"));
    btnCopy->setShortcut(QKeySequence::Copy);

    //Button cut
    btnCut = new QPushButton();
    btnCut->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/edit-cut.png"));
    btnCut->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnCut->setToolTip(tr("Cut"));
    btnCut->setShortcut(QKeySequence::Cut);

    //Button paste
    btnPaste = new QPushButton();
    btnPaste->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/edit-paste.png"));
    btnPaste->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnPaste->setToolTip(tr("Paste"));
    btnPaste->setShortcut(QKeySequence::Paste);

    //Add first row
    hBoxLayoutActions->addWidget(btnNewFile);
    hBoxLayoutActions->addWidget(btnOpenFile);
    hBoxLayoutActions->addWidget(btnSaveFile);
    hBoxLayoutActions->addWidget(btnSaveAsFile);
    hBoxLayoutActions->addSpacing(10);
    hBoxLayoutActions->addWidget(btnUndo);
    hBoxLayoutActions->addWidget(btnRedo);
    hBoxLayoutActions->addSpacing(10);
    hBoxLayoutActions->addWidget(btnCopy);
    hBoxLayoutActions->addWidget(btnCut);
    hBoxLayoutActions->addWidget(btnPaste);
    hBoxLayoutActions->addStretch();

    //Add second row
    hBoxLayoutFormat->addWidget(comboFont);
    hBoxLayoutFormat->addWidget(comboSize);
    hBoxLayoutFormat->addWidget(btnBold);
    hBoxLayoutFormat->addWidget(btnItalic);
    hBoxLayoutFormat->addWidget(btnUnderline);
    hBoxLayoutFormat->addWidget(btnStrikethrough);
    hBoxLayoutFormat->addWidget(btnAlignLeft);
    hBoxLayoutFormat->addWidget(btnAlignCenter);
    hBoxLayoutFormat->addWidget(btnAlignJustify);
    hBoxLayoutFormat->addWidget(btnAlignRight);
    hBoxLayoutFormat->addWidget(btnLTR);
    hBoxLayoutFormat->addWidget(btnRTL);
    hBoxLayoutFormat->addWidget(btnIndentMore);
    hBoxLayoutFormat->addWidget(btnIndentLess);
    hBoxLayoutFormat->addWidget(btnList);
    hBoxLayoutFormat->addWidget(btnSpellcheck);
    hBoxLayoutFormat->addStretch();

    //add Textedit
    textEdit = new QTextEdit();
    textEdit->setAcceptRichText(true);
    textEdit->setAutoFillBackground(true);
    textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    textEdit->setWordWrapMode(QTextOption::WordWrap);
    textEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    textEdit->setCursor(Qt::IBeamCursor);



    //set Font
    QFont textFont("Arial");
    textFont.setStyleHint(QFont::SansSerif);
    textEdit->setFont(textFont);
    fontChanged(textEdit->font());
    colorChanged(textEdit->textColor());
    alignmentChanged(textEdit->alignment());


    //TOD0: connect all slots

    //for TextEdit
    QObject::connect(textEdit, &QTextEdit::currentCharFormatChanged,
            this, &TextEditor::currentCharFormatChanged);
    QObject::connect(textEdit, &QTextEdit::cursorPositionChanged,
            this, &TextEditor::cursorPositionChanged);

    QObject::connect(textEdit->document(), &QTextDocument::modificationChanged,
            this, &QWidget::setWindowModified);


    //for the buttons
    QObject::connect(btnNewFile,    &QPushButton::clicked, this, &TextEditor::newFile);
    QObject::connect(btnOpenFile,   &QPushButton::clicked, this, &TextEditor::openFile);
    QObject::connect(btnSaveFile,   &QPushButton::clicked, this, &TextEditor::saveFile);
    QObject::connect(btnSaveAsFile, &QPushButton::clicked, this, &TextEditor::saveAs);
    QObject::connect(btnUndo,       &QPushButton::clicked, this, &TextEditor::undo);
    QObject::connect(btnRedo,       &QPushButton::clicked, this, &TextEditor::redo);
    QObject::connect(btnCopy,       &QPushButton::clicked, this, &TextEditor::copy);
    QObject::connect(btnCut,        &QPushButton::clicked, this, &TextEditor::cut);
    QObject::connect(btnPaste,      &QPushButton::clicked, this, &TextEditor::paste);
    QObject::connect(btnBold,       &QPushButton::clicked, this, &TextEditor::textBold);



    //add all hBoxlayouts to the main layout
    vBoxLayout->addLayout(hBoxLayoutActions);
    vBoxLayout->addLayout(hBoxLayoutFormat);

    vBoxLayout->addWidget(textEdit);

    textEdit->setFocus();
    setWindowTitle(tr("untitled"));
}


TextEditor::~TextEditor()
{
    //destructor

}
QString TextEditor::read(QString fileName)
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

bool TextEditor::write() {
    //TODO: Put the save here.
    return 0;
}

void TextEditor::setCurrentFileName(const QString &fileName)
{
    this->fileName = fileName;
    textEdit->document()->setModified(false);

    QString shownName;
    if (fileName.isEmpty())
        shownName = "untitled.txt";
    else
        shownName = QFileInfo(fileName).fileName();

    setWindowTitle(tr("%1[*] - %2").arg(shownName, QCoreApplication::applicationName()));
    setWindowModified(false);
}

void TextEditor::openFile(){

    //TODO: make available for translation
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    QObject::tr("Load file"),
                                                    "../../",
                                                    QObject::tr("Text Files (*.txt);;OpenDocument Files (*.odt);;Word Files (*.doc *.docx);;HTML Files(*.html *.htm)"));

    if(!fileName.isEmpty()){
        QFile file(fileName);

        if(file.open(QFile::ReadOnly | QFile::Text)){
            //read the file

            QTextStream in(&file);
            QString text = in.readAll();
            file.close();

            textEdit->setDocumentTitle(fileName);
            textEdit->setPlainText(text);
        }
    }
}

bool TextEditor::saveFile(){
    //save the file
    QFile file(saveFileName);
    if(file.open(QFile::WriteOnly | QFile::Text)){
        QTextStream out(&file);

        out << textEdit->toPlainText();

        file.flush();
        file.close();
    }
    return true;
}

void TextEditor::saveAs(){
    //load the file dialog  and save it

    //TODO: make available for translation
    saveFileName = QFileDialog::getOpenFileName(this,
                                                    "Save file as",
                                                    "../../",
                                                    "Text Files (*.txt);;OpenDocument Files (*.odt);;Word Files (*.doc *.docx);;HTML Files(*.html *.htm)");

    saveFile();
}

void TextEditor::newFile(){
    if (maybeSave()) {
            textEdit->clear();
            setCurrentFileName(QString());
        }
}

bool TextEditor::maybeSave()
{
    if (!textEdit->document()->isModified())
        return true;

    const QMessageBox::StandardButton ret =
        QMessageBox::warning(this, QCoreApplication::applicationName(),
                             tr("The document has been modified.\n"
                                "Do you want to save your changes?"),
                             QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    if (ret == QMessageBox::Save)
        return saveFile();
    else if (ret == QMessageBox::Cancel)
        return false;
    return true;
}


void TextEditor::cut(){
    textEdit->cut();
}

void TextEditor::paste(){
    textEdit->paste();
}

void TextEditor::copy(){
    textEdit->copy();
}


void TextEditor::undo(){
    textEdit->undo();
}

void TextEditor::redo(){
    textEdit->redo();
}

void TextEditor::closeFile(){
    //TODO: finish.
}

void TextEditor::textBold(){
    //apply bold text
    QTextCharFormat fmt;
    fmt.setFontWeight(btnBold->isChecked() ? QFont::Bold : QFont::Normal);
    mergeFormatOnWordOrSelection(fmt);
}

void TextEditor::textItalic(){

}
void TextEditor::textUnderline(){

}
void TextEditor::textStrikethrough(){

}
void TextEditor::textAlignLeft(){

}
void TextEditor::textAlignRight(){

}

void TextEditor::textAlignCenter(){

}

void TextEditor::textAlignFill(){

}

void TextEditor::textLTR(){

}

void TextEditor::textRTL(){

}

void TextEditor::textFamily(const QString &f)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(f);
    mergeFormatOnWordOrSelection(fmt);
}

void TextEditor::textSize(const QString &p)
{
    qreal pointSize = p.toFloat();
    if (p.toFloat() > 0) {
        QTextCharFormat fmt;
        fmt.setFontPointSize(pointSize);
        mergeFormatOnWordOrSelection(fmt);
    }
}

void TextEditor::textStyle(int styleIndex)
{
    QTextCursor cursor = textEdit->textCursor();

    if (styleIndex != 0) {
        QTextListFormat::Style style = QTextListFormat::ListDisc;

        switch (styleIndex) {
        default:
        case 1:
            style = QTextListFormat::ListDisc;
            break;
        case 2:
            style = QTextListFormat::ListCircle;
            break;
        case 3:
            style = QTextListFormat::ListSquare;
            break;
        case 4:
            style = QTextListFormat::ListDecimal;
            break;
        case 5:
            style = QTextListFormat::ListLowerAlpha;
            break;
        case 6:
            style = QTextListFormat::ListUpperAlpha;
            break;
        case 7:
            style = QTextListFormat::ListLowerRoman;
            break;
        case 8:
            style = QTextListFormat::ListUpperRoman;
            break;
        }

        cursor.beginEditBlock();

        QTextBlockFormat blockFmt = cursor.blockFormat();

        QTextListFormat listFmt;

        if (cursor.currentList()) {
            listFmt = cursor.currentList()->format();
        } else {
            listFmt.setIndent(blockFmt.indent() + 1);
            blockFmt.setIndent(0);
            cursor.setBlockFormat(blockFmt);
        }

        listFmt.setStyle(style);

        cursor.createList(listFmt);

        cursor.endEditBlock();
    } else {
        // ####
        QTextBlockFormat bfmt;
        bfmt.setObjectIndex(-1);
        cursor.mergeBlockFormat(bfmt);
    }
}
void TextEditor::mergeFormatOnWordOrSelection(const QTextCharFormat & format){
    QTextCursor cursor = textEdit->textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(format);
    textEdit->mergeCurrentCharFormat(format);
}

void TextEditor::fontChanged(const QFont &f)
{
    comboFont->setCurrentIndex(comboFont->findText(QFontInfo(f).family()));
    comboSize->setCurrentIndex(comboSize->findText(QString::number(f.pointSize())));
    btnBold->setChecked(f.bold());
    btnItalic->setChecked(f.italic());
    btnUnderline->setChecked(f.underline());
}

void TextEditor::colorChanged(const QColor &c)
{
    QPixmap pix(16, 16);
    pix.fill(c);
    //actionTextColor->setIcon(pix);
}

void TextEditor::alignmentChanged(Qt::Alignment a)
{
    if (a & Qt::AlignLeft)
        btnAlignLeft->setChecked(true);
    else if (a & Qt::AlignCenter)
        btnAlignCenter->setChecked(true);
    else if (a & Qt::AlignRight)
        btnAlignRight->setChecked(true);
    else if (a & Qt::AlignJustify)
        btnAlignJustify->setChecked(true);
}

void TextEditor::currentCharFormatChanged(const QTextCharFormat &format)
{
    fontChanged(format.font());
    colorChanged(format.foreground().color());
}

void TextEditor::cursorPositionChanged()
{
    alignmentChanged(textEdit->alignment());
}

void TextEditor::clipboardDataChanged()
{
#ifndef QT_NO_CLIPBOARD
    //if (const QMimeData *md = QApplication::clipboard()->mimeData())
    //actionPaste->setEnabled(md->hasText());
#endif
}


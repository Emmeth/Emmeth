/*********************************
 *
 * mainwindow.cpp
 *
 * (C) Benjamin Schnabel, 2016
 *
 * LGPL
 *
 * the main window class
 *
 **********************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "xmlreader.h"
#include "aboutDialog.h"
#include "texteditor.h"
#include "pdfreader.h"

#include <QMessageBox>
#include <QtCore>
#include <QString>
#include <QFileDialog>
#include <QDebug>
#include <QFileInfo>
#include <QImage>
#include <QScrollArea>
#include <QPalette>
#include <QLabel>
#include <QFile>
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
#include <QMdiArea>
#include <QMdiSubWindow>
#include <jsonparser.h>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPageSetupDialog>
#include <QtPrintSupport/QPrintPreviewDialog>
#include <QtPrintSupport/QtPrintSupport>
#include <QTextStream>
#include <QSplashScreen>
#include <QTimer>
#include <settingsdialog.h>
#include <logindialog.h>
#include <QDir>
#include <QAction>
#include <QTextEdit>

/**
 * @desc construtor
 * @brief MainWindow::MainWindow
 * @param parent
 */


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //constructor for the main window.
    //set a new mdiArea as central widget for the whole application.
    ui->setupUi(this);
    mdiArea = new QMdiArea(this);

    setCentralWidget(mdiArea);
    mdiArea->show();
    addBooksToMenuBar();

    //set additional information for the application.
    QApplication::setApplicationName("Emmeth");
    QApplication::setOrganizationDomain("emmeth.org");
    //QApplication::setOrganizationName("Emmeth"); //not needed for now, changes the libary path
    QApplication::setApplicationVersion("0.1");

    //set default shortcuts
    QShortcut *shortcutCopy = new QShortcut(QKeySequence("Ctrl+Ü"), this);
    QObject::connect(shortcutCopy, SIGNAL(activated()), this, SLOT(copy()));
}

/**
 * @desc destructor
 * @brief MainWindow::~MainWindow
 */


MainWindow::~MainWindow()
{
    //destroy the user interface.
    delete ui;
}

/**
 * @desc opens a file. First it loads the file dialog,
 * then it test the file for reading and finally opens it.
 *
 * @brief MainWindow::openFile
 */


void MainWindow::openFile()
{
    //opens a file
    QString fileName = openFileDialog();        //select the first file from the file dialog

    if(!fileName.isEmpty()){
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this,
                                  tr("Error"),
                                  tr("Could not open file"));
            return;
        }
        qDebug() << "Open:"  + fileName;
        loadFile(file.fileName(), 1);              //loads the file
        file.close();
    }
}

/**
 * @desc Opens a file Dialog to open just one single file.
 *
 * @brief MainWindow::openFileDialog
 * @return QString fileName
 */


QString MainWindow::openFileDialog(){
    //creates a file dialog to open files

    QFileDialog dialog(this);
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName = dialog.getOpenFileName(this,
                                              tr("Load file"),
                                              "../../",
                                              tr("Emmeth Files (*.emt);; XML Files (*.xml);;PDF Files (*.pdf);;TXT Files (*.txt);;HTML Files (*.htm *.html)"));

    if(!fileName.isEmpty()){
        return fileName;
    }else {
        //returns an error
        // TODO: no need for an errror, if the dialog is cancelled.

        QMessageBox messageBox;
        messageBox.critical(this,
                            tr("Error"),
                            tr("Could not open file"),
                            QMessageBox::Ok);
        messageBox.exec();

        //TODO: throw an execption and continue without drawing a new mdiArea
    return 0;
    }
}

/**
 * @desc Opens a file Dialog to open many files.
 *
 * @brief MainWindow::openFilesDialog
 * @return QStringList fileNames
 */

QStringList MainWindow::openFilesDialog(){
    //creates a file open dialog for many files
    QFileDialog dialog(this);
    QStringList fileNames = dialog.getOpenFileNames(this,
                                                    tr("Load files"),
                                                    "../../",
                                                    tr("Emmeth Files (*.emt);; XML Files (*.xml);; PDF Files (*.pdf);; TXT Files (*.txt);; HTML Files (*.html *.htm"));

    if(!fileNames.isEmpty()){
        return fileNames;
        //TODO: iterate through the filenames and open multiple mdiAreas

    }else{
        //TODO: throw an execption and continue without drawing a new mdiArea
        return QStringList("");
    }
}

/**
 * @desc saves a file
 * throws error on fail.
 *
 * @brief MainWindow::save
 * @param fileName
 * @return bool
 */

bool MainWindow::save(QString fileName)
{
    //saves a file

    if(fileSaveName.isEmpty())
        saveAs();               //calls opens save file dialog, if the name is empty.

    QFile file(fileName);
    try{
        file.open(QIODevice::WriteOnly);
        QDataStream out(&file);
        file.close();
        qDebug() << "File succesfull written";  //success
    }catch(...){
        qDebug() << "Error writing file";
        return false;                           //throws the error
    }

    //TODO: determine the file type

    //TODO: save according to type
    return true;
}

/**
 * @desc Save a file under a name.
 * creates a dialog.
 *
 * @brief MainWindow::saveAs
 * @return
 */

bool MainWindow::saveAs() {
    QString fileSaveName = QFileDialog::getSaveFileName(this,
                                                        tr("Save as"),
                                                        QString(),
                                                        tr("TXT files (*.txt);; RTF files (*.rtf);; ODT files (*.odt);;HTML Files (*.htm *.html);;All Files (*)"));

    if (fileSaveName.isEmpty())
        return false;                       //throw an exceoption if the file name is empty

    if (! (fileSaveName.endsWith(".txt", Qt::CaseInsensitive)
           || fileSaveName.endsWith(".rtf", Qt::CaseInsensitive)
           || fileSaveName.endsWith(".odt", Qt::CaseInsensitive)
           || fileSaveName.endsWith(".htm", Qt::CaseInsensitive)
           || fileSaveName.endsWith(".html", Qt::CaseInsensitive)) )

        fileSaveName += ".txt"; // default

    bool result = save(fileSaveName);       //saves the file
    return result;
}
/**
 * @desc opens the about window
 *
 * @brief MainWindow::about
 */

void MainWindow::about()
{
    //open the about dialog
    AboutDialog *aboutDialog = new AboutDialog(this);
      //XXX aboutDialog::open();
}


/**
 * @desc slot for the button to open a file
 *
 * @brief MainWindow::on_actionOpen_triggered
 */

void MainWindow::on_actionOpen_triggered()
{
    MainWindow::openFile();
}

/**
 * @desc loads a file
 * @brief MainWindow::loadFile
 * @param fileName
 */

void MainWindow::loadFile(QString fileName, bool newFile)
{
    //TODO @10/19/2017: load into temporary memory. Then display the current

    //get File ending info
    QFileInfo fi(fileName);
    QString base = fi.completeBaseName();       //file name without memory address
    QString ending = fi.completeSuffix();       //only ending of the file name
    //qDebug() << fi(fileName);
    qDebug() << "base: " + base;
    qDebug() << "ending: " + ending;

    // open according to the ending
    // TODO change to switch
    if(ending == "pdf"){    //load reader classes and render by the reader.
        //construct new window and menu for pdf
        addPdf(fileName);


    }

    /***************************************************
     * if the file is of type xml => load the xml parser
     *
     */

    if(ending == "xml"){
        // opening xml file
        // same as emmeth file (.emt)

        qDebug() << "reading xml file.";
        statusBar()->showMessage("opening document", 3000);
        qDebug() << fileName;
        //read the content and more
        xmlReader *reader = new xmlReader();
        QString result = reader->load(fileName);

        // If the file returns nothing,
        // don't continue.
        if(result != NULL){
            QStringList Verses = reader->readChapterVerses(fileName);
            bookName = reader->readBookTitle(fileName);

            // build UI
            //XXX if(newFile == true){
            createMdiArea(result);
            //XXX }

            // add book name, chapter and verses
            // exception handler for if bookname is not found.
            if(!bookName.isEmpty()){
                qDebug() << cmbBook->findText(bookName);
                cmbBook->setCurrentIndex(cmbBook->findText(bookName));
                //XXX cmbBook->addItem(bookName);
                for(int i = 1; i <= Verses.count(); i++){
                    cmbChapter->addItem(QString::number(i));
                }
                for(int i = 1; i <= Verses[0].toInt(); i++){
                    cmbVerse->addItem(QString::number(i));
                }
            }
        }else {
           QErrorMessage *errorMessage = new QErrorMessage(this);
           errorMessage->showMessage(QString("Could not open file"));
        }


    }

    if(ending == "txt"){
        //read a txt file

        qDebug() << "reading txt file";
        createMdiArea(fileName);

        //uses texteditor object
        //TODO: change the textedit
        //XXX texteditor text;
        //XXX QString content;
        //XXX content = text.read(fileName);
        //FIXME
        //TextEditor *textEditor =;
    }

    if((ending == "html")||(ending == "html")){

    }
}

/**
 * @desc  If the quit button is pressed
 * @brief MainWindow::on_actionQuit_triggered
 */

void MainWindow::on_actionQuit_triggered()
{
    //Todo: Check in the settings if the Dialog needs to be reopened.

    //add close Dialog
    QMessageBox *closeDialog = new QMessageBox(this);
    closeDialog->setIcon(QMessageBox::Question);
    closeDialog->setText(tr("Are you sure you want to close the application?"));
    QCheckBox *checkBox = new QCheckBox(tr("Remind me again."), this);
    checkBox->setCheckState(Qt::Checked);

    closeDialog->setCheckBox(checkBox);
    closeDialog->setStandardButtons(QMessageBox::Ok | QMessageBox::Abort);
    closeDialog->setDefaultButton(QMessageBox::Abort);
    int ret = closeDialog->exec();

    //Todo: check the checkbox.
    if (ret == QMessageBox::Ok){
        QApplication::closeAllWindows();
    }
}

/**
 * @desc  Closes all child dialogs
 * @brief MainWindow::closeEvent
 * @param event
 */

void MainWindow::closeEvent(QCloseEvent *event){
    //close all child Dialogs.
    QList<QDialog *> allDialogs = findChildren<QDialog *>();
    for(int i = 0; i < allDialogs.size(); ++i) {
        allDialogs.at(i)->close();
    }
}

/**
 * @desc  Display pdf Files in a scroll Area.
 * @brief MainWindow::imageLabel
 */

void MainWindow::imageLabel()
{   //uses imageLabel
    QLabel *imageLabel = new QLabel(this);
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    //adds a scroll area
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Base);
    scrollArea->setWidget(imageLabel);
    setCentralWidget(scrollArea);
}

/**
 * @desc If the about button is pressed.
 *
 * @brief MainWindow::on_actionAbout_triggered
 */

void MainWindow::on_actionAbout_triggered()
{
    MainWindow::about();
}

/**
 * @desc  used to display mdiArea
 *
 * @brief MainWindow::display
 * @param string
 */
void MainWindow::display(QString string){

    //TODO: delete
    createMdiArea("");

}

/**
 * @desc  create an MdiArea.
 * @brief MainWindow::createMdiArea
 * @param content
 */

void MainWindow::createMdiArea(QString content){
    //creates the MdiArea

    //Widget als central widget
    QWidget *widget = new QWidget();
    //create mdiSubWindow
    //XXX subWindow = new QMdiSubWindow(mdiArea);
    QWidget *subWindow = new QWidget(this);
    gridLayout = new QGridLayout();
    gridLayout->setColumnStretch(0,1);
    gridLayout->setOriginCorner(Qt::TopRightCorner);

    //create the search bar.
    createSearchArea();

    //create Textedit
    textEdit = new QTextEdit(subWindow);
    textEdit->setText(content);
    textEdit->setReadOnly(true);

    //TODO: set background color in the settings.
    //set background color
    QColor color;
    color.setRgb(236,240,241);
    QPalette palette = textEdit->palette();
    palette.setColor(QPalette::Base, color);
    textEdit->setPalette(palette);

    //create context menu
    textEdit->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(textEdit,
            SIGNAL(customContextMenuRequest(const QPoint&)),
            this,
            SLOT(showContextMenu(const QPoint &)));

    //Align scrollbar to the left for Hebrew
    textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QScrollBar* scrollBar = textEdit->verticalScrollBar();
    gridLayout->addWidget(scrollBar,1,1);

    //TODO: set font in the settings.
    QFont fontHebrew = QFont("SBL Hebrew");
    QFont fontGreek = QFont("SBL Greek");
    QFont fontLatin = QFont("Roboto");
    QFont fontArabic = QFont("Traditional Arabic");
    QFont fontSyriac = QFont("Estrangelo (V1.1) Standard");
    QString languageFamily; //FIXME: get the font from the settings.

    font.setPixelSize(20); //FIXME
    
    if(languageFamily == "hebrew"){
        textEdit->setFont(fontHebrew);
    }
    if(languageFamily == "greek"){
        textEdit->setFont(fontGreek);
    }
    if(languageFamily == "latin"){
        textEdit->setFont(fontLatin);
    }
    if(languageFamily == "arabic"){
        textEdit->setFont(fontArabic);
    }
    if(languageFamily == "syriac"){
        textEdit->setFont(fontSyriac);
    }


    //mdiSubWindow->setWindowTitle(fileName);
    subWindow->setWindowIcon(QIcon(":/appicon/assets/icons/24.png"));
    subWindow->setWindowState(Qt::WindowNoState);
    subWindow->setAttribute(Qt::WA_DeleteOnClose);
    //mdiSubWindow->setLayout();

    //XXX mdiArea->addSubWindow(subWindow);
    gridLayout->addWidget(textEdit,1,0);

    widget->setLayout(gridLayout);
    widget->setParent(this);
    widget->setMinimumSize(300,300);
    widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    widget->setWindowFlags(Qt::Window);
    widget->show();

    //XXX subWindow->setLayout(gridLayout);

    //XXX setCentralWidget(widget);
    //XXX subWindow->setMinimumSize(300,300);
    //XXX subWindow->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    
    
    //add copy and paste connectors
    connect(ui->actionCut, SIGNAL(triggered),this, SLOT(cut()));
    connect(ui->actionCopy, SIGNAL(triggered),this, SLOT(copy()));
    connect(ui->actionPaste, SIGNAL(triggered),this, SLOT(paste()));

    //XXX subWindow->show();

}

/**
 * @desc  Create a new search Area
 * Should run on default.
 * @brief MainWindow::createNewSearchArea
 */

void MainWindow::createSearchArea(){
    //creates the search bar on top of the mdiSubWindow
    //below there nees to the be the text edit

    QHBoxLayout *hBoxLayout = new QHBoxLayout();

    QPushButton *btnSearch = new QPushButton("&Search");
    btnSearch->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/find.png"));
    QComboBox *cmbSearch = new QComboBox();
    cmbSearch->setEditable(true);
    cmbSearch->setMinimumContentsLength(30);
    cmbBook = new QComboBox();
    cmbChapter = new QComboBox();
    cmbVerse = new QComboBox();

    cmbSearch->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLengthWithIcon);
    cmbBook->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    cmbChapter->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    cmbVerse->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    QSpacerItem *spacerItem = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    //hboxlayout
    hBoxLayout->addWidget(cmbSearch);
    hBoxLayout->addWidget(btnSearch);
    hBoxLayout->addWidget(cmbBook);
    hBoxLayout->addWidget(cmbChapter);
    hBoxLayout->addWidget(cmbVerse);
    hBoxLayout->addSpacerItem(spacerItem);

    gridLayout->addLayout(hBoxLayout,0,0);

    //add the book Names
    getBookNames();

    //add slots
    //FIXME: these slots are conditional and trigger an error on compiling.
    QObject::connect(cmbBook, SIGNAL(currentIndexChanged(int)), this, SLOT(bookNameChanged()));
    QObject::connect(cmbChapter, SIGNAL(currentIndexChanged(int)), this, SLOT(on_action_cmbChapter_triggered()));
    QObject::connect(cmbVerse, SIGNAL(currentIndexChanged(int)),this, SLOT(on_action_cmbVerse_triggered()));


}
/**
 * @desc Button for a new text file pressed.
 *
 * @brief MainWindow::on_actionNew_triggered
 */

void MainWindow::on_actionNew_triggered()
{
    fileNew();
}

/**
 * @desc Create a new file and set up the window.
 * @brief MainWindow::fileNew
 * @param type
 */

void MainWindow::fileNew() {
    //creates a new file in an mdiArea.
    //create new mdiSubWindow
    //Widget als central widget
    widget = new QWidget();

    //create mdiSubWindow
    mdiSubWindow = new QMdiSubWindow(mdiArea);

    mdiSubWindow->setWindowIcon(QIcon(":/faenza/mimetypes/24/assets/icons/faenza/mimetypes/24/application-text.png"));

    //add textedit
    TextEditor* textEdit = new TextEditor(this);

    //add to the mdisubwindow
    mdiSubWindow->setWidget(textEdit);

    //subwindow attributes
    mdiSubWindow->setWindowState(Qt::WindowNoState);
    mdiSubWindow->setAttribute(Qt::WA_DeleteOnClose);
    mdiSubWindow->setMinimumSize(300,300);

    mdiArea->addSubWindow(mdiSubWindow);
    mdiSubWindow->show();
}

/**
 * @desc Print button pressed.
 * @brief MainWindow::on_actionPrint_triggered
 */
void MainWindow::on_actionPrint_triggered(){
    //TODO: print
}
/**
 * @desc Print file method
 * @brief MainWindow::printFile
 */
void MainWindow::printFile(){
    //TODO: Finish printing file
}

/**
 * @desc Preview print file.
 * @brief MainWindow::filePrintPreview
 */
void MainWindow::filePrintPreview(){
    //TODO: finish
}

/**
 * @desc Print preview.
 * @brief MainWindow::printPreview
 */
void MainWindow::printPreview(){
    //TODO: finish
}

/**
 * @desc Print a pdf file.
 * @brief MainWindow::filePrintPdf
 */
void MainWindow::filePrintPdf(){
    //TODO: finish
}

/**
 * @desc Settings button pressed.
 * @brief MainWindow::on_action_Settings_triggered
 */
void MainWindow::on_action_Settings_triggered()
{
    MainWindow::settings();
}

/**
 * @desc Open settings dialog.
 * @brief MainWindow::settings
 */
void MainWindow::settings()
{
    SettingsDialog *settings = new SettingsDialog(this);
    //settings->show();
}

/**
 * @desc Splash screen.
 * @brief MainWindow::splashscreen
 */
void MainWindow::splashscreen() {
    QSplashScreen *splashScreen = new QSplashScreen();
    QPixmap pixmap(":/assets/splashscreen.jpg");
    splashScreen->setPixmap(pixmap);
    splashScreen->show();

    QTimer::singleShot(2500, splashScreen, SLOT(close()));
}
/**
 * @desc
 * @brief MainWindow::on_actionLogin_triggered
 */
void MainWindow::on_actionLogin_triggered()
{
    loginDialogShow();
}

/**
 * @desc Creates the login dialog.
 * @brief MainWindow::loginDialogShow
 */
void MainWindow::loginDialogShow(){
    loginDialog *login = new loginDialog(this);
}

/**
 * @desc Displays an info about the book.
 * @brief MainWindow::bookInfo
 */
void MainWindow::bookInfo(){
    QDialog *bookInfo = new QDialog();

    //QLabel *label = new QLabel();
    xmlReader *reader = new xmlReader();

    //FIXME: OsX, Win, Linux
    QString result = reader->loadInfo(QCoreApplication::applicationDirPath() + "\\library\\bibles\\tanach-xml\\Genesis.xml");
    //label->setText(result);

    textEdit->setText(result);
    qDebug() << result;

    gridLayout = new QGridLayout();
    QPushButton *btnClose = new QPushButton();
    btnClose->setText(tr("&Close"));

    gridLayout->addWidget(textEdit);
    gridLayout->addWidget(btnClose);

    bookInfo->setLayout(gridLayout);
    bookInfo->setMinimumSize(200,200);
    bookInfo->setWindowTitle("Book Info");
    bookInfo->setWindowIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/gtk-info.png"));
    bookInfo->show();
    bookInfo->raise();
    QObject::connect(btnClose, SIGNAL(clicked(bool)),bookInfo, SLOT(close()));

}

void MainWindow::on_actionAbout_Book_triggered()
{
    bookInfo();
}

void MainWindow::on_action_Fullscreen_triggered()
{

    if(!QMainWindow::isFullScreen()){
        showFullScreen();
        ui->action_Fullscreen->setText("Exit &Fullscreen");
    }else{
        showNormal();
        ui->action_Fullscreen->setText("&Fullscreen");
    }
}

void MainWindow::on_action_Cascade_triggered()
{
    mdiArea->cascadeSubWindows();
}

void MainWindow::on_action_Tile_triggered()
{
    mdiArea->tileSubWindows();
}

void MainWindow::on_actionZoomIn_triggered()
{
    QFont font = textEdit->font();
    int size = font.pointSize();
    qDebug() << size;
    font.setPointSize(size++);
    textEdit->setFont(font);
}

void MainWindow::on_actionZoomOut_triggered()
{
    QFont font = textEdit->font();
    int size = font.pointSize();
    qDebug() << size;
    size = size-1;
    if(size <= 8){
        size = 8;
    }
    font.setPointSize(size);
    textEdit->setFont(font);
}

void MainWindow::on_actionZoomOriginal_triggered()
{
    QFont font = textEdit->font();
    font.setPointSize(12);
    textEdit->setFont(font);
}

void MainWindow::getBookNames()
{   // adds the names of the bible books
    //for WLC first
    //TODO: what if the text does not contain all the bible books, like the WLC?

    QStringList bookNames = (QStringList()
                             << "Genesis"
                             << "Exodus"
                             << "Leviticus"
                             << "Numbers"
                             << "Deuteronomy"
                             << "Joshua"
                             << "Judges"
                             << "Ruth"
                             << "1 Samuel"
                             << "2 Samuel"
                             << "1 Kings"
                             << "2 Kings"
                             << "1 Chronicles"
                             << "2 Chronicles"
                             << "Ezra"
                             << "Nehemiah"
                             << "Esther"
                             << "Job"
                             << "Psalms"
                             << "Proverbs"
                             << "Ecclesiastes"
                             << "Song of Solomon"
                             << "Isaiah"
                             << "Jeremiah"
                             << "Lamentations"
                             << "Ezekiel"
                             << "Daniel"
                             << "Hosea"
                             << "Joel"
                             << "Amos"
                             << "Obadiah"
                             << "Jonah"
                             << "Micah"
                             << "Nahum"
                             << "Habakkuk"
                             << "Zephaniah"
                             << "Haggai"
                             << "Zechariah"
                             << "Malachi");

    cmbBook->insertItems(0, bookNames);
}

void MainWindow::bookNameChanged(){
    if(cmbBook->currentText()!= bookName){
        qDebug() << "Book Index Changed: " + cmbBook->currentText();
        qDebug() << "Book name:" + bookName;
        changeBook();
    }
}

void MainWindow::changeBook(){
    //define path, used with
    QStringList path = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation);
    bookName = cmbBook->currentText();
    //check if number is at the beginning.
    if(!bookName.isEmpty()){
        if(bookName.at(1) == ("1" || "2")){
            QString number = bookName.at(1);
            bookName.remove(0,2);
            bookName.append(" ");
            bookName.append(number);
        }
        bookName.replace(" ", "_");
        bookName.append(".xml");
        //open file at in the right directory
        qDebug() << "Path: " << path.first();
        QString libraryPath = path.first();
        libraryPath.append("\\library\\bibles\\tanach-xml\\");
        QDir pathLibrary = libraryPath;
        qDebug() << "libraryPath:" << libraryPath;
        if(pathLibrary.exists())
        {
            //ApplicationPath/library/bibles/Translation/Name[_Number].xml
            //FIXME: deactivated for testing
            QString fileName = QString(libraryPath);
            fileName.append(bookName);
            loadFile(fileName);
        }else{
            qDebug() << "Cannot open path: " + QString(pathLibrary.path());
        }
    }else{
        qDebug() << "Error reading book name.";
    }
}

void MainWindow::on_actionScripts_triggered()
{
    createScriptingBox();
}

void MainWindow::createScriptingBox(){
    //panel belwo with input for scripts
    //TODO: Change Layout
    QDockWidget *dockWidget = new QDockWidget(tr("Scripting"));
    dockWidget->setAllowedAreas(Qt::BottomDockWidgetArea);

    gridLayout = new QGridLayout();
    QTextEdit *resultArea = new QTextEdit();
    resultArea->setReadOnly(true);
    QTextEdit *inputArea = new QTextEdit();
    QPushButton *runButton = new QPushButton(tr("Execute"));
    gridLayout->addWidget(resultArea,0,0);
    gridLayout->addWidget(inputArea,1,0);
    gridLayout->addWidget(runButton,1,1);

    dockWidget->setLayout(gridLayout);
    dockWidget->setWidget(resultArea);
    dockWidget->setWidget(inputArea);
    addDockWidget(Qt::BottomDockWidgetArea,dockWidget);
}

void MainWindow::on_actionWLC_triggered()
{
    openBookMenu();
}

void MainWindow::openBookMenu(){
    //TODO: readFolder and Genesis file

}

void MainWindow::on_action_cmbChapter_triggered(){
    //TODO: highlight it for 1 sec.
    changeChapter();
}

void MainWindow::on_action_cmbVerse_triggered(){
    //TODO: highlight it for 1 sec.
    changeVerse();
}

void MainWindow::changeChapter(){
    //changes the chapter
    qDebug() << "Chapter index changed: " << cmbChapter->currentText();
    textEdit->moveCursor(QTextCursor::Start);
    QString text = "ch_" + cmbChapter->currentText();
    qDebug() << "Chapter text: " << text;
    textEdit->scrollToAnchor(text);
}

void MainWindow::changeVerse(){
    //changes the verse

    //FIXME: jumps back to chapter 1
    qDebug() << "Verse index changed: " << cmbVerse->currentText();
    textEdit->moveCursor(QTextCursor::Start);
    QString text = "c" + cmbChapter->currentText() + "_v" + cmbVerse->currentText();
    qDebug() << "Verse Text: " << text;
    textEdit->scrollToAnchor(text);
}

void MainWindow::textScrolled(){
    //calles when the the text is scrolled to update the book chapter and verses.

}

void MainWindow::addBooksToMenuBar(){
    //add book to the menu Bar
    //ToDO load lists from the downloaded book
    //Create multideimensional array for the content
    QStringList Categories;
    Categories << "Bibles" << "Dictionaries" << "Lexicas" << "Maps" << "Other";
    QStringList Languages;
    Languages << "English" << "Hebrew" << "German" << "Greek" << "French" << "Spanish" << "Arabic";
    Languages.sort();
    QStringList hebrewBibles;
    hebrewBibles << "Westminster Leningrad Codex" << "Aleppo Codex" << "BHS" << "Masoretic Text";
    hebrewBibles.sort();
    QStringList englishBibles;
    englishBibles << "King James" << "NIV" << "ESV";
    englishBibles.sort();
    QStringList germanBibles;
    germanBibles << "Luther 1912" << "Elberfelder" << "Buber-Rosenzweig" << "Hoffnung für alle" << "NGÜ" << "Schlacher 2000";
    //germanBibles.sort();
    QStringList greekBibles;
    greekBibles << "NA 28";
    greekBibles.sort();

    QMenu *menuLibrary;
    QMenu *menuBibles = new QMenu(tr("&Bibles"),this);
    QMenu *menuDictionaries = new QMenu(tr("&Dictionaries"),this);
    QMenu *menuLexicas = new QMenu(tr("&Lexicas"),this);
    QMenu *menuOther = new QMenu(tr("&Other"),this);

    menuLibrary = new QMenu(tr("&Library"), this);

    menuBar()->insertMenu(ui->menuTools->menuAction(), menuLibrary);
    menuLibrary->addMenu(menuBibles);
    menuLibrary->addMenu(menuDictionaries);
    menuLibrary->addMenu(menuLexicas);
    menuLibrary->addMenu(menuOther);

    QAction* wlc = new QAction("WLC",this);
    menuBibles->addAction(wlc);

    QAction* sblgnt = new QAction("SBLGNT",this);
    menuBibles->addAction(sblgnt);

    //connect signals.
    QSignalMapper* signalMapper = new QSignalMapper(this);

    connect(wlc, SIGNAL(triggered(bool)), signalMapper, SLOT(map()));
    connect(sblgnt, SIGNAL(triggered(bool)), signalMapper, SLOT(map()));

    signalMapper->setMapping(wlc, "wlc");
    signalMapper->setMapping(sblgnt, "sblgnt");
    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(defaultBook(QString)));

    //TODO: dynamically add bibles from the library
    //menuBibles->addActions(germanBibles);
    QListIterator<QString>i(Languages);
    while(i.hasNext()){
        QMenu *newMenu = new QMenu(QString(i.next()),menuBibles);
        menuBibles->addMenu(newMenu);
    }

    //XXX
    //QListIterator<QString>j (germanBibles);
    //while(i.hasNext()){
    //    QAction *newAction = new QAction(QString(j.next()), newMenu);
    //    newMenu->addAction(newAction);
    //}

    //TODO: add a connector to each slot
    //XXX QList<QAction*> actions = newMenu->actions();
    //XXX qDebug() << actions;

}

void MainWindow::defaultBook(QString book){
    //default books from the Main Menu

    //get standart paths, different on each platfrom.
    //FIXME: check platforms and include files on install
    //XXX QString path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);

    //FIXME: for development purposes only.
    QString path = QCoreApplication::applicationDirPath()+("/../../../../..");
    if(book == "wlc"){
        path.append("/library/bibles/tanach-xml/Genesis.xml");
    }
    if(book == "sblgnt"){
        path.append("/library/bibles/SBLGNTxml/sblgnt.xml");
    }
    if(!path.isEmpty()){
        qDebug() << "path:" << path;

        //load the File
        loadFile(path, true);
    }
}

void MainWindow::addPdf(QString fileName){
    //creates a window for display pdf files
    fileNew();

    //add pdf relevant icons
    gridLayout = new QGridLayout();
    QSpacerItem *spacerItem;

    //editor icons
    hBoxLayoutTextedit = new QHBoxLayout(); //new HBoxLayout for Pushbuttons

    //Search input
    QLineEdit *lineEditSearch = new QLineEdit();

    //Serch button
    QPushButton *btnSearch = new QPushButton();
    btnSearch->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/find.png"));
    btnSearch->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    //divider

    //begin button
    QPushButton *btnBegin = new QPushButton();
    btnBegin->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/go-top.png"));
    btnBegin->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    //end button
    QPushButton *btnEnd = new QPushButton();
    btnEnd->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/go-bottom.png"));
    btnEnd->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    //page up
    QPushButton *btnUp = new QPushButton();
    btnUp->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/go-up.png"));
    btnUp->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    //page down
    QPushButton *btnDown = new QPushButton();
    btnDown->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/go-down.png"));
    btnDown->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    //page input
    QLineEdit *lineEditPage = new QLineEdit();

    //TODO: sidebar with bookmarks

    //add buttons to menu
    hBoxLayoutTextedit->addWidget(lineEditSearch);
    hBoxLayoutTextedit->addWidget(btnSearch);
    hBoxLayoutTextedit->addSpacerItem(spacerItem);
    hBoxLayoutTextedit->addWidget(btnBegin);
    hBoxLayoutTextedit->addWidget(btnUp);
    hBoxLayoutTextedit->addWidget(lineEditPage);
    hBoxLayoutTextedit->addWidget(btnDown);
    hBoxLayoutTextedit->addWidget(btnEnd);

    //add all hBoxlayouts to gridlayout
    gridLayout->addLayout(hBoxLayoutTextedit,0,0);


    //Widget als central widget
    widget = new QWidget();
    widget->setLayout(gridLayout);
    //widget->setLayout()

    //TODO: load pdf
    pdfReader* reader = new pdfReader();
    reader->load(fileName);

}


void MainWindow::on_action_New_triggered()
{
    //trigger from
    fileNew();
}

void MainWindow::cut(){
    textEdit->cut();
}

void MainWindow::copy(){
    textEdit->copy();
}

void MainWindow::paste(){
    //TODO
}

void MainWindow::showContextMenu(const QPoint &pt){
    QMenu *contextMenu = textEdit->createStandardContextMenu();
    contextMenu->addAction("clear");
    contextMenu->exec(textEdit->mapToGlobal(pt));
    //textEdit->setContextMenuPolicy(Qt::CustomContextMenu);
    delete contextMenu;
}


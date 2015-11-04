#include "mainwindow.h"
#include "ui_mainwindow.h"
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

#include "xmlreader.h"
#include "aboutDialog.h"
#include "txteditor.h"
//#include "pdfreader.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QMdiArea *mdiArea = new QMdiArea(this);

    setCentralWidget(mdiArea);
    mdiArea->show();
    addBooksToMenuBar();

    QApplication::setApplicationName("Emmeth");
    QApplication::setOrganizationDomain("emmeth.org");
    QApplication::setOrganizationName("Emmeth");
    QApplication::setApplicationVersion("0.1");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Load file"), "../../", tr("Emmeth Files (*.emt);; XML Files (*.xml);; PDF Files (*.pdf);; TXT Files (*.txt)"));

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

bool MainWindow::save(QString fileName)
{
    //saves a file
    if(fileSaveName.isEmpty())
        saveAs(); //open file dialog

    QFile file(fileName);
    try{
        file.open(QIODevice::WriteOnly);
        QDataStream out(&file);
        file.close();
        qDebug() << "File succesfull written";
    }catch(...){
        qDebug() << "Error writing file";
        return false;
    }

    //determine the file type

    //save according to type
    return true;
}

bool MainWindow::saveAs() {
    QString fileSaveName = QFileDialog::getSaveFileName(this,tr("Save as"), QString(), tr("TXT files (*.txt);; RTF files (*.rtf);; ODT files (*.odt);;HTML-Files (*.htm *.html);;All Files (*)"));
    if (fileSaveName.isEmpty())
        return false;
    if (! (fileSaveName.endsWith(".txt", Qt::CaseInsensitive) ||fileSaveName.endsWith(".rtf", Qt::CaseInsensitive) || fileSaveName.endsWith(".odt", Qt::CaseInsensitive) || fileSaveName.endsWith(".htm", Qt::CaseInsensitive) || fileSaveName.endsWith(".html", Qt::CaseInsensitive)) )
        fileSaveName += ".txt"; // default

    bool result = save(fileSaveName);
    return result;
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
        //opening xml file
        qDebug() << "reading xml file.";
        statusBar()->showMessage("opening document", 3000);
        qDebug() << fileName.fileName();
        //read the content and more
        xmlReader *reader = new xmlReader();
        QString result = reader->load(fileName.fileName());
        QStringList Verses = reader->readChapterVerses(fileName.fileName());
        QString bookName = reader->readBookTitle(fileName.fileName());

        //build UI
        createMdiArea(result);
        MainWindow::getBookNames();

        //add book name, chapter and verses
        qDebug() << cmbBook->findText(bookName);
        cmbBook->setCurrentIndex(cmbBook->findText(bookName));
        //cmbBook->addItem(bookName);
        for(int i = 1; i <= Verses.count(); i++){
            cmbChapter->addItem(QString::number(i));
        }
        for(int i = 1; i <= Verses[0].toInt(); i++){
            cmbVerse->addItem(QString::number(i));
        }

    }

    if(ending == "txt"){
        qDebug() << "reading txt file";

        //TODO: change the textedit
        txteditor text;
        QString content;
        content = text.read(fileName.fileName());
        txteditor *txtEditor = new txteditor();
        txtEditor->display(content);
        createMdiArea(fileName.fileName());
    }
}

void MainWindow::on_actionQuit_triggered()
{
    this->close();

    QList<QDialog *> allDialogs = findChildren<QDialog *>();
    for(int i = 0; i < allDialogs.size(); ++i) {
        allDialogs.at(i)->close();
    }
}
void MainWindow::closeEvent(QCloseEvent *event){
    QList<QDialog *> allDialogs = findChildren<QDialog *>();
    for(int i = 0; i < allDialogs.size(); ++i) {
        allDialogs.at(i)->close();
    }
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

    //TODO: add MdiArea
    createMdiArea("");

}
void MainWindow::createMdiArea(QString content){
    //Widget als central widget
    QWidget *widget = new QWidget();
    //create mdiSubWindow
    QMdiSubWindow *mdiSubWindow = new QMdiSubWindow(mdiArea);
    //QGridLayout *gridLayout = new QGridLayout();
    //create the search bar.
    createNewSearchArea();

    //create Textedit
    //QTextEdit *textEdit = new QTextEdit(mdiSubWindow);
    textEdit->setText(content);
    textEdit->setReadOnly(true);
    QFont font = QFont("SBL Hebrew");
    font.setPointSize(12);
    textEdit->setFont(font);




    //mdiSubWindow->setWindowTitle(fileName);
    mdiSubWindow->setWindowIcon(QIcon(":/faenza/mimetypes/24/assets/icons/faenza/mimetypes/24/application-text.png"));
    mdiSubWindow->setWindowState(Qt::WindowNoState);
    mdiSubWindow->setAttribute(Qt::WA_DeleteOnClose);
    //mdiSubWindow->setLayout(gridLayout);

    mdiArea->addSubWindow(mdiSubWindow);
    widget->setLayout(gridLayout);
    gridLayout->addWidget(textEdit);
    //widget->setLayout(gridLayout);
    mdiSubWindow->setWidget(widget);
    mdiSubWindow->setMinimumSize(300,300);

    mdiSubWindow->show();


    //widget->setLayout(gridLayout);
    //mdiSubWindow->setWidget(widget); //add to the mdiArea


}

void MainWindow::createNewSearchArea(){
    QHBoxLayout *hBoxLayout = new QHBoxLayout();

    QPushButton *btnSearch = new QPushButton("&Search");
    btnSearch->setIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/find.png"));
    QComboBox *cmbSearch = new QComboBox();
    cmbSearch->setEditable(true);
    cmbSearch->setMinimumContentsLength(30);
    //QComboBox *cmbBook = new QComboBox();
    //QComboBox *cmbChapter = new QComboBox();
    //QComboBox *cmbVerse = new QComboBox();
    QSpacerItem *spacerItem = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    //hboxlayout
    hBoxLayout->addWidget(cmbSearch);
    hBoxLayout->addWidget(btnSearch);
    hBoxLayout->addWidget(cmbBook);
    hBoxLayout->addWidget(cmbChapter);
    hBoxLayout->addWidget(cmbVerse);
    hBoxLayout->addSpacerItem(spacerItem);
    gridLayout->addLayout(hBoxLayout,0,0);

    //add slots
        //connect(cmbBook, SIGNAL(currentIndexChanged(int)), this, SLOT(bookNameChanged()));
        connect(cmbChapter, SIGNAL(currentIndexChanged(int)), this, SLOT(on_action_cmbChapter_triggered()));
        connect(cmbVerse, SIGNAL(currentIndexChanged(int)),this, SLOT(on_action_cmbVerse_triggered()));

}

void MainWindow::on_actionNew_triggered()
{
    fileNew();
}

void MainWindow::fileNew() {
    //create new mdiWindow//Widget als central widget
    QWidget *widget = new QWidget();
    //create mdiSubWindow
    QMdiSubWindow *mdiSubWindow = new QMdiSubWindow(mdiArea);
    //QGridLayout *gridLayout = new QGridLayout();
    //create the search bar.
    //mdiSubWindow->setWindowTitle(fileName);
    mdiSubWindow->setWindowIcon(QIcon(":/faenza/mimetypes/24/assets/icons/faenza/mimetypes/24/application-text.png"));
    mdiSubWindow->setWindowState(Qt::WindowNoState);
    mdiSubWindow->setAttribute(Qt::WA_DeleteOnClose);
    //mdiSubWindow->setLayout(gridLayout);

    mdiArea->addSubWindow(mdiSubWindow);
    //widget->setLayout(gridLayout);
    mdiSubWindow->setWidget(widget);
    mdiSubWindow->setMinimumSize(300,300);

    mdiSubWindow->show();
    //add textedit
    //txteditor *txtEditor = new txteditor();
    //txtEditor->display(QString(""));


}


void MainWindow::on_actionPrint_triggered()
{

}

void MainWindow::printFile(){
    //TODO: Finish printing file
}

void MainWindow::filePrintPreview(){

}

void MainWindow::printPreview(){

}

void MainWindow::filePrintPdf()
{

}

void MainWindow::on_action_Settings_triggered()
{
    MainWindow::settings();
}

void MainWindow::settings()
{
    settingsdialog *settings = new settingsdialog(this);
}

void MainWindow::splashscreen() {
    QSplashScreen *splashScreen = new QSplashScreen();
    QPixmap pixmap(":/assets/splashscreen.jpg");
    splashScreen->setPixmap(pixmap);
    splashScreen->show();

    QTimer::singleShot(2500, splashScreen, SLOT(close()));
}

void MainWindow::on_actionLogin_triggered()
{
    loginDialogShow();
}

void MainWindow::loginDialogShow(){
    loginDialog *login = new loginDialog(this);
}

void MainWindow::bookInfo(){
    QDialog *bookInfo = new QDialog();

    //QLabel *label = new QLabel();
    xmlReader *reader = new xmlReader();

    QString result = reader->loadInfo("C:\\Users\\Benni\\Programmierung\\Emmeth\\library\\bibles\\tanach-xml\\Amos.xml");
    //label->setText(result);

    textEdit->setText(result);
    qDebug() << result;

    QGridLayout *gridLayout = new QGridLayout();
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
    connect(btnClose, SIGNAL(clicked(bool)),bookInfo, SLOT(close()));

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
    font.setPointSize(size+1);
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
{ //TODO: fix loading
    //for WLC first
    QStringList bookNames;
    bookNames << "Genesis"
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
              << "Malachi";
    cmbBook->addItems(bookNames);
    //connect(cmbBook, SIGNAL(currentIndexChanged(int)), this, SLOT(bookNameChanged()));
}

void MainWindow::bookNameChanged(){
    changeBook();
}

void MainWindow::changeBook(){
    QString bookName = cmbBook->currentText();
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
        libraryPath.append("/library/bibles/tanach-xml/");
        QDir pathLibrary = libraryPath;
        qDebug() << "libraryPath:" << libraryPath;
        if(pathLibrary.exists())
        {
            //ApplicationPath/library/bibles/Translation/Name[_Number].xml
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
    //TODO: Change Layout
    QDockWidget *dockWidget = new QDockWidget(tr("Scripting"));
    dockWidget->setAllowedAreas(Qt::BottomDockWidgetArea);

    QGridLayout *gridLayout = new QGridLayout();
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
    //TODO: connect SLOT, scroll to the chapter, highlight it for 1 sec.
    findChapter();
}

void MainWindow::on_action_cmbVerse_triggered(){
    //TODO: connect SLOT, scroll to the verse, highlight it for 1 sec.
}

void MainWindow::findChapter(){
    textEdit->moveCursor(QTextCursor::Start);
    QString text = "<a><h1 dir=\"rtl\" style=\"color:blue\">" + cmbChapter->currentText();
    qDebug() << "text: " << text;
    textEdit->find(text);
}

void MainWindow::addBooksToMenuBar(){
    //add book to the menu Bar
    //ToDO load lists from the downloaded book
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
    germanBibles.sort();
    QStringList greekBibles;
    greekBibles << "NA 28";
    greekBibles.sort();

    QMenu *MainMenu;
    QAction *ActionBibles = new QAction(tr("Bibles"),this);
    QAction *ActionDictionaries = new QAction(tr("Dictionaries"),this);
    QAction *ActionLexicas = new QAction(tr("Lexicas"),this);
    QAction *ActionOther = new QAction(tr("Other"),this);

    QAction *ActionHebrew = new QAction(tr("Hebrew"),this);
    QAction *ActionEnglish = new QAction(tr("English"),this);

    MainMenu = menuBar()->addMenu("Books");
    MainMenu->addAction(ActionBibles);
    MainMenu->addAction(ActionDictionaries);
    MainMenu->addAction(ActionLexicas);
    MainMenu->addAction(ActionOther);

    QListIterator<QString>i(Languages);
    while(i.hasNext()){
          QAction *newAction = new QAction(QString(i.next()),ActionBibles);
          MainMenu->addAction(newAction);
         //ActionBibles->children(Languages);
    }
    //Todo add a connector to each slot

}

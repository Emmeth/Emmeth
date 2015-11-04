#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QImage>
#include <QScrollArea>
#include <QString>
#include <QTextEdit>
#include <QMdiArea>
#include <QGridLayout>
#include <QComboBox>
#include <QStandardPaths>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void splashscreen();

private slots:
    void on_actionOpen_triggered();
    void about();
    void open();
    void settings();
    void on_actionQuit_triggered();
    void on_actionAbout_triggered();
    void on_actionNew_triggered();
    void on_actionPrint_triggered();
    void on_action_Settings_triggered();
    void on_actionLogin_triggered();
    void on_actionAbout_Book_triggered();
    void on_action_Fullscreen_triggered();
    void on_action_Cascade_triggered();
    void on_action_Tile_triggered();
    void on_actionZoomIn_triggered();
    void on_actionZoomOut_triggered();
    void on_actionZoomOriginal_triggered();
    void on_actionScripts_triggered();
    void bookNameChanged();
    void on_actionWLC_triggered();

    void on_action_cmbVerse_triggered();
    void on_action_cmbChapter_triggered();
private:
    Ui::MainWindow *ui;
    QString fileName;
    //QImage pdfImage;
    QScrollArea *scrollArea;
    QString fileSaveName;
    QMdiArea *mdiArea = new QMdiArea();
    QGridLayout *gridLayout = new QGridLayout();
    QComboBox *cmbBook = new QComboBox();
    QComboBox *cmbChapter = new QComboBox();
    QComboBox *cmbVerse = new QComboBox();
    QTextEdit *textEdit = new QTextEdit();
    QString book;
    QString library;
    QString libraryDirectory;
    QString chapter;
    QString verse;
    const QStringList path = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation);

    void loadFile(QFile fileName);
    void imageLabel();
    void display(QString string);
    void fileNew();
    bool save(QString fileName);
    bool saveAs();
    void printFile();
    void printPreview();
    void filePrintPdf();
    void createMdiArea(QString content);
    void filePrintPreview();
    void closeEvent(QCloseEvent *event);
    void loginDialogShow();
    void bookInfo();
    void createNewSearchArea();
    void getBookNames();
    void createScriptingBox();
    void changeBook();
    void openBookMenu();
    void findChapter();
    void addBooksToMenuBar();
};

#endif // MAINWINDOW_H

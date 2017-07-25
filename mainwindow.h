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
#include <QWidget>
#include <QMdiSubWindow>

namespace Ui {
class MainWindow;
}

/**
 * @brief
 *
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param parent
     */
    explicit MainWindow(QWidget *parent = 0);
    /**
     * @brief
     *
     */
    ~MainWindow();
    /**
     * @brief
     *
     */
    void splashscreen();
    /**
     * @brief
     *
     * @param fileName
     */
    void loadFile(QString fileName, bool newFile = false);

   QMdiSubWindow *mdiSubWindow; /** Subwindow for the Multiwindows */
private slots:
    /**
     * @brief
     *
     */
    void on_actionOpen_triggered();
    /**
     * @brief
     *
     */
    void about();
    /**
     * @brief
     *
     */
    void openFile();
    /**
     * @brief
     *
     */
    void settings();
    /**
     * @brief
     *
     */
    void on_actionQuit_triggered();
    /**
     * @brief
     *
     */
    void on_actionAbout_triggered();
    /**
     * @brief
     *
     */
    void on_actionNew_triggered();
    /**
     * @brief
     *
     */
    void on_actionPrint_triggered();
    /**
     * @brief
     *
     */
    void on_action_Settings_triggered();
    /**
     * @brief
     *
     */
    void on_actionLogin_triggered();
    /**
     * @brief
     *
     */
    void on_actionAbout_Book_triggered();
    /**
     * @brief
     *
     */
    void on_action_Fullscreen_triggered();
    /**
     * @brief
     *
     */
    void on_action_Cascade_triggered();
    /**
     * @brief
     *
     */
    void on_action_Tile_triggered();
    /**
     * @brief
     *
     */
    void on_actionZoomIn_triggered();
    /**
     * @brief
     *
     */
    void on_actionZoomOut_triggered();
    /**
     * @brief
     *
     */
    void on_actionZoomOriginal_triggered();
    /**
     * @brief
     *
     */
    void on_actionScripts_triggered();
    /**
     * @brief
     *
     */
    void bookNameChanged();
    /**
     * @brief
     *
     */
    void on_actionWLC_triggered();
    /**
     * @brief
     *
     */
    void on_action_cmbVerse_triggered();
    /**
     * @brief
     *
     */
    void on_action_cmbChapter_triggered();
    /**
     * @brief
     *
     */
    void on_action_New_triggered();
    void defaultBook(QString book);

    void cut();
    void copy();
    void paste();
private:
    Ui::MainWindow *ui; /**< TODO: describe */
    //QImage pdfImage;
    QScrollArea *scrollArea; /**< TODO: describe */
    QString fileSaveName; /** The name of the file to be saved. */
    QMdiArea *mdiArea; /**< TODO: describe */
    QGridLayout *gridLayout; /**< TODO: describe */
    QComboBox *cmbBook; /**< TODO: describe */
    QComboBox *cmbChapter; /**< TODO: describe */
    QComboBox *cmbVerse; /**< TODO: describe */
    QTextEdit *textEdit; /**< TODO: describe */
    QString book; /**< TODO: describe */
    QString library; /**< TODO: describe */
    QString libraryDirectory; /**< TODO: describe */
    QString chapter; /**< TODO: describe */
    QString verse; /**< TODO: describe */
    QWidget *widget; /**< TODO: describe */
    QHBoxLayout *hBoxLayoutTextedit; /**< TODO: describe */
    QFile file; /**< TODO: describe */
    QString fileName; /** The name of the file to be loaded. */
    QString bookName;
    QFont font; /* Main font */

    /**
     * @brief
     *
     */
    void imageLabel();
    /**
     * @brief
     *
     * @param string
     */
    void display(QString string);
    /**
     * @brief
     *
     * @param type
     */
    void fileNew();
    /**
     * @brief
     *
     * @param fileName
     * @return bool
     */
    bool save(QString fileName);
    /**
     * @brief
     *
     * @return bool
     */
    bool saveAs();
    /**
     * @brief
     *
     */
    void printFile();
    /**
     * @brief
     *
     */
    void printPreview();
    /**
     * @brief
     *
     */
    void filePrintPdf();
    /**
     * @brief
     *
     * @param content
     */
    void createMdiArea(QString content);
    /**
     * @brief
     *
     */
    void filePrintPreview();
    /**
     * @brief
     *
     * @param event
     */
    void closeEvent(QCloseEvent *event);
    /**
     * @brief
     *
     */
    void loginDialogShow();
    /**
     * @brief
     *
     */
    void bookInfo();
    /**
     * @brief
     *
     */
    void createSearchArea();
    /**
     * @brief
     *
     */
    void getBookNames();
    /**
     * @brief
     *
     */
    void createScriptingBox();
    /**
     * @brief
     *
     */
    void changeBook();
    /**
     * @brief
     *
     */
    void openBookMenu();
    /**
     * @brief
     *
     */
    void changeChapter();
    /**
     * @brief
     *
     */
    void addBooksToMenuBar();
    /**
     * @brief
     *
     * @param fileName
     */
    void addPdf(QString fileName);
    /**
     * @brief
     *
     * @return QString
     */
    QString openFileDialog();
    /**
     * @brief
     *
     * @return QStringList
     */
    QStringList openFilesDialog();
    void changeVerse();
    void textScrolled();
    void showContextMenu(const QPoint &pt);
};

#endif // MAINWINDOW_H

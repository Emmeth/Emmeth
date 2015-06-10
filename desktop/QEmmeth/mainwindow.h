#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QFile"
#include "QImage"
#include "QScrollArea"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();
    void about();
    void open();
    void save();
    void on_actionQuit_triggered();
    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
    QFile fileName;
    //QImage pdfImage;
    QScrollArea scrollArea;
    void MainWindow::loadFile(QFile fileName);
    void MainWindow::imageLabel();
};

#endif // MAINWINDOW_H

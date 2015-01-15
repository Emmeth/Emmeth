#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();

}

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
        loadFile(fileName);
}

bool MainWindow::save()
{

}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Emmeth"), tr("(c) by Benjamin Schnabel 2015"));
}

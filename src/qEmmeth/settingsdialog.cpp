#include "settingsdialog.h"
#include <QWidget>
#include <QtWidgets>
#include <QStringList>
#include <QObject>
#include <QSettings>
#include <QApplication>
#include <QDebug>

settingsdialog::settingsdialog(QWidget* parent) : QDialog(parent)
{   //constructor
    //TODO: Close the Dialog if the Mainwindow is closed.

    //Dialog GUI
    //QDialog *sDialog = new QDialog();
    sDialog->setWindowTitle(QObject::tr("Settings"));
    sDialog->setWindowIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/system-run.png"));
    sDialog->setAttribute(Qt::WA_DeleteOnClose);
    sDialog->setWindowFlags(Qt::Window);

    QStringList languages;
    languages << "English" << "Deutsch" << "עברית" << "Polski";
    //QComboBox *cmbLanguages = new QComboBox();
    cmbLanguages->addItems(languages);

    QPushButton *btnOk = new QPushButton();
    btnOk->setText(QObject::tr("Ok"));
    QPushButton *btnCancel = new QPushButton();
    btnCancel->setText(QObject::tr("Cancel"));
    QPushButton *btnSave = new QPushButton();
    btnSave->setText(QObject::tr("Save"));


    QHBoxLayout *hBoxLayout = new QHBoxLayout();
    hBoxLayout->addWidget(btnOk);
    hBoxLayout->addWidget(btnCancel);
    hBoxLayout->addWidget(btnSave);

    QVBoxLayout *vBoxLayout = new QVBoxLayout();
    vBoxLayout->addWidget(cmbLanguages);
    vBoxLayout->addLayout(hBoxLayout);
    sDialog->setLayout(vBoxLayout);
    sDialog->setMinimumSize(500,200);
    sDialog->show();
    sDialog->raise();
    sDialog->activateWindow();
    sDialog->setFocus();

    connect(btnOk, SIGNAL(clicked(bool)), this, SLOT(okButton()));
    connect(btnCancel, SIGNAL(clicked(bool)), this, SLOT(cancelButton()));
    connect(btnSave, SIGNAL(clicked(bool)), this, SLOT(saveButton()));
    QApplication::setApplicationName("Emmeth");
    QApplication::setOrganizationDomain("emmeth.org");
    QApplication::setOrganizationName("Emmeth");
    QApplication::setApplicationVersion("0.1");

    //load the settings and aply them to the GUI
    loadSettings();


}

settingsdialog::~settingsdialog(){
    //destructor
}

void settingsdialog::loadSettings(){
    qDebug() << "load Settings";
    QSettings settings;
    settings.setDefaultFormat(QSettings::NativeFormat);
    settings.beginGroup("Common");
    QString sLanguage = settings.value("language").toString();
    settings.endGroup();
    qDebug() << sLanguage;
    qDebug() << settings.allKeys();

    //select the right language
    if(sLanguage.isEmpty()== false){
        //int index = cmbLanguages->findText(sLanguage);
        //cmbLanguages->setCurrentIndex(index);
        cmbLanguages->setCurrentText(sLanguage);
    }
}

void settingsdialog::saveSettings(){
    qDebug() << "save Settings";
    QSettings settings;
    settings.setDefaultFormat(QSettings::NativeFormat);
    //get the Values
    QString sLanguage = this->cmbLanguages->currentText();
    qDebug() << sLanguage;

    if(settings.isWritable() == true){
        settings.beginGroup("Common");
        settings.setValue("language", sLanguage); //save string to config.ini
        settings.endGroup();
    }
    else{
        qDebug() << "Error writing config";
    }
    int index = this->cmbLanguages->findText(sLanguage);
    this->cmbLanguages->setCurrentIndex(index);
}

void settingsdialog::closeDialog(){
   //close the dialog properly
   sDialog->close();
   close();
   this->close();
   qDebug() << "Settings closed";
}

void settingsdialog::okButton(){
    saveSettings();
    closeDialog();
}

void settingsdialog::cancelButton(){
    closeDialog();
}

void settingsdialog::saveButton(){
    saveSettings();
}

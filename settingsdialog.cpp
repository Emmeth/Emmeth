/*********************************
 *
 * settingsdialog.cpp
 *
 * (C) Benjamin Schnabel, 2016
 *
 * LGPL
 *
 * manages the settings.
 *
 **********************************/

#include "settingsdialog.h"
#include <QWidget>
#include <QtWidgets>
#include <QStringList>
#include <QObject>
#include <QSettings>
#include <QApplication>
#include <QDebug>

SettingsDialog::SettingsDialog(QWidget* parent) : QWidget(parent)
{   //constructor
    //TODO: Close the Dialog if the Mainwindow is closed.

    //latinFont = new QFont(); //initialize Font
    //Dialog GUI
    setWindowTitle(QObject::tr("Settings"));
    setWindowIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/system-run.png"));
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(Qt::Window);

    //languages list
    QStringList languages;
    languages << "English" << "Deutsch" << "עברית" << "Polski";
    cmbLanguages = new QComboBox();
    cmbLanguages->addItems(languages);

    //create buttons
    QPushButton *btnOk = new QPushButton();
    btnOk->setText(QObject::tr("Ok"));
    QPushButton *btnCancel = new QPushButton();
    btnCancel->setText(QObject::tr("Cancel"));
    QPushButton *btnSave = new QPushButton();
    btnSave->setText(QObject::tr("Save"));  

    //add the buttons to the layout
    //XXX QHBoxLayout *hBoxLayout = new QHBoxLayout();
    //XXX hBoxLayout->addWidget(btnOk);
    //XXX hBoxLayout->addWidget(btnCancel);
    //XXX hBoxLayout->addWidget(btnSave);

    QVBoxLayout *vBoxLayout = new QVBoxLayout();
    vBoxLayout->addWidget(cmbLanguages);


    //layout for the general settings

    //system wide font settings

    //latin text font settings
    //font family
    QLabel *latinFontSettingsLabel = new QLabel(this);
    latinFontSettingsLabel->setText("Latin Font Settings");
    latinFontSettingsLabel->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    //XXX for testing create a font Dialog
    QPushButton *fontDialogButton = new QPushButton("Open Fonts Dialog", this);

    connect(fontDialogButton, SIGNAL(clicked()), this, SLOT(openFontDialog()) );

    //Font
    QFontComboBox *fontComboBox = new QFontComboBox(this);
    fontComboBox->setWritingSystem(QFontDatabase::Latin);

    //font size
    QComboBox *fontSizeComboBox = new QComboBox(this); //TODO: declare in Header file
    fontSizeComboBox->setEditable(true);
    fontSizeComboBox->setInsertPolicy(QComboBox::InsertAlphabetically);
    fontSizeComboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    fontSizeComboBox->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    QStringList fontSizes;
    fontSizes << "8" << "9" << "10" << "11" << "12" << "14" << "16" << "18" << "20" << "22" << "24" << "26" << "28" << "36" << "48" << "72";
    fontSizeComboBox->insertItems(0,fontSizes);

    QHBoxLayout *fontsLayout = new QHBoxLayout();
    fontsLayout->addWidget(fontDialogButton);
    fontsLayout->addWidget(latinFontSettingsLabel);
    fontsLayout->addWidget(fontComboBox);
    fontsLayout->addWidget(fontSizeComboBox);

    //text color

    //hebrew text font settings

    //greek text font settings


    QGroupBox *groupBoxLanguages = new QGroupBox(tr("Languages"));
    groupBoxLanguages->setLayout(vBoxLayout);

    QGroupBox *groupBoxGeneral = new QGroupBox(tr("General"));
    groupBoxGeneral->setLayout(fontsLayout);

    QTabWidget *tabs = new QTabWidget();
    tabs->setContentsMargins(0,0,0,0);
    tabs->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    tabs->addTab(groupBoxGeneral, tr("General"));
    tabs->addTab(groupBoxLanguages, tr("Languages"));

     //GridLayout as master
    QGridLayout *layout = new QGridLayout();
    //Header label
    QLabel *header = new QLabel();
    //default header
    header->setText(tr("General"));

    //Search input field
    QLineEdit *searchInput = new QLineEdit();
    searchInput->setPlaceholderText(tr("search"));

    //ListWidget on the left side
    QListWidget *listWidget = new QListWidget();
    //Add the corresponding items.
    new QListWidgetItem(tr("General"), listWidget);
    new QListWidgetItem(tr("Editor"), listWidget);
    new QListWidgetItem(tr("Languages"), listWidget);

    //XXX QVBoxLayout *layout = new QVBoxLayout();
    //XXX layout->addWidget(tabs);
    //XXX layout->addLayout(hBoxLayout);

    layout->addWidget(searchInput,0,0);
    layout->addWidget(listWidget,1,0,2,1);
    layout->addWidget(header,0,1);
    layout->addWidget(tabs,1,1,1,3);
    layout->addWidget(btnSave,3,0);
    QSpacerItem *spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
    layout->addItem(spacer,3,1);
    layout->addWidget(btnCancel,3,2);
    layout->addWidget(btnOk,3,3);

    setLayout(layout);

    setMinimumSize(500,200);
    show();
    raise();
    activateWindow();
    setFocus();

    QObject::connect(btnOk, SIGNAL(clicked(bool)), this, SLOT(okButton()));
    QObject::connect(btnCancel, SIGNAL(clicked(bool)), this, SLOT(cancelButton()));
    QObject::connect(btnSave, SIGNAL(clicked(bool)), this, SLOT(saveButton()));
    QApplication::setApplicationName("Emmeth");
    QApplication::setOrganizationDomain("emmeth.org");
    QApplication::setOrganizationName("Emmeth");
    QApplication::setApplicationVersion("0.1");

    //load the settings and aply them to the GUI
    loadSettings();

}

SettingsDialog::~SettingsDialog(){
    //destructor
}

void SettingsDialog::loadSettings(){
    //loads the settings
    qDebug() << "load Settings";
    QSettings settings;
    settings.setDefaultFormat(QSettings::NativeFormat);
    settings.beginGroup("Common");
    QString sLanguage = settings.value("language").toString();
    settings.endGroup();
    qDebug() << sLanguage;
    qDebug() << settings.allKeys();

    //select the right language
    if(sLanguage.isNull() == false){
        cmbLanguages->setCurrentText(sLanguage);
    }

    //TODO: apply the language to the system.
}

void SettingsDialog::saveSettings(){
    //saves the settings
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

void SettingsDialog::closeDialog(){
   //close the dialog properly
   close();
   qDebug() << "Settings closed";
}

void SettingsDialog::okButton(){
    //ok button, saves and closes the dialog
    saveSettings();
    closeDialog();
}

void SettingsDialog::cancelButton(){
    //cancel button, closes without saving
    closeDialog();
}

void SettingsDialog::saveButton(){
    //save button, saves only
    saveSettings();
}

void SettingsDialog::openFontDialog(){
    //opens the font dialog
    bool ok;

    QFont font = QFontDialog::getFont(&ok, QFont("Arial", 10), this, "Select Latin Font");
    latinFont = font; //TODO: refactor for general use.
}

void SettingsDialog::loadGeneralTab(){

}

/***************
 *
 * LoginDialog
 *
 * Benjamin Schnabel, 2015
 *
 * handles the user login.
 *
 * *************/

#include "logindialog.h"
#include <QWidget>
#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QSettings>
#include <QCryptographicHash>
#include <QDebug>
#include <QApplication>

loginDialog::loginDialog(QWidget *parent) : QDialog (parent)
{
    //constructor

    QApplication::setApplicationName("Emmeth");
    QApplication::setOrganizationDomain("emmeth.org");
    QApplication::setOrganizationName("Emmeth");
    QApplication::setApplicationVersion("0.1");

    //build GUI

    lDialog->setWindowTitle(tr("Login"));
    lDialog->setWindowIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/lock.png"));

    QLabel *labelUsername = new QLabel(tr("Username"));
    QLabel *labelPassword = new QLabel(tr("Password"));

    editPassword->setEchoMode(QLineEdit::Password);
    editPassword->setInputMethodHints(Qt::ImhHiddenText| Qt::ImhNoPredictiveText|Qt::ImhNoAutoUppercase);

    QPushButton *btnOk = new QPushButton(this);
    QPushButton *btnClose = new QPushButton(this);
    btnOk->setText(tr("&Ok"));
    btnClose->setText(tr("&Close"));

    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->addWidget(labelUsername,0,0);
    gridLayout->addWidget(editUsername,0,1);
    gridLayout->addWidget(labelPassword,1,0);
    gridLayout->addWidget(editPassword,1,1);
    gridLayout->addWidget(btnOk,2,0);
    gridLayout->addWidget(btnClose,2,1);

    lDialog->setLayout(gridLayout);
    lDialog->setMinimumSize(200,200);
    lDialog->show();
    lDialog->raise();
    lDialog->activateWindow();
    lDialog->setFocus();

    connect(btnOk,SIGNAL(clicked(bool)),this, SLOT(okButton()));
    connect(btnClose, SIGNAL(clicked(bool)), this, SLOT(closeButton()));

}

loginDialog::~loginDialog(){
    //destructor

}

void loginDialog::loadSettings(){
    //load the settings
    qDebug() << "load Login";
    QSettings settings;
    settings.setDefaultFormat(QSettings::NativeFormat);
    settings.beginGroup("Login");
    QString sUsername = settings.value("username").toString();
    QString sPassword = settings.value("password").toString();
    bool sIsLoggedIn = settings.value("isLoggedIn").toBool();
    settings.endGroup();
    qDebug() << settings.allKeys();
}

void loginDialog::saveSettings(){
    qDebug() << "save LoginSettings";
    bool isLoggedIn = false;

    QSettings settings;
    settings.setDefaultFormat(QSettings::NativeFormat);
    //get the Values
    QString sUsername = this->editUsername->text();
    QString sPassword = this->editPassword->text();

    //hide password with md5

    QString hiddenPassword = "";
    if(!sPassword.isEmpty()){
        hiddenPassword = QString(QCryptographicHash::hash((sPassword.toUtf8().left(1000)), QCryptographicHash::Md5).toHex());
    }

    if(!sUsername.isEmpty() && !hiddenPassword.isEmpty() ){
        isLoggedIn = true;
    }

    qDebug() << sUsername;
    qDebug() << sPassword;
    qDebug() << hiddenPassword;

    if(settings.isWritable() == true){
        settings.beginGroup("Login");
        settings.setValue("username", sUsername);
        settings.setValue("password", hiddenPassword);
        settings.setValue("isLoggedIn", isLoggedIn);
        settings.endGroup();
    }
    else{
        qDebug() << "Error writing config";
    }
}

void loginDialog::okButton(){
    saveSettings();
    this->close();
}

void loginDialog::closeButton(){
    this->close();
}

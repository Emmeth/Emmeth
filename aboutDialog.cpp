/*********************************
 *
 * aboutDialog.cpp
 *
 * (C) Benjamin Schnabel, 2016
 *
 * LGPL
 *
 * The About Dialog.
 *
 **********************************/


#include "aboutDialog.h"
#include <QPushButton>
#include <QDialog>
#include <QPushButton>
#include <QImage>
#include <QString>
#include <QChar>
#include <QLabel>
#include <QLayout>
#include <QWidget>
#include <QScrollArea>
#include <QObject>

AboutDialog::AboutDialog(QWidget *parent) : QWidget (parent)
{
    //initialize Dialog
    QDialog *dialog = new QDialog;
    dialog->setWindowTitle("About Emmeth");
    QGridLayout *gridLayout = new QGridLayout;

    QVBoxLayout *layout =new QVBoxLayout;
    dialog->setWindowIcon(QIcon(":/assets/icons/Moleskine.ico"));

    //Copyright
    QLabel *labelAbout = new QLabel(tr("<h1>About Emmeth - אמת</h1>"));
    layout->addWidget(labelAbout);
    QString versionNumber = QCoreApplication::applicationVersion();

    QString versionInfo = "<h2>Version info:\n</h2> "+ versionNumber +" (unstable,";
    QChar c = (0x03B1);
    versionInfo += c;
    versionInfo += ")";
    QLabel *labelCopyright = new QLabel(versionInfo);
    layout->addWidget(labelCopyright);
    QString copyright = " Benjamin Schnabel, et al., ";
    c = (0x00a9);
    QString developers = "<h2>Developers</h2>\n";
    QDate year;
    copyright  = developers + c + copyright + year.currentDate().toString("yyyy");
    QLabel *labelDevelopers = new QLabel(copyright);
    layout->addWidget(labelDevelopers);

    //Application licences and thanks
    QLabel *labelLicences = new QLabel(tr("<h2>Licences:</h2>"));
    layout->addWidget(labelLicences);
    QLabel *labelPoppler = new QLabel(tr("<ul><li>GPL\n</li><li>Qt\n</li><li>poppler</li></ul>"));
    layout->addWidget(labelPoppler);
    QLabel *labelIcon = new QLabel (tr("<h2>Icons</h2>"));
    layout->addWidget(labelIcon);
    QLabel *labelMoleskine = new QLabel (tr("Moleskin by <a href=\"http://www.http://stezycki.com\">Michael Stezycki</a>"));
    layout->addWidget(labelMoleskine);
    QLabel *labelFaenza = new QLabel (tr("Faenza Icons by <a href=\"https://github.com/shlinux/faenza-icon-theme\">Matthieu James</a>"));
    layout->addWidget(labelFaenza);

    //TODO
    //change file path to Application Directory
    QFile gplFile("://GPL3.txt");
    gplFile.open(QIODevice::ReadOnly);
    QString gplString = gplFile.readAll();
    gplFile.close();

    QLabel *gplLabel = new QLabel(gplString);
    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setWidget(gplLabel);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //website
    QLabel *labelWebsite = new QLabel(tr("<h2>Our website:</h2> <a href=\"http://www.emmeth.com\">www.emmeth.com</a>"));
    labelWebsite->setAlignment(Qt::AlignLeft);
    layout->addWidget(labelWebsite);

    //Application Image
    QLabel *imageLabel = new QLabel();
    imageLabel->setBackgroundRole(QPalette::Dark);
    imageLabel->setScaledContents(true);

    //TODO
    //change file path to Application Directory
    QPixmap pixmap(":/appicon/assets/icons/128.png");
    qDebug() << qApp->applicationDirPath();
    imageLabel->setPixmap(pixmap);


    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

    //Close button
    QPushButton *btnClose = new QPushButton("Close");
    QObject::connect(btnClose, SIGNAL(clicked(bool)),dialog,SLOT(close()));
    //FIXME: On close application, close the widget too.

    gridLayout->addWidget(imageLabel,0,0);
    gridLayout->addLayout(layout,0,1);
    gridLayout->addWidget(scrollArea,1,0,1,2);
    gridLayout->addWidget(btnClose,2,0,1,2);

    dialog->setLayout(gridLayout);

    dialog->setMinimumSize(500,200);
    dialog->show();
    dialog->raise();
    dialog->activateWindow();
}

AboutDialog::~AboutDialog() {

}

void AboutDialog::on_actionQuit_triggered()
{
    this->close();
}



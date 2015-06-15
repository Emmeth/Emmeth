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

void aboutDialog::open()
{
    //initialize Dialog
    QDialog *aDialog = new QDialog;
    aDialog->setWindowTitle("About Emmeth");
    QHBoxLayout *hLayout = new QHBoxLayout;
    QVBoxLayout *layout =new QVBoxLayout;
    aDialog->setWindowIcon(QIcon(":/assets/icons/Moleskine.ico"));

    //Copyright
    QLabel *label1 = new QLabel(tr("<h1>About Emmeth</h1>"));
    layout->addWidget(label1);
    QString version = "<h2>Version info:\n</h2> 0.0.1 (unstable,";
    QChar c = (0x03B1);
    version += c;
    version += ")";
    QLabel *label2 = new QLabel(version);
    layout->addWidget(label2);
    QString copy = " Benjamin Schnabel, 2015";
    c = (0x00a9);
    QString developers = "<h2>Developers</h2>\n";
    copy  = developers + c + copy;
    QLabel *label3 = new QLabel(copy);
    layout->addWidget(label3);

    //Application licences and thanks
    QLabel *label4 = new QLabel(tr("<h2>Licences:</h2>"));
    layout->addWidget(label4);
    QLabel *label5 = new QLabel(tr("<ul><li>GPL\n</li><li>Qt\n</li><li>poppler</li></ul>"));
    layout->addWidget(label5);
    //TODO
    //change file path to Application Directory
    QFile gplFile("C:/Users/Benni/Programmierung/Emmeth/desktop/QEmmeth/GPL3.html");
    gplFile.open(QIODevice::ReadOnly);
    QString gplString = gplFile.readAll();
    gplFile.close();

    QLabel *gplLabel = new QLabel(gplString);
    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setWidget(gplLabel);
    layout->addWidget(scrollArea);

    //website
    QLabel *webLabel = new QLabel(tr("<a href=\"http://www.emmeth.com\">www.emmeth.com</a>"));
    webLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(webLabel);

    //Application Image
    QLabel *imageLabel = new QLabel();
    imageLabel->setBackgroundRole(QPalette::Dark);
    imageLabel->setScaledContents(true);
    //TODO
    //change file path to Application Directory
    QPixmap pixmap("C:/Users/Benni/Programmierung/Emmeth/desktop/QEmmeth/assets/icons/128.png");
    qDebug() << qApp->applicationDirPath();
    imageLabel->setPixmap(pixmap);


    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    //aDialog->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed);

    //Close button
    QPushButton *btnClose = new QPushButton("Close");
    connect(btnClose, SIGNAL(clicked(bool)),aDialog,SLOT(close()));
    layout->addWidget(btnClose);
    hLayout->addWidget(imageLabel);
    hLayout->addLayout(layout);
    aDialog->setLayout(hLayout);
    //aDialog->setMaximumSize(500,200);
    aDialog->setMinimumSize(500,200);
    aDialog->show();
    aDialog->raise();
    aDialog->activateWindow();
}


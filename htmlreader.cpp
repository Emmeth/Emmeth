/*********************************
 *
 * htmlreader.cpp
 *
 * (C) Benjamin Schnabel, 2016
 *
 * LGPL
 *
 * loads html files
 *
 **********************************/

#include "htmlreader.h"
#include <QWidget>
#include <QProgressBar>
#include <QLabel>
#include <QLineEdit>
#include <QSettings>

HtmlReader::HtmlReader()
{
    setupUi(this);

        addressEdit = new QLineEdit;
        tbAddress->insertWidget(actionGo, new QLabel(tr("Address")));
        tbAddress->insertWidget(actionGo, addressEdit);

        connect(addressEdit, SIGNAL(returnPressed()), actionGo, SLOT(trigger()));
        connect(actionBack, SIGNAL(triggered()), WebBrowser, SLOT(GoBack()));
        connect(actionForward, SIGNAL(triggered()), WebBrowser, SLOT(GoForward()));
        connect(actionStop, SIGNAL(triggered()), WebBrowser, SLOT(Stop()));
        connect(actionRefresh, SIGNAL(triggered()), WebBrowser, SLOT(Refresh()));
        connect(actionHome, SIGNAL(triggered()), WebBrowser, SLOT(GoHome()));
        connect(actionSearch, SIGNAL(triggered()), WebBrowser, SLOT(GoSearch()));

        pb = new QProgressBar(statusBar());
        pb->setTextVisible(false);
        pb->hide();
        statusBar()->addPermanentWidget(pb);

        connect(&locationActionMapper, SIGNAL(mapped(QString)), this, SLOT(navigate(QString)));

        QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                           QCoreApplication::organizationName(), QCoreApplication::applicationName());
        const QByteArray restoredGeometry = settings.value(QLatin1String(geometryKey)).toByteArray();
        if (restoredGeometry.isEmpty() || !restoreGeometry(restoredGeometry)) {
            const QRect availableGeometry = QApplication::desktop()->availableGeometry(this);
            const QSize size = (availableGeometry.size() * 4) / 5;
            resize(size);
            move(availableGeometry.center() - QPoint(size.width(), size.height()) / 2);
        }
        const QString restoredVersion = settings.value(QLatin1String(versionKey)).toString();
        QList<Location> bookmarks = readBookMarks(settings);
        if (bookmarks.isEmpty() || restoredVersion.isEmpty())
            bookmarks = defaultBookmarks();
        foreach (const Location &bookmark, bookmarks)
            addBookmark(bookmark);
}

HtmlReader::~HtmlReader()
{

}

void HtmlReader::read(){
    //TODO: Finish reading parser
}

void HtmlReader::write(){
    //TODO: finish write parser

}

void HtmlReader::on_WebBrowser_TitelChange(const QString &title){
    // This is called multiple times after NavigateComplete().
        // Add new URLs to history here.
        setWindowTitle("Qt WebBrowser - " + title);
        const QString currentAddress = address();
        const QString historyAddress = historyActions.isEmpty() ?
            QString() : locationFromAction(historyActions.last()).address;
        if (currentAddress.isEmpty() || currentAddress == "about:blank" || currentAddress == historyAddress)
            return;
        historyActions << addLocation(Location(title, currentAddress), HistoryMenu);
        if (historyActions.size() > 10)
            delete historyActions.takeFirst();
}

void HtmlReader::on_WebBrowser_ProgressChange(int a, int b)
{
    if (a <= 0 || b <= 0) {
        pb->hide();
        return;
    }
    pb->show();
    pb->setRange(0, b);
    pb->setValue(a);
}

void HtmlReader::on_WebBrowser_CommandStateChange(int cmd, bool on)
{
    switch (cmd) {
    case 1:
        actionForward->setEnabled(on);
        break;
    case 2:
        actionBack->setEnabled(on);
        break;
    }
}

void HtmlReader::on_WebBrowser_BeforeNavigate()
{
    actionStop->setEnabled(true);
}

void HtmlReader::on_WebBrowser_NavigateComplete(const QString &url)
{
    actionStop->setEnabled(false);
    const bool blocked = addressEdit->blockSignals(true);
    addressEdit->setText(url);
    addressEdit->blockSignals(blocked);
}

void HtmlReader::on_actionGo_triggered()
{
    navigate(address());
}

#include "pluginslibrary.h"
#include <QWidget>
#include <QStringList>
#include <QObject>
#include <QSettings>
#include <QApplication>
#include <QDebug>

pluginsLibrary::pluginsLibrary(QWidget *parent): QWidget(parent)
{

    setWindowTitle(QObject::tr("Plugins"));
    setWindowIcon(QIcon(":/faenza/actions/24/assets/icons/faenza/actions/24/add.png"));
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(Qt::Window);


}

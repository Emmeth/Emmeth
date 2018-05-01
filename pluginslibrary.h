#ifndef PLUGINSLIBRARY_H
#define PLUGINSLIBRARY_H

#include <QObject>
#include <QWidget>

class pluginsLibrary : public QWidget
{
    Q_OBJECT

public:
   explicit pluginsLibrary(QWidget *parent = 0);
};

#endif // PLUGINSLIBRARY_H

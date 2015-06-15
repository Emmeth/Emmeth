#ifndef TXTEDITOR_H
#define TXTEDITOR_H
#include <QString>
#include <QFile>


class txteditor
{
public:
    txteditor();
    ~txteditor();
    QString read(QString fileName);
    bool write();
    void display();
private:
    QString fileName;
    QFile file;
    QString content;
};

#endif // TXTEDITOR_H

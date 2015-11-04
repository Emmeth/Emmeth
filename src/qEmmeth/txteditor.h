#ifndef TXTEDITOR_H
#define TXTEDITOR_H
#include <QString>
#include <QFile>
#include <QTextEdit>


class txteditor
{
public:
    txteditor();
    ~txteditor();
    QString read(QString fileName);
    bool write();
    void display(QString string);

private:
    QString fileName;
    QFile file;
    QString content;
    QTextEdit *textEdit = new QTextEdit();
};

#endif // TXTEDITOR_H

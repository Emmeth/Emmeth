#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QWidget>
#include <QDialog>
#include <QLineEdit>

class loginDialog : public QDialog
{
    Q_OBJECT
public:
    explicit loginDialog(QWidget *parent);
    ~loginDialog();

private slots:
    void okButton();
    void closeButton();
private:
    void loadSettings();
    void saveSettings();

    QDialog *lDialog = new QDialog();
    QLineEdit *editUsername = new QLineEdit(this);
    QLineEdit *editPassword = new QLineEdit(this);

};

#endif // LOGINDIALOG_H

#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QString>
#include <QComboBox>

class settingsdialog : public QDialog
{
    Q_OBJECT

public:
    explicit settingsdialog(QWidget *parent);
    ~settingsdialog();

private slots:
    void okButton();
    void cancelButton();
    void saveButton();

private:
    void loadSettings();
    void saveSettings();
    void closeDialog();
    QDialog *sDialog = new QDialog();
    QComboBox *cmbLanguages = new QComboBox();
};

#endif // SETTINGSDIALOG_H

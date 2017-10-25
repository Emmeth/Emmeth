#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QString>
#include <QComboBox>
#include <QFont>

/**
 * @brief
 *
 */
class SettingsDialog : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param parent
     */
    explicit SettingsDialog(QWidget *parent = 0);
    /**
     * @brief
     *
     */
    ~SettingsDialog();
    QFont latinFont;

private slots:
    /**
     * @brief
     *
     */
    void okButton();
    /**
     * @brief
     *
     */
    void cancelButton();
    /**
     * @brief
     *
     */
    void saveButton();

    void openFontDialog();
private:
    /**
     * @brief
     *
     */
    void loadSettings();
    /**
     * @brief
     *
     */
    void saveSettings();
    /**
     * @brief
     *
     */
    void closeDialog();
    QDialog *sDialog; /**< TODO: describe */
    QComboBox *cmbLanguages; /**< TODO: describe */
    void loadGeneralTab();
};

#endif // SETTINGSDIALOG_H

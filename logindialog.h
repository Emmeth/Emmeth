#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QWidget>
#include <QDialog>
#include <QLineEdit>

/**
 * @brief
 *
 */
class loginDialog : public QDialog
{
    Q_OBJECT
public:
    /**
     * @brief
     *
     * @param parent
     */
    explicit loginDialog(QWidget *parent);
    /**
     * @brief
     *
     */
    ~loginDialog();

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
    void closeButton();
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

    QDialog *lDialog; /**< TODO: describe */
    QLineEdit *editUsername; /**< TODO: describe */
    QLineEdit *editPassword; /**< TODO: describe */

};

#endif // LOGINDIALOG_H

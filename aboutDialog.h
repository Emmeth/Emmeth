#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QWidget>
#include <QtGui>
#include <QLayout>

/**
 * @brief
 *
 */
class AboutDialog : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     */
    explicit AboutDialog(QWidget *parent = 0);
    ~AboutDialog();

signals:

public slots:
private slots:
    void on_actionQuit_triggered();
};

#endif // ABOUTDIALOG_H

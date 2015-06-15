#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include <QWidget>

namespace Ui {
class bookstore;
}

class bookstore : public QWidget
{
    Q_OBJECT

public:
    explicit bookstore(QWidget *parent = 0);
    ~bookstore();

private:
    Ui::bookstore *ui;
};

#endif // BOOKSTORE_H

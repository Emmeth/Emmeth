#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include <QWidget>

namespace Ui {
class bookstore;
}

/**
 * @brief
 *
 */
class bookstore : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param parent
     */
    explicit bookstore(QWidget *parent = 0);
    /**
     * @brief
     *
     */
    ~bookstore();

private:
    Ui::bookstore *ui; /**< TODO: describe */
};

#endif // BOOKSTORE_H

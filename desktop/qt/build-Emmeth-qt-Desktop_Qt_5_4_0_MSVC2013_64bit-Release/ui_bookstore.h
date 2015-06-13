/********************************************************************************
** Form generated from reading UI file 'bookstore.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKSTORE_H
#define UI_BOOKSTORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bookstore
{
public:

    void setupUi(QWidget *bookstore)
    {
        if (bookstore->objectName().isEmpty())
            bookstore->setObjectName(QStringLiteral("bookstore"));
        bookstore->resize(535, 341);

        retranslateUi(bookstore);

        QMetaObject::connectSlotsByName(bookstore);
    } // setupUi

    void retranslateUi(QWidget *bookstore)
    {
        bookstore->setWindowTitle(QApplication::translate("bookstore", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class bookstore: public Ui_bookstore {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKSTORE_H

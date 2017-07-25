/********************************************************************************
** Form generated from reading UI file 'bookstore.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bookstore
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;

    void setupUi(QWidget *bookstore)
    {
        if (bookstore->objectName().isEmpty())
            bookstore->setObjectName(QStringLiteral("bookstore"));
        bookstore->resize(581, 456);
        tabWidget = new QTabWidget(bookstore);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(140, 60, 127, 80));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        retranslateUi(bookstore);

        QMetaObject::connectSlotsByName(bookstore);
    } // setupUi

    void retranslateUi(QWidget *bookstore)
    {
        bookstore->setWindowTitle(QApplication::translate("bookstore", "Form", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("bookstore", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("bookstore", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class bookstore: public Ui_bookstore {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKSTORE_H

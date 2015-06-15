#include "bookstore.h"
#include "ui_bookstore.h"

bookstore::bookstore(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bookstore)
{
    ui->setupUi(this);
}

bookstore::~bookstore()
{
    delete ui;
}

/*********************************
 *
 * bookstore.cpp
 *
 * (C) Benjamin Schnabel, 2016
 *
 * LGPL
 *
 * The dialog for the bookstore.
 *
 **********************************/


#include "bookstore.h"
#include "ui_bookstore.h"

bookstore::bookstore(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bookstore)
{
    //create new ui
    ui->setupUi(this);
}

bookstore::~bookstore()
{
    //delete the ui
    delete ui;
}

//TODO: load the books from the online store via json

//TODO: view categories
//categories: books, bibles, dictionaries, maps, lexicons, plugins, timetables, other

//TODO: download the books to temporary location

//TODO: verify the files via md5

//TODO: load the files in the directory

//TODO: your downloads view

//TODO: login dialog

//TODO: register dialog

//TODO: close dialog


//TODO: pause downloading

//TODO: resume downloading

//TODO: logout

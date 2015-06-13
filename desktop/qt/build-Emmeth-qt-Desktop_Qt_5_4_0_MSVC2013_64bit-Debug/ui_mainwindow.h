/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionAbout;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionPrint;
    QAction *actionSave_As;
    QAction *action_Settings;
    QAction *actionAbout_Book;
    QAction *actionHelp;
    QAction *actionPlugins;
    QAction *actionContextual_Help;
    QAction *actionIndex;
    QAction *actionNew;
    QAction *actionCopy;
    QAction *actionCut;
    QAction *actionPaste;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionLogin;
    QAction *actionZoomIn;
    QAction *actionZoomOut;
    QAction *actionZoomOriginal;
    QAction *action_Library;
    QAction *action_Bookshop;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuWindows;
    QMenu *menuHelp;
    QMenu *menuExtras;
    QToolBar *toolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(944, 749);
        QIcon icon;
        icon.addFile(QStringLiteral(":/appicon/assets/icons/48.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setDocumentMode(false);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/faenza/actions/scalable/assets/icons/faenza/actions/scalable/gtk-quit.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon1);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/faenza/actions/24/assets/icons/faenza/actions/24/help-about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon2);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/faenza/actions/24/assets/icons/faenza/actions/24/document-open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon3);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/faenza/actions/24/assets/icons/faenza/actions/24/document-save-as.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon4);
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QStringLiteral("actionPrint"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/faenza/actions/24/assets/icons/faenza/actions/24/document-print.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon5);
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionSave_As->setIcon(icon4);
        action_Settings = new QAction(MainWindow);
        action_Settings->setObjectName(QStringLiteral("action_Settings"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/faenza/actions/24/assets/icons/faenza/actions/24/system-run.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Settings->setIcon(icon6);
        actionAbout_Book = new QAction(MainWindow);
        actionAbout_Book->setObjectName(QStringLiteral("actionAbout_Book"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/faenza/actions/24/assets/icons/faenza/actions/24/gtk-info.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_Book->setIcon(icon7);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionPlugins = new QAction(MainWindow);
        actionPlugins->setObjectName(QStringLiteral("actionPlugins"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/faenza/actions/24/assets/icons/faenza/actions/24/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlugins->setIcon(icon8);
        actionContextual_Help = new QAction(MainWindow);
        actionContextual_Help->setObjectName(QStringLiteral("actionContextual_Help"));
        actionIndex = new QAction(MainWindow);
        actionIndex->setObjectName(QStringLiteral("actionIndex"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/faenza/actions/24/assets/icons/faenza/actions/24/document-new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon9);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/faenza/actions/24/assets/icons/faenza/actions/24/edit-copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon10);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/faenza/actions/24/assets/icons/faenza/actions/24/edit-cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon11);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/faenza/actions/24/assets/icons/faenza/actions/24/edit-paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon12);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/faenza/actions/24/assets/icons/faenza/actions/24/edit-undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon13);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/faenza/actions/24/assets/icons/faenza/actions/24/edit-redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon14);
        actionLogin = new QAction(MainWindow);
        actionLogin->setObjectName(QStringLiteral("actionLogin"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/faenza/actions/24/assets/icons/faenza/actions/24/contact-new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLogin->setIcon(icon15);
        actionZoomIn = new QAction(MainWindow);
        actionZoomIn->setObjectName(QStringLiteral("actionZoomIn"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/faenza/actions/24/assets/icons/faenza/actions/24/gtk-zoom-in.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomIn->setIcon(icon16);
        actionZoomOut = new QAction(MainWindow);
        actionZoomOut->setObjectName(QStringLiteral("actionZoomOut"));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/faenza/actions/24/assets/icons/faenza/actions/24/zoom-out.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomOut->setIcon(icon17);
        actionZoomOriginal = new QAction(MainWindow);
        actionZoomOriginal->setObjectName(QStringLiteral("actionZoomOriginal"));
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/faenza/actions/24/assets/icons/faenza/actions/24/zoom-original.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomOriginal->setIcon(icon18);
        action_Library = new QAction(MainWindow);
        action_Library->setObjectName(QStringLiteral("action_Library"));
        action_Bookshop = new QAction(MainWindow);
        action_Bookshop->setObjectName(QStringLiteral("action_Bookshop"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 944, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuWindows = new QMenu(menuBar);
        menuWindows->setObjectName(QStringLiteral("menuWindows"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuExtras = new QMenu(menuBar);
        menuExtras->setObjectName(QStringLiteral("menuExtras"));
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuWindows->menuAction());
        menuBar->addAction(menuExtras->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionPrint);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionPaste);
        menuHelp->addAction(actionHelp);
        menuHelp->addAction(actionIndex);
        menuHelp->addAction(actionContextual_Help);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);
        menuExtras->addAction(actionLogin);
        menuExtras->addAction(actionAbout_Book);
        menuExtras->addSeparator();
        menuExtras->addAction(action_Library);
        menuExtras->addAction(action_Bookshop);
        menuExtras->addSeparator();
        menuExtras->addAction(actionPlugins);
        menuExtras->addAction(action_Settings);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionNew);
        toolBar->addAction(actionSave);
        toolBar->addAction(actionPrint);
        toolBar->addSeparator();
        toolBar->addAction(actionCopy);
        toolBar->addAction(actionCut);
        toolBar->addAction(actionPaste);
        toolBar->addSeparator();
        toolBar->addAction(actionUndo);
        toolBar->addAction(actionRedo);
        toolBar->addSeparator();
        toolBar->addAction(actionZoomIn);
        toolBar->addAction(actionZoomOut);
        toolBar->addAction(actionZoomOriginal);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Emmeth", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "&Quit", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "&About", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "&Open", 0));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionSave->setText(QApplication::translate("MainWindow", "&Save", 0));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionPrint->setText(QApplication::translate("MainWindow", "&Print", 0));
        actionPrint->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save &As", 0));
        actionSave_As->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", 0));
        action_Settings->setText(QApplication::translate("MainWindow", "&Settings", 0));
        actionAbout_Book->setText(QApplication::translate("MainWindow", "About Book", 0));
        actionHelp->setText(QApplication::translate("MainWindow", "Content", 0));
        actionPlugins->setText(QApplication::translate("MainWindow", "Plugins", 0));
        actionContextual_Help->setText(QApplication::translate("MainWindow", "Contextual Help", 0));
        actionContextual_Help->setShortcut(QApplication::translate("MainWindow", "F1", 0));
        actionIndex->setText(QApplication::translate("MainWindow", "&Index", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("MainWindow", "New File", 0));
#endif // QT_NO_TOOLTIP
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", 0));
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0));
        actionCut->setText(QApplication::translate("MainWindow", "Cut", 0));
#ifndef QT_NO_TOOLTIP
        actionCut->setToolTip(QApplication::translate("MainWindow", "Cut", 0));
#endif // QT_NO_TOOLTIP
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0));
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", 0));
#ifndef QT_NO_TOOLTIP
        actionPaste->setToolTip(QApplication::translate("MainWindow", "Paste", 0));
#endif // QT_NO_TOOLTIP
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0));
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", 0));
#ifndef QT_NO_TOOLTIP
        actionUndo->setToolTip(QApplication::translate("MainWindow", "undo", 0));
#endif // QT_NO_TOOLTIP
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0));
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", 0));
#ifndef QT_NO_TOOLTIP
        actionRedo->setToolTip(QApplication::translate("MainWindow", "redo", 0));
#endif // QT_NO_TOOLTIP
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0));
        actionLogin->setText(QApplication::translate("MainWindow", "Login", 0));
        actionZoomIn->setText(QApplication::translate("MainWindow", "ZoomIn", 0));
#ifndef QT_NO_TOOLTIP
        actionZoomIn->setToolTip(QApplication::translate("MainWindow", "zoom in", 0));
#endif // QT_NO_TOOLTIP
        actionZoomIn->setShortcut(QApplication::translate("MainWindow", "Ctrl++", 0));
        actionZoomOut->setText(QApplication::translate("MainWindow", "ZoomOut", 0));
#ifndef QT_NO_TOOLTIP
        actionZoomOut->setToolTip(QApplication::translate("MainWindow", "zoom out", 0));
#endif // QT_NO_TOOLTIP
        actionZoomOut->setShortcut(QApplication::translate("MainWindow", "Ctrl+-", 0));
        actionZoomOriginal->setText(QApplication::translate("MainWindow", "ZoomOriginal", 0));
#ifndef QT_NO_TOOLTIP
        actionZoomOriginal->setToolTip(QApplication::translate("MainWindow", "zoom original size", 0));
#endif // QT_NO_TOOLTIP
        actionZoomOriginal->setShortcut(QApplication::translate("MainWindow", "Ctrl+0", 0));
        action_Library->setText(QApplication::translate("MainWindow", "&Library", 0));
        action_Bookshop->setText(QApplication::translate("MainWindow", "&Bookshop", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "&Edit", 0));
        menuWindows->setTitle(QApplication::translate("MainWindow", "&Windows", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "&Help", 0));
        menuExtras->setTitle(QApplication::translate("MainWindow", "Extras", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

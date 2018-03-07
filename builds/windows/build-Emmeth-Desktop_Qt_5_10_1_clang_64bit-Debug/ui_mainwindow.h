/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
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
    QAction *action_Fullscreen;
    QAction *action_Cascade;
    QAction *action_Tile;
    QAction *action_Dictionaries;
    QAction *action_Lexicas;
    QAction *actionWLC;
    QAction *actionAdvanced_Search;
    QAction *actionWord_Statitics;
    QAction *actionWord_Analysis;
    QAction *actionSyntactical_Analysis;
    QAction *actionMaps;
    QAction *actionTimelines;
    QAction *actionVideos;
    QAction *actionGraphics;
    QAction *action3D_Models;
    QAction *actionStyle_Analysis;
    QAction *actionSemantical_Analysis;
    QAction *actionHebrew_Calendar;
    QAction *actionGematria_calculator;
    QAction *actionSymbols;
    QAction *actionScripts;
    QAction *actionAleppo;
    QAction *actionBHS;
    QAction *action_New;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuWindows;
    QMenu *menuHelp;
    QMenu *menuExtras;
    QMenu *menuTools;
    QMenu *menuAnalytics;
    QMenu *menuFeatures;
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
        action_Fullscreen = new QAction(MainWindow);
        action_Fullscreen->setObjectName(QStringLiteral("action_Fullscreen"));
        action_Cascade = new QAction(MainWindow);
        action_Cascade->setObjectName(QStringLiteral("action_Cascade"));
        action_Tile = new QAction(MainWindow);
        action_Tile->setObjectName(QStringLiteral("action_Tile"));
        action_Dictionaries = new QAction(MainWindow);
        action_Dictionaries->setObjectName(QStringLiteral("action_Dictionaries"));
        action_Lexicas = new QAction(MainWindow);
        action_Lexicas->setObjectName(QStringLiteral("action_Lexicas"));
        actionWLC = new QAction(MainWindow);
        actionWLC->setObjectName(QStringLiteral("actionWLC"));
        actionAdvanced_Search = new QAction(MainWindow);
        actionAdvanced_Search->setObjectName(QStringLiteral("actionAdvanced_Search"));
        actionWord_Statitics = new QAction(MainWindow);
        actionWord_Statitics->setObjectName(QStringLiteral("actionWord_Statitics"));
        actionWord_Analysis = new QAction(MainWindow);
        actionWord_Analysis->setObjectName(QStringLiteral("actionWord_Analysis"));
        actionSyntactical_Analysis = new QAction(MainWindow);
        actionSyntactical_Analysis->setObjectName(QStringLiteral("actionSyntactical_Analysis"));
        actionMaps = new QAction(MainWindow);
        actionMaps->setObjectName(QStringLiteral("actionMaps"));
        actionTimelines = new QAction(MainWindow);
        actionTimelines->setObjectName(QStringLiteral("actionTimelines"));
        actionVideos = new QAction(MainWindow);
        actionVideos->setObjectName(QStringLiteral("actionVideos"));
        actionGraphics = new QAction(MainWindow);
        actionGraphics->setObjectName(QStringLiteral("actionGraphics"));
        action3D_Models = new QAction(MainWindow);
        action3D_Models->setObjectName(QStringLiteral("action3D_Models"));
        actionStyle_Analysis = new QAction(MainWindow);
        actionStyle_Analysis->setObjectName(QStringLiteral("actionStyle_Analysis"));
        actionSemantical_Analysis = new QAction(MainWindow);
        actionSemantical_Analysis->setObjectName(QStringLiteral("actionSemantical_Analysis"));
        actionHebrew_Calendar = new QAction(MainWindow);
        actionHebrew_Calendar->setObjectName(QStringLiteral("actionHebrew_Calendar"));
        actionGematria_calculator = new QAction(MainWindow);
        actionGematria_calculator->setObjectName(QStringLiteral("actionGematria_calculator"));
        actionSymbols = new QAction(MainWindow);
        actionSymbols->setObjectName(QStringLiteral("actionSymbols"));
        actionScripts = new QAction(MainWindow);
        actionScripts->setObjectName(QStringLiteral("actionScripts"));
        actionAleppo = new QAction(MainWindow);
        actionAleppo->setObjectName(QStringLiteral("actionAleppo"));
        actionBHS = new QAction(MainWindow);
        actionBHS->setObjectName(QStringLiteral("actionBHS"));
        action_New = new QAction(MainWindow);
        action_New->setObjectName(QStringLiteral("action_New"));
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/faenza/actions/16/assets/icons/faenza/actions/16/document-new.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_New->setIcon(icon19);
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
        menuBar->setGeometry(QRect(0, 0, 944, 20));
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
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuAnalytics = new QMenu(menuTools);
        menuAnalytics->setObjectName(QStringLiteral("menuAnalytics"));
        menuFeatures = new QMenu(menuTools);
        menuFeatures->setObjectName(QStringLiteral("menuFeatures"));
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
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuExtras->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionNew);
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
        menuWindows->addAction(action_Fullscreen);
        menuWindows->addSeparator();
        menuWindows->addAction(action_Cascade);
        menuWindows->addAction(action_Tile);
        menuWindows->addSeparator();
        menuWindows->addAction(actionSymbols);
        menuWindows->addAction(actionScripts);
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
        menuTools->addAction(actionAdvanced_Search);
        menuTools->addSeparator();
        menuTools->addAction(menuAnalytics->menuAction());
        menuTools->addAction(menuFeatures->menuAction());
        menuAnalytics->addAction(actionWord_Statitics);
        menuAnalytics->addAction(actionWord_Analysis);
        menuAnalytics->addAction(actionSyntactical_Analysis);
        menuAnalytics->addAction(actionStyle_Analysis);
        menuAnalytics->addAction(actionSemantical_Analysis);
        menuAnalytics->addAction(actionHebrew_Calendar);
        menuAnalytics->addAction(actionGematria_calculator);
        menuFeatures->addAction(actionTimelines);
        menuFeatures->addAction(actionMaps);
        menuFeatures->addAction(action3D_Models);
        menuFeatures->addAction(actionVideos);
        menuFeatures->addAction(actionGraphics);
        toolBar->addAction(actionOpen);
        toolBar->addAction(action_New);
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Emmeth", nullptr));
        actionQuit->setText(QApplication::translate("MainWindow", "&Quit", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "&About", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "&Open", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "&Save", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionPrint->setText(QApplication::translate("MainWindow", "&Print", nullptr));
#ifndef QT_NO_SHORTCUT
        actionPrint->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave_As->setText(QApplication::translate("MainWindow", "Save &As", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave_As->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_NO_SHORTCUT
        action_Settings->setText(QApplication::translate("MainWindow", "&Settings", nullptr));
        actionAbout_Book->setText(QApplication::translate("MainWindow", "About Book", nullptr));
        actionHelp->setText(QApplication::translate("MainWindow", "Content", nullptr));
        actionPlugins->setText(QApplication::translate("MainWindow", "&Plugins", nullptr));
        actionContextual_Help->setText(QApplication::translate("MainWindow", "Contextual Help", nullptr));
#ifndef QT_NO_SHORTCUT
        actionContextual_Help->setShortcut(QApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_NO_SHORTCUT
        actionIndex->setText(QApplication::translate("MainWindow", "&Index", nullptr));
        actionNew->setText(QApplication::translate("MainWindow", "New", nullptr));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("MainWindow", "New File", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionCut->setText(QApplication::translate("MainWindow", "Cut", nullptr));
#ifndef QT_NO_TOOLTIP
        actionCut->setToolTip(QApplication::translate("MainWindow", "Cut", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_NO_SHORTCUT
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", nullptr));
#ifndef QT_NO_TOOLTIP
        actionPaste->setToolTip(QApplication::translate("MainWindow", "Paste", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_NO_SHORTCUT
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", nullptr));
#ifndef QT_NO_TOOLTIP
        actionUndo->setToolTip(QApplication::translate("MainWindow", "undo", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_NO_SHORTCUT
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", nullptr));
#ifndef QT_NO_TOOLTIP
        actionRedo->setToolTip(QApplication::translate("MainWindow", "redo", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", nullptr));
#endif // QT_NO_SHORTCUT
        actionLogin->setText(QApplication::translate("MainWindow", "Login", nullptr));
        actionZoomIn->setText(QApplication::translate("MainWindow", "ZoomIn", nullptr));
#ifndef QT_NO_TOOLTIP
        actionZoomIn->setToolTip(QApplication::translate("MainWindow", "zoom in", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionZoomIn->setShortcut(QApplication::translate("MainWindow", "Ctrl++", nullptr));
#endif // QT_NO_SHORTCUT
        actionZoomOut->setText(QApplication::translate("MainWindow", "ZoomOut", nullptr));
#ifndef QT_NO_TOOLTIP
        actionZoomOut->setToolTip(QApplication::translate("MainWindow", "zoom out", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionZoomOut->setShortcut(QApplication::translate("MainWindow", "Ctrl+-", nullptr));
#endif // QT_NO_SHORTCUT
        actionZoomOriginal->setText(QApplication::translate("MainWindow", "ZoomOriginal", nullptr));
#ifndef QT_NO_TOOLTIP
        actionZoomOriginal->setToolTip(QApplication::translate("MainWindow", "zoom original size", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionZoomOriginal->setShortcut(QApplication::translate("MainWindow", "Ctrl+0", nullptr));
#endif // QT_NO_SHORTCUT
        action_Library->setText(QApplication::translate("MainWindow", "&Library", nullptr));
        action_Bookshop->setText(QApplication::translate("MainWindow", "&Bookshop", nullptr));
        action_Fullscreen->setText(QApplication::translate("MainWindow", "&Fullscreen", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Fullscreen->setShortcut(QApplication::translate("MainWindow", "F11", nullptr));
#endif // QT_NO_SHORTCUT
        action_Cascade->setText(QApplication::translate("MainWindow", "&Cascade", nullptr));
        action_Tile->setText(QApplication::translate("MainWindow", "&Tile", nullptr));
        action_Dictionaries->setText(QApplication::translate("MainWindow", "&Dictionaries", nullptr));
        action_Lexicas->setText(QApplication::translate("MainWindow", "&Lexicas", nullptr));
        actionWLC->setText(QApplication::translate("MainWindow", "Westminster Leningrad Codex", nullptr));
        actionAdvanced_Search->setText(QApplication::translate("MainWindow", "Advanced &Search", nullptr));
        actionWord_Statitics->setText(QApplication::translate("MainWindow", "Word Statitics", nullptr));
        actionWord_Analysis->setText(QApplication::translate("MainWindow", "Word Analysis", nullptr));
        actionSyntactical_Analysis->setText(QApplication::translate("MainWindow", "Syntactical Analysis", nullptr));
        actionMaps->setText(QApplication::translate("MainWindow", "Maps", nullptr));
        actionTimelines->setText(QApplication::translate("MainWindow", "Timelines", nullptr));
        actionVideos->setText(QApplication::translate("MainWindow", "Videos", nullptr));
        actionGraphics->setText(QApplication::translate("MainWindow", "Graphics", nullptr));
        action3D_Models->setText(QApplication::translate("MainWindow", "3D Models", nullptr));
        actionStyle_Analysis->setText(QApplication::translate("MainWindow", "Style Analysis", nullptr));
        actionSemantical_Analysis->setText(QApplication::translate("MainWindow", "Semantical Analysis", nullptr));
        actionHebrew_Calendar->setText(QApplication::translate("MainWindow", "Hebrew Calendar", nullptr));
        actionGematria_calculator->setText(QApplication::translate("MainWindow", "Gematria calculator", nullptr));
        actionSymbols->setText(QApplication::translate("MainWindow", "Symbols", nullptr));
        actionScripts->setText(QApplication::translate("MainWindow", "Scripts", nullptr));
        actionAleppo->setText(QApplication::translate("MainWindow", "Aleppo Codex", nullptr));
        actionBHS->setText(QApplication::translate("MainWindow", "BHS", nullptr));
        action_New->setText(QApplication::translate("MainWindow", "&New", nullptr));
#ifndef QT_NO_STATUSTIP
        action_New->setStatusTip(QApplication::translate("MainWindow", "Create a new file.", nullptr));
#endif // QT_NO_STATUSTIP
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "&Edit", nullptr));
        menuWindows->setTitle(QApplication::translate("MainWindow", "&Windows", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "&Help", nullptr));
        menuExtras->setTitle(QApplication::translate("MainWindow", "E&xtras", nullptr));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", nullptr));
        menuAnalytics->setTitle(QApplication::translate("MainWindow", "Analytics", nullptr));
        menuFeatures->setTitle(QApplication::translate("MainWindow", "Features", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

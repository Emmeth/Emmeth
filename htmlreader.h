#ifndef HTMLREADER_H
#define HTMLREADER_H


/**
 * @brief
 *
 */
class HtmlReader
{
public:
    /**
     * @brief
     *
     */
    HtmlReader();
    /**
     * @brief
     *
     */
    ~HtmlReader();

public slots:
    void navigate(const QString &address);
    void on_WebBrowser_TitleChange(const QString &title);
    void on_WebBrowser_ProgressChange(int a, int b);
    void on_WebBrowser_CommandStateChange(int cmd, bool on);
    void on_WebBrowser_BeforeNavigate();
    void on_WebBrowser_NavigateComplete(const QString &address);

    void on_actionGo_triggered();
    void on_actionNewWindow_triggered();
    void on_actionAddBookmark_triggered();
    void on_actionAbout_triggered();
    void on_actionAboutQt_triggered();
    void on_actionFileClose_triggered();
private:
    /**
     * @brief
     *
     */
    void read();
    /**
     * @brief
     *
     */
    void write();
    inline const QString address() const
            { return addressEdit->text().trimmed(); }
        QList<Location> bookmarks() const;
        QAction *addLocation(const Location &location, QMenu *menu);
        inline void addBookmark(const Location &location)
            { bookmarkActions << addLocation(location, BookmarksMenu); }

        QProgressBar *pb;
        QLineEdit *addressEdit;
        QList<QAction *> bookmarkActions;
        QList<QAction *> historyActions;
        QSignalMapper locationActionMapper;
};

#endif // HTMLREADER_H

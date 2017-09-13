#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QString>
#include <QFile>
#include <QTextEdit>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QWindow>
#include <QObject>
#include <QTextEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QComboBox>

/**
 * @brief
 *
 */
class TextEditor : public QWidget
{
    Q_OBJECT
public:
    TextEditor(QWidget *parent = 0);
    /**
     * @brief
     *
     */
    ~TextEditor();
    /**
     * @brief
     *
     * @param fileName
     * @return QString
     */
    QString read(QString fileName);
    /**
     * @brief
     *
     * @return bool
     */
    bool write();
    /**
     * @brief
     *
     * @param string
     */
    QString fileName; /**< TODO: describe */
    QString saveFileName;

protected:
    void textAlignCenter();
private slots:
    void textBold();
    void textItalic();
    void textUnderline();
    void textStrikethrough();
    void textAlignLeft();
    void textAlignRight();
    void cut();
    void paste();
    void newFile();
    void saveAs();
    bool saveFile();
    void undo();
    void redo();
    void openFile();
    void closeFile();
    void copy();
    void textAlignFill();
    void textLTR();
    void textRTL();
    void currentCharFormatChanged(const QTextCharFormat &format);
    void cursorPositionChanged();
    void clipboardDataChanged();
    void textStyle(int styleIndex);
    void textSize(const QString &p);
    void textFamily(const QString &f);
private:
    QFile file; /**< TODO: describe */
    QString content; /**< TODO: describe */
    QTextEdit *textEdit; /**< TODO: describe */
    QGridLayout *gridLayout; /**< TODO: describe */
    QWidget *widget; /**< TODO: describe */
    QVBoxLayout* vBoxLayout;
    QHBoxLayout* hBoxLayoutActions;
    QHBoxLayout* hBoxLayoutFormat;
    QHBoxLayout* hBoxLayoutFeatures;
    QComboBox *comboFont;
    QStringList fonts;
    QComboBox *comboSize;
    QComboBox *comboStyle;
    QStringList fontSizes;
    QPushButton *btnBold;
    QPushButton *btnItalic;
    QPushButton *btnUnderline;
    QPushButton *btnStrikethrough;
    QPushButton *btnAlignLeft;
    QPushButton *btnAlignCenter;
    QPushButton *btnAlignJustify;
    QPushButton *btnAlignRight;
    QPushButton *btnLTR;
    QPushButton *btnRTL;
    QFont *textFont;
    QPushButton *btnIndentMore;
    QPushButton *btnIndentLess;
    QPushButton *btnList;
    QPushButton *btnSpellcheck;
    QPushButton *btnNewFile;
    QPushButton *btnOpenFile;
    QPushButton *btnSaveFile;
    QPushButton *btnSaveAsFile;
    QPushButton *btnUndo;
    QPushButton *btnRedo;
    QPushButton *btnCopy;
    QPushButton *btnCut;
    QPushButton *btnPaste;

    void mergeFormatOnWordOrSelection(const QTextCharFormat &format);
    void fontChanged(const QFont &f);
    void colorChanged(const QColor &c);
    void alignmentChanged(Qt::Alignment a);
    void setCurrentFileName(const QString &fileName);
    bool maybeSave();
};

#endif // TXTEDITOR_H

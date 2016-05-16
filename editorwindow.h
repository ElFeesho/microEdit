#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H

#include <QMainWindow>
#include <QList>
#include "filerecord.h"
#include "syntaxhighlighter.h"

namespace Ui {

    class EditorWindow;

}

class EditorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditorWindow(QWidget *parent = 0);
    ~EditorWindow();

    QString newFileName();

    void keyPressEvent(QKeyEvent *);
public slots:
    void textEntered();

private:
    QList<FileRecord*> files;
    Ui::EditorWindow *ui;
    SyntaxHighlighter highlighter;
};

#endif // EDITORWINDOW_H

#ifndef EDITORSTATUSBAR_H
#define EDITORSTATUSBAR_H

#include <QWidget>
#include <QLabel>
#include <QStatusBar>

class EditorStatusBar : public QStatusBar
{
    Q_OBJECT
public:
    EditorStatusBar(QWidget *widget = nullptr);

    void clearPosition();
public slots:
    void updateEditorPosition(long columns, long lines);

private:
    QLabel *colsLinesLabel;
};

#endif // EDITORSTATUSBAR_H

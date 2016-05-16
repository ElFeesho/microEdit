#include "editorstatusbar.h"

EditorStatusBar::EditorStatusBar(QWidget *parent) : QStatusBar(parent), colsLinesLabel(new QLabel(this))
{
    addPermanentWidget(colsLinesLabel);
}

void EditorStatusBar::updateEditorPosition(long columns, long lines)
{
    colsLinesLabel->setText(QString::asprintf("%ld:%ld", columns, lines));
}

void EditorStatusBar::clearPosition()
{
    colsLinesLabel->setText("-:-");
}

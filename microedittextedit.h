#ifndef MICROEDITTEXTEDIT_H
#define MICROEDITTEXTEDIT_H

#include "linecountwidget.h"

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QPlainTextEdit>

class MicroEditTextEdit : public QWidget
{
    Q_OBJECT
public:
    MicroEditTextEdit(QWidget *parent = nullptr);
    QString getText() const;
    void setText(QString text);

signals:
    void editorPositionUpdated(long columns, long lines);

private:
    QHBoxLayout *hbox;
    LineCountWidget *gutter;
    QPlainTextEdit *plainText;
};

#endif // MICROEDITTEXTEDIT_H

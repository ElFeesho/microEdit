#ifndef LINECOUNTWIDGET_H
#define LINECOUNTWIDGET_H

#include <QWidget>

class LineCountWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LineCountWidget(QWidget *parent = 0);

    void paintEvent(QPaintEvent *);

    void totalLines(long lines);
    void offsetLines(long offset);
private:
    int maxLines;
    int lineOffset;
};

#endif // LINECOUNTWIDGET_H

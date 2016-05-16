#include "linecountwidget.h"
#include <QPaintEvent>
#include <QPainter>
#include <QStyle>

LineCountWidget::LineCountWidget(QWidget *parent) : QWidget(parent), maxLines{1}, lineOffset{0}
{

}

void LineCountWidget::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);

    painter.setFont(QFont("Courier New"));
    painter.setPen(QColor(255, 255, 255));
    painter.fillRect(rect(), QColor(60, 60, 60));

    auto lineHeight = painter.fontMetrics().height();
    auto characterWidth = painter.fontMetrics().width("M");
    for(int i = 0; i <= maxLines; i++)
    {
        auto num = QString::number(i+lineOffset);
        painter.drawText(QPoint(width() - num.length()*characterWidth, lineHeight * i), num);
    }

    painter.end();
}

void LineCountWidget::totalLines(long lines)
{
    maxLines = lines;
    repaint();
}

void LineCountWidget::offsetLines(long offset)
{
    lineOffset = offset;
    repaint();
}

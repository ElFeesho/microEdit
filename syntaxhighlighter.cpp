#include "syntaxhighlighter.h"

SyntaxHighlighter::SyntaxHighlighter()
{

}

void SyntaxHighlighter::highlight(const QString &input, std::function<void (long, long, const QColor &)> delegate)
{
    delegate(0, input.length(), QColor(0, 128, 255));
}

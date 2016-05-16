#ifndef SYNTAXHIGHLIGHTER_H
#define SYNTAXHIGHLIGHTER_H

#include <functional>

#include <QString>
#include <QColor>

class SyntaxHighlighter
{
public:
    SyntaxHighlighter();

    void highlight(const QString &input, std::function<void(long start, long len, const QColor& colour)> delegate);
};

#endif // SYNTAXHIGHLIGHTER_H

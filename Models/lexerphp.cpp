#include "lexerphp.h"
#include <QRegularExpression>

LexerPhp::LexerPhp(QObject *parent)
    : QSyntaxHighlighter(parent)
{
    initFormats();
}

void LexerPhp::highlightBlock(const QString &text)
{
    QRegularExpression keywordRegex("\\b(?:echo|if|else|while|for|function|class|return)\\b");
    QRegularExpressionMatchIterator keywordIterator = keywordRegex.globalMatch(text);
    while (keywordIterator.hasNext()) {
        QRegularExpressionMatch match = keywordIterator.next();
        setFormat(match.capturedStart(), match.capturedLength(), keywordFormat);
    }

    QRegularExpression commentRegex("//[^\n]*");
    QRegularExpressionMatchIterator commentIterator = commentRegex.globalMatch(text);
    while (commentIterator.hasNext()) {
        QRegularExpressionMatch match = commentIterator.next();
        setFormat(match.capturedStart(), match.capturedLength(), commentFormat);
    }

    QRegularExpression stringRegex("\".*?\"");
    QRegularExpressionMatchIterator stringIterator = stringRegex.globalMatch(text);
    while (stringIterator.hasNext()) {
        QRegularExpressionMatch match = stringIterator.next();
        setFormat(match.capturedStart(), match.capturedLength(), stringFormat);
    }
}

void LexerPhp::initFormats()
{
    keywordFormat.setForeground(Qt::blue);
    keywordFormat.setFontWeight(QFont::Bold);

    commentFormat.setForeground(Qt::green);
    commentFormat.setFontItalic(true);

    stringFormat.setForeground(Qt::darkRed);
}

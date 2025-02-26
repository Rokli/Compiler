#ifndef LEXERPHP_H
#define LEXERPHP_H

#include <QSyntaxHighlighter>
#include <QTextCharFormat>

class LexerPhp : public QSyntaxHighlighter
{
public:
    explicit LexerPhp(QObject *parent = nullptr);
protected:
    void highlightBlock(const QString &text) override;
private:
    QTextCharFormat keywordFormat;
    QTextCharFormat commentFormat;
    QTextCharFormat stringFormat;

    void initFormats();
};

#endif // LEXERPHP_H

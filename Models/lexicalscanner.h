#ifndef LEXICALSCANNER_H
#define LEXICALSCANNER_H
#include <QString>
#include <QTableWidget>

enum TokenType {
    TOKEN_DEFINE = 1,
    TOKEN_TRUE,
    TOKEN_FALSE,
    TOKEN_IDENTIFIER,
    TOKEN_INT,
    TOKEN_FLOAT,
    TOKEN_STRING,
    TOKEN_SEMICOLON,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_ARRAY,
    TOKEN_ARRAY_START,
    TOKEN_ARRAY_END,
    TOKEN_COMMA,
    TOKEN_UNKNOWN,
    TOKEN_NULL,
    TOKEN_END
};

struct Token {
    TokenType type;
    QString value;
    int line;
    int start;
    int end;
};

class LexicalScanner
{
public:
    LexicalScanner(const QString& input);
    Token getNextToken();
    void analyzeToTable(QTableWidget* table);
    bool hasSyntaxError() const;

private:
    QString input;
    int position;
    int lineNumber;
    bool syntaxError;
    bool foundDefine;
    bool foundName;
    bool expectingConstantName;
    bool expectingLparen;
    bool expectingRparen;
    bool expectingSemicolon;
    bool expectingArray;
    bool inArray;

    bool peekKeyword(const QString& keyword);
    Token readString(QChar quoteChar);
    void advance();
    Token createToken(TokenType type, const QString &value, int startColumn, int endColumn);
};

#endif // LEXICALSCANNER_H

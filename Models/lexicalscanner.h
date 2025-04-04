#ifndef LEXICALSCANNER_H
#define LEXICALSCANNER_H

#include <QString>
#include <QTableWidget>
#include <QChar>

// Типы токенов
enum TokenType {
    TOKEN_UNKNOWN,      // Неизвестный токен
    TOKEN_DEFINE,       // Ключевое слово define
    TOKEN_IDENTIFIER,   // Идентификатор (имя константы)
    TOKEN_STRING,       // Строка
    TOKEN_INT,          // Целое число
    TOKEN_FLOAT,        // Число с плавающей точкой
    TOKEN_LPAREN,       // Открывающая скобка '('
    TOKEN_RPAREN,       // Закрывающая скобка ')'
    TOKEN_COMMA,        // Запятая ','
    TOKEN_SEMICOLON,    // Точка с запятой ';'
    TOKEN_END           // Конец входных данных
};

struct Token {
    TokenType type;
    QString value;
    int lineNumber;
    int startPos;
    int endPos;
};

class LexicalScanner {
public:
    LexicalScanner(const QString &input);

    Token getNextToken();
    void analyzeToTable(QTableWidget *table);
    bool hasSyntaxError() const;

private:
    void advance();
    Token createToken(TokenType type, const QString &value, int start, int end);
    bool peekKeyword(const QString &keyword);
    Token readString(QChar quoteChar);
    bool isRussianLetter(QChar ch);

    QString input;
    int position;
    int lineNumber;
    bool syntaxError;

    bool foundDefine;
    bool foundName;
    bool foundComma;
    bool foundValue;
    bool foundRParen;
    bool foundSemicolon;
};

#endif // LEXICALSCANNER_H

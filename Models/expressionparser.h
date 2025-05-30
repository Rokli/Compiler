#ifndef EXPRESSIONPARSER_H
#define EXPRESSIONPARSER_H

#include <QString>
#include <QTableWidget>
#include <QChar>

class ExpressionParser {
public:
    ExpressionParser(const QString& input);
    void analyze(QTableWidget* table);

private:
    QString input;
    int pos;
    QChar currentChar;
    QTableWidget* errorTable;
    int errorCount;
    QStringList callSequence;

    void nextChar();
    void skipWhitespace();
    void addError(const QString& message);
    void addCall(const QString& functionName);
    bool matchString(const QString& str);

    void parseConditionalOperator();
    void parseCondition();
    void parseRelationalOperation();
    void parseExpression();
    void parseTerm();
    void parseMultiplier();
    void parseIdentifier();
    void parseOperator();
};

#endif // EXPRESSIONPARSER_H

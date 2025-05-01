#ifndef EXPRESSIONPARSER_H
#define EXPRESSIONPARSER_H

#include <QString>
#include <QStringList>
#include <QStack>
#include <QTableWidget>
#include <QRegularExpression>

class ExpressionParser {
public:
    ExpressionParser(const QString& expression);
    void analyze(QTableWidget* table);

private:
    QString expression;
    QStringList tokens;
    QStringList poliz;
    QString errorMsg;
    int pos = 0;

    void tokenize();
    bool parseExpression();
    bool parseAddSub();
    bool parseMulDiv();
    bool parseFactor();
    double evalPoliz(bool& ok);
    void analyzeToTable(QTableWidget* table);
};

#endif // EXPRESSIONPARSER_H

#ifndef EXPRESSIONPARSER_H
#define EXPRESSIONPARSER_H

#include <QString>
#include <QStringList>
#include <QStack>
#include <QTableWidget>
#include <QRegularExpression>
#include <vector>

class ExpressionParser {
public:
    struct ParseError {
        int position;
        QString message;
        QString context;
    };

    ExpressionParser(const QString& expression);
    void analyze(QTableWidget* table);

    const std::vector<ParseError>& errors() const { return m_errors; }
    bool hasErrors() const { return !m_errors.empty(); }

private:
    QString m_expression;
    QStringList m_tokens;
    QStringList m_poliz;
    std::vector<ParseError> m_errors;
    int m_pos = 0;

    void tokenize();
    bool parseExpression();
    bool parseAddSub();
    bool parseMulDiv();
    bool parseFactor();
    double evalPoliz(bool& ok);
    void analyzeToTable(QTableWidget* table);

    void addError(const QString& message, int pos = -1);
    QString getErrorContext(int pos) const;
};

#endif // EXPRESSIONPARSER_H

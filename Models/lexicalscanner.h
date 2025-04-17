#ifndef LEXICALSCANNER_H
#define LEXICALSCANNER_H

#include <QString>
#include <QTableWidget>
#include <QVector>
#include <QPair>

class LexicalScanner {
public:
    explicit LexicalScanner(const QString& input);
    void analyzeToTable(QTableWidget* table);

private:
    QString input;
    QVector<QString> lines;
    QVector<QString> errors;

    void parseLine(const QString& line, int lineNumber);
    bool isValidIdentifier(const QString& str);
    void addError(int lineNumber, const QString& message);
};

#endif // LEXICALSCANNER_H

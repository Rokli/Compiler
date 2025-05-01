#ifndef PATTERNMATCHER_H
#define PATTERNMATCHER_H

#include <QString>
#include <QTableWidget>

class PatternMatcher {
public:
    PatternMatcher(const QString& inputText);

    void findUSZipCodes(QTableWidget* table);
    void findYearsInRange(QTableWidget* table);
    void findRealNumbersWithExponent(QTableWidget* table);

    void analyzeText(QTableWidget* table, int taskNumber);

private:
    QString text;
    void parseAndFillTable(const QRegularExpression& regex, QTableWidget* table);
};

#endif // PATTERNMATCHER_H

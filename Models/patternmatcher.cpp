#include "patternmatcher.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QTableWidgetItem>

PatternMatcher::PatternMatcher(const QString& inputText) : text(inputText) {}

void PatternMatcher::findUSZipCodes(QTableWidget* table) {
    QRegularExpression regex(R"((?:^|\s)(\d{5}(?:-\d{4})?)(?=$|\s|[,\.]))");
    parseAndFillTable(regex, table);
}

void PatternMatcher::findYearsInRange(QTableWidget* table) {
    QRegularExpression regex(R"((?:^|\s)(199[89]|200[0-4])(?=$|\s|[^\w]))");
    parseAndFillTable(regex, table);
}

void PatternMatcher::findRealNumbersWithExponent(QTableWidget* table) {
    QRegularExpression regex(R"((?:^|\s)([+-]?(?:\d+\.?\d*|\.\d+)(?:[eE][+-]?\d+)?)(?=$|\s|[^\w\.]))");
    parseAndFillTable(regex, table);
}

void PatternMatcher::analyzeText(QTableWidget* table, int taskNumber) {
    switch(taskNumber) {
    case 2: findUSZipCodes(table); break;
    case 18: findYearsInRange(table); break;
    case 20: findRealNumbersWithExponent(table); break;
    default: break;
    }
}

void PatternMatcher::parseAndFillTable(const QRegularExpression& regex, QTableWidget* table) {
    table->clearContents();
    table->setRowCount(0);

    if (!regex.isValid()) {
        qDebug() << "Invalid regex:" << regex.errorString();
        return;
    }

    QRegularExpressionMatchIterator matchIterator = regex.globalMatch(text);
    while (matchIterator.hasNext()) {
        QRegularExpressionMatch match = matchIterator.next();
        int row = table->rowCount();
        table->insertRow(row);

        table->setItem(row, 0, new QTableWidgetItem(match.captured()));
        table->setItem(row, 1, new QTableWidgetItem(QString::number(match.capturedStart())));
    }
}


#include "lexicalscanner.h"
#include <QRegularExpression>

LexicalScanner::LexicalScanner(const QString& input) : input(input) {
    lines = input.split('\n');
}

void LexicalScanner::analyzeToTable(QTableWidget* table) {
    errors.clear();
    for (int i = 0; i < lines.size(); ++i) {
        parseLine(lines[i].trimmed(), i + 1);
    }

    table->setRowCount(errors.size() + 1);
    table->setColumnCount(1);
    table->setHorizontalHeaderLabels(QStringList() << "Ошибки");

    for (int i = 0; i < errors.size(); ++i) {
        table->setItem(i, 0, new QTableWidgetItem(errors[i]));
    }

    table->setItem(errors.size(), 0,
                   new QTableWidgetItem(QString("Всего ошибок: %1").arg(errors.size())));
}

void LexicalScanner::parseLine(const QString& line, int lineNumber) {
    if (line.isEmpty()) return;

    bool hasDefine = line.contains(QRegularExpression(R"(\bdefine\b)"));
    if (!hasDefine) {
        addError(lineNumber, "Ошибка: отсутствует ключевое слово define");
    }

    bool hasOpeningParen = line.contains('(');
    bool hasClosingParen = line.contains(')');
    bool hasSemicolon = line.contains(';');
    bool semicolonAfterParen = line.contains(");");
    bool hasComma = line.contains(',');

    if (!hasOpeningParen)
        addError(lineNumber, "Ошибка: отсутствует открывающая скобка");

    if (!hasClosingParen)
        addError(lineNumber, "Ошибка: отсутствует закрывающая скобка");

    if (!hasSemicolon)
        addError(lineNumber, "Ошибка: отсутствует завершающий оператор ;");

    if (hasClosingParen && hasSemicolon && !semicolonAfterParen)
        addError(lineNumber, "Ошибка: точка с запятой должна стоять сразу после закрывающей скобки");

    // Проверка имени константы
    QRegularExpression nameRegex(R"(\s*\(\s*(['"])?([A-Za-z_][A-Za-z0-9_]*)\1?)");
    if (!nameRegex.match(line).hasMatch())
        addError(lineNumber, "Ошибка: отсутствует имя константы");

    if (!hasComma)
        addError(lineNumber, "Ошибка: отсутствует запятая");

    // Попробуем достать значение
    if (hasClosingParen) {
        QRegularExpression valueRegex(R"(,\s*(.+?)\s*\))");
        QRegularExpressionMatch valueMatch = valueRegex.match(line);
        if (valueMatch.hasMatch()) {
            QString value = valueMatch.captured(1).trimmed();

            // Проверка на незакрытую строку
            if ((value.startsWith("\"") && !value.endsWith("\"")) ||
                (value.startsWith("'") && !value.endsWith("'"))) {
                addError(lineNumber, "Ошибка: незакрытая строка");
            }

            // Проверка допустимого значения
            QRegularExpression validValueRegex(R"(^(true|false|null|[+-]?\d+(\.\d+)?|(['"]).*\3)$)", QRegularExpression::CaseInsensitiveOption);
            if (!validValueRegex.match(value).hasMatch()) {
                addError(lineNumber, "Ошибка: отсутствует значение константы или оно некорректно");
            }
        } else {
            addError(lineNumber, "Ошибка: отсутствует значение константы");
        }
    }
}



void LexicalScanner::addError(int lineNumber, const QString& message) {
    errors.append(QString("Строка %1: %2").arg(lineNumber).arg(message));
}

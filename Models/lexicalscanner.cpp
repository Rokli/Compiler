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

    QRegularExpression nameRegex(R"(\(\s*(['"]))");
    QRegularExpressionMatch nameMatch = nameRegex.match(line);
    if (nameMatch.hasMatch()) {
        QString quote = nameMatch.captured(1);
        int start = line.indexOf(quote);
        int end = line.indexOf(quote, start + 1);
        if (end == -1) {
            addError(lineNumber, "Ошибка: незакрытая строка в имени константы");
        }
    } else {
        addError(lineNumber, "Ошибка: отсутствует имя константы");
    }

    if (!hasComma)
        addError(lineNumber, "Ошибка: отсутствует запятая");

    if (hasComma) {
        int commaPos = line.indexOf(',');
        QString valuePart = line.mid(commaPos + 1).trimmed();

        valuePart = valuePart.replace(QRegularExpression(R"([);].*$)"), "").trimmed();

        if (valuePart.isEmpty()) {
            addError(lineNumber, "Ошибка: отсутствует значение константы");
        } else {
            if ((valuePart.startsWith("\"") && !valuePart.endsWith("\"")) ||
                (valuePart.startsWith("'") && !valuePart.endsWith("'"))) {
                addError(lineNumber, "Ошибка: незакрытая строка в значении");
            }

            QRegularExpression validValueRegex(R"(^(true|false|null|[+-]?\d+(\.\d+)?|(['"]).*\3)$)",
                                               QRegularExpression::CaseInsensitiveOption);
            if (!validValueRegex.match(valuePart).hasMatch()) {
                addError(lineNumber, "Ошибка: значение константы некорректно");
            }
        }
    }
}



void LexicalScanner::addError(int lineNumber, const QString& message) {
    errors.append(QString("Строка %1: %2").arg(lineNumber).arg(message));
}

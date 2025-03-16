#include "lexicalscanner.h"
#include <stdexcept>

LexicalScanner::LexicalScanner(const QString &input)
    : input(input), position(0), lineNumber(1), syntaxError(false), foundDefine(false), foundName(false), expectingConstantName(false), inArray(false) {}

void LexicalScanner::advance() {
    position++;
}

Token LexicalScanner::createToken(TokenType type, const QString &value, int start, int end) {
    return {type, value, lineNumber, start, end};
}

bool LexicalScanner::peekKeyword(const QString& keyword) {
    return input.mid(position, keyword.length()) == keyword;
}

Token LexicalScanner::readString(QChar quoteChar) {
    int start = position;
    QString str;
    advance();
    while (position < input.length() && input[position] != quoteChar) {
        str += input[position];
        advance();
    }

    if (position >= input.length() || input[position] != quoteChar) {
        syntaxError = true;
        return createToken(TOKEN_UNKNOWN, "Ошибка: незакрытая строка", start, position);
    }

    advance();

    if (expectingConstantName) {
        foundName = true;
        expectingConstantName = false;
        return createToken(TOKEN_IDENTIFIER, str, start, position);
    }

    return createToken(TOKEN_STRING, str, start, position);
}

Token LexicalScanner::getNextToken() {
    while (position < input.length()) {
        QChar currentChar = input[position];

        if (currentChar.isSpace()) {
            advance();
            continue;
        }

        if (peekKeyword("define")) {
            int start = position;
            position += 6;
            foundDefine = true;
            expectingConstantName = true;
            return createToken(TOKEN_DEFINE, "define", start, position);
        }

        if (currentChar == '(') {
            advance();
            return createToken(TOKEN_LPAREN, "(", position - 1, position);
        }

        if (currentChar == ')') {
            advance();
            return createToken(TOKEN_RPAREN, ")", position - 1, position);
        }

        if (currentChar == '[') {
            inArray = true;
            advance();
            return createToken(TOKEN_ARRAY_START, "[", position - 1, position);
        }

        if (currentChar == ']') {
            inArray = false;
            advance();
            return createToken(TOKEN_ARRAY_END, "]", position - 1, position);
        }

        if (currentChar == ',') {
            advance();
            return createToken(TOKEN_COMMA, ",", position - 1, position);
        }

        if (currentChar == ';') {
            advance();
            return createToken(TOKEN_SEMICOLON, ";", position - 1, position);
        }

        if (currentChar == '"' || currentChar == "'") {
            return readString(currentChar);
        }

        if (currentChar.isLetter() || currentChar == '_') {
            QString identifier;
            int start = position;
            while (position < input.length() && (input[position].isLetterOrNumber() || input[position] == '_')) {
                identifier += input[position];
                advance();
            }
            return createToken(TOKEN_IDENTIFIER, identifier, start, position);
        }

        if (currentChar.isDigit()) {
            QString number;
            int start = position;
            bool isFloat = false;
            while (position < input.length() && (input[position].isDigit() || input[position] == '.')) {
                if (input[position] == '.') {
                    isFloat = true;
                }
                number += input[position];
                advance();
            }
            return createToken(isFloat ? TOKEN_FLOAT : TOKEN_INT, number, start, position);
        }

        advance();
        return createToken(TOKEN_UNKNOWN, QString("Ошибка: неизвестный символ '%1'").arg(currentChar), position - 1, position);
    }
    return {TOKEN_END, "", lineNumber, position, position};
}

void LexicalScanner::analyzeToTable(QTableWidget* table) {
    table->setRowCount(0);
    table->setColumnCount(5);
    table->setHorizontalHeaderLabels({"Код состояния", "Значение", "Строка", "Начало", "Конец"});

    Token token;
    bool foundSemicolon = false;

    while ((token = getNextToken()).type != TOKEN_END) {
        int row = table->rowCount();
        table->insertRow(row);

        table->setItem(row, 0, new QTableWidgetItem(QString::number(token.type)));
        table->setItem(row, 1, new QTableWidgetItem(token.value));
        table->setItem(row, 2, new QTableWidgetItem(QString::number(token.line)));
        table->setItem(row, 3, new QTableWidgetItem(QString::number(token.start)));
        table->setItem(row, 4, new QTableWidgetItem(QString::number(token.end)));

        if (token.type == TOKEN_SEMICOLON) {
            foundSemicolon = true;
        }
    }

    if (!foundDefine) {
        table->insertRow(table->rowCount());
        table->setItem(table->rowCount() - 1, 1, new QTableWidgetItem("Ошибка: отсутствие define"));
    }

    if (!foundName) {
        table->insertRow(table->rowCount());
        table->setItem(table->rowCount() - 1, 1, new QTableWidgetItem("Ошибка: отсутствие имени константы"));
    }

    if (inArray) {
        table->insertRow(table->rowCount());
        table->setItem(table->rowCount() - 1, 1, new QTableWidgetItem("Ошибка: незакрытый массив"));
    }

    if (!foundSemicolon) {
        table->insertRow(table->rowCount());
        table->setItem(table->rowCount() - 1, 1, new QTableWidgetItem("Ошибка: отсутствует точка с запятой"));
    }
}

bool LexicalScanner::hasSyntaxError() const {
    return syntaxError;
}

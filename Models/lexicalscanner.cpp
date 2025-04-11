#include "lexicalscanner.h"
#include <stdexcept>

LexicalScanner::LexicalScanner(const QString &input)
    : input(input), position(0), lineNumber(1), syntaxError(false), foundDefine(false), foundName(false), foundComma(false),
    foundValue(false), foundRParen(false), foundSemicolon(false), foundLParen(false), semicolonAfterRParen(true) {}

void LexicalScanner::advance() {
    position++;
}

Token LexicalScanner::createToken(TokenType type, const QString &value, int start, int end) {
    return {type, value, lineNumber, start, end};
}

bool LexicalScanner::peekKeyword(const QString& keyword) {
    int len = keyword.length();

    if (input.mid(position, len) == keyword) {
        if (position + len < input.length()) {
            QChar nextChar = input[position + len];
            if (nextChar.isLetterOrNumber() || nextChar == '_') {
                syntaxError = true;
                return false;
            }
        }
        return true;
    }
    return false;
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
            return createToken(TOKEN_DEFINE, "define", start, position);
        }

        if (peekKeyword("true") || peekKeyword("false")) {
            int start = position;
            QString value = (input.mid(position, 4) == "true") ? "true" : "false";
            position += value.length();
            foundValue = true;
            return createToken(TOKEN_BOOL, value, start, position);
        }

        if (currentChar.isLetter() || currentChar == '_') {
            QString identifier;
            int start = position;
            while (position < input.length() && (input[position].isLetterOrNumber() || input[position] == '_')) {
                identifier += input[position];
                advance();
            }
            if (foundDefine) {
                foundName = true;
            }

            return createToken(TOKEN_IDENTIFIER, identifier, start, position);
        }

        if (currentChar.isDigit()) {
            QString number;
            int start = position;
            bool isFloat = false;
            while (position < input.length() && (input[position].isDigit() || input[position] == '.')) {
                if (input[position] == '.') {
                    if(!isFloat){
                        isFloat = true;
                    }else{ break;}
                }
                number += input[position];
                advance();
            }
            foundValue = true;
            return createToken(isFloat ? TOKEN_FLOAT : TOKEN_INT, number, start, position);
        }

        if (currentChar == '(' || currentChar == ')' || currentChar == ',' || currentChar == ';') {
            TokenType type;
            bool error = false;
            int start = position;

            switch (currentChar.unicode()) {
            case '(':
                foundLParen = true;
                type = TOKEN_LPAREN;
                break;
            case ')':
                foundRParen = true;
                type = TOKEN_RPAREN;
                if (position + 1 < input.length() && input[position+1] != ';') {
                    semicolonAfterRParen = false;
                }
                break;
            case ',':
                foundComma = true;
                type = TOKEN_COMMA;
                break;
            case ';':
                foundSemicolon = true;
                type = TOKEN_SEMICOLON;
                if (!foundRParen) {
                    semicolonAfterRParen = false;
                }
                break;
            default:
                type = TOKEN_UNKNOWN;
                break;
            }

            advance();
            return createToken(type, QString(currentChar), start, position);
        }


        if (currentChar == '"' || currentChar == '\'') {
            Token token = readString(currentChar);
            if (token.type == TOKEN_STRING) {
                foundName = true;
                defineArgsCount += 1;
            }
            if(foundName){
                foundValue = true;
            }
            return token;
        }
        advance();
        return createToken(TOKEN_UNKNOWN, QString("Ошибка: неизвестный символ '%1'").arg(currentChar), position - 1, position);
    }
    return {TOKEN_END, "", lineNumber, position, position};
}

void LexicalScanner::analyzeToTable(QTableWidget* table) {
    table->setRowCount(0);
    table->setColumnCount(1);
    table->setHorizontalHeaderLabels({"Ошибки"});

    Token token;
    int errorCount = 0;

    while ((token = getNextToken()).type != TOKEN_END) {
        if (token.type == TOKEN_UNKNOWN && token.value.contains("Ошибка")) {
            int row = table->rowCount();
            table->insertRow(row);
            table->setItem(row, 0, new QTableWidgetItem(token.value));
            errorCount++;
        }
    }

    if (!foundDefine) {
        table->insertRow(table->rowCount());
        table->setItem(table->rowCount() - 1, 0, new QTableWidgetItem("Ошибка: отсутствует ключевое слово define"));
        errorCount++;
    }
    if (foundDefine && !foundName) {
        table->insertRow(table->rowCount());
        table->setItem(table->rowCount() - 1, 0, new QTableWidgetItem("Ошибка: отсутствует имя константы"));
        errorCount++;
    }
    if (!foundLParen) {
        table->insertRow(table->rowCount());
        table->setItem(table->rowCount() - 1, 0, new QTableWidgetItem("Ошибка: отсутствует открывающая скобка"));
        errorCount++;
    }

    if (!foundRParen) {
        table->insertRow(table->rowCount());
        table->setItem(table->rowCount() - 1, 0, new QTableWidgetItem("Ошибка: отсутствует закрывающая скобка"));
        errorCount++;
    }

    if (!foundSemicolon) {
        table->insertRow(table->rowCount());
        table->setItem(table->rowCount() - 1, 0, new QTableWidgetItem("Ошибка: отсутствует завершающий оператор ;"));
        errorCount++;
    }

    if (!semicolonAfterRParen) {
        table->insertRow(table->rowCount());
        table->setItem(table->rowCount() - 1, 0, new QTableWidgetItem("Ошибка: точка с запятой должна стоять после закрывающей скобки"));
        errorCount++;
    }

    if (!foundValue) {
        table->insertRow(table->rowCount());
        table->setItem(table->rowCount() - 1, 0, new QTableWidgetItem("Ошибка: отсутствует значение константы"));
        errorCount++;
    }

    if (!foundComma) {
        table->insertRow(table->rowCount());
        table->setItem(table->rowCount() - 1, 0, new QTableWidgetItem("Ошибка: отсутствует запятая"));
        errorCount++;
    }

    table->insertRow(table->rowCount());
    table->setItem(table->rowCount() - 1, 0, new QTableWidgetItem(QString("Всего ошибок: %1").arg(errorCount)));
}

#include "expressionparser.h"
#include <QTableWidgetItem>

ExpressionParser::ExpressionParser(const QString& input)
    : input(input), pos(0), errorCount(0) {
    nextChar();
}

void ExpressionParser::nextChar() {
    if (pos < input.length()) {
        currentChar = input.at(pos++);
    } else {
        currentChar = QChar();
    }
}

void ExpressionParser::skipWhitespace() {
    while (currentChar.isSpace() && currentChar != QChar()) {
        nextChar();
    }
}

void ExpressionParser::addError(const QString& message) {
    errorTable->insertRow(errorCount);
    errorTable->setItem(errorCount, 0, new QTableWidgetItem(QString::number(errorCount + 1)));
    errorTable->setItem(errorCount, 1, new QTableWidgetItem("Ошибка: " + message));
    errorCount++;
}

void ExpressionParser::addCall(const QString& functionName) {
    callSequence.append(functionName);
}

bool ExpressionParser::matchString(const QString& str) {
    int savedPos = pos;
    QChar savedChar = currentChar;

    for (int i = 0; i < str.length(); ++i) {
        if (currentChar.toUpper() != str.at(i).toUpper()) {
            pos = savedPos;
            currentChar = savedChar;
            return false;
        }
        nextChar();
    }
    return true;
}

void ExpressionParser::parseConditionalOperator() {
    addCall("Условный оператор");
    skipWhitespace();

    if (!matchString("IF")) {
        addError("Ожидается IF в начале условного оператора");
        return;
    }
    skipWhitespace();

    parseCondition();
    skipWhitespace();

    if (!matchString("THEN")) {
        addError("Ожидается THEN после условия");
        return;
    }
    skipWhitespace();

    parseOperator();
}


void ExpressionParser::parseCondition() {
    addCall("Условие");
    parseExpression();
    skipWhitespace();
    parseRelationalOperation();
    skipWhitespace();
    parseExpression();
}

void ExpressionParser::parseRelationalOperation() {
    QString op;
    bool validOp = true;

    if (currentChar == '=') {
        nextChar();
        if (currentChar == '=') {
            op = "==";
            nextChar();
        } else {
            validOp = false;
        }
    }
    else if (currentChar == '<') {
        op = "<";
        nextChar();
        if (currentChar == '=') {
            op = "<=";
            nextChar();
        }
    }
    else if (currentChar == '>') {
        op = ">";
        nextChar();
        if (currentChar == '=') {
            op = ">=";
            nextChar();
        }
    }
    else if (currentChar == '!') {
        nextChar();
        if (currentChar == '=') {
            op = "!=";
            nextChar();
        } else {
            validOp = false;
        }
    }
    else {
        validOp = false;
    }

    if (!validOp || op.isEmpty()) {
        addError("Недопустимая операция отношения");
        return;
    }

    addCall("Операция отношения: " + op);
}


void ExpressionParser::parseExpression() {
    addCall("Выражение");
    parseTerm();
    skipWhitespace();
    while (currentChar == '+') {
        addCall("Операция +");
        nextChar();
        skipWhitespace();
        parseTerm();
        skipWhitespace();
    }
}

void ExpressionParser::parseTerm() {
    addCall("Терм");
    parseMultiplier();
    skipWhitespace();
    while (currentChar == '*') {
        addCall("Операция *");
        nextChar();
        skipWhitespace();
        parseMultiplier();
        skipWhitespace();
    }
}

void ExpressionParser::parseMultiplier() {
    addCall("Множитель");
    if (currentChar == '(') {
        addCall("Скобка (");
        nextChar();
        skipWhitespace();
        parseExpression();
        skipWhitespace();
        if (currentChar == ')') {
            addCall("Скобка )");
            nextChar();
        } else {
            addError("Ожидается закрывающая скобка )");
        }
    } else {
        parseIdentifier();
    }
}

void ExpressionParser::parseIdentifier() {
    if (currentChar.isLetter()) {
        QString id;
        id += currentChar;
        nextChar();
        while (currentChar.isLetterOrNumber()) {
            id += currentChar;
            nextChar();
        }
        addCall("Идентификатор: " + id);
    } else {
        addError("Ожидается идентификатор");
    }
}

void ExpressionParser::parseOperator() {
    addCall("Оператор");
    if (currentChar.toUpper() == 'I') {
        parseConditionalOperator();
    } else {
        parseExpression();
    }
}

void ExpressionParser::analyze(QTableWidget* table) {
    errorTable = table;
    errorTable->setRowCount(0);
    errorCount = 0;
    callSequence.clear();

    parseConditionalOperator();

    skipWhitespace();
    if (currentChar != QChar()) {
        addError("Лишние символы в конце выражения");
    }

    if (errorCount == 0) {
        errorTable->insertRow(0);
        errorTable->setItem(0, 0, new QTableWidgetItem("1"));
        errorTable->setItem(0, 1, new QTableWidgetItem("Анализ завершен успешно"));

        for (int i = 0; i < callSequence.size(); ++i) {
            errorTable->insertRow(i+1);
            errorTable->setItem(i+1, 0, new QTableWidgetItem(QString::number(i+2)));
            errorTable->setItem(i+1, 1, new QTableWidgetItem(callSequence[i]));
        }
    }
}

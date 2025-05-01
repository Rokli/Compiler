#include "expressionparser.h"

ExpressionParser::ExpressionParser(const QString& expression)
    : expression(expression) {}

void ExpressionParser::analyze(QTableWidget* table) {
    table->setRowCount(0);
    tokens.clear();
    poliz.clear();
    errorMsg.clear();
    pos = 0;

    tokenize();
    if (!parseExpression()) {
        errorMsg = "Ошибка синтаксиса";
        analyzeToTable(table);
        return;
    }

    if (pos < tokens.size()) {
        errorMsg = "Ошибка: лишний токен \"" + tokens[pos] + "\"";
        analyzeToTable(table);
        return;
    }

    bool ok = true;
    double result = evalPoliz(ok);

    if (!ok) {
        if (errorMsg.isEmpty()) errorMsg = "Ошибка вычисления";
        analyzeToTable(table);
        return;
    }

    analyzeToTable(table);
    table->insertRow(table->rowCount());
    table->setItem(table->rowCount() - 1, 0, new QTableWidgetItem("Результат: " + QString::number(result)));
}

void ExpressionParser::tokenize() {
    QRegularExpression regex(R"((\d+(?:\.\d+)?|[+\-*/()]))");
    QRegularExpressionMatchIterator i = regex.globalMatch(expression);
    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        tokens << match.captured(1);
    }
}

bool ExpressionParser::parseExpression() {
    return parseAddSub();
}

bool ExpressionParser::parseAddSub() {
    if (!parseMulDiv())
        return false;

    while (pos < tokens.size()) {
        QString op = tokens[pos];
        if (op != "+" && op != "-") break;
        ++pos;
        if (!parseMulDiv()) return false;
        poliz.append(op);
    }
    return true;
}

bool ExpressionParser::parseMulDiv() {
    if (!parseFactor()) return false;

    while (pos < tokens.size()) {
        QString op = tokens[pos];
        if (op != "*" && op != "/") break;
        ++pos;
        if (!parseFactor()) return false;
        poliz.append(op);
    }
    return true;
}

bool ExpressionParser::parseFactor() {
    if (pos >= tokens.size()) return false;

    QString token = tokens[pos];

    if (token == "(") {
        ++pos;
        if (!parseExpression()) return false;
        if (pos >= tokens.size() || tokens[pos] != ")") return false;
        ++pos;
        return true;
    }

    bool ok;
    token.toDouble(&ok);
    if (ok) {
        poliz.append(token);
        ++pos;
        return true;
    }

    return false;
}

double ExpressionParser::evalPoliz(bool& ok) {
    QStack<double> stack;
    for (const QString& token : poliz) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2) {
                ok = false;
                errorMsg = "Ошибка: Отсутствие оператора";
                return 0;
            }
            double b = stack.pop();
            double a = stack.pop();
            if (token == "+") stack.push(a + b);
            else if (token == "-") stack.push(a - b);
            else if (token == "*") stack.push(a * b);
            else if (token == "/") {
                if (b == 0) {
                    ok = false;
                    errorMsg = "Ошибка: Деление на 0";
                    return 0;
                }
                stack.push(a / b);
            }
        } else {
            bool conv = false;
            double val = token.toDouble(&conv);
            if (!conv) {
                ok = false;
                errorMsg = "Ошибка: Неверный операнд";
                return 0;
            }
            stack.push(val);
        }
    }

    if (stack.size() > 1) {
        ok = false;
        errorMsg = "Ошибка: Лишний операнд";
        return 0;
    }

    ok = (stack.size() == 1);
    return stack.top();
}

void ExpressionParser::analyzeToTable(QTableWidget* table) {
    table->setRowCount(0);
    table->setColumnCount(1);

    if (!errorMsg.isEmpty()) {
        table->setHorizontalHeaderLabels({"Ошибки"});
        table->insertRow(0);
        table->setItem(0, 0, new QTableWidgetItem(errorMsg));
    } else {
        table->setHorizontalHeaderLabels({"ПОЛИЗ"});
        QString postfixString = poliz.join("");
        table->insertRow(0);
        table->setItem(0, 0, new QTableWidgetItem(postfixString));
    }
}

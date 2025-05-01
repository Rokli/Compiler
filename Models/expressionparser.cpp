#include "expressionparser.h"

ExpressionParser::ExpressionParser(const QString& expression)
    : m_expression(expression.trimmed()) {}

void ExpressionParser::addError(const QString& message, int pos) {
    if (pos < 0) pos = m_pos < m_tokens.size() ? m_pos : m_tokens.size() - 1;
    m_errors.push_back({pos, message, getErrorContext(pos)});
}

QString ExpressionParser::getErrorContext(int pos) const {
    if (pos < 0 || pos >= m_tokens.size()) return "конец выражения";

    QString context;
    int start = qMax(0, pos - 2);
    int end = qMin(m_tokens.size() - 1, pos + 2);

    for (int i = start; i <= end; ++i) {
        if (i == pos) context += " >>" + m_tokens[i] + "<< ";
        else context += m_tokens[i] + " ";
    }

    return context.trimmed();
}

void ExpressionParser::analyze(QTableWidget* table) {
    table->setRowCount(0);
    m_tokens.clear();
    m_poliz.clear();
    m_errors.clear();
    m_pos = 0;

    tokenize();

    if (m_tokens.isEmpty()) {
        addError("Пустое выражение", 0);
    } else {
        if (!parseExpression()) {
            if (m_errors.empty()) {
                addError("Синтаксическая ошибка");
            }
        }
    }

    bool evalOk = false;
    double result = 0;

    if (m_errors.empty()) {
        result = evalPoliz(evalOk);
        if (!evalOk && m_errors.empty()) {
            addError("Ошибка вычисления");
        }
    }

    analyzeToTable(table);

    if (!hasErrors()) {
        table->insertRow(table->rowCount());
        table->setItem(table->rowCount() - 1, 0,
                       new QTableWidgetItem("Результат: " + QString::number(result)));
    }
}

void ExpressionParser::tokenize() {
    QRegularExpression regex(R"((\d+(?:\.\d+)?(?:[eE][+-]?\d+)?|[+\-*/()]|\S))");
    QRegularExpressionMatchIterator i = regex.globalMatch(m_expression);

    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        QString token = match.captured(1);

        if (token.length() == 1 && !token[0].isDigit() &&
            !(token == "+" || token == "-" || token == "*" || token == "/" || token == "(" || token == ")")) {
            addError("Недопустимый символ '" + token + "'", m_tokens.size());
        }

        m_tokens << token;
    }
}

bool ExpressionParser::parseExpression() {
    return parseAddSub();
}

bool ExpressionParser::parseAddSub() {
    if (!parseMulDiv())
        return false;

    while (m_pos < m_tokens.size()) {
        QString op = m_tokens[m_pos];
        if (op != "+" && op != "-") break;

        ++m_pos;
        if (!parseMulDiv() && m_pos >= m_tokens.size()) {
            return false;
        }
        m_poliz.append(op);
    }
    return true;
}


bool ExpressionParser::parseMulDiv() {
    if (!parseFactor())
        return false;

    while (m_pos < m_tokens.size()) {
        QString op = m_tokens[m_pos];
        if (op != "*" && op != "/") break;

        ++m_pos;
        if (!parseFactor() && m_pos >= m_tokens.size()) {
            addError("Отсутствует операнд после оператора '" + op + "'");
            return false;
        }
        m_poliz.append(op);
    }
    return true;
}

bool ExpressionParser::parseFactor() {
    if (m_pos >= m_tokens.size()) {
        return false;
    }

    QString token = m_tokens[m_pos];

    if (token == "(") {
        int parenPos = m_pos;
        ++m_pos;

        if (!parseExpression()) {
            addError("Некорректное подвыражение в скобках", parenPos);
            return false;
        }

        if (m_pos >= m_tokens.size() || m_tokens[m_pos] != ")") {
            addError("Незакрытая скобка", parenPos);
            return false;
        }

        ++m_pos;
        return true;
    }

    bool ok;
    token.toDouble(&ok);
    if (ok) {
        m_poliz.append(token);
        ++m_pos;
        return true;
    }

    addError("Ожидалось число или скобка, получено '" + token + "'");
    return false;
}

double ExpressionParser::evalPoliz(bool& ok) {
    QStack<double> stack;
    ok = true;

    for (const QString& token : m_poliz) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2) {
                addError("Недостаточно операндов для оператора '" + token + "'");
                ok = false;
                return 0;
            }

            double b = stack.pop();
            double a = stack.pop();

            if (token == "+") stack.push(a + b);
            else if (token == "-") stack.push(a - b);
            else if (token == "*") stack.push(a * b);
            else if (token == "/") {
                if (b == 0) {
                    addError("Деление на ноль");
                    ok = false;
                    return 0;
                }
                stack.push(a / b);
            }
        } else {
            bool convOk;
            double val = token.toDouble(&convOk);

            if (!convOk) {
                addError("Некорректный операнд '" + token + "'");
                ok = false;
                return 0;
            }

            stack.push(val);
        }
    }

    if (stack.size() != 1) {
        addError("Неполное выражение");
        ok = false;
        return 0;
    }

    return stack.top();
}

void ExpressionParser::analyzeToTable(QTableWidget* table) {
    table->setRowCount(0);

    if (hasErrors()) {
        table->setColumnCount(1);  // Только одна колонка с ошибками
        table->setHorizontalHeaderLabels({"Ошибки"});

        for (const auto& error : m_errors) {
            int row = table->rowCount();
            table->insertRow(row);
            table->setItem(row, 0, new QTableWidgetItem(error.message)); // Только текст ошибки
        }
    } else {
        table->setColumnCount(1);
        table->setHorizontalHeaderLabels({"ОПН (Обратная Польская Нотация)"});

        // Вывод всего ПОЛИЗа одной строкой
        QString polizStr = m_poliz.join(" ");
        table->insertRow(0);
        table->setItem(0, 0, new QTableWidgetItem(polizStr));
    }
}

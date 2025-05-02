# Лабораторная работа №3. Разработка синтаксического анализатора (парсера)
## Цель работы: Изучить назначение синтаксического анализатора. Спроектировать алгоритм и выполнить программную реализацию парсера.
## Персональный вариант:
Компилятор функции инициализации константы `define()` языка PHP.\
## Грамматика:
    1. <DEF> -> 'define' <LPAREN>
    2. <LPAREN> -> '(' <MARK>
    3. <MARK> -> '"' <ID>
    4. <ID> -> letter <IDREM> 
    5. <ID> -> digit <IDREM>
    6. <IDREM> -> letter <IDREM>
    7. <IDREM> -> digit <IDREM>
    8. <IDREM> -> '"' <COMMA>
    9. <COMMA> -> ',' <VALUE>
    10.  <VALUE> -> digit <VALUEREM>
    11.  <VALUE> -> '"' <STRING>
    12.  <VALUE> -> 'true' <RPAREN>
    13.  <VALUE> -> 'false' <RPAREN>
    14.  <VALUE> -> '+' <VALUETYPE>
    15.  <VALUE> -> '-' <VALUETYPE>
    16.  <VALUETYPE> -> digit <VALUEREM>
    17.  <VALUEREM> -> digit <VALUEREM>
    18.  <VALUEREM> -> ')' <SEMICOLON>
    19.  <VALUEREM> -> '.' <DECIMAL>
    20.  <DECIMAL> -> digit <DECIMALREM>
    21.  <DECIMALREM> -> digit <DECIMALREM>
    22.  <DECIMALREM> -> ")" <SEMILICON>
    23.  <STRING> -> letter <STRINGREM>
    24.  <STRING> -> digit <STRINGREM>
    25.  <STRINGREM> -> letter <STRINGREM>
    26.  <STRINGREM> -> digit <STRINGREM
    27.  <STRINGREM> -> '"' <RPAREN>
    28.  <RPAREN> -> ')' <SEMICOLON>
    29.  <SEMICOLON> -> ';'
<letter> → "a" | "b" | "c" | ... | "z" | "A" | "B" | "C" | ... | "Z" |
<digit> → "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"
## Граф:
![image](https://github.com/user-attachments/assets/a5d73092-8593-48af-b379-e2df337f3622)

### Примеры допустимых строк
- define("NAME","max")
- define("PI", 3.14159);
- define("COLORS", ["red", "green", "blue"]);
- define("bool",true)
- define("bool",false)
### Тестовые примеры:
![image](https://github.com/user-attachments/assets/2e3a86e7-536c-417b-bbfc-eee6ac6b11b0)
![image](https://github.com/user-attachments/assets/ff313b68-9adf-4064-a1ef-c0057c29c831)
![image](https://github.com/user-attachments/assets/db8eda82-ca0f-45bc-a998-68d52d55633f)
![image](https://github.com/user-attachments/assets/706e36c5-ad51-40ce-9482-e4194e2c7f83)
![image](https://github.com/user-attachments/assets/9e71d487-d90f-4ae8-bf04-40280e3a6c56)

# Лабораторная работа №4. Нейтрализация ошибок (метод Айронса)
## Цель работы: Реализовать алгоритм нейтрализации синтаксических ошибок и дополнить им программную реализацию парсера.
# Задание: Реализовать алгоритм синтаксического анализа с нейтрализацией ошибок (метод Айронса). 
## Персональный вариант:
Компилятор функции инициализации константы `define()` языка PHP.
## Грамматика:
    1. <DEF> -> 'define' <LPAREN>
    2. <LPAREN> -> '(' <MARK>
    3. <MARK> -> '"' <ID>
    4. <ID> -> letter <IDREM> 
    5. <ID> -> digit <IDREM>
    6. <IDREM> -> letter <IDREM>
    7. <IDREM> -> digit <IDREM>
    8. <IDREM> -> '"' <COMMA>
    9. <COMMA> -> ',' <VALUE>
    10.  <VALUE> -> digit <VALUEREM>
    11.  <VALUE> -> '"' <STRING>
    12.  <VALUE> -> 'true' <RPAREN>
    13.  <VALUE> -> 'false' <RPAREN>
    14.  <VALUE> -> '+' <VALUETYPE>
    15.  <VALUE> -> '-' <VALUETYPE>
    16.  <VALUETYPE> -> digit <VALUEREM>
    17.  <VALUEREM> -> digit <VALUEREM>
    18.  <VALUEREM> -> ')' <SEMICOLON>
    19.  <VALUEREM> -> '.' <DECIMAL>
    20.  <DECIMAL> -> digit <DECIMALREM>
    21.  <DECIMALREM> -> digit <DECIMALREM>
    22.  <DECIMALREM> -> ")" <SEMILICON>
    23.  <STRING> -> letter <STRINGREM>
    24.  <STRING> -> digit <STRINGREM>
    25.  <STRINGREM> -> letter <STRINGREM>
    26.  <STRINGREM> -> digit <STRINGREM
    27.  <STRINGREM> -> '"' <RPAREN>
    28.  <RPAREN> -> ')' <SEMICOLON>
    29.  <SEMICOLON> -> ';'
<letter> → "a" | "b" | "c" | ... | "z" | "A" | "B" | "C" | ... | "Z" |
<digit> → "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"
## Граф:
![image](https://github.com/user-attachments/assets/a5d73092-8593-48af-b379-e2df337f3622)

### Примеры допустимых строк
- define("NAME","max")
- define("PI", 3.14159);
- define("COLORS", ["red", "green", "blue"]);
- define("bool",true)
- define("bool",false)

### Тестовые примеры:
![image](https://github.com/user-attachments/assets/2e3a86e7-536c-417b-bbfc-eee6ac6b11b0)
![image](https://github.com/user-attachments/assets/ff313b68-9adf-4064-a1ef-c0057c29c831)
![image](https://github.com/user-attachments/assets/db8eda82-ca0f-45bc-a998-68d52d55633f)
![image](https://github.com/user-attachments/assets/706e36c5-ad51-40ce-9482-e4194e2c7f83)
![image](https://github.com/user-attachments/assets/9e71d487-d90f-4ae8-bf04-40280e3a6c56)

# Лабораторная работа №5. Включение семантики в анализатор. Создание внутренней формы представления программы.
## Цель работы: Дополнить анализатор, разработанный в рамках лабораторных работ, этапом формирования внутренней формы представления программы.
## Персональный вариант:
1 вариант. В качестве внутренней формы представления программы выберем польскую инверсную запись (ПОЛИЗ). Эта форма представления наглядна и достаточно проста для последующей интерпретации, которая может быть выполнена с использованием стека.

Задание:

1) Реализовать в текстовом редакторе поиск лексических и синтаксических ошибок для грамматики G[<E>]. Реализовать данную КС-граммматику методом рекурсивного спуска:

1. E → TA 

2. A → ε | + TA | - TA 

3. T → ОВ 

4. В → ε | *ОВ | /ОВ 

5. О → num | (E) 

6. num  → digit {digit}

2) Реализовать алгоритм записи арифметических выражений в ПОЛИЗ и алгоритм вычисления выражений в ПОЛИЗ.

### Примеры допустимых строк
- 6 + 7 + 10 * 4
- 5*5*5
- 10 * 10 + 5

### Тестовые примеры:
![image](https://github.com/user-attachments/assets/585cf056-10af-46eb-9f80-a6893ea1b84d)
![image](https://github.com/user-attachments/assets/b2e9929c-68cf-4ecb-9cea-fb9150b12298)
![image](https://github.com/user-attachments/assets/0e97a5e0-6cba-48ef-9f3e-6e1cc4a896f5)

# Лабораторная работа №6. Реализация алгоритма поиска подстрок с помощью регулярных выражений.
## Цель работы: Реализовать алгоритм поиска в тексте подстрок, соответствующих заданным регулярным выражениям.
## Задачи:
### 2) Построить РВ, описывающее американские почтовые индексы.
void PatternMatcher::findUSZipCodes(QTableWidget* table) {
    QRegularExpression regex(R"((?:^|\s)(\d{5}(?:-\d{4})?)(?=$|\s|[,\.]))");
    parseAndFillTable(regex, table);
}
### 18)
void PatternMatcher::findYearsInRange(QTableWidget* table) {
    QRegularExpression regex(R"((?:^|\s)(199[89]|200[0-4])(?=$|\s|[^\w]))");
    parseAndFillTable(regex, table);
}
### 20)
void PatternMatcher::findRealNumbersWithExponent(QTableWidget* table) {
    QRegularExpression regex(R"((?:^|\s)([+-]?(?:\d+\.?\d*|\.\d+)(?:[eE][+-]?\d+)?)(?=$|\s|[^\w\.]))");
    parseAndFillTable(regex, table);
}

### Тестовые примеры:
![image](https://github.com/user-attachments/assets/64b126fd-db93-482f-b3f3-baf0f04d015e)
![image](https://github.com/user-attachments/assets/47a4cfaf-773e-4b6d-b3e6-dcbc1e78a0db)
![image](https://github.com/user-attachments/assets/18c2222d-4757-4659-a4e2-177ae572c160)





















































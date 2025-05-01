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































































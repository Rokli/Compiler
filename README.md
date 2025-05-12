# Лабораторная работа №1. Разработка пользовательского интерфейса (GUI) для языкового процессора.
## Цель работы: Разработать приложение – текстовый редактор. 
## Персональный вариант:
Компилятор функции инициализации константы `define()` языка PHP.
### Справка:
Этот компилятор предназначен для обработки и выполнения кода, написанного на PHP.

## Установка

### На Linux

#### Установка зависимостей:
```sh
sudo dnf install qt5-qtbase-devel qt5-qmake
```

#### Скачивание проекта:
```sh
git clone https://github.com/Rokli/Complier.git
cd Complier
```

#### Сборка проекта:
```sh
qmake
make
```

#### Запуск:
```sh
./complier
```

### На Windows

#### Установка Qt:
[Скачать и установить Qt](https://doc.qt.io/qt-6/windows.html)

#### Скачивание проекта:
```sh
git clone https://github.com/Rokli/Complier.git
cd Complier
```

#### Сборка проекта:
```sh
cd C:\path\to\Complier
qmake
mingw32-make
```

#### Запуск:
```sh
complier.exe
```

## Как пользоваться компилятором

### Файл (работа с файлами .txt)
- **Создать** — создаёт новый файл
- **Открыть** — открывает существующий файл
- **Сохранить** — сохраняет изменения в текущем файле
- **Сохранить как** — сохраняет текущий файл в указанное место
- **Выход** — закрывает приложение

### Правка (редактирование текста)
- **Отменить** — отменяет последнее изменение
- **Повторить** — повторяет последнюю операцию
- **Вырезать** — вырезает выделенный текст
- **Копировать** — копирует выделенный текст
- **Вставить** — вставляет текст из буфера обмена
- **Удалить** — удаляет выделенный текст
- **Выделить всё** — выделяет весь текст

### Пуск *(не готово)*
### Текст *(не готово)*

### Справка
- **Вызов справки** — открывает документацию в браузере
- **О программе** — отображает дополнительное окно с информацией о программе

## Обратная связь
Если у вас есть вопросы, пишите на [satalomaksimka12345678910@gmail.com](mailto:satalomaksimka12345678910@gmail.com).

# Лабораторная работа №2. Разработка лексического анализатора (сканера)
## Цель работы: Изучить назначение лексического анализатора. Спроектировать алгоритм и выполнить программную реализацию сканера.
## Персональный вариант:
Компилятор функции инициализации константы `define()` языка PHP.
### Примеры допустимых строк
- define("NAME","max")
- define("PI", 3.14159);
- define("COLORS", ["red", "green", "blue"]);
- define("bool",true)
- define("bool",false)
Этот компилятор предназначен для обработки и выполнения кода, написанного на PHP.
### Тестовые примеры
![image](https://github.com/user-attachments/assets/3676f4a1-c534-435a-9c81-78ac8968b390)
![image](https://github.com/user-attachments/assets/79a42046-a363-4299-a92c-2d42b6ac6c57)
![image](https://github.com/user-attachments/assets/ac94cc83-29ab-45dc-a321-96237f4f6f1e)


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
![image](https://github.com/user-attachments/assets/386b184a-1529-4a8f-aefe-eb2452d38b73)
![image](https://github.com/user-attachments/assets/59aac5b4-9b0d-4f0a-9c19-b1a307996d6d)
![image](https://github.com/user-attachments/assets/75738ec3-d628-4149-88c4-de28ef0a26fa)


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





















































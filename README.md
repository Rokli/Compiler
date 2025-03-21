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

### Диаграмма состояний сканера
![Диаграмма б123ез названия drawio](https://github.com/user-attachments/assets/ebbe7806-af97-476f-84c1-b7a88e2d557c)

### Тестовые примеры

![image](https://github.com/user-attachments/assets/084a8f50-ff32-4987-9380-e791bc08c643)
![image](https://github.com/user-attachments/assets/8184a099-e3c8-4436-bc28-37cad84e6851)
![image](https://github.com/user-attachments/assets/9a82913c-5754-4d4a-9023-b2c54720f9a9)
![image](https://github.com/user-attachments/assets/e62dbeb6-823a-4e19-aad7-6ed1b8a5866a)
![image](https://github.com/user-attachments/assets/e6a2b572-8325-4452-aea0-26add62cc889)
![image](https://github.com/user-attachments/assets/9f4b649b-4ac8-4410-a28b-ca1a8bef3c38)
![image](https://github.com/user-attachments/assets/947af4a3-0fde-4770-824f-679d816fc8c3)
![image](https://github.com/user-attachments/assets/8565cb4e-4a5a-44a1-be9c-738450795309)

## Грамматика

< define-statement > ::= "define" "(" < constant-name > "," < constant-value > ")" ";"

< constant-name > ::= < string-literal >

< constant-value > ::= < scalar-value >

< scalar-value > ::= < integer > | < float > | < string-literal > | < boolean >

< string-literal > ::= '"' < char-sequence > '"' | "'" < char-sequence > "'"

< char-sequence > ::= < char > | < char > < char-sequence >

< char > ::= любой символ, кроме кавычек и управляющих символов

< integer > ::= < digit > | < digit > < integer >

< float > ::= < integer > "." < integer >

< boolean > ::= "true" | "false"

< digit > ::= "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"














































# Лабораторная работа №3. Разработка синтаксического анализатора (парсера)
## Цель работы: Изучить назначение синтаксического анализатора. Спроектировать алгоритм и выполнить программную реализацию парсера.
## Персональный вариант:
Компилятор функции инициализации константы `define()` языка PHP.
### Грамматика
1) <DEF> -> 'define' <LPAREN>
2) <LPAREN> -> '(' <MARK>
3) <MARK> -> '"' <ID>
4) <ID> -> letter <IDREM>  
5) <ID> -> digit <IDREM>
6) <IDREM> -> letter <IDREM>
7) <IDREM> -> digit <IDREM>
8) <IDREM> -> '"' <COMMA>
9) <COMMA> -> ',' <VALUE>
10) <VALUE> -> digit <VALUEREM> 
11) <VALUE> -> '"' <STRING> 
12) <VALUE> -> 'true' <RPAREN>
13) <VALUE> -> 'false' <RPAREN>
14) <VALUE> -> '+' <VALUETYPE>
15) <VALUE> -> '-' <VALUETYPE> 
16) <VALUETYPE> -> digit <VALUEREM> 
17) <VALUEREM> -> digit <VALUEREM>
18) <VALUEREM> -> ')' <SEMICOLON>
19) <VALUEREM> -> '.' <DECIMAL>
20) <DECIMAL> -> digit <DECIMALREM>
21) <DECIMALREM> -> digit <DECIMALREM> 
22) <DECIMALREM> -> ")" <SEMILICON>
23) <STRING> -> letter <STRINGREM> 
24) <STRING> -> digit <STRINGREM> 
25) <STRINGREM> -> letter <STRINGREM>
26) <STRINGREM> -> digit <STRINGREM>
27) <STRINGREM> -> '"' <RPAREN>
28) <RPAREN> -> ')' <SEMICOLON>
29) <SEMICOLON> -> ';'
digit -> '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
letter -> 'a' | 'b' | 'c' | ... | 'z' | 'A' | 'B' | 'C' | ... | 'Z'
Vn = {<DEF>, <LPAREN>, <MARK>, <ID>, <IDREM>, <COMMA>, <VALUE>, <ARRAY>, <STRING_ARRAY>, <ID_ARRAY>, <NUMBER_ARRAY>, <ARRAY_REM>, <END_ARRAY>, <VALUEREM>, <STRING>, <STRINGREM>, <RPAREN>, <SEMICOLON>}
Vt = {'.','+', '-', 'define', 'true', 'false' , digit, letter}

 ### Граф
![image](https://github.com/user-attachments/assets/8fa45d77-a87e-4c93-a1e5-ac9bf29af719)

###Тестовые примеры
![image](https://github.com/user-attachments/assets/928ffe6d-ffad-41bd-aaa2-46264a715c2f)
![image](https://github.com/user-attachments/assets/6ad3e4b4-f111-4b3a-863b-8db1df9e4c53)
![image](https://github.com/user-attachments/assets/8167e703-e2f1-4d56-bc65-b324778ba32e)































































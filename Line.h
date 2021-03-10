#pragma once
#include <iostream>
#include "Failure.h"

#define MAX_LINE_LEN 129 // 64 четные цифры заменить на "КВ" + '\0'

class Line { // класс введенной строки
public:
    Line();
    ~Line();
    int read_line(); // чтение строки
    void handle_line(); // обработка строки
    void print_line(); // вывод строки
    int count_line_sum(); // расчет суммы цифр строки

private:
    int size_; // длина строки
    char* data_; // содержимое строки
};
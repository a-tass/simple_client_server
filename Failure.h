#pragma once
#include <string>
#include <iostream>

class Failure { // класс обработки ошибок
public:
    Failure();
    Failure(int);
    ~Failure();
    Failure& operator=(int);
    bool error_appeared(); // возникла ли ошибка
    void print_error(); // вывод сообщения об ошибке

private:
    int error_num_ = 0; // номер ошибки
};
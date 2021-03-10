#pragma once
#include <string>
#include <iostream>

class Failure { // ����� ��������� ������
public:
    Failure();
    Failure(int);
    ~Failure();
    Failure& operator=(int);
    bool error_appeared(); // �������� �� ������
    void print_error(); // ����� ��������� �� ������

private:
    int error_num_ = 0; // ����� ������
};
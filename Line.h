#pragma once
#include <iostream>
#include "Failure.h"

#define MAX_LINE_LEN 129 // 64 ������ ����� �������� �� "��" + '\0'

class Line { // ����� ��������� ������
public:
    Line();
    ~Line();
    int read_line(); // ������ ������
    void handle_line(); // ��������� ������
    void print_line(); // ����� ������
    int count_line_sum(); // ������ ����� ���� ������

private:
    int size_; // ����� ������
    char* data_; // ���������� ������
};
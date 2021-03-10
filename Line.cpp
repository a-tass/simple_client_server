#include "Line.h"

Line::Line() : size_(0), data_(new char[MAX_LINE_LEN]) {}

Line::~Line() { delete[] data_; }

int Line::read_line() {
    size_ = 0;
    Failure f; // индикатор возникновения ошибки во время чтения
    char c = '\0';
    while (std::cin.get(c) && c != '\n' && c != '\0') {
        if (f.error_appeared()) continue;
        data_[size_++] = c;        
        if (size_ <= 64 && isdigit(c)) { 
            continue;
        }
        f = 1; // длина строки больше 64 или встречена не цифра        
    }
    if (f.error_appeared()) {
        f.print_error();
        return -1;
    }
    data_[size_] = '\0';
    return 0;
}

void Line::handle_line() {
    int digits[10] = {};
    for (int i = 0; i < size_; ++i)
        ++digits[data_[i] - '0']; // подсчет количеств цифр
    int k = 0;
    for (int i = 9; i >= 0; --i) // сортировка цифр по убыванию
        while (digits[i]--)
            if (i % 2 == 0) { // замена четных цифр на "КВ"
                data_[k++] = 'K';
                data_[k++] = 'B';
                ++size_;
            }
            else data_[k++] = i + '0';
    data_[size_] = '\0';
}

void Line::print_line() {
    std::cout << data_ << "\n\n";
}

int Line::count_line_sum() {
    int sum = 0;
    for (int i = 0; i < size_; ++i) {
        if (data_[i] >= '0' && data_[i] <= '9') sum += data_[i] - '0';
    }
    return sum;
}
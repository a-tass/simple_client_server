#include "Failure.h"

Failure::Failure() {}

Failure::Failure(int error_num) : error_num_(error_num) {}

Failure::~Failure(){}

Failure& Failure::operator=(int error_num) {
    error_num_ = error_num;
    return *this;
}

bool Failure::error_appeared() {
    if (error_num_ == 0) return false;
    return true;
}

void Failure::print_error() {
    std::string error_;
    switch (error_num_) {
    case 1:
        error_ = "Incorrect line. The line must contain only digits be no more than 64 characters long";
        break;
    case 2:
        error_ = "Incorect received number. Number should be longer that 2 characters and divisible by 32";
        break;
    case 3:
        error_ = "Error in socket creation. Please restart";
        break;
    case 4:
        error_ = "Cannot connect. Please restart";
        break;
    case 5:
        error_ = "Client stopped connection. Please restart";
        break;
    default:
        error_ = "Something went wrong";
    }
	std::cout << error_ << "\n\n";
}
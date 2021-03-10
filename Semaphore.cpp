#include "Semaphore.h"

Semaphore::Semaphore(){}

Semaphore::~Semaphore() {}

void Semaphore::acquire() {
    std::unique_lock<std::mutex> lock(mut_);
    while (count == 1) cv_.wait(lock); // ожидание освобождения семафора
    count = 1;
}

void Semaphore::release() {
    std::lock_guard<std::mutex> lock(mut_);
    count = 0; // освобождение семафора
    cv_.notify_one();
}
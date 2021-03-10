#pragma once
#include <mutex>
#include <condition_variable>

class Semaphore { // класс бинарного семафора
public:
    Semaphore();
    ~Semaphore();
    void acquire(); // завладеть семафором
    void release(); // освободить семафор
    int count; // счетчик

private:   
    std::mutex mut_;
    std::condition_variable cv_;
};
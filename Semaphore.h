#pragma once
#include <mutex>
#include <condition_variable>

class Semaphore { // ����� ��������� ��������
public:
    Semaphore();
    ~Semaphore();
    void acquire(); // ��������� ���������
    void release(); // ���������� �������
    int count; // �������

private:   
    std::mutex mut_;
    std::condition_variable cv_;
};
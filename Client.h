#pragma once
#include <thread>
#include "Line.h"
#include "Semaphore.h"
#include "Socket.h"

class Client { // ����� �������
public:
	Client();
	~Client();
	void thread1_func(); // ������� ��� ������ 1
	void thread2_func(); // ������� ��� ������ 2

private:
	Socket cl_socket; // ����� ��������-�������
	Line str; // ������, �������������� ��������
	std::thread t1; // ����� 1
	std::thread t2; // ����� 2
	Semaphore thread1_lock; // ������� ��� ������ 1
	Semaphore thread2_lock; // ������� ��� ������ 2
	Failure f_conn; // ��������� ������������� ������
};
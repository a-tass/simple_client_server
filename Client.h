#pragma once
#include <thread>
#include "Line.h"
#include "Semaphore.h"
#include "Socket.h"

class Client { // класс клиента
public:
	Client();
	~Client();
	void thread1_func(); // функция для потока 1
	void thread2_func(); // функция для потока 2

private:
	Socket cl_socket; // сокет програмы-клиента
	Line str; // строка, обрабатываемая потоками
	std::thread t1; // поток 1
	std::thread t2; // поток 2
	Semaphore thread1_lock; // семафор для потока 1
	Semaphore thread2_lock; // семафор для потока 2
	Failure f_conn; // индикатор возникновения ошибки
};
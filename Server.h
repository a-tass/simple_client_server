#pragma once
#include <iostream>
#include "Failure.h"
#include "Socket.h"

class Server { // класс сервера
public:
	Server();
	~Server();
	void start_server(); // запуск сервера
	void handle_message(int); // обработка полученного сообщения

private:
	Socket ser_socket; // сокет программы-сервера
	Failure f_conn; // // индикатор возникновения ошибки
};
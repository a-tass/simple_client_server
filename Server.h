#pragma once
#include <iostream>
#include "Failure.h"
#include "Socket.h"

class Server { // ����� �������
public:
	Server();
	~Server();
	void start_server(); // ������ �������
	void handle_message(int); // ��������� ����������� ���������

private:
	Socket ser_socket; // ����� ���������-�������
	Failure f_conn; // // ��������� ������������� ������
};
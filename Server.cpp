#include "Server.h"

Server::Server() {
}

Server::~Server() {
}

void Server::start_server() {
	int number = 0;
	int client_socket = -1;
	if (ser_socket.s_socket < 0) { // �������� ������
		f_conn = 3;
		f_conn.print_error();
		return;
	}
	else if ((client_socket = ser_socket.start_listening()) == -1) { // ��������� ����������
		f_conn = 4;
		f_conn.print_error();
		return;
	}
	while (true) {
		number = ser_socket.rcv_msg(client_socket); // �������� ���������
		if (number == -1) {
			f_conn = 5;
			f_conn.print_error();
			return;
		}
		handle_message(number); // ��������� ���������
	}	
}

void Server::handle_message(int number) {
	std::cout << "Received number: " << number << "\n"; // ����� ����� �� �����
	if (number >= 100 && number % 32 == 0)
		std::cout << "Nice number\n\n";
	else { // ����� ������ ���� �������� ��� �� ������� �� 32
		Failure f_mess = 2;
		f_mess.print_error();
	}
}
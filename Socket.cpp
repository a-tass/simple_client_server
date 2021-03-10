#include "Socket.h"

Socket::Socket() {
    s_socket = socket(AF_INET, SOCK_STREAM, 0); // �������� ������
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(PORT_NUMBER);
    sock_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK); // ��������� ������
}

Socket::~Socket() {
    if (s_socket != -1) close(s_socket); // �������� ������
} 

int Socket::start_listening() {
    if(bind(s_socket, (struct sockaddr*)(&sock_addr), sizeof(sock_addr)) == -1) return -1;
    if(listen(s_socket, SOMAXCONN) == -1) return -1;
    int client_socket =  accept(s_socket, 0, 0); // ��������� ���������� � ��������
    return client_socket; // ���������� ������ �������
}

int Socket::start_sending() {
    return connect(s_socket, (struct sockaddr*)(&sock_addr), sizeof(sock_addr)); // ��������� ���������� � ��������
}

int Socket::send_msg(int number) {
    char message[MAX_MSG_LEN];
    for (int i = MAX_MSG_LEN - 1; i >= 0; --i) { // ������� ����� � ������ ��������
        message[i] = number % 10 + '0';
        number /= 10;
    }
    if (send(s_socket, message, 4, MSG_NOSIGNAL)<=0) return -1; // �������� ���������
    return 0;
}

int Socket::rcv_msg(int client_socket) {
    char buff[MAX_MSG_LEN];
    if (recv(client_socket, buff, 4, MSG_NOSIGNAL)<= 0) return -1; // ��������� ���������
    int sum = 0;
    for (int i = 0; i < MAX_MSG_LEN; ++i) { // ������� ������� �������� � �����
        sum *= 10;
        sum += buff[i] - '0';
    }
    return sum;
}
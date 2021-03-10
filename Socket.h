#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT_NUMBER 12345 // ����� �����
#define MAX_MSG_LEN 3 // ������������ ����� ��������� (64 * 9 == 576) ��� �������

class Socket {
public:
	Socket();
	~Socket();
	int start_listening(); // ������ �������� �������
	int start_sending(); // ������ �������� ����������
	int send_msg(int); // �������� ���������
	int rcv_msg(int); // �������� ���������
	int s_socket = -1; // ���������� ������

private:
	struct sockaddr_in sock_addr;
};
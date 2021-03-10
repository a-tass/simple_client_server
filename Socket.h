#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT_NUMBER 12345 // номер порта
#define MAX_MSG_LEN 3 // максимальная длина сообщения (64 * 9 == 576) три символа

class Socket {
public:
	Socket();
	~Socket();
	int start_listening(); // сервер начинает слушать
	int start_sending(); // клиент начинает передавать
	int send_msg(int); // отправка сообщения
	int rcv_msg(int); // принятие сообщения
	int s_socket = -1; // дескриптор сокета

private:
	struct sockaddr_in sock_addr;
};
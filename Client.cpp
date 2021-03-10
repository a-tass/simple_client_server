#include "Client.h"

Client::Client() : t1(&Client::thread1_func, this), t2(&Client::thread2_func, this) {
    thread1_lock.count = 1; 
    thread2_lock.count = 1;
}

Client::~Client() {
    t1.join(); // ����������� �������
    t2.join(); // ����������� �������
}

void Client::thread1_func() { 
    thread1_lock.acquire();
    thread1_lock.release();
    while (!f_conn.error_appeared()) { 
        thread1_lock.acquire();
        if (!f_conn.error_appeared()) {
            while (str.read_line() < 0) continue; // ���������� ������
            str.handle_line(); // ��������� ������
            thread2_lock.release();
        }
    }
}

void Client::thread2_func() { 
    if (cl_socket.s_socket < 0) { // �������� ������
        f_conn = 3;
        f_conn.print_error();
    }
    else if (cl_socket.start_sending() != 0) { // ��������� ����������
        f_conn = 4;
        f_conn.print_error();        
    }
    thread1_lock.release(); // �������� ���������� ������ 1
    while (!f_conn.error_appeared()) {     
        thread2_lock.acquire();        
        int sum = str.count_line_sum(); // ������ ����� ���� � ������
        if (cl_socket.send_msg(sum) == -1) { // �������� ����� �������
            f_conn = 4;
            f_conn.print_error();
            thread1_lock.release();
            return;
        }
        str.print_line(); // ����� ����� �� �����
        thread1_lock.release();
    }    
}
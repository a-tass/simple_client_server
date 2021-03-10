#include "Client.h"

Client::Client() : t1(&Client::thread1_func, this), t2(&Client::thread2_func, this) {
    thread1_lock.count = 1; 
    thread2_lock.count = 1;
}

Client::~Client() {
    t1.join(); // отсоедиение потоков
    t2.join(); // отсоедиение потоков
}

void Client::thread1_func() { 
    thread1_lock.acquire();
    thread1_lock.release();
    while (!f_conn.error_appeared()) { 
        thread1_lock.acquire();
        if (!f_conn.error_appeared()) {
            while (str.read_line() < 0) continue; // считывание строки
            str.handle_line(); // обработка строки
            thread2_lock.release();
        }
    }
}

void Client::thread2_func() { 
    if (cl_socket.s_socket < 0) { // создание сокета
        f_conn = 3;
        f_conn.print_error();
    }
    else if (cl_socket.start_sending() != 0) { // установка соединения
        f_conn = 4;
        f_conn.print_error();        
    }
    thread1_lock.release(); // передача управления потоку 1
    while (!f_conn.error_appeared()) {     
        thread2_lock.acquire();        
        int sum = str.count_line_sum(); // расчет суммы цифр в строке
        if (cl_socket.send_msg(sum) == -1) { // передача суммы серверу
            f_conn = 4;
            f_conn.print_error();
            thread1_lock.release();
            return;
        }
        str.print_line(); // вывод числа на экран
        thread1_lock.release();
    }    
}
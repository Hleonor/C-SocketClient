#include <iostream>
#include <thread>
#include "Client_Socket.h"

int main()
{
    Client_Socket client_socket;
    int err = client_socket.connect_to_server("127.0.0.1", 8888);
    if (err == SOCKET_ERROR)
    {
        cout << "发生了错误，系统退出" << endl;
        exit(-1);
    }
    char buffer[1024];
    thread send_thread(&Client_Socket::send_message, &client_socket, buffer);
    send_thread.detach();

    client_socket.receive_message();
    client_socket.closeSocket();
    return 0;
}

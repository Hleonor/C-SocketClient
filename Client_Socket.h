//
// Created by Hleonor on 2023-03-06.
//

#ifndef CLIENT_CLIENT_SOCKET_H
#define CLIENT_CLIENT_SOCKET_H
#include <iostream>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

#include <vector>
#include <string.h>
using namespace std;

class Client_Socket
{
public:
    SOCKET client_sock;

    int connect_to_server(string ip_addr, int port);
    void send_message(char* buffer);
    int receive_message();
    void closeSocket();
    void handleSendAndReceive();

    string client_send_change;
    char client_send[MAXBYTE];
    char client_recv[MAXBYTE];
};


#endif //CLIENT_CLIENT_SOCKET_H

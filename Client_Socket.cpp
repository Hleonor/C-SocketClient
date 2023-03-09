//
// Created by Hleonor on 2023-03-06.
//

#include <thread>
#include "Client_Socket.h"


int Client_Socket::connect_to_server(string ip_addr, int port)
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    struct sockaddr_in client_addr{};
    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = inet_addr(ip_addr.c_str());
    client_addr.sin_port = htons(port);

    client_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (client_sock == INVALID_SOCKET)
    {
        cout << "�ͻ��˴����׽���ʧ��." << endl;
        return -1;
    }
    int err = connect(client_sock, (struct sockaddr *) &client_addr, sizeof(client_addr));
    if (err == SOCKET_ERROR)
    {
        cout << "�ͻ�������ʧ��." << endl;
        return -1;
    }
    return 0;
}

void Client_Socket::send_message(char *buffer)
{
    while (1)
    {
        cout << "������Ҫ���͵���Ϣ: ";
        client_send_change.clear();
        cin >> client_send_change;
        for (int i = 0; i < client_send_change.length(); i++)
        {
            client_send[i] = client_send_change[i];
        }
        if (send(client_sock, client_send, client_send_change.length() + 1 + sizeof(char), 0) == SOCKET_ERROR)
        {
            cout << "�ͻ��˷�����Ϣʧ��." << endl;
            // return -1;
        }
        cout << "�ͻ��˷�����Ϣ�ɹ�." << endl;
        // return 0;
    }
}

int Client_Socket::receive_message()
{
    while (1)
    {
        int err = recv(client_sock, client_recv, MAXBYTE, 0);
        if (err == SOCKET_ERROR)
        {
            cout << "�ͻ��˽�����Ϣʧ��." << endl;
            return -1;
        }
        else
        {
            cout << "�յ���������Ϣ: ";
        }
        for (int i = 0; i < strlen(client_recv); i++)
        {
            cout << client_recv[i];
        }
        cout << endl;
        err = 0;
    }
}

void Client_Socket::closeSocket()
{
    WSACleanup();
    closesocket(client_sock);
}

void Client_Socket::handleSendAndReceive()
{
    
}

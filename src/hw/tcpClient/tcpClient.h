#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#pragma once

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string>

using namespace std;

#define TCP_PORT 5100

class tcpClient
{
private:
    int serverSock_fd;

    struct sockaddr_in serv_addr;
    socklen_t serv_addr_size;

    char mesg[BUFSIZ];

public:
    tcpClient();
    ~tcpClient();
    void createSocket();
    int getServerSocket();
    void connectServer();
    void sendDatatoServer();
    void receiveDatafromServer();
    string DataToString();
    void closeSocket(int socket);
};

#endif
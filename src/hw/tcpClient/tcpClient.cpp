#include "tcpClient.h"

tcpClient::tcpClient()
{}

tcpClient::~tcpClient()
{

}

void tcpClient::createSocket()
{
    /* 소켓을 생성 */
    if((serverSock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket()");
        return;
    }

    /* 소켓이 접속할 주소 지정 */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;

    /* 문자열을 네트워크 주소로 변경 */
    inet_pton(AF_INET, "127.0.0.1"/*ip주소를 넣겠다.*/, &(serv_addr.sin_addr.s_addr));
    serv_addr.sin_port = htons(TCP_PORT);
}

int tcpClient::getServerSocket()
{
    return serverSock_fd;
}

void tcpClient::connectServer()
{
    /* 지정한 주소로 접속 */
    if(connect(serverSock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect()");
        return;
    }
}

void tcpClient::sendDatatoServer()
{
    fgets(mesg, BUFSIZ, stdin);
    if(send(serverSock_fd, mesg, BUFSIZ, MSG_DONTWAIT) <= 0) /* 데이터를 소켓에 쏨*/
    {
        perror("send()");
        return;
    }
}

void tcpClient::receiveDatafromServer()
{
    memset(mesg, 0, BUFSIZ);
    if(recv(serverSock_fd, mesg, BUFSIZ, 0) <= 0) /* 데이터를 소켓으로부터 읽음 */
    {
        perror("recv()");
        return;
    }
    //printf("Received data : %s ", mesg); /* 받은 문자열을 화면에 출력 */
}

string tcpClient::DataToString()
{
    string data = mesg;
    return data;
}

void tcpClient::closeSocket(int socket)
{
    close(socket); /* 소켓을 닫음 */
}
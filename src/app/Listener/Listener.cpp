#include "Listener.h"
#include <iostream>

using namespace std;

Listener::Listener(Button *ledButton, Button *clientButton, Controller *controller, tcpClient *client)
{
    this->ledButton = ledButton;
    this->clientButton = clientButton;
    this->controller = controller;
    this->client = client;
}

Listener::~Listener()
{

}

void Listener::checkEvent()
{
    if(ledButton->getState() == RELEASE_ACTIVE)
        controller->updateEvent("ledButton");

    if(clientButton->getState() == RELEASE_ACTIVE)
        checkClient();
}

void Listener::checkClient()
{
    int socket;
    string str;

    client->createSocket();
    client->connectServer();
    socket = client->getServerSocket();
    cout << "명령어를 입력하세요" << endl;
    client->sendDatatoServer();
    client->receiveDatafromServer();
    str = client->DataToString();
    client->closeSocket(socket);
    //cout << str;
    controller->updateEvent(str);
}
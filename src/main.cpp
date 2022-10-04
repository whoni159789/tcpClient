#include <iostream>
#include <wiringPi.h>

#include "tcpClient.h"
#include "Button.h"
#include "Led.h"
#include "Listener.h"
#include "Controller.h"
#include "View.h"

int main()
{
    Button ledButton(27);
    Button activeButton(28);
    Led led(21);
    tcpClient client;

    View view(&led);
    Controller controller(&view);
    Listener listener(&ledButton, &activeButton, &controller, &client);

    while(1)
    {
        listener.checkEvent();
        view.ledView();
        
        delay(60);
    }

    return 0;

}
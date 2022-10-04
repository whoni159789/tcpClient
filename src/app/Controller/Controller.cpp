#include "Controller.h"
#include <iostream>

Controller::Controller(View *view)
{
    activeState = INACITVE;
    ledState = LED_OFF;
    this->view = view;
}

Controller::~Controller()
{

}

void Controller::updateEvent(std::string strbtn)
{
    if(activeState == ACTIVE)
    {
        if(strbtn == "ledButton")
        {
            ledState = LED_ON;
            std::cout << "LED ON!!!" << std::endl;
            view->setLedState(ledState);
        }
    }
    else if(activeState == INACITVE)
    {
        std::cout << strbtn << std::endl;
        if(strbtn.compare("ledActive") > 0)
        {
            activeState = ACTIVE;
            std::cout << "LED 활성화!!!" << std::endl;
            view->setActState(activeState);
        }
    }
    
}
#include "View.h"

View::View(Led *led)
{   
    activeState = INACITVE;
    ledState = LED_OFF;
    this->led = led;
}

View::~View()
{

}

void View::setActState(int state)
{
    activeState = state;
}

void View::setLedState(int state)
{
    ledState = state;
}

void View::ledView()
{
    if(activeState == INACITVE)
        led->Off();
        
    else if(activeState == ACTIVE)
    {
        if(ledState == LED_OFF)
            led->Off();
        else if(ledState == LED_ON)
            led->On();
    }
}
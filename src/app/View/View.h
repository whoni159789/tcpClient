#ifndef VIEW_H
#define VIEW_H

#pragma once

#include "activeState.h"
#include "ledState.h"
#include "Led.h"

class View
{
private:
    int activeState;
    int ledState;
    Led *led;

public:
    View(Led *led);
    ~View();
    void setActState(int state);
    void setLedState(int state);
    void ledView();

};

#endif
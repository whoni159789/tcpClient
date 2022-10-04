#ifndef CONTROLLER_H
#define CONTROLLER_H

#pragma once
#include <string>
#include "activeState.h"
#include "ledState.h"
#include "View.h"

class Controller
{
private:
    int activeState;
    int ledState;
    View *view;

public:
    Controller(View *view);
    ~Controller();
    void updateEvent(std::string strbtn);


};

#endif
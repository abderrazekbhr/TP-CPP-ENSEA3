#pragma once
#include "./State.h"
class Init:public State
{
public:
    void handle();
    ~Init();
};


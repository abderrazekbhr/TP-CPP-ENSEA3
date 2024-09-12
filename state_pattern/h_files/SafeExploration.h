#pragma once
#include "./State.h"
class SafeExploration : public State
{
public:
    void handle();
    ~SafeExploration();
};
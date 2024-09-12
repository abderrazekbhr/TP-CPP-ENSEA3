#include "../h_files/State.h"
#include "../h_files/Context.h"
#include <iostream>
State::State()
{
    context = new Context();
}
State::~State()
{
    delete context;
}
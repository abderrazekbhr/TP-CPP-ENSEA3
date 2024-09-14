#include "./State.h"

class Wait:public State{
    public :
        void handle();
        ~Wait();
};
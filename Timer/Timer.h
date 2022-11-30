/*
* DESCRIPTION: class Timer
* AUTHOR:      cs91chris
* LICENCE:     GPLv3
*/
#ifndef _TIMER_
#define _TIMER_

#include <Arduino.h>

#define MS 1000


class Timer 
{
    public:
        Timer() : lastTime(0) {}

        void init();
        void delayMS(uint16_t s);
        uint16_t waitMS(uint16_t interval);

    private:
        uint64_t lastTime;
};

#endif

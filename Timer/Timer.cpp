/*
* DESCRIPTION: timer implementation
* AUTHOR:      cs91chris
* LICENCE:     GPLv3
*/
#include "timer.h"


void Timer::init()
{
    lastTime = millis();
}

uint16_t Timer::waitMS(uint16_t interval)
{
    uint64_t currTime = millis();
    uint16_t timePassed = currTime - lastTime;
    lastTime = currTime;

    if(timePassed < interval)
        delayMS(interval - timePassed);

    return timePassed;
}

void Timer::delayMS(uint16_t s)
{
    while(s--)
        delayMicroseconds(MS);
}

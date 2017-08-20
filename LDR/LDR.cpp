#include "LDR.h"


void LDR::setup(byte p)
{
    _lux = 0.0;
    _pin = p;
    pinMode(p, INPUT);
}

double LDR::read()
{
    byte val = analogRead(_pin);

    double vout = LDR_VREF * val;
    double ldr  = (LDR_RREF / vout) - PULLDOWN;
    _lux = pow(ldr / LDR_UNIT, ANTI_GAMMA);

    return _lux;
}

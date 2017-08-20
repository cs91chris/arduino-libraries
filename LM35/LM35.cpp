#include "LM35.h"

void LM35::setup(byte vref, byte vout)
{
	vref_pin = vref;
	vout_pin = vout;
	temperature = 0.0;
}

float LM35::read()
{
	byte vout = analogRead(vout_pin);
	byte vref = analogRead(vref_pin);

	temperature = (vout - vref) * getConst();
	return temperature;
}

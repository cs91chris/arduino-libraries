/*
 *	@ Author: Christian Sannino
 */

#include "Pin.h"


void Pin::setup(byte p) 
{//===============================
	_pin = p;
	setMode(OUTPUT);
	write(LOW);
}

void Pin::setup(byte p, State s, bool m) 
{//===============================
	_pin = p;
	setMode(m);
	write(s);
}

void Pin::setMode(bool m)
{//===============================
	_mode = m;
	pinMode(_pin, _mode);
}

State Pin::switchState()
{//===============================
	State s = !_state;

	setState(s);
	return s;
}

void Pin::write(State s)
{//===============================
	if(_mode == OUTPUT)
	{
		_state = s;

		if(digitalPinHasPWM(_pin))
			analogWrite(_pin, s);
		else
			digitalWrite(_pin, s);
	}
}

State Pin::read()
{//===============================
	if(_mode == INPUT)
	{
		if(_pin >= (NUM_DIGITAL_PINS - NUM_ANALOG_INPUTS))
			_state = analogRead(_pin);
		else
			_state = digitalRead(_pin);
	}
	return _state;
}

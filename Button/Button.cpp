#include "Button.h"


void Button::setup(byte pin)
{
	setup(pin, DEBOUNCE_TIME);
}

void Button::setup(byte pin, word time)
{
	_pin = pin;
	old_val = HIGH;
	last_time = 0L;
	debounce_time = time;

	pinMode(_pin, INPUT);
}

bool Button::read()
{
	bool state = LOW;
	unsigned long current_time = millis();

	if(current_time - last_time > debounce_time) {
		last_time = current_time;
		bool value = digitalRead(_pin);

		if(value == LOW && old_val == HIGH)
			state = HIGH;

		old_val = value;
	}
	return state;
}

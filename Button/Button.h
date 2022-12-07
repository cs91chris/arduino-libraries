#ifndef _BUTTON_
#define _BUTTON_

#include <Arduino.h>

#define DEBOUNCE_TIME 200

/*
 * Read a button with pulldown resistor
 */
class Button
{
	public:
		void setup(byte pin);
		void setup(byte pin, word time);
		bool read();

		bool getState() const {
			return old_val;
		}

	private:
		byte _pin;
		word debounce_time;
		bool old_val;
		unsigned long last_time;
};

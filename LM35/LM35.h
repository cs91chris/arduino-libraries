#ifndef _LM35_
#define _LM35_

#include <Arduino.h>


#define AREF 5.0
#define RES	 1024


class LM35
{
	public:
		void  setup(byte vref, byte vout);
		float getTemperature() const { return temperature; }
		float read();

	private:
		byte  vref_pin;
		byte  vout_pin;
		float temperature;

		float getConst() const { return (AREF / RES) * 100.0; }
};

#endif


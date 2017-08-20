/*
 *	@ Author: Christian Sannino
 */

#ifndef _Pin_H_
#define _Pin_H_

#include <Arduino.h>


#define	PWM_25		0x40
#define	PWM_50		0x80
#define	PWM_75		0xC0
#define PWM_MAX		0xFF


typedef byte State;


class Pin
{
	public:
		Pin() {};

		void  setup(byte p);
		void  setup(byte p, State s, bool m);

		void  setMode(bool m);
		void  write(State s);

		State read();
		State switchState();

		byte  getPin()		const { return _pin;   }
		State getState()	const { return _state; }
		bool  getMode()		const { return _mode;  }

		void setState(State s) { write(s); }

	protected:
		byte _pin;
		bool _mode;
		volatile State _state;
};

#endif


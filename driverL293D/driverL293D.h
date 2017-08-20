/*
 *	@ Author: Christian Sannino
 */

#ifndef _DRIVER_MOTOR_L293D_H_
#define _DRIVER_MOTOR_L293D_H_

#include <Arduino.h>


#define	M_START		true
#define	M_STOP		!M_START

#define M_ENABLED	true
#define M_DISABLED	!M_ENABLED

#define M_UP		true
#define M_DOWN		!M_UP

#define M_FRONT		true
#define M_BACK 		!M_BACK

#define	M_SX		true
#define	M_DX		!M_SX

#define	M_25VEL		0x40
#define	M_50VEL		0x80
#define	M_75VEL		0xC0
#define M_MAXVEL	0xFF


class Motor
{
	public:
		Motor(byte p1, byte p2, byte en) : pin1(p1), pin2(p2), enable(en) {}

		void begin(bool dir);
		void enableMotor(bool en);
		void pwm(byte pin, byte vel);

		void move(bool dir);
		void move(byte vel);
		void move(bool dir, byte vel);

		void move() { move(direction); }

		bool reverse();
		bool getDirection() const { return direction;  }
		bool getState()	 	const { return state; 	   }

		void setDirection(bool dir) { direction = dir; }
		void setState(bool st)		{ state = st;      }


	private:
		const byte pin1;
		const byte pin2;
		const byte enable;

		volatile bool state;
		volatile bool direction;
};

#endif


/*
 *	@ Author: Christian Sannino
 */

#include "driverL293D.h"


void Motor::begin(bool dir)
{//===============================
	state = M_STOP;
	direction = dir;

	pinMode(enable, OUTPUT);
	pinMode(pin1,   OUTPUT);
	pinMode(pin2,   OUTPUT);
}

void Motor::pwm(byte pin, byte vel)
{//===============================
	analogWrite(enable, 0xFF);
	delayMicroseconds(5000);
	analogWrite(pin, vel);
}

void Motor::enableMotor(bool st)
{//===============================
	setState(st);
	digitalWrite(enable, state);
}

void Motor::move(bool dir)
{//===============================
	setDirection(dir);
	digitalWrite(pin1, direction);
	digitalWrite(pin2, !direction);
}

void Motor::move(byte vel)
{//===============================
	move(direction);
	pwm(enable, vel);
	setState(M_START);
}

void Motor::move(bool dir, byte vel)
{//===============================
	move(dir);
	pwm(enable, vel);
	setState(M_START);
}

bool Motor::reverse()
{//===============================
	setDirection(!direction);
	return direction;
}


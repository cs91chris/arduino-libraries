# include "28BYJStepper.h"


const byte 28BYJStepper::phases[] = {
	B1000,
	B1100,
	B0100,
	B0110,
	B0010,
	B0011,
	B0001,
	B1001
};

28BYJStepper::setup(byte in1, byte in2, byte in3, byte in4)
{
	phase = 0;
	speed = 100;
	
	IN1 = in1;
	IN2 = in2;
	IN3 = in3;
	IN4 = in4;
	
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);
}

void 28BYJStepper::steps(int count)
{
	int rotationDirection = count < 1 ? -1 : 1;
	count *= rotationDirection;

	for(int x = 0; x < count; x++)
	{
		digitalWrite(IN1, bitRead(phases[phase], 0));
		digitalWrite(IN2, bitRead(phases[phase], 1));
		digitalWrite(IN3, bitRead(phases[phase], 2));
		digitalWrite(IN4, bitRead(phases[phase], 3));

		phase += NUM_PHASE + rotationDirection;
		phase %= NUM_PHASE;
		delay(100 / speed);
	}
}

void 28BYJStepper::stop()
{
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, LOW);
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, LOW);
}

void 28BYJStepper::getSpeed() {
	return this.speed;
}

void 28BYJStepper::setSpeed(byte s) {
	this.speed = s;
}

void 28BYJStepper::clockWise() {
	steps(1);
}

void 28BYJStepper::antiClockWise() {
	steps(-1);
}

void 28BYJStepper::clockWiseFull() {
	steps(FULL_ROTATION);
}

void 28BYJStepper::antiClockWiseFull() {
	steps(-FULL_ROTATION);
}

void 28BYJStepper::clockWiseHalf() {
	steps(HALF_ROTATION);
}

void 28BYJStepper::antiClockWiseHalf() {
	steps(-HALF_ROTATION);
}

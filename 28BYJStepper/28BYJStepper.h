#ifndef _28BYJ_
#define _28BYJ_

#define NUM_PHASE 	  8
#define FULL_ROTATION 512 //4076
#define HALF_ROTATION FULL_ROTATION / 2


class 28BYJStepper {
	public:
		void setup(byte in1, byte in2, byte in3, byte in4);

		void getSpeed() {
			return this.speed;
		}

		void setSpeed(byte s) {
			this.speed = s;
		}

		void stop();
		void steps(int count);
		
		void clockWise();
		void clockWiseFull();
		void clockWiseHalf();
		
		void antiClockWise();
		void antiClockWiseFull();
		void antiClockWiseHalf();
	
	private:
		const byte phases[NUM_PHASE];

		byte phase;
		byte speed;

		byte IN1;
		byte IN2;
		byte IN3;
		byte IN4;
};

#endif

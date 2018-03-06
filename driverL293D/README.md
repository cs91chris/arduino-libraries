# DriverL293D
Arduino library to manage L293D driver.

You do not worry about setting enable motor or direction configuration 
#

# Example1: move motor and reverse direction repetedly

<code>
Motor motor(7, 8, 9);

void setup() {
  motor.begin(M_FRONT);
  motor.move();
  motor.enableMotor(M_ENABLED);
}

void loop() {
  delay(1000);
  motor.reverse();
}
</code>
#

# Example2: regulate velocity (pwm)
<code>
Motor motor(7, 8, 9);

void setup() {
  motor.begin();
  motor.move(M_FRONT, M_75VEL);
}

void loop() {

}
</code>

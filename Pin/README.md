# pin
Arduino library to manage pins of your board simply.

You do not worry about setting mode, check analog or pwm, etc.
#

# Example1: blinking a led on pin 10

<pre>
Pin mypin;

void setup() {
  mypin.setup(10);
}

void loop() {
  mypin.switchState();
  delay(1000);
}
</pre>
#

# Example2: read analog values on pin A0
<pre>
Pin mypin;

void setup() {
  mypin.setup(A0, LOW, INPUT);
}

void loop() {
  Serial.println(mypin.read());
  delay(1000);
}
</pre>
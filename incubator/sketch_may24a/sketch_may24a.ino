// Project 1 - Police Lights by Dave1324

int ledDelay = 50; // delay by 50ms
int redPin = 9;
int bluePin = 12;


void setup() {
pinMode(redPin, OUTPUT);
pinMode(bluePin, OUTPUT);

}

void loop() {

digitalWrite(redPin, HIGH); // turn the red light on
delay(ledDelay); // wait 50 ms

digitalWrite(redPin, LOW); // turn the red light off
delay(ledDelay); // wait 50 ms

digitalWrite(redPin, HIGH); // turn the red light on
delay(ledDelay); // wait 50 ms

digitalWrite(redPin, LOW); // turn the red light off
delay(ledDelay); // wait 50 ms

digitalWrite(redPin, HIGH); // turn the red light on
delay(ledDelay); // wait 50 ms

digitalWrite(redPin, LOW); // turn the red light off
delay(ledDelay); // wait 50 ms

delay(100); // delay midpoint by 100ms

digitalWrite(bluePin, HIGH); // turn the blue light on
delay(ledDelay); // wait 50 ms

digitalWrite(bluePin, LOW); // turn the blue light off
delay(ledDelay); // wait 50 ms

digitalWrite(bluePin, HIGH); // turn the blue light on
delay(ledDelay); // wait 50 ms

digitalWrite(bluePin, LOW); // turn the blue light off
delay(ledDelay); // wait 50 ms

digitalWrite(bluePin, HIGH); // turn the blue light on
delay(ledDelay); // wait 50 ms

digitalWrite(bluePin, LOW); // turn the blue light off
delay(ledDelay); // wait 50 ms


}

/*
    Name:       MouseBumper.ino
    Created:	2/18/2019 11:32:12 AM
    Author:     MURRAYOFFICE\chips
*/


#include "Blinker.h"
#include <Servo.h>
#include <Timer.h>
#include <Event.h>

#define BLINK_TIME 1000		// ms
#define BUMP_TIME 60000		// ms

#define SERVO_PIN 9

Servo servo;
Timer timer;

BlinkerClass led;

void setup()
{
	Serial.begin(115200);
	led.init(LED_BUILTIN);
	servo.attach(SERVO_PIN);
	Serial.println("Ready");
	timer.every(BLINK_TIME, toggle);
	timer.every(BUMP_TIME, goleft);
	delay(1000);
	timer.every(BUMP_TIME, goright);
}

void toggle() {
	led.toggle();
	//Serial.print("T");
}

void goleft() {
	servo.write(0);
	Serial.print("L");
}

void goright() {
	servo.write(180);
	Serial.print("R");
}

void loop()
{
	timer.update();
}

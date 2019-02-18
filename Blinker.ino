// 
// 
// 

#include "Blinker.h"

void BlinkerClass::init() {
	BlinkerClass::init(LED_BUILTIN);
}

void BlinkerClass::init(int mypin)
{
	state = 0;
	pin = mypin;
	sync();
	pinMode(pin, OUTPUT);
}

void BlinkerClass::sync() {
	digitalWrite(pin, state);
	//Serial.print(state);
}

void BlinkerClass::set(bool val) {
	state = val;
	sync();
}

void BlinkerClass::toggle() {
	set(!state);
}


// Blinker.h

#ifndef _BLINKER_h
#define _BLINKER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class BlinkerClass
{
 protected:

 public:
	void init();
	void init(int pin);
	void set(bool val);
	void sync();
	void toggle();

private:
	bool state;
	int pin;
};

extern BlinkerClass Blinker;

#endif


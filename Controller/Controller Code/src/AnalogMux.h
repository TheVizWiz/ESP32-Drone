//
// Created by vibhu on 6/9/2022.
//

#ifndef CONTROLLER_CODE_ANALOGMUX_H
#define CONTROLLER_CODE_ANALOGMUX_H

#include "Arduino.h"

class AnalogMux {
public:
	int s_0, s_1, s_2, z;
	AnalogMux(int s_0, int s_1, int s_2, int z);
	AnalogMux(int s_0, int s_1, int s_2, int z, int inputMode);
	bool* digitalReadAll();
	uint16_t * analogReadAll();
	bool digitalRead(int signalNumber);
	uint16_t analogRead (int signalNumber);

private:
	void setMux(int signalNumber);
};


#endif //CONTROLLER_CODE_ANALOGMUX_H

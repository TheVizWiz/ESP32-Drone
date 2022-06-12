//
// Created by vibhu on 6/9/2022.
//

#include "AnalogMux.h"
#include "Arduino.h"


AnalogMux::AnalogMux (int s_0, int s_1, int s_2, int z) : AnalogMux(s_0, s_1, s_2, z, INPUT) {
}

AnalogMux::AnalogMux (int s_0, int s_1, int s_2, int z, int inputMode) {
	this->s_0 = s_0;
	this->s_1 = s_1;
	this->s_2 = s_2;
	this->z = z;
	pinMode(s_0, OUTPUT);
	pinMode(s_1, OUTPUT);
	pinMode(s_2, OUTPUT);
	pinMode(z, inputMode);

}

bool *AnalogMux::digitalReadAll () {
	bool reads[8];
	for (int i = 0; i < 8; ++i) {
		reads[i] = digitalRead(i);
	}
	return reads;
}

uint16_t *AnalogMux::analogReadAll () {
	uint16_t reads[8];
	for (int i = 0; i < 8; ++i) {
		setMux(i);
		reads[i] = Arduino_h::analogRead(z);
	}
	return reads;
}

void AnalogMux::setMux (int signalNumber) {
	digitalWrite(s_0, (signalNumber & 1) ? HIGH : LOW);
	digitalWrite(s_1, (signalNumber & 2) ? HIGH : LOW);
	digitalWrite(s_2, (signalNumber & 4) ? HIGH : LOW);
}

bool AnalogMux::digitalRead (int signalNumber) {
	setMux(signalNumber);
	return ::digitalRead(z);
}

uint16_t AnalogMux::analogRead (int signalNumber) {
	setMux(signalNumber);
	return ::analogRead(z);
}





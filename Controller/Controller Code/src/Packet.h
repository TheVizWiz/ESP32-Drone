//
// Created by vibhu on 6/9/2022.
//

#ifndef CONTROLLER_CODE_PACKET_H
#define CONTROLLER_CODE_PACKET_H

#include "Arduino.h"

struct ControllerPacket {
public:
	ControllerPacket();
	uint8_t pot0, pot1, pot2, pot3, pot4, pot5, pot6, pot7;
	uint8_t pot8, pot9, pot10, pot11, pot12, pot13, pot14, pot15, pot16;
	byte buttonMatrix1, buttonMatrix2;
	bool getButton(int buttonNumber);

};


struct TelemetryPacket {
public:
	TelemetryPacket();
	uint8_t stat0, stat1, stat2, stat3, stat4, stat5, stat6, stat7;
	uint8_t stat8, stat9, stat10, stat11, stat12, stat13, stat14, stat15;
	byte boolMatrix1, boolMatrix2;
	bool getBool(int boolNumber);
};


#endif //CONTROLLER_CODE_PACKET_H

#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson/Document/DynamicJsonDocument.hpp>
#include "RF24.h"
#include "AnalogMux.cpp"
#include "Packet.h"
#include "main.h"


#define s_0 1
#define s_1 2
#define s_2 3
#define z_0 4
#define z_1 5
#define z_2 6
#define z_3 7

#define RADIO_CE_PIN 26
#define RADIO_CS_PIN 25

AnalogMux
		mux1 = AnalogMux(s_0, s_1, s_2, z_0),
		mux2 = AnalogMux(s_0, s_1, s_2, z_1),
		mux3 = AnalogMux(s_0, s_1, s_2, z_2),
		mux4 = AnalogMux(s_0, s_1, s_2, z_3);

ControllerPacket controllerData = ControllerPacket();
TelemetryPacket droneData = TelemetryPacket();

RF24 radio = RF24(RADIO_CE_PIN, RADIO_CS_PIN);
byte radioAddress[6] = "00001";


const char *ssid = "arduinoWifi";
AsyncWebServer server(80);
AsyncWebSocket socket("/ws");
char jsonSerialized[2048];
ArduinoJson6194_F1::DynamicJsonDocument jsonDocument(2048);


void setup () {
	Serial.begin(115200);


	radio.begin();
	radio.setPALevel(RF24_PA_LOW);
	radio.setDataRate(RF24_1MBPS);
	radio.setChannel(0);
	radio.enableAckPayload();
	radio.openWritingPipe(radioAddress);
	radio.stopListening();

	WiFi.softAP(ssid);

	// Print ESP Local IP Address
	Serial.println("IP: " + WiFi.softAPIP().toString());

	server.addHandler(&socket);


	// Route for root / web page
	server.on("/", HTTP_GET, [] (AsyncWebServerRequest *request) {
		parseInput();
		request->send(200, "application/json", jsonSerialized);
	});

	// Start server
	server.begin();

// write your initialization code here
}

void loop () {

	parseInput();
	radio.write(&controllerData, sizeof(controllerData));

	if (radio.isAckPayloadAvailable()) {
		radio.read(&droneData, sizeof(droneData));
	}

	socket.textAll(jsonSerialized);
	socket.cleanupClients();

}

void parseInput () {

}

void writeJSON () {
	jsonDocument["pitch"] = ;

}
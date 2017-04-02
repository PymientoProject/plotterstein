#include <SoftwareSerial.h>

#define TX 14
#define RX 15
SoftwareSerial rpi(TX, RX);
String msg;

void setup(){
    Serial.begin(9600);
    pinMode(TX, OUTPUT);
    pinMode(RX, INPUT);
    rpi.begin(96000);
    msg = "";
}

void loop(){
	if(rpi.available()){
    Serial.println("Mensaje ha llegado");
		msg = "";
		char car;
		while(rpi.available()){
		    car = rpi.read();
       Serial.println("Caracter recibido = " + car);
		    msg += String(car);
		}
		Serial.println("Recibido = " + msg);
		if(msg != ""){
			rpi.println("HOLA");
		}
	}
}

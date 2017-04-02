
/*

**********************************************************
*
* Control de velocidad motor DC con Mosfet
* 
* Daniel López
* V 0.1
* Sep-2016
*********************************************************


Sketch de prueba para controlar un motor DC por PWM 
con el puente H fabricado con 4 mosfet IRFZ44
Realizo el control mediante un potenciómetro. La mitad para un sentido y la otra mitad para el otro.

V 0.1
  - Versión inicial
  - Incorporo lectura del potenciómetro. mitad del potenciómetro para giro a derecha y mitad para giro a izquierda. Centrado,
  de forma similar a un joyStick.
  - Definición de pines para usar los 4 mosfet. 2 abiertos y 2 en modo PWM para control de velocidad y sentido de giro
  - He realizado el puente H con 4 IRF44Z controlados por dos driver IR2110. De esta forma puedo controlar cargas importantes.
  El objetivo es montar el driver en un ploter reciclado para el proyecto PyMiento 2016

*/


 
#define pot A0
#define uno 9
#define dos 5
int pot_estado;
int contador = 0;
int n = contador;

void setup() {
    pinMode(pot, INPUT);
    pinMode(uno, OUTPUT);
    pinMode(dos, OUTPUT);

    digitalWrite(uno,0);
    digitalWrite(dos,0);
  
    Serial.begin(115200);
    attachInterrupt( 1, encX, FALLING);
}


void loop() {
  /*

    pot_estado = analogRead(pot);
    int avance = (511-pot_estado)/2;
    int retroceso = (pot_estado - 512)/2;

    if (avance < 0) avance = 0;
    else if(avance == 255) avance =254;

    if (retroceso < 0) retroceso = 0;
    else if(retroceso == 255) retroceso = 254;

    //Serial.print(avance);
    //Serial.print(", ");
    //Serial.println(retroceso);

    if (avance >0) {        
        analogWrite(uno, 0);
        analogWrite(dos, avance);
        //if (n != contador) {
        n += contador;
        Serial.println(n);
        contador =0;
    }

    if (retroceso >0) {  
        analogWrite(dos, 0);
        analogWrite(uno, retroceso);
        n -= contador;
        Serial.println(n);
        contador =0;
    }
*/
Serial.println(contador);
}

void encX() {
    contador++;
}


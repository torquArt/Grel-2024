/* (invertido) cabo roxo longo, esquerdo
cinza longo, meio esquerda
roxo curto, meio direita
cinza curto, direita
amarelo, frente-*/

#include <Servo.h>

Servo servoEsquerda;
Servo servoDireita;

#define sensorF A1 // MAX: 506 MIN: 202
#define sensorEsq A3 // MAX: 632 MIN: 433
#define sensorDir A4 // MAX: 486 MIN: 120
#define sensorMesq A2 // MAX: 370 MIN: 102
#define senosr Mdir A5 // MAX: 360 MIN: 120


void setup(){
pinMode(A1, INPUT);
pinMode(A2, INPUT);
pinMode(A3, INPUT);
pinMode(A4,INPUT);
pinMode(A5, INPUT);

servoEsquerda.attach(3);
servoDireita.attach(6);

Serial.begin(9600);
}

void loop(){
Serial.print(analogRead(A3)); // esquerda
Serial.print(" /// ");
Serial.print(analogRead(A2)); // meio esquerda
Serial.print(" /// ");
Serial.print(analogRead(A1)); // frente 
Serial.print(" /// ");
Serial.print(analogRead(A5)); // meio direita
Serial.print(" /// ");
Serial.print(analogRead(A4)); // // direita
Serial.println();
}

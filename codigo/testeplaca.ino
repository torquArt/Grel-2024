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

int pinosSensores[5] = {A1, A2, A3, A4, A5};
int valoresSegueFaixa[5] = {};

void setup(){
for(int i = 0; i<5, i++){
pinMode (pinosSeguefaixa[i], INPUT);

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

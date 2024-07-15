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
int valorF = 0;
int valorEsq = 0;
int valorDir = 0;
int valorMesq = 0;
int valorMdir = 0;

void setup(){
for(int i = 0; i<5; i++){
pinMode (pinosSensores[i], INPUT);
}
servoEsquerda.attach(3);
servoDireita.attach(6);

Serial.begin(9600);
}


void loop(){
if (analogRead(sensorF) >= 300 ){
  valorF = 0;
} else {valorF = 1;}

if (analogRead(sensorEsq) >= 400 ){
  valorF = 0;
} else {valorEsq = 1;}
  
if (analogRead(sensorDir) >= 150 ){
  valorF = 0;
} else {valorDir = 1;}
  
if (analogRead(sensorMesq) >= 120 ){
  valorF = 0;
} else {valorMesq = 1;}
  
if (analogRead(sensorMdir) >= 150 ){
  valorF = 0;
} else {valorMdir = 1;}

Serial.print(valorF);
/*Serial.print(analogRead(A3)); // esquerda
Serial.print(" /// ");
Serial.print(analogRead(A2)); // meio esquerda
Serial.print(" /// ");
Serial.print(analogRead(A1)); // frente 
Serial.print(" /// ");
Serial.print(analogRead(A5)); // meio direita
Serial.print(" /// ");
Serial.print(analogRead(A4)); // // direita*/
Serial.println();
}

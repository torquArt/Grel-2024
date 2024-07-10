/* cabo roxo longo, esquerdo
cinza longo, meio esquerda
roxo curto, meio direita
cinza curto, direita
amarelo, frente-*/

#include <Servo.h>

Servo servoEsquerda;
Servo servoDireita;

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
/*Serial.print(analogRead(A1));
Serial.print(" /// ");*/
Serial.print(digitalRead(A5));
Serial.print(" /// ");
Serial.print(digitalRead(A2));
Serial.print(" /// ");
Serial.print(digitalRead(A4));
Serial.print(" /// ");
Serial.println(digitalRead(A3));
}

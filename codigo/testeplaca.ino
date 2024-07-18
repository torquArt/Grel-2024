// usar p/ calibrar os sensores

/* cabo roxo longo, direita
cinza longo, meio direita
roxo curto, meio esquerda
cinza curto, esquerda
amarelo, frente-*/

#define sensorF A1 // MAX: 506 MIN: 202
#define sensorEsq A3 // MAX: 632 MIN: 433
#define sensorDir A4 // MAX: 486 MIN: 120
#define sensorMesq A5 // MAX: 370 MIN: 102
#define sensorMdir A2 // MAX: 360 MIN: 120

int pinosSensores[5] = {A1, A2, A3, A4, A5};

void setup(){
for(int i = 0; i<5; i++){
pinMode (pinosSensores[i], INPUT);

Serial.begin(9600);
}


void loop(){
Serial.print(analogRead(sensorEsq));
Serial.print(" // ");
Serial.print(analogRead(sensorMesq));
Serial.print(" // ");
Serial.print(analogRead(sensorF));
Serial.print(" //");
Serial.print(analogRead(sensorMdir));
Serial.print(" // ");
Serial.print(analogRead(sensorDir));

Serial.println();
}

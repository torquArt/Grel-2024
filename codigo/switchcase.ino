
/* cabo roxo longo, direita
cinza longo, meio direita
roxo curto, meio esquerda
cinza curto, esquerda
amarelo, frente-*/

#include <Servo.h>

Servo servoEsquerda;
Servo servoDireita;

#define velEsq 97
#define velDir 83
#define velParar 90

///////////////////////

#define sensorF A1 
#define sensorEsq A3 
#define sensorDir A4 
#define sensorMesq A5 
#define sensorMdir A2 

//Ordem:  esquerda, meioesquerda, frente, meiodireita, direita
int sensoresMax[5] = {625, 365, 530, 320, 480}; // valores de cada sensor no branco

int sensoresMin[5] = {448, 116, 218, 74, 130}; //valores de cada sensor no preto

int mediaSensores[5] = {0, 0, 0, 0, 0};

int pinosSensores[5] = {A3, A5, A1, A2, A4};

int valorSensores[] = {0, 0, 0, 0, 0};

void setup(){
//definindo os tcrt como saídas.
  for(int i = 0; i<5; i++){
    pinMode (pinosSensores[i], INPUT);
  }

  servoEsquerda.attach(3);
  servoDireita.attach(6);

  Serial.begin(9600);
}


void loop(){
  media(0); media(1); media(2); media(3); media(4);

  if (analogRead(pinosSensores[0]) > mediaSensores[0] ){valorSensores[0] = 0;} else{valorSensores[0] = 1;}

  if (analogRead(pinosSensores[1]) > mediaSensores[1] ){valorSensores[1] = 0;} else {valorSensores[1] = 1;}
    
  if (analogRead(pinosSensores[2]) > mediaSensores[2] ){valorSensores[2] = 0;} else {valorSensores[2] = 1;}
    
  if (analogRead(pinosSensores[3]) > mediaSensores[3] ){valorSensores[3] = 0;} else {valorSensores[3] = 1;}
    
  if (analogRead(pinosSensores[4]) > mediaSensores[4] ){valorSensores[4] = 0;} else {valorSensores[4] = 1;}

   // Variável para armazenar os valores dos pinos
  byte leitura = 0;

  // Realiza a leitura dos pinos digitais
  for(int i= 0; i<5; i++){
    leitura |= valorSensores[i] << i;}

  // Exibe o valor lido em binário
  Serial.print("Valor lido: ");
  Serial.println(leitura, BIN);

  switch (leitura) {
    case 0b01110:
      Serial.print("FRENTE");
      break;
    default:
      break;
  }

}

void media(int x){
  mediaSensores[x] = (sensoresMax[x] + sensoresMin[x])/2;
}

////////////////////

void frente(){
  servoEsquerda.write(velEsq);
  servoDireita.write(velDir);
}

void esquerda(){
  servoEsquerda.write(velDir);
  servoDireita.write(velDir);
}
  
void direita(){
  servoEsquerda.write(velEsq);
  servoDireita.write(velEsq);
}
void novg_esquerda(){}
void novg_direita(){}
void t(){}
void encruzilhada(){}

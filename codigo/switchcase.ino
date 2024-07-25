
/* cabo roxo longo, direita
cinza longo, meio direita
roxo curto, meio esquerda
cinza curto, esquerda
amarelo, frente-*/

#include <Servo.h>

Servo servoEsquerda;
Servo servoDireita;

#define velEsq 100
#define velDir 80
#define velParar 90

///////////////////////

//Ordem:  esquerda, meioesquerda, frente, meiodireita, direita
int sensoresMax[5] = {594, 281, 494, 350, 502}; // valores de cada sensor no branco

int sensoresMin[5] = {428, 105, 215, 50, 115}; //valores de cada sensor no preto

int mediaSensores[5] = {0, 0, 0, 0, 0};

int pinosSensores[5] = {A3, A5, A1, A2, A4};

int valorSensores[] = {0, 0, 0, 0, 0};

void setup(){
//definindo os tcrt como saídas.
  for(int i = 0; i<5; i++){
    pinMode (pinosSensores[i], INPUT);
  }

  servoEsquerda.attach(5);
  servoDireita.attach(3);

  Serial.begin(9600);
}


void loop(){
  media(0); media(1); media(2); media(3); media(4);

  if (analogRead(pinosSensores[0]) > mediaSensores[0] ){valorSensores[0] = 0;} else{valorSensores[0] = 1;}

  if (analogRead(pinosSensores[1]) > mediaSensores[1] ){valorSensores[1] = 0;} else {valorSensores[1] = 1;}
    
  if (analogRead(pinosSensores[2]) > mediaSensores[2] ){valorSensores[2] = 0;} else {valorSensores[2] = 1;}
    
  if (analogRead(pinosSensores[3]) > mediaSensores[3] ){valorSensores[3] = 0;} else {valorSensores[3] = 1;}
    
  if (analogRead(pinosSensores[4]) > mediaSensores[4] ){valorSensores[4] = 0;} else {valorSensores[4] = 1;}


byte leitura = 0;
leitura |= valorSensores[0] << 4;
leitura |= valorSensores[1] << 3;
leitura |= valorSensores[2] << 2;
leitura |= valorSensores[3] << 1;
leitura |= valorSensores[4] ;

Serial.print("Valor lido: ");
Serial.println(leituraInvertida, BIN);


  switch (leituraInvertida) {
    case 0b01000:
        Serial.println("ESQ");
      esquerda();
      break;
    case 0b00010:
      Serial.println("DIR");
      direita();
      break;
    case 0b11010:
    case 0b11000:
    case 0b10010:
      Serial.println("NOV G ESQ");
      esquerda();
      break;
    case 0b01011:
    case 0b00011:
    case 0b01001:
      Serial.println("NOV G DIR");
      direita();
      break;
    default:
      Serial.println("FRENTE");
      frente();
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

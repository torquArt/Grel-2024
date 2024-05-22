


//1 = preto, 0 = branco
#include <Ultrasonic.h>

#define sensorEsquerda 12
#define sensorDireita 4
#define sensorEsquerda2 13
#define sensorDireita2 5
#define sensorMeio 8

#define motorEsquerda_frente 11  //esquerda, frente
#define motorEsquerda_antih 10  //esquerda, anti-horário
#define motorDireita_frente 3   //direita, frente
#define motorDireita_antih 9   //direira, anti-horário

#define velocidade 60
#define d 200

#define dlvirar_d1 1800
#define dlandar1 3000  //afastar
#define dlvirar_e1 2000
#define dlandar2 6000  //ultrapassar
#define dlvirar_e2 2000
#define dlandar3 500
#define dlandar4 200  //voltar p/ linha

int leituraEsquerda = !digitalRead(sensorEsquerda);
int leituraDireita = !digitalRead(sensorDireita);
int leituraEsquerda2 = !digitalRead(sensorEsquerda2);
int leituraDireita2 = !digitalRead(sensorDireita2);

Ultrasonic ultra(A3, A2);


void setup() {
  Serial.begin(9600);
  pinMode(sensorEsquerda, INPUT);
  pinMode(sensorDireita, INPUT);
  pinMode(sensorEsquerda2, INPUT);
  pinMode(sensorDireita2, INPUT);
  pinMode(sensorMeio, INPUT);
  pinMode(motorEsquerda_frente, OUTPUT);
  pinMode(motorEsquerda_antih, OUTPUT);
  pinMode(motorDireita_frente, OUTPUT);
  pinMode(motorDireita_antih, OUTPUT);
}

void loop() {

  int leituraEsquerda = !digitalRead(sensorEsquerda);
  int leituraDireita = !digitalRead(sensorDireita);
  int leituraEsquerda2 = !digitalRead(sensorEsquerda2);
  int leituraDireita2 = !digitalRead(sensorDireita2);

  //analogWrite(6, 100);
  Serial.print(" leituraEsquerda2 = ");
  Serial.print(leituraEsquerda2);
  
  Serial.print(" leituraEsquerda = ");
  Serial.print(leituraEsquerda);
  
  Serial.print(" leituraDireita = ");
  Serial.print(leituraDireita);
  
  Serial.print(" leituraDireita2 = ");
  Serial.println(leituraDireita2);


  if ((leituraEsquerda2 == 0 && leituraEsquerda == 0 && leituraDireita == 0 && leituraDireita2 == 0) ||
      (leituraEsquerda2 == 0 && leituraEsquerda == 1 && leituraDireita == 1 && leituraDireita2 == 0) || 
      (leituraEsquerda2 == 1 && leituraEsquerda == 1 && leituraDireita == 1 && leituraDireita2 == 1)) 
  {
        Serial.print("frente");
        frente();
  } 
  
  else if (leituraEsquerda2 == 0 && leituraEsquerda == 0 && leituraDireita == 1 && leituraDireita2 == 0) 
  {
    Serial.print("direita");
    direita();
  } 
  
  else if (leituraEsquerda2 == 0 && leituraEsquerda == 1 && leituraDireita == 0 && leituraDireita2 == 0)
  {    
    Serial.print("esquerda");
    esquerda();
  } 
  
  else if ((leituraEsquerda2 == 1 && leituraEsquerda == 0 && leituraDireita == 0 && leituraDireita2 == 0) ||
           (leituraEsquerda2 == 1 && leituraEsquerda == 1 && leituraDireita == 0 && leituraDireita2 == 0) ||
           (leituraEsquerda2 == 1 && leituraEsquerda == 0 && leituraDireita == 1 && leituraDireita2 == 0)) 
  {            
    Serial.print("noventa graus esquerda");
    noventaGraus_esquerda();
  } 
  
  else if ((leituraEsquerda2 == 0 && leituraEsquerda == 0 && leituraDireita == 0 && leituraDireita2 == 1) ||
           (leituraEsquerda2 == 0 && leituraEsquerda == 0 && leituraDireita == 1 && leituraDireita2 == 1) || 
           (leituraEsquerda2 == 0 && leituraEsquerda == 1 && leituraDireita == 0 && leituraDireita2 == 1)) 
  {
    Serial.print("noventa graus direita");
    noventaGraus_direita();
  }
  
}


void frente() {
  analogWrite(motorEsquerda_frente, velocidade);
  analogWrite(motorEsquerda_antih, 0);
  analogWrite(motorDireita_frente, velocidade);
  analogWrite(motorDireita_antih, 0);
}
void esquerda() {
  analogWrite(motorEsquerda_frente, 0);
  analogWrite(motorEsquerda_antih, velocidade);
  analogWrite(motorDireita_frente, velocidade);
  analogWrite(motorDireita_antih, 0);
}
void direita() {
  analogWrite(motorEsquerda_frente, velocidade);
  analogWrite(motorEsquerda_antih, 0);
  analogWrite(motorDireita_frente, 0);
  analogWrite(motorDireita_antih, velocidade);
}

void parar() {
  analogWrite(motorEsquerda_frente, 0);
  analogWrite(motorEsquerda_antih, 0);
  analogWrite(motorDireita_frente, 0);
  analogWrite(motorDireita_antih, 0);
}

void noventaGraus_esquerda() {
  frente();
  delay(d);
  while (!digitalRead(sensorMeio) == 0)
    esquerda();
}

void noventaGraus_direita() {
  frente();
  delay(d);
  while (!digitalRead(sensorMeio) == 0)
    direita();
}

void desvio() {
  direita();
  delay(dlvirar_d1);

  frente();
  delay(dlandar1);

  esquerda();
  delay(dlvirar_e1);

  frente();
  delay(dlandar2);

  esquerda();
  delay(dlvirar_e2);

  frente();
  delay(dlandar3);

  while (!digitalRead(sensorMeio) == 0)
    frente();

  frente();
  delay(dlandar4);

  while (!digitalRead(sensorMeio) == 0)
    direita();
}

#define sensorFrente x
#define sensorEsquerda x
#define sensorDireita x
#define sensorNoroeste x
#define sensorNordeste x

#include <servo.h>
Servo servoEsquerda
Servo servoDireita

#define velHorario 0
#define velAntiHorario 180

void setup(){
  servoEsquerda.attach(x);
  servoDireita.attach(x);
  
  pinMode(sensorFrente, INPUT);
  pinMode(sensorEsquerda, INPUT);
  pinMode(sensorDireita, INPUT);
  pinMode(sensorNoroeste, INPUT);
  pinMode(sensorNordeste, INPUT);

  Serial.begin(9600);
}

void loop(){
  int leituraFrente = !digitalRead(sensorFrente);
  int leituraEsquerda = !digitalRead(sensorEsquerda);
  int leituraDireita = !digitalRead(sensorDireita);]
  int leituraNoroeste = !digitalRead(sensorNordeste);
  int leituraNordeste = !digitalRead(sensorNoroeste);

  Serial.print("leituraNoroeste: ");
  Serial.print(leituraNoroeste);
  Serial.print("leituraEsquerda: ");
  Serial.print(leituraEsquerda);
  Serial.print("leituraFrente: ");
  Serial.print(leituraFrente);
  Serial.print("leituraDireita: ");
  Serial.print( leituraDireita);
  Serial.println("leituraNordeste: ");
  Serial.println(leituraNordeste);


  if (leituraEsquerda == 1 && leituraDireita == 1 && leituraFrente == 1 && leituraNordest e== 0 && leituraNoroeste == 0){
   Serial.print("frente");
   frente();
  }
  else {
    parar();
  }

}


/*---------------------------------------------------------------------------------------*/

void frente(){
  servoDireita.write(velHorario);
  servoEsquerda.write(velHorario);
}
void parar(){
  servoDireita.write(90);
  servoEsquerda.write(90);
}
void esquerda(){
  servoDireita.write(velHorario);
  servoEsquerda.write(velAntiHorario);
}
void direita(){
  servoDireita.write(velAntiHorario);
  servoEsquerda.write(velHorario);
}

#define sensorFrente x
#define sensorEsquerda x
#define sensorDireita x
#define sensorNoroeste x
#define sensorNordeste x

int pinosSeguefaixa[5] = {x, x, x, x, x};

#include <servo.h>
Servo servoEsquerda
Servo servoDireita

/*#define velHorario 0
#define velAntiHorario 180 os motores vao pra direções diferentes c a mesma vel*/ 

void setup(){
  servoEsquerda.attach(x);
  servoDireita.attach(x);

  for(int i = 0; i<5, i++){
  pinMode (pinosSeguefaixa[i], INPUT);
  }
  
  Serial.begin(9600);
}

void loop(){
  int leituraFrente = !digitalRead(sensorFrente);
  int leituraEsquerda = !digitalRead(sensorMeioEsquerda);
  int leituraDireita = !digitalRead(sensorMeioDireita);
  int leituraNoroeste = !digitalRead(sensorEsquerda);
  int leituraNordeste = !digitalRead(sensorDireita);

  Serial.print("leituraEsquerda: ");
  Serial.print(leituraEsquerda);
  Serial.print("leituraEsquerda: ");
  Serial.print(leituraMeioEsquerda);
  Serial.print("leituraFrente: ");
  Serial.print(leituraFrente);
  Serial.print("leituraDireita: ");
  Serial.print( leituraMeioDireita);
  Serial.println("leituraDireita: ");
  Serial.println(leituradireita);


 /* if (leituraEsquerda == 1 && leituraDireita == 1 && leituraFrente == 1 && leituraNordest e== 0 && leituraNoroeste == 0){
   Serial.print("frente");
   frente();
  }
  else {
    parar();
  }*/

}


/*---------------------------------------------------------------------------------------*/

/*void frente(){
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
}*/

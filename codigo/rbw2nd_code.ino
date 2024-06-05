#define sensorFrente x
#define sensorEsquerda x
#define sensorDireita x
#define sensorNoroeste x
#define sensorNordeste x

void setup(){
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

  Serial.print("leituraFrente: ");
  Serial.print(leituraFrente);
  Serial.print("leituraEsquerda: ");
  Serial.print(leituraEsquerda);
  Serial.print("leituraDireita: ");
  Serial.print( leituraDireita);
  Serial.print("leituraNoroeste: ");
  Serial.print(leituraNoroeste);
  Serial.println("leituraNordeste: ");


}

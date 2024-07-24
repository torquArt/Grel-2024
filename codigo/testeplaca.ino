// usar p/ calibrar os sensores

/* cabo roxo longo, direita
cinza longo, meio direita
roxo curto, meio esquerda
cinza curto, esquerda
amarelo, frente-*/

//Ordem:  esquerda, meioesquerda, frente, meiodireita, direita
int sensoresMax[] = {0, 0, 0, 0, 0}; // valores de cada sensor no branco

int sensoresMin[] = {0, 0, 0, 0, 0}; //valores de cada sensor no preto

int pinosSensores[] = {A3, A5, A1, A2, A4};

void setup(){
for(int i = 0; i<5; i++){
  pinMode (pinosSensores[i], INPUT);}

Serial.begin(9600);
  
Serial.println("Colocar sensores no preto.");
delay (3000);
for (int i = 0; i<5; i++){
  sensoresMin[i] = analogRead(pinosSensores[i]);
  Serial. print(i);
  Serial.print(" = ");
  Serial.println(sensoresMin[i]);
}
  delay(1000);
Serial.println("Colocar sensores no branco.");
delay (8000);
  for (int i = 0; i<5; i++){
  sensoresMax[i] = analogRead(pinosSensores[i]);
  Serial. print(i);
  Serial.print(" = ");
  Serial.println(sensoresMax[i]);
}
  
}


void loop(){}

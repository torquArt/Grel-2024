void setup()
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);

Serial.begin(9600);

void loop()
Serial.print("4: ");
Serial.print(analogRead(4));
Serial.print(" /// 5: ");
Serial.print(analogRead(5));
Serial.print(" /// 6: ");
Serial.print(analogRead(6));
Serial.print(" /// 7: ");
Serial.print(analogRead(7));
Serial.print(" /// 8: ");
Serial.println(analogRead(8));
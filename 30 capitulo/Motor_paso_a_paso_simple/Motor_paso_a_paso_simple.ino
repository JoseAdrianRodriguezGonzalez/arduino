int IN1 = 8;    //Se declaran las bobinas en sus respectivos pines 
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;
int demora = 20;    //Se declara una demora de 20 milisegundos

void setup() {
 pinMode(IN1, OUTPUT);    //Se declaran como salidas todas las bobinas
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);

}

void loop() {
for(int i=0; i<512; i++){   //512*4 =2048 PASOS
  
}

digitalWrite(IN1,HIGH);   //Se enciende la bobina 1
digitalWrite(IN2,LOW);
digitalWrite(IN3,LOW);
digitalWrite(IN4,LOW);
delay(demora);

digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);   //Se enciende la bobina 2
digitalWrite(IN3,LOW);
digitalWrite(IN4,LOW);
delay(demora);

digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
digitalWrite(IN3,HIGH);   //Se enciende la bobina 3
digitalWrite(IN4,LOW);
delay(demora);

digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);   //Se enciende la bobina 4
delay(demora);
}

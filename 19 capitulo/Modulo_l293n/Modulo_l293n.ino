int IN1= 2;
int IN2= 3;
int ENA =5;
int VELOCIDAD;

void setup() {
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
pinMode(ENA,OUTPUT);
}

void loop() {
  for(VELOCIDAD= 0; VELOCIDAD < 256; VELOCIDAD++){
  digitalWrite(ENA,HIGH);
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);

delay(50);
  }
delay(3000);
digitalWrite(ENA,LOW);
delay(2000);
 for(VELOCIDAD= 0; VELOCIDAD < 256; VELOCIDAD++){
digitalWrite(ENA,HIGH);
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
delay(50)
 }
delay(3000);
digitalWrite(ENA,LOW);
delay(2000);
  
}

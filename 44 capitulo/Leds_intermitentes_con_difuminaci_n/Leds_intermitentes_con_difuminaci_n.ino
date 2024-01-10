#define  LED1 3
#define LED2 5

void setup() {
 pinMode(LED1,OUTPUT);
 pinMode(LED2,OUTPUT);

}

void loop() {
  digitalWrite(LED2,LOW);
for(int i=0; i<255; i++){
  analogWrite(LED1,i);
  delay(15);
}
for(int i=255; i>0; i--){
  analogWrite(LED1,i);
  delay(15);
}
digitalWrite(LED1,LOW);
for(int a=0; a<255; a++){
  analogWrite(LED2,a);
  delay(15);
}
for(int a=255; a>0; a--){
  analogWrite(LED2,a);
  delay(15);
}
 digitalWrite(LED2,LOW);
for(int i=0; i<255; i++){
  analogWrite(LED1,i);
 
}
for(int b=0; b<30; b++){
  delay(100);
for(int i=255; i>0; i--){
  analogWrite(LED1,i);
  
}
digitalWrite(LED1,LOW);
for(int a=0; a<255; a++){
  analogWrite(LED2,a);
  
}
for(int a=255; a>0; a--){
  analogWrite(LED2,a);
  
}
}
for(int c=0; c<30; c++){
  delay (100);
digitalWrite(LED1, HIGH);
digitalWrite(LED2, LOW);
delay(100);
digitalWrite(LED1, LOW);
digitalWrite(LED2, HIGH);
delay(100);
}

}

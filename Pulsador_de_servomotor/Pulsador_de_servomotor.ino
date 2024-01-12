#include<ESP32Servo.h>
Servo servo;
int Pinservo=2;
int P1=4;
int P2=15;
void setup() {
pinMode(P1, INPUT);
pinMode(P2, INPUT);
servo.attach(Pinservo,500,2500);
Serial.begin(115200);
servo.write(90);
}
int posicion=0;
void loop(){

//Serial.println(P2);
delay(1000);
bool estado1=digitalRead(P1);
bool estado2=digitalRead(P2);

if(estado1==1){
  servo.write(0);
  Serial.print("Si");
}  
if(estado2==1){
  servo.write(180);
Serial.print("no");
}
}

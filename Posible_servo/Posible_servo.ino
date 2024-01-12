#include "ESP32Servo.h"
#define push 4
#define servo 2
Servo servo1;
int position[180];
int posicion[180];
int i,j;
int ultposi,ultposj;
unsigned long TA,TA2;
unsigned long TU=0,TU2=0;
void IRAM_ATTR r(){
  //servo1.write();
  Serial.println(atra(0));
  if(ade(0)==true){
    Serial.println(ultposi);
    servo1.write(ultposi);
    delay(1000);
    continuar(ultposi);
      
  }
  else if(atra(0)==true){
        Serial.println(ultposj);
        servo1.write(ultposj);
        delay(1000);
        continuar(ultposj);
  }
  

}

void setup() {
  // put your setup code here, to run once:
  servo1.attach(servo,500,2500);
  pinMode(push,INPUT);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(push),r,RISING);
  arreglos();
}

void arreglos(){
  for(i=0;i<180;i++){
    position[i]=i;
  } 
  for(j=180;j>0;j--){
    posicion[j]=j;
  } 
}
void loop() {
    // put your main code here, to run repeatedly:

  ade(0);
  atra(0);

}
int adelante(){
    for(i=0;i<180;i++){
      servo1.write(position[i]);
      delay(10);
      ultposi=i;
  }   
    return i;
    
}
bool ade(int a){
  if(a==0){
    adelante();
    
  }
  return true;
}
int atras(){
    for(j=180;j>0;j--){
      servo1.write(posicion[j]);
      delay(10);
      ultposj=j;
    }
    return posicion[j];
}
bool atra(int b){
  if(b==0){
    atras();

  }
  return true;
}
void continuar(int let){
  if(atra(0)==true){
    for(int cont=let;cont>0;cont--){
      servo1.write(cont);
      delay(10);
    }
  }
    else if(ade(0)==true){
      for(int cont=let;cont<180;cont++){
        servo1.write(cont);
        delay(10);
      }
    }
  }


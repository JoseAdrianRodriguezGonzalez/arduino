#include <SoftwareSerial.h>   //Se incluye la librería del modulo

SoftwareSerial miBT(10,11);     //Se crea un objeto del tipo "SoftwareSerial" llamado miBT conectado en los pines 10 y 11 
char DATO = 0;    //Se crea una cadena de caracteres llamada "DATO" que empieza desde cero
 int  a =2;                  //Se crean las variables del display de las partes del numero o letra        
int  b =3;
int  c =4;
int  d =5;
int  e =6;
int  f =7;
int  g =8;
void setup(){
  miBT.begin(38400);      //Se inicializa el modulo a 38400 baudios
  pinMode(a, OUTPUT);   //Se declaran los displays como salidas
   pinMode(b, OUTPUT);
    pinMode(c, OUTPUT);
     pinMode(d,OUTPUT); 
      pinMode(e, OUTPUT);
       pinMode(f, OUTPUT);
        pinMode(g, OUTPUT);
}
void loop(){
  if(miBT.available()){   //Si miBT tiene datos,se porcede a...
    DATO= miBT.read();    //Dato es igual a los datos leídos en el modulo Bluetooth
    if (DATO =='1')     //Si el dato es igual a 1
    //uno 
    digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  }
  if(miBT.available()){
    DATO= miBT.read();
    if (DATO =='2')
    //DOS
     digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);
  }
   if(miBT.available()){
    DATO= miBT.read();
    if (DATO =='3')
    //TRES
    digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);
   }
    if(miBT.available()){
    DATO= miBT.read();
    if (DATO =='4')
    //CUATRO
     digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
    }
    if(miBT.available()){
    DATO= miBT.read();
    if (DATO =='5')
    //CINCO
    digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
    }
    if(miBT.available()){
    DATO= miBT.read();
    if (DATO =='6')
    //SEIS
    digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
    }
    if(miBT.available()){
    DATO= miBT.read();
    if (DATO =='7')
    //SIETE
     digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
    }
    if(miBT.available()){
    DATO= miBT.read();
    if (DATO =='8')
    //OCHO
    digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
    }
    if(miBT.available()){
    DATO= miBT.read();
    if (DATO =='9')
    //NUEVE
    digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
    }
     if(miBT.available()){
    DATO= miBT.read();
    if (DATO =='10')
     //CERO
    digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
     }
}

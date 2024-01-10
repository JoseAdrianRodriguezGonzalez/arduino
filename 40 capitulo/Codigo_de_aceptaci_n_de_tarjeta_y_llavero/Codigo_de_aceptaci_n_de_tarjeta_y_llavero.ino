#include<SPI.h>   // Se incluye la librería de la comunciación SPI 
#include<MFRC522.h>   //Se incluye la librería del modulo MFRC522
#define RST_PIN 9   //Se define una constante llamada RST_PIN en el pin 9
#define SS_PIN 10   //Se define una constante llamada SS_PIN en el pin 10
int LED1 =2;    //Se declaran como enteros los leds
int LED2= 4;
MFRC522 mfrc522(SS_PIN, RST_PIN);   //Se crea un objeto del tipo MFRC522 llamado mfr522 con los parámetros de "SS_PIN" y "RST_PIN"
byte LecturaUID[4];   //Se crea un array del tipo byte llamado "LecturaUID", de un tamaño de 4 y almacenará los codigos leídos
byte Usuario1[4] = {0x30, 0x3B, 0XFE, 0XA7} ; //Se crea un usuario con los codigos hexadecimales de la tarjeta
byte Usuario2[4] = {0x15, 0x2F, 0X34, 0X53};//Se crea un usuario con los codigos hexadecimales del llavero

void setup() {
 Serial.begin(9600);    //Se inicializa la comunciación al monitor serie
 SPI.begin();   //Se inicializa la comunicación ISP
 mfrc522.PCD_Init();    //Se inciailiza el lector de tarjetas
 Serial.println("Listo");   //Se incializa el monitor serie
 pinMode(LED1, OUTPUT);   //Se inicializan los LEDS
 pinMode(LED2, OUTPUT);
}

void loop() {
  
  if(! mfrc522.PICC_IsNewCardPresent())   //Si el lector reconoce una tarjeta
  return;   //Se regresa

  if(!mfrc522.PICC_ReadCardSerial())    //Si la tarjeta reconoce la lectura
  return;   //Regresa

  Serial.print("UID:");   //Se escribe en el monitor serie "UID:"
  for(byte i = 0; i<mfrc522.uid.size; i++){   //Se crea un bucle for con una iteración del tipo "byte" y que dicha tendrá que ser menor el mfrc522
    if(mfrc522.uid.uidByte[i] < 0x10){    //Si el mfrc.uid.uidByte es menor que diez
      Serial.print(" 0");   //Se crean espacios
    }
    else{ //Si no
      Serial.print(" ");    //Secrea un espacio
    }
    Serial.print(mfrc522.uid.uidByte[i],HEX);   //Los codigos serán leídos en hexadecimal
    LecturaUID[i]=mfrc522.uid.uidByte[i];   //Almacenará el byte del UID y mostrará los codigos
  }
Serial.print("\t"); //Deja un espacio de tabulación entre el UID y el texto que seguirá

if(comparaUID(LecturaUID, Usuario1))    //Si la función "comparaUID" se ejecuta con los parámetros de "Lectura UID" usuario1
Led1();   //Se ejecuta la función "led1"
else if (comparaUID(LecturaUID, Usuario2))    //Si no y si se compara la lecturaUID, con el Usuario2
Serial.println("Bienvenido Usuario 2"); //Si es extiosa se escribe en el monitor serie "Bienvenido Usuario2"
  else  //Si no
Led2();   //Se ejecuta la función de "Led2"
    mfrc522.PICC_HaltA();     //Solo permite el paso individual y unico de la tarjeta o llavero

}
boolean comparaUID(byte lectura[], byte usuario[])    //Se crea una función booleana que pose dos parametros de variables locales que tomaran los valores del loop
{
  for(byte i=0; i< mfrc522.uid.size; i++){    //Se lee un codigo por vez,por eso la existencia del bucle for que su estatuto será ser menor al mfrc522.uid.size o al tamaño
    if(lectura[i] != usuario[i])    //Si la lectura es diferente a usuario
    return(false);    //Será falso
  }
  return(true);  //Si es igual entonces torna a verdadero
}
void Led1(){    //Función Led1
digitalWrite(LED1,HIGH);    //Se escribe como valor alto el led
delay(1000);    //Una demora de 1 segundo
digitalWrite(LED1,LOW);   //Se apaga el led
Serial.println("Bienvenido Usuario 1");   //Se escribe en el monitor serie "Bienvendio Usuario1"
}
void Led2(){
digitalWrite(LED2,HIGH);    //Se enciende el led
delay(1000);    //Demora 1 segundo
digitalWrite(LED2,LOW);   //Se apaga el led
Serial.println("No te conozco");    //Se escribe en el monitor serie "No te conozco"
}

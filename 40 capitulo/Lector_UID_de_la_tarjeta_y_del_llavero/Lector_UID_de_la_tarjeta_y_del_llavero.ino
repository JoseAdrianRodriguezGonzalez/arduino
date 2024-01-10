#include <SPI.h>    //Se incluye la librería de la comunicación SPI
#include <MFRC522.h>  //Se incluye la librería del MFRC522

#define RST_PIN 9   //Se define el pin del reset
#define SS_PIN 10   //Se define el selector de esclavo en el pin 10
MFRC522 mfrc522 (SS_PIN,RST_PIN);   //Se crea un objeto del tipo "MFRC522" llamado mfrc522 con los siguientes parametros ""SS_PIN" y "RST_PIN"

void setup() {
 Serial.begin(9600);    //Se inicializa la comunicación del monitor serie
SPI.begin();    //Se inicializa la comunciación SPI
mfrc522.PCD_Init();   //Se inicialia el modulo lector
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent())    //Condicional en el que reconoce si hay una tarjeta 
  return;
  if(!mfrc522.PICC_ReadCardSerial())    //Condicional en el que lee la tarjeta o si puede leer la tarjeta
  return;

  Serial.print("UID:");   //Se escribe en el monitor serie "UID"
  for(byte i=0; i<mfrc522.uid.size;i++){    //Se obtiene el indentificador único. Será una iteración del tipo "byte" que será menor al mdfrc522.uid.size, que este parametro determina el espacio que hay en la tarjeta
  //Conersión de a 2 unidades por byte
    if(mfrc522.uid.uidByte[i] < 0x10){  //Consulta que si el mfrc522 es menor que 10
      Serial.print(" 0");   //Agrega un cero del valor leído y un espacio
    }
    else{//Si es mayor de 10
    Serial.print(" ");    //Separa los bytes de otro
    }
    Serial.print(mfrc522.uid.uidByte[i], HEX);    //Mostrará byte por byte del Uid en hexadecimal
  }
  Serial.println();   //Prepara un salto de línea
  mfrc522.PICC_HaltA();     //Con este comando, le dice al llavero que ya no es necesario que esté y que corte la comunicación
}

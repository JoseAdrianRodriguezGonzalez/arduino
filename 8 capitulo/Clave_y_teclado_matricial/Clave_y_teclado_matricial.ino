#include <Keypad.h>   // Se incluye la librería keypad
const byte FILAS = 4;   //Se delcaran la cantidad de filas
const byte COLUMNAS = 4;    //Se delcaran la cantidad de columnas
char keys [FILAS][COLUMNAS] ={      //Define un mapa de caracteres
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte pinesFilas[FILAS] = {9,8,7,6};   //Define los pines en las filas
byte pinesColumnas[COLUMNAS] = {5,4,3,2,};    //Define los pines de las columnas

Keypad teclado = Keypad(makeKeymap(keys),pinesFilas,pinesColumnas,FILAS,COLUMNAS);    //define un objeto del tipo keypa llamado teclado con algunos parametros
char TECLA;   //Se declara la variable tecla en char
char CLAVE [7];   //Se delcara un array de 7 
char CLAVE_MAESTRA [7] = "123456";    //Se declara los digitos y el array de 7 para contemplar el string
byte INDICE = 0;    // Se inicializa el indice 0
int LED = 10;
int LED_1 = 11;

void setup(){
  Serial.begin(9600);   //Se incializa el monitor serie
  pinMode(LED, OUTPUT);   
   pinMode(LED_1, OUTPUT);
}
void loop(){
  TECLA = teclado.getKey();   //Se obtiene la tecla
  if(TECLA){    //Compara la función tecla si dicha recibe o no algún dato
    CLAVE [INDICE] = TECLA;   //colocará el caracter de la tecla en el indice 0 del array
    INDICE++;   //incrementa el valor del indice
    Serial.print(TECLA);    //Se imprime las teclas
  }
  if ( INDICE == 6){      //Se evalúa si se llego a un indice 6
    if(!strcmp(CLAVE, CLAVE_MAESTRA)){    //Este fi evalua y compara con la función strcmp la clave maestra con la clave presionada
    Serial.println(" Correcta");    //Se escribe si es correcta
     digitalWrite(LED,HIGH);
    delay(1000);
      digitalWrite(LED,LOW);
    }  else
    Serial.println(" Incorrecta");    //Si la comparación es falsa, entonces se escribe si es incorrecta
      digitalWrite(LED,LOW);
     digitalWrite(LED_1,HIGH);
     delay (1000);
     digitalWrite(LED_1,LOW);
    INDICE = 0;   //Vuelve al inicio
  
  }
}

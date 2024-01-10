int LED = 3;   //Se declara el pin entero del led
int BRILLO;   //Se crea una vaariable entera llamada "BRILLO"

void setup() {
 pinMode(LED,OUTPUT);   //Se declara el led como salida

}

void loop() {
  for(BRILLO = 0;BRILLO < 255; BRILLO++){       //Crea un bucle for que repetira una condición determinada hasta un limite que aumenta el brillo
    analogWrite(LED,BRILLO);      //Se lo escribirá en el analogWrite porque lo haría en un numero cercando de 255
    delay(15);      //Retraso de 15 milisegundos
  }
   for(BRILLO = 255;BRILLO < 0; BRILLO--){      //Disminuye el brillo
    analogWrite(LED,BRILLO);    //Se escribe en el led y en el brillo
    delay(15);    //Retraso de 15 milisegundos
   }
}

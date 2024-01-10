int SENSOR =0;    //Se crea la variable sensor en una entrada analogica
int LED = 3;      //Se crea la variable LED
int VALOR;    //Se crea una variable llamada "VALOR"


void setup() {
 pinMode(LED, OUTPUT);  //Se declara el LD como una salida

}

void loop() {
 VALOR = analogRead(SENSOR);    //El valor es igual a la lectura del sensor
 if(VALOR <200){      //Si el valor es menor que 200
 digitalWrite(LED, HIGH);     //Se enciende el led
 delay(1000); //durante 1 segundo
 }
 digitalWrite(LED, LOW);      //Se apaga
}

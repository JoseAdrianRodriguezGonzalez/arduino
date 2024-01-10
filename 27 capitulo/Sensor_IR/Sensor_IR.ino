int SENSOR =2;    //Se crea una variable llamada sensor en la que estará en el pin digital 2
int VALOR;    //Se crea una variable entera llamada "valor"
int ANTERIOR =1;  //Se crea una variable llamada "anterior" que empieza en un valor de 1


void setup() {
 Serial.begin(9600);    //Se inicializa el monitor serie
 pinMode(SENSOR, INPUT);    //Se declara que es una salida

}

void loop() {
 VALOR = digitalRead(SENSOR);   //El valor es igual a la lectura del sensor
 if(VALOR !=ANTERIOR){    //Si valor es diferente de anterior, entonces...
if(VALOR ==HIGH)//Si valor es igual a un valor alto
  Serial.println("Linea ");   //Se imprime en el monitor serie "linea"
  else  //Si no
  Serial.println("Fuera");    //Se imprime que está afuera
  ANTERIOR= VALOR;    //Se actualiza anterior a que sea igual a valor
 }
 delay(500);  //Demora de medio segundo
}

    //Se definen 2 constantes
#define STEP 4    // Se define STEP en su respectiva entrada digital
#define DIR 5//Se define DIR en su respectivo entrada digital
//No se crea una variable "int" porque solamente vamos a utilizar un valor
void setup() {
  pinMode(STEP,OUTPUT);   //Se declara STEP como salida
  pinMode(DIR, OUTPUT);   //Se declara a DIR como salida

}

void loop() {
 digitalWrite( DIR, HIGH);  //Establece el giro del motor
 for(int i=0; i <200;i++){  //Estable los pasos para hacher un giro de 180°
  digitalWrite(STEP,HIGH);    //Se enciende el step
  delay(10);    //Se demora 10 milisegundos
  digitalWrite(STEP,LOW);   //Se apaga el step
  delay(10);    //Demora de 10 milisegundos
 }
 delay(2000);   //Demora de 2 segundos
  digitalWrite( DIR, HIGH);  //Establece el giro del motor en sentido contrario
 for(int i=0; i <200;i++){  //Estable los pasos para hacher un giro de 180°
  digitalWrite(STEP,HIGH);    //Se enciende el step
  delay(10);    //Se demora 10 milisegundos
  digitalWrite(STEP,LOW);   //Se apaga el step
  delay(10);    //Demora de 10 milisegundos
 }
 delay (2000);    //Demora de 2 segundos
}

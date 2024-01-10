int SENSOR =0;    //Se establece el sensor en una entrada aalogica
int LED = 3;    //Se establece el LED
int VALOR;    //Se declara la vairable de valor
int PWM;    //Se declara la variable PWM

void setup() {
 pinMode(LED, OUTPUT);  //Se declara el led como salida

}

void loop() {
 VALOR = analogRead(SENSOR);    //Valor es igal a la lectura analogica del sensor
 PWM = map(VALOR, 0, 1023, 255, 0); //PWM es igual y crea una conversion de valores de 0 a 1023 a los valores PWM 255
 analogWrite(LED, PWM);   //Se escribe analogicamente al led lo de PWM
}

int MIC = 2;    //Se declara el microfono en el pin 2
int LED = 3;    //Se declara el LED
int VALOR;    //Se declara una variable llamda "VALOR"
int ESTADO;     //Se declara una variable llamda "ESTADO"
void setup(){
  pinMode(MIC, INPUT);    //Se declara el microfono como entrada
  pinMode(LED, OUTPUT);     //Se declara el LED como "salida"
}
void loop (){
  VALOR = digitalRead(MIC);   //Valor es igual a la lectura del microfono
    if (VALOR == HIGH){     //Si el valor es alto
    ESTADO = digitalRead(LED);    //Estado es igual a la lectura del estado del led
    digitalWrite(LED, !ESTADO);     //Se escribe el led con el valor opuesto del LED
    delay(500);  //Se crea una demora de medio segundo
    }
}

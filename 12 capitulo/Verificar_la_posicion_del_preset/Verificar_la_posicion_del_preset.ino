int MIC =0;//Se conectal el punto analogico del microfono
int valor;    //Se crea una variable llamada valor

void setup() {
  Serial.begin(9600);   //Se inicializa el monitor serie

}

void loop() {
  valor = analogRead(MIC);    //Valor es igual a la lectura del microfono
  Serial.println(valor);        //Se imprime el valor en el monitor serie
  delay(500);   //Se crea cada medio segundo

}

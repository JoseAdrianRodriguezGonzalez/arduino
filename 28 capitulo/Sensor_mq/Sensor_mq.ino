
int VALOR;  //Se crea una variable llamado "valor"

void setup() {
  Serial.begin(9600);   //Se inicializa el monitor serie
}

void loop() {
  VALOR = analogRead(A0);   //Valor es igual a la lectura de la slaida digital
  Serial.println(VALOR);    //En el monitor serie se imprime el valor
  delay(500);   //Se imprime cada medio segundo   
}

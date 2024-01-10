int POT= A0;  //Potenciometro
int  valor; //Valor
void setup() {
  Serial.begin(9600); //Monitor serie

}

void loop() {
  valor=analogRead(POT);    //Valor lee lo que hay en el POT
  Serial.println("potenciometro:"); //Se imprime "potenciometro"
  Serial.println(valor);    //Y el valor del potenciometro  
  delay(1000);  //Demora 1 segundo

}

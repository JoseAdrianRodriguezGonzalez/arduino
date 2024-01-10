#define PINLED1 D0  //Se declara el led
#define PINLED2 D1
int POT=A0;
int valor;
int valorpot;
int estado=0;
void setup() {
  Serial.begin(9600);
  pinMode(PINLED1, OUTPUT); //Se declara como salida
  pinMode(PINLED2, OUTPUT);
  valorpot=0;
}

void loop() {
  //Se busca tener una comunicación serie
  if(Serial.available()>0){ //Si hay datos disponibles
    String cad= Serial.readString();  //La cadena cad leera el string en el monitor serie
    estado=cad.toInt(); //Estado será igual cad
    Serial.println("camibo a estado:  "+String(estado));  //Se imprime "cambio a estado:" más lo que viene del estado
  }
  if(estado==0) //Si estado es igual a cero
  ledDigital(PINLED1, 1000);  //Se activa la función "ledDigital"
  else if (estado==1) //Si estado es igual a 1
 ReadPoten(POT, PINLED2); //Se activa la función "ReadPoten"
  else if( estado==2) //Si estado es igual a 2
  ledanalogico(PINLED1, 30, 10);  //Se activa la función "ledanalogico"
  }
void ReadPoten(int pot, int led){
valor=analogRead(pot);  //El valor es igual al resultado leido en pot
if(valor<valorpot-10 ||valor>valorpot+10){    //Si el valor es menor que el valorpot de -10 o valor es mayor que valor pot +10
valorpot=valor;   //Valor pot será igual a valor
analogWrite(led, valor);  //Analogicamente se escribirá el valor a led
Serial.println("Valor pot:  " + String(valor));   //Se imprime en el monitor serie
  }  
}
void ledanalogico(int led, int pausa, int incre){
  
for(int i=0;i <=PWMRANGE;i+=incre){    //Se crea un bucle for para aumentar el brillo
analogWrite(led, i);  //Se escribe la cantidad de brillo
delay(pausa);  //Se da una peuqeña pausa
}
for(int i=PWMRANGE;i >=0;i-=incre){  //Se crea un bucle for para disminuir el brillos
analogWrite(led, i);    //Se escrbie la cantidad de brillo
delay(pausa);  //Se da una pequeña pausa
}
}
void ledDigital(int led, int pausa){
  digitalWrite(led,HIGH);
  delay(pausa);
    digitalWrite(led,LOW);
  delay(pausa);
}

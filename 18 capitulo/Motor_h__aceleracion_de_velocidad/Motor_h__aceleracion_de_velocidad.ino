int IN1 = 4;    //Se declaran la variable in1
int IN2 = 6;    //Se declara la variable in2 
int ENA = 3;      //Se declara la variable ENA
int VELOCIDAD;    //Se declara la variable velocidad
void setup() {      //Se declaran todas como salidas
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(ENA,OUTPUT);

}

void loop() {
  for( VELOCIDAD = 0; VELOCIDAD < 256; VELOCIDAD ++){   //Aumento gradual de la velocidad
   analogWrite(ENA, VELOCIDAD);     //Sentido del giro horario
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

delay(50);
  }
  
digitalWrite(ENA, LOW);   //Se apaga
delay(2000);
 for( VELOCIDAD = 0; VELOCIDAD < 256; VELOCIDAD ++){      //Aumento gradual del giro del motor   
   analogWrite(ENA, VELOCIDAD);     //Giro en el sentido contrario
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

delay(50);
 }
 digitalWrite(ENA, LOW);
delay(2000);
}

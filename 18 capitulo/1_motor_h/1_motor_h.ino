int IN1 = 2;    //Se declaran los ina y el ena y enb con las salidas digitales
int IN2 = 3;
int IN3=4;
int IN4=7;
 int ENB=6;
int ENA = 5;
int VELOCIDAD;
void setup() {      //Todas se declaran como salidas 
pinMode(IN1, OUTPUT); 
pinMode(IN2, OUTPUT);
pinMode(ENA,OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
pinMode(ENB,OUTPUT);

}

void loop() {   //Giran en sentido horario
   digitalWrite(ENA, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
 
   digitalWrite(ENB, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

delay(3000);
  
  //Se apagan
  
digitalWrite(ENA, LOW);
digitalWrite(ENB,LOW);
delay(2000);

 //Giran en sentido contrario
   digitalWrite(ENA, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
   digitalWrite(ENB, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(3000);
  //Se apagan
  digitalWrite(ENA, LOW);
digitalWrite(ENB,LOW);
delay(2000);

 
  }

  

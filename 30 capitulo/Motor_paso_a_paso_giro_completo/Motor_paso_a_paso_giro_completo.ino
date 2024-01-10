int IN1 = 8;    //Se declaran las bobinas en sus pines digitales
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;
int motor = 6;    //Se crea una variable llamada motor con un valor 6
int demora = 20;    //Se crea una demora de 20 milisegundos
int paso [4][4] =   //Se crea la matriz
{
  {1, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 1},
  {1, 0, 0, 1}
};
void setup() {
 pinMode(IN1, OUTPUT);    //Se declaran las bobinas como salidas
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
  pinMode(motor, OUTPUT);   //Se declara el motor como salida

}

void loop() {
  digitalWrite(motor, HIGH);    //El motor se escribe en un estado alto
for(int i=0; i<512; i++){   //La cantidad de pasos 512*4 =2048
}
for (int i = 0; i< 4 ; i++){    //Se contabiliza la fila de la matriz cada vez que se acompleta un ciclo 
  digitalWrite(IN1, paso [i][0]);
  digitalWrite(IN2, paso [i][1]);
  digitalWrite(IN3, paso [i][2]);
  digitalWrite(IN4, paso [i][3]);
   delay(demora);
}

}

int IN1 = 8;    //Se declaran las bobinas con su respectivo pin digital
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;
int demora = 20;    //Se declara la demora de 20 milisegundos
int paso [8][4] =   //Se crea la matriz
{
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};
void setup() {
  //Se declaran las bobinas como salidas
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);

}

void loop() {
for(int i=0; i<512; i++){   //521*8=4096 Se cargan los pasos
}
for (int i = 0; i< 8 ; i++){    //Se caragará la poición en la matirz de cada bobina, es decir, en la primera, todos van a estar localizado en la fila 1
  digitalWrite(IN1, paso [i][0]);
  digitalWrite(IN2, paso [i][1]);
  digitalWrite(IN3, paso [i][2]);
  digitalWrite(IN4, paso [i][3]);   
   delay(demora);   //Con una demora de 20 milisegundos
}

}

int IN1 = 8;    //Se declaran las bobinas en sus respectivos pines
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;
int demora = 20;    //Demora de 20 milisegundos
int paso [4][4] =   //Se declara un indice de 4x4
{
  {1, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 1}
};    //Se forma la matriz con la tabla del paso completo simple del motor
void setup() {
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);

}

void loop() {
for(int i=0; i<512; i++){   //Se crea un bucle for para repetir todo los pasos del motor
}
for (int i = 0; i< 4 ; i++){    //Se repite el bucle for de las 4 filas
  digitalWrite(IN1, paso [i][0]);   //En el i, se coloca el numero de fila 0
  digitalWrite(IN2, paso [i][1]);   //En el i se coloca el numero de fila 1
  digitalWrite(IN3, paso [i][2]); //En el i se coloca el numero de fila 3
  digitalWrite(IN4, paso [i][3]); //En el i se coloca el numero de fila 4
   delay(demora);
}

}

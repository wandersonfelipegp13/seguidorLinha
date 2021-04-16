//Lembrando que os pinos e as variaveis dependem de sua montagem , portanto os valor
const int motor1 = 3; // Pino_Velocidade 1º Motor ( 0 a 255)_ Porta ATV_A ponte H;
const int motor2 = 10; //Pino_Velocidade 2º Motor ( 0 a 255) _ Porta ATV_B ponte H;
const int dir1 = 2; //Pino_Direção do 1º Motor: Para frente / Para trás (HIGH ou LOW)
const int dir2 = 9; //Pino_Direção do 2º Motor: Para frente / Para trás (HIGH ou LOW)

//Agora definiremos os pinos responsáveis pelos sensores:
#define Sensor1 5
#define Sensor2 6
bool Valor_Sensor1 = 0;
bool Valor_Sensor2 = 0;

void setup(){
  // Definimos os motores e as direções como saídas.
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  // Agora definimos a direção inicial dos motores.
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, HIGH);
  // Por ultimo colocaremos os pinos digitais dos sensores como entradas
  pinMode(Sensor1, INPUT);
  pinMode(Sensor2, INPUT);
  Serial.begin(9600);
}

void loop(){
  
  //Neste processo armazenamos o valor lido pelo sensor na variável que controla
  // a velocidade dos motores.
  Valor_Sensor1 = digitalRead(Sensor1);
  Valor_Sensor2 = digitalRead(Sensor2);

  // Aqui criamos nossa condicional que define como o motor se comporta
  //LEMBRANDO QUE CONVECIONALMENTE ASSUMIMOS O VALOR 0 PARA PRETO E O VALOR 1 PARA BRANCO

  if((Valor_Sensor1 == 0) && (Valor_Sensor2 == 0)){
    analogWrite(motor1, 150);
    analogWrite(motor2, 150);
  }

  if((Valor_Sensor1 == 1) && (Valor_Sensor2 == 0)){
    analogWrite(motor1, 0);
    analogWrite(motor2, 150);
  }

  // adicionei essa condicao para o robo virar para o outro lado tambem
  if((Valor_Sensor1 == 0) && (Valor_Sensor2 == 1)){
    analogWrite(motor1, 150);
    analogWrite(motor2, 0);
  }
  
}

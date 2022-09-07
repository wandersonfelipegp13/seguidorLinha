// Pino de velocidade do 1º motor (0 a 255). Porta ATV_A da ponte H.
const int MOTOR1 = 3;

// Pino de velocidade do 2º motor (0 a 255). Porta ATV_B ponte H.
const int MOTOR2 = 10;

// Pino de direção do 1º motor. HIGH para frente e LOW para trás.
const int DIR1 = 2; 

// Pino de direção do 2º motor. HIGH para frente e LOW para trás.
const int DIR2 = 9; 

// Pinos responsáveis pelos sensores
#define SENSOR1 5
#define SENSOR2 6
bool valorSensor1 = 0;
bool valorSensor2 = 0;

void setup() {

    // Motores e direções como saídas.
    pinMode(MOTOR1, OUTPUT);
    pinMode(MOTOR2, OUTPUT);
    pinMode(DIR1, OUTPUT);
    pinMode(DIR2, OUTPUT);
    
    // Direção inicial dos motores.
    digitalWrite(DIR1, HIGH);
    digitalWrite(DIR2, HIGH);
  
    // Pinos digitais dos sensores como entradas.
    pinMode(SENSOR1, INPUT);
    pinMode(SENSOR2, INPUT);

}

void loop() {
  
    valorSensor1 = digitalRead(SENSOR1);
    valorSensor2 = digitalRead(SENSOR2);

    if ((valorSensor1 == 0) && (valorSensor2 == 0)){
        analogWrite(MOTOR1, 150);
        analogWrite(MOTOR2, 150);
    }

    if ((valorSensor1 == 1) && (valorSensor2 == 0)){
        analogWrite(MOTOR, 0);
        analogWrite(MOTOR, 150);
    }

    if ((valorSensor1 == 0) && (valorSensor2 == 1)){
        analogWrite(MOTOR1, 150); 
        analogWrite(MOTOR2, 0);
    }
  
}

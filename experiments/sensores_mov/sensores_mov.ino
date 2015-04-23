const int sensor0 = 2; 
const int sensor1 = 4;
int sensor0State = 0; 
int sensor1State = 0;

const int rojo = 8;
const int verde = 12;
const int azul = 7;

void setup() {
pinMode(sensor0,INPUT);
pinMode(sensor1,INPUT);
pinMode (rojo, OUTPUT);
pinMode (verde, OUTPUT);
pinMode (azul, OUTPUT);

Serial.begin(9600);
}
void loop(){

 // leer sensor
 sensor0State = digitalRead(sensor0); 
 sensor1State = digitalRead(sensor1);

 // Impresión de los valores leídos por el sensor

 Serial.print("sensor0 = ");
 Serial.println(sensor0State);
 
 if (sensor0State == HIGH) {
    digitalWrite(rojo, 255);
    digitalWrite(verde, 0);
    digitalWrite(azul, 0);
    
 if (sensor0State == LOW) {
    digitalWrite(rojo, 0);
    digitalWrite(verde, 0);
    digitalWrite(azul, 0);
    } 
 }
Serial.print("sensor1 = ");
 Serial.println(sensor1State);
 
  if (sensor1State == HIGH) {
    digitalWrite(rojo, 0);
    digitalWrite(verde, 0);
    digitalWrite(azul, 255);
    
  if (sensor1State == LOW) {
    digitalWrite(rojo, 0);
    digitalWrite(verde, 0);
    digitalWrite(azul, 0);
  } 
  }
} 


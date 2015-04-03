int sensor0 = A0; // Leeremos del pin A0
int sensor1 = A1;
int sensorState = 0; // Variable para leer los datos del sensor
const int rojo = 9;
const int verde = 11;
const int azul = 10;

void setup() {
pinMode(sensor0,INPUT);
pinMode (rojo, OUTPUT);
pinMode (verde, OUTPUT);
pinMode (azul, OUTPUT);

Serial.begin(9600);
}
void loop(){

 // leer sensor
sensorState1 = analogRead(sensor0); 
sensorState2 = analogRead(sensor1);

 // Impresión de los valores leídos por el sensor

 Serial.print("sensor0 = ");
 Serial.println(sensorState);
 
 if (sensorState == HIGH) {
    digitalWrite(rojo, 255);
    digitalWrite(verde, 0);
    digitalWrite(azul, 0);
    delay(1000);
    } 

  if (sensorState2 == HIGH) {
    digitalWrite(rojo, 0);
    digitalWrite(verde, 0);
    digitalWrite(azul, 255);
  } 

} 


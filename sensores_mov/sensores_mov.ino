int sensor0 = A0; // Leeremos del pin A0
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
sensorState = analogRead(sensor0); 

 // Impresión de los valores leídos por el sensor

 Serial.print("sensor0 = ");
 Serial.println(sensorState);
 
 if (sensorState == HIGH) {
    digitalWrite(rojo, HIGH);
    digitalWrite(verde, LOW);
    digitalWrite(azul, HIGH);
    delay(1000);
    
    digitalWrite(rojo, LOW);
    digitalWrite(verde, HIGH);
    digitalWrite(azul, LOW);
  } 
 // Paro 1 segundo
delay(1000);
} 


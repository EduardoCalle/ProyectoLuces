#include <Adafruit_DotStar.h>
#include <SPI.h>  

#define NUMPIXELS 145 
#define PISO1 A0
#define DATAPIN    4
#define CLOCKPIN   6

Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN);

// Este es un experimento
void setup() {

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1); 
#endif

  strip.begin(); 
  strip.show();  
  Serial.begin(9600);
}

uint32_t color = 0xFF0000;      
int segundo = 500;
int cont = 1;

void loop() {
  int valorSensor = analogRead(PISO1);
  Serial.println(valorSensor);
  delay(1*segundo);
  cont+=1;
  if (cont>40) {
    Serial.println("The End!");
    exit(0);
  }
}
 

#include "light.h"
#include "sensor.h"


light luz1(11,10,9);
light luz2(3,5,6);
sensor dSensor1(13, DIGITAL);
sensor dSensor2(12, DIGITAL);
sensor dSensor3(8, DIGITAL);
sensor dSensor4(7, DIGITAL);


int sSensor1=0;
int sSensor2=0;
int sSensor3=0;
int sSensor4=0;
unsigned long timer1=0;
unsigned long timer2=0;
unsigned long timer3=0;
unsigned long timer4=0;
float velocidad=0;
long tiempo=0;
float distanciaSensorLuz = 2;
float distanciaEntreLuces = 0.5;
// tiempo de apagado de luz 1
long tiempoApagado = 1500;
    
int flag1=0;
int flag2=0;
int flag3=0;
int flag4=0;


void setup() {
  // put your setup code here, to run once:
  luz1.setRGB(0,0,0);
  luz2.setRGB(0,0,0);
  luz1.show();
  luz2.show();
  Serial.begin(9600);
  
}

//Returns time after which to switch first lamp off
//and second lamp on, as someone walks through.
double switchdelay(double velocidad) {
  double distance_bw_lights=2;
//  double distance_from_last_sensor=0.82;
  double switchdelay =  (distance_bw_lights-.5) / velocidad;  //distance between lights minus the radius of the light
  return switchdelay*1000;

}
void loop() {
  // put your main code here, to run repeatedly:
  sSensor1=dSensor1.readSensor();
  sSensor2=dSensor2.readSensor();
  sSensor3=dSensor3.readSensor();
  sSensor4=dSensor4.readSensor();



//Left to Right
  if(sSensor3==HIGH){
     if(flag3==0){
       timer3=millis();
       flag3=1;
       Serial.print("RIGHT OUT time = ");
       Serial.println(timer3);
     }
  }
  if(sSensor4==HIGH){
     if(flag4==0){
       timer4=millis();
       Serial.print("RIGHT IN time = ");
       Serial.println(timer4);
       flag4=1;
     }
  }
  if(flag3>0 & millis()-timer3>4000){
    flag3=0;
          Serial.println("Ready for next experiment!");
  }
  if(flag4>0 & millis()-timer4>4000){
    flag4=0;
          Serial.println("Ready for next experiment!");
  }
  

  if((flag3==1)&(flag4==1))
  {
    tiempo=(timer4-timer3); 
//    Serial.println(tiempo,DEC);
    velocidad=0.61/((float)tiempo/1000); 
    
    distanciaSensorLuz = 2.5;
    
    // tiempo de apagado de luz 1
    tiempoApagado = round(velocidad*distanciaSensorLuz*1000/100); 
        
    if(velocidad>0 & velocidad<4) {
     luz1.setRGB(0,255,0);
     luz1.show();
     // delay(switchdelay(velocidad));
     // Serial.println(switchdelay(velocidad));
     
     // Trying fade lights 
     luz2.setRGB(0,0,255);
     luz2.show();       
     
     Serial.print("Inicio de apagado de Luz 1 en 50 pasos de ");
     Serial.print(tiempoApagado/2);
     Serial.println(" milisegundos ");     
     luz1.fadeInTime(50, tiempoApagado/2);
     Serial.println("Luz 1 off");
          
     Serial.print("Inicio de apagado de Luz 2 en en 50 pasos de ");
     Serial.print(tiempoApagado/2);
     Serial.println(" milisegundos");
     luz2.fadeInTime(50, tiempoApagado/2);
     Serial.println("Luz 2 off");

    } else {
     flag3=0;
     flag4=0;
   }
   
   Serial.print("velocidad RL: ");
   Serial.println(velocidad,2);
   Serial.println("--------------");
   delay(2000);
     
   luz2.setRGB(0,0,0);
   luz2.show(); 
   luz1.setRGB(0,0,0);
   luz1.show();
   flag3=0;
   flag4=0;
   Serial.println("Ready for next experiment!");
  }










   
  //Right to Left
  if(sSensor1==HIGH){
     if(flag1==0){
       timer1=millis();
       flag1=1;
       Serial.print("LEFT OUT time = ");
       Serial.println(timer1);
     }
  }
  if(sSensor2==HIGH){
     if(flag2==0){
       timer2=millis();
       Serial.print("LEFT IN time = ");
       Serial.println(timer2);
       flag2=1;
     }
  }
  if(flag1>0 & millis()-timer1>4000){
    flag1=0;
          Serial.println("Ready for next experiment!");
  }
  if(flag2>0 & millis()-timer2>4000){
    flag2=0;
          Serial.println("Ready for next experiment!");
  }
  

  if((flag1==1)&(flag2==1))
  {
    tiempo=(timer2-timer1); 
//    Serial.println(tiempo,DEC);
    velocidad=0.6/((float)tiempo/1000); 
    
    distanciaSensorLuz = 2.1;
    
    // tiempo de apagado de luz 1
    tiempoApagado = round(velocidad*distanciaSensorLuz*1000/100); 
    
    if(velocidad>0 & velocidad<4) {
     luz2.setRGB(0,0,255);
     luz2.show();
     luz1.setRGB(0,255,0);
     luz1.show();            
     Serial.print("Inicio de apagado de Luz 1 en 50 pasos de ");
     Serial.print(tiempoApagado/2);
     Serial.println(" milisegundos ");

     luz2.fadeInTime(50, tiempoApagado/2);
     Serial.println("Luz1 off");
     Serial.print("Inicio de apagado de Luz 2 en en 50 pasos de ");
     Serial.print(tiempoApagado);
     Serial.println(" milisegundos");
     
     luz1.fadeInTime(50,tiempoApagado/2);
     Serial.println("Luz2 off");

    } else {
      flag1=0; // flag
      flag2=0;
    }
    
    Serial.println("Velocidad LR: ");
    Serial.println(velocidad,2);
    Serial.println("--------------");
    delay(2000);
     luz1.setRGB(0,0,0);
     luz1.show(); 
     luz2.setRGB(0,0,0);
     luz2.show();
    flag1=0;
    flag2=0;
    Serial.println("Ready for next experiment!");
//    delay(3000);
  }
 
 // Serial.println(velocidad);
 }


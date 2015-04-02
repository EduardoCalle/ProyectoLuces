#include "sensor.h"

sensor::sensor(int sensorPin)
{
  _sensorPin=sensorPin; 
  pinMode(sensorPin,INPUT); 
}

byte sensor::readSensor(void)
{
   state=digitalRead(_sensorPin);
   if (state==1)
     flagState=1;
   return state;
}

byte sensor::active(void)
{
  state=digitalRead(_sensorPin);
   if (state==1)
     flagState=1;
  return flagState; 
}

void sensor::deactive(void)
{
  flagState=0; 
}



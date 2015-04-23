#include "sensor.h"

sensor::sensor(int sensorPin, byte type)
{
  _sensorPin=sensorPin; 
  pinMode(sensorPin,INPUT); 
  _sensorType=type;
}

int sensor::readSensor(void)
{
  if(_sensorType==DIGITAL)
  { 
    state=digitalRead(_sensorPin);
     if (state==1)
       flagState=1;
     return state;
  }
}

int sensor::active(void)
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



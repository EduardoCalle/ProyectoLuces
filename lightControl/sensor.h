// Class for control lights.
// Version 1.0
// E. Calle

#ifndef sensor_h
#define sensor_h

#include "arduino.h"

class sensor
{
  private:
  byte _sensorPin=0;
  byte state=0;
  byte flagState;
  
  public:
  sensor(int sensorPin);
  byte readSensor(void);
  byte active(void);
  void deactive(void);
      
};

#endif

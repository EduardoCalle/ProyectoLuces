// Class for control lights.
// Version 1.0
// E. Calle

#ifndef sensor_h
#define sensor_h

#include "arduino.h"

#define DIGITAL 1
#define ANALOG  0

class sensor
{
  private:
    byte _sensorPin=0;
    byte _sensorType=1;
    byte state=0;
    byte flagState=0;
 
  public:
    sensor(int sensorPin, byte type);
    int readSensor(void);
    int active(void);
    void deactive(void);
      
};

#endif

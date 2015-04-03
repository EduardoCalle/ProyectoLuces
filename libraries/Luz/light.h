// Class for control lights.
// Version 1.0
// E. Calle

#ifndef light_h
#define light_h

#include "arduino.h"

class light
{
  private:
    int _rPin=0;
    int _gPin=0;
    int _bPin=0;
    int rValue=0;  //This variable define the quantity of color RED in the light
    int gValue=0;  //This variable define the quantity of color GREEN in the light
    int bValue=0;  //This variable define the quantity of color BLUE in the light

  public:
    light(void);
    light(int rPin,int gPin, int bPin);
    void setRed(int value);
    void setGreen(int value);
    void setBlue(int value);
    int  getRed(void);
    int  getGreen(void);
    int  getBlue(void);
    void setRGB(int R, int G, int B);
    void setYUV(float Y, float U, float V);
    void fadeIn(void);
    void linealTo(int R,int G,int B,int nroPasos, int tiempo);
    void cubicTo(int R, int G, int B, int nroPasos, int tPausa);
    
    // void fadeOut(void);
    void show(void);
    
    void respira(float value,float tiempo);
    
    
};

#endif

#include "light.h"

// This is the constructor without hardware pins
light::light(void)
{
  _rPin=0;
  _gPin=0;
  _bPin=0;
}

// This is the constructor for setting the hardware pins
light::light(int rPin, int gPin, int bPin)
{
  _rPin=rPin;
  _gPin=gPin;
  _bPin=bPin;   
  pinMode(_rPin,OUTPUT);
  pinMode(_gPin,OUTPUT);
  pinMode(_bPin,OUTPUT); 
}

// Set the red color in the color variables
void light::setRed(int value)
{
  rValue=value;
}

// Set the green color in the color variables
void light::setGreen(int value)
{
  gValue=value;
}

// Set the blue color in the color variables
void light::setBlue(int value)
{
  bValue=value;
}

// Return the value of red color in the color variables
int light::getRed(void)
{
  return rValue;
}

// Return the value of green color in the color variables
int light::getGreen(void)
{
  return gValue;
}

// Return the value of blue color in the color variables
int light::getBlue(void)
{
  return bValue;
}

//Set RGB color in color variables
void light::setRGB(int R,int G, int B)
{
  rValue=R;
  gValue=G;
  bValue=B;
  
}

 /* setYUV allow to set the color variables in a YUV space 
    Y change between 0 and 1. 0 is the minimal intensity.
    U change between -0.436 to 0.436
    V change between -0.615 to 0.615
   ------------------------------------------------------ */
 void light::setYUV(float Y, float U, float V)
 {
    rValue= (int) 255*(Y+0*U+1.14*V);
    gValue=(int) 255*(Y-0.396*U-0.581*V);
    bValue=(int) 255*(Y+2.029*U+0*V);
    Serial.println(rValue);
 }

// Turn on the light with the colors set in the color variables
void light::show()
{
  analogWrite(_rPin,rValue);
  analogWrite(_gPin,gValue);
  analogWrite(_bPin,bValue);
}

//Fade In between 0 and the color set in the color variables
void light::fadeIn(void)
{
  int nroPasos=200;
  int tempR=rValue;
  int tempG=gValue;
  int tempB=bValue;
  double incR=getRed()/nroPasos;
  double incG=getGreen()/nroPasos;
  double incB=getBlue()/nroPasos;
  setRGB(0,0,0);
  for(int i=1;i<=nroPasos;i++)
  {
     setRed(rValue+=incR);
     show();
     delay(50);
     
  }
}

//Fade In between 0 and the color set in the color variables
void light::linealTo(int R,int G,int B,int nroPasos, int tiempo)
{
  double incR=(double)(R-getRed())/nroPasos;
  double incG=(double)(G-getGreen())/nroPasos;
  double incB=(double)(B-getBlue())/nroPasos;
  //Serial.println(incR,DEC);
  //Serial.println(incG,DEC);
  //Serial.println(incB,DEC);
  float rTemp=rValue;
  float gTemp=gValue;
  float bTemp=bValue;
  for(int i=1;i<=nroPasos;i++)
  {
     rTemp+=incR;
     gTemp+=incG;
     bTemp+=incB;
     rValue=(int)rTemp;
     gValue=(int)gTemp;
     bValue=(int)bTemp;
     show();
     delay(tiempo);
     //Serial.println(rValue);
  }
}


// Fade from Current Values to 0 and in time T
void light::fadeInTime(int nroPasos, int tiempo)
{
  double decR=(double)(getRed())/nroPasos;
  double decG=(double)(getGreen())/nroPasos;
  double decB=(double)(getBlue())/nroPasos;
  //Serial.println(incR,DEC);
  //Serial.println(incG,DEC);
  //Serial.println(incB,DEC);
  float rTemp=rValue;
  float gTemp=gValue;
  float bTemp=bValue;
  for(int i=1;i<=nroPasos;i++)
  {
     rTemp-=decR;
     gTemp-=decG;
     bTemp-=decB;

     if (i==nroPasos) {
     	rTemp = 0;
     	gTemp = 0;
     	bTemp = 0;
     }

     rValue=(int)rTemp;
     gValue=(int)gTemp;
     bValue=(int)bTemp;
     show();
     delay(tiempo);
     //Serial.println(rValue);
  }
}


void light::cubicTo(int R, int G, int B, int nroPasos, int tPausa)
{  
   float aRed=rValue;
   float cRed=(float)3*(R-rValue)/(pow(nroPasos,2));
   float dRed=(float)-2*(R-rValue)/(pow(nroPasos,3));
   //Serial.println(aRed,DEC);
   //Serial.println(cRed,DEC);
   //Serial.println(dRed,DEC); 
   
   float aGreen=gValue;
   float cGreen=(float)3*(G-gValue)/(pow(nroPasos,2));
   float dGreen=(float)-2*(G-gValue)/(pow(nroPasos,3));
   
   
   float aBlue=bValue;
   float cBlue=(float)3*(B-bValue)/(pow(nroPasos,2));
   float dBlue=(float)-2*(B-bValue)/(pow(nroPasos,3));
   

   float rTemp=200;
   float gTemp=0;
   float bTemp=0;
   
   for(float i=0;i<=nroPasos;i++)
   {
     rTemp=(aRed+cRed*pow(i,2)+dRed*pow(i,3));
     gTemp=aGreen+cGreen*pow(i,2)+dGreen*pow(i,3);
     bTemp=aBlue+cBlue*pow(i,2)+dBlue*pow(i,3);

     rValue=(int)rTemp;
     gValue=(int)gTemp;
     bValue=(int)bTemp;
     show();
     delay(tPausa);
     //Serial.println(rValue,DEC);
   } 
}
// Esta es una prueba temporal
void light::respira(float value, float tiempo)
{
  float cte=0.0003;
  float valor=0;
  for(float i=0;i<=tiempo;i+=cte)
  {
    valor=255*(1-exp(-value*i));
    setRGB(0,(int)valor,0);
    show();   
  }
  
   for(float i=0;i<=tiempo+2;i+=cte)
  {
    valor=255*(exp(-0.8*i));
    setRGB(0,(int)valor,0);
    show();   
  }
  
}


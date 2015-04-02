
#include "light.h"
#include "sensor.h"

light light1(11,10,9);
light light2(3,5,6);
sensor sensor1(13);
sensor sensor2(12);
sensor sensor3(8);
sensor sensor4(1);


byte s1,s2,s3,s4;
byte sensorsStack[10];
byte posStack=0;
int Rc,Gc,Bc;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  light1.setRGB(0,0,0);
 
}

void loop() {
  // put your main code here, to run repeatedly:
 Rc=random(255);
 Gc=random(255);
 Bc=random(255);
  /*light1.linealTo(200,0,0,200,25);
  light1.linealTo(0,200,0,200,25);
  light1.linealTo(0,0,200,200,25);*/
 
  //light1.cubicTo(200,0,0,500,5);
  //light1.cubicTo(200,0,0,500,5);
  //light2.cubicTo(0,0,200,500,5);
  //light1.cubicTo(0,0,0,500,5);
  //light2.cubicTo(0,0,0,500,5);
  
  s1=sensor1.active();
//  if(s1==1){
//    sensorsStack[posStack]=1;
//    posStack++;
//  }
  s2=sensor2.active();
//  if(s2==1){
//    sensorsStack[posStack]=2;
//    posStack++;
//  }
  s3=sensor3.active();
//  if(s3==1){
//    sensorsStack[posStack]=3;
//    posStack++;
//  }
  s4=sensor4.active();
//  if(s4==1){
//    sensorsStack[posStack]=4;
//    posStack++;
//  }
    
  
  //if((sensorsStack[0]==1)&(sensorsStack[1]==4))
  if(s1==1)
    {
      light1.cubicTo(Rc,Gc,Bc,150,5);
      light2.cubicTo(Rc,Gc,Bc,150,5);
      light1.cubicTo(0,0,0,150,5);
      light2.cubicTo(0,0,0,500,5);
      sensor1.deactive();
      sensor3.deactive();
     //sensor4.deactive();
     // posStack=0;
     delay(5000);
    }
 
  //if((sensorsStack[0]==4)&(sensorsStack[1]==1))
  if(s3==1)
    {
      light2.cubicTo(Rc,Gc,Bc,150,5);
      light1.cubicTo(Rc,Gc,Bc,150,5);
      light2.cubicTo(0,0,0,150,5);
      light1.cubicTo(0,0,0,150,5);
      //sensor1.deactive();
      sensor3.deactive();
      sensor1.deactive();
      delay(5000);
      
      //posStack=0;
    }
  
  
   
  Serial.println(s1);
  Serial.println(s3);

}

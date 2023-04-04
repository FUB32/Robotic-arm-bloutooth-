#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

#include <Servo.h>


Servo baseservo;  // create servo object to control a servo
Servo shoulderservo;
Servo elbowservo;
Servo gripperservo;

int base=90;
int shoulder=100;
int elbow=120;
int gripper=120;

void setup() 
{
  Serial.begin(9600);    // Set your Serial Monitor is set at 9600
  Dabble.begin(9600);      // This is the baude rate of the HM-10
  smove(baseservo,4,base,"Base set to: ");
  delay(1000);
  smove(shoulderservo,5,shoulder,"Shoulder set to: ");
  delay(1000);
  smove(elbowservo,6,elbow,"Elbow set to: ");
  delay(1000);
  smove(gripperservo,7,gripper,"Gripper set to: ");
  delay(1000);
 
}

void loop() {
Dabble.processInput();  // This line is crucial in grabbing our data  
  if (GamePad.isRightPressed())       
  {
    if(base!=0){
    base-=2;
    smove(baseservo,4,base,"B-"); 
    }
  }
  else if (GamePad.isLeftPressed())
  {
    if(base!=180)
    {
      base+=2;
      smove(baseservo,4,base,"B+");
    }
  }

  else if (GamePad.isUpPressed())
  {
    if(shoulder<=130)
    {
      shoulder+=2;
      smove(shoulderservo,5,shoulder,"S+");
    }
  }

  else if (GamePad.isDownPressed())
  {
    if(shoulder>=60)
    {
      shoulder-=2;
      smove(shoulderservo,5,shoulder,"S-");
    }
  }
  else if (GamePad.isTrianglePressed())
  {
    if(elbow!=140)
    {
      elbow+=2;
      smove(elbowservo,6,elbow,"E+");
    }
  }
  else if (GamePad.isCrossPressed ())
  {
    if(elbow!=90)
    {
      elbow-=2;
      smove(elbowservo,6,elbow,"E-");
    }
  }
  else if (GamePad.isCirclePressed ())
  {
    if(gripper!=180)
    {
      gripper+=2;
      smove(gripperservo,7,gripper,"G+");
    }
  }
  else if (GamePad.isSquarePressed ())
  {
    if(gripper!=100)
    {
      gripper-=2;
      smove(gripperservo,7,gripper,"G-");
    }
  }
    delay(20);

}
void smove(Servo is,int sp,int deg, String m)
{
  is.attach(sp);
  delay(50);
  is.write(deg);
  Serial.print(m);
  Serial.print(": ");
  Serial.println(deg);
  if(sp!=7){
    
  is.detach();
  delay(10);
  }
}

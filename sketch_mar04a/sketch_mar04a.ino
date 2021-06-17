#include <Servo.h>

#include <ultrasound.h>
#include <vector.h>
#define LAMPPIN 9


const byte maximum = 255;
byte elapsed[5];
vector<UltraSound> uSensor;


enum Tame
{
  NONE =    0,
  SIGHT =   1,
  HEAR =    1 << 1,
  SMELL =   1 << 2,
  TOUCH =   1 << 3,
  RAND =    1 << 4
};


Tame level = NONE;

Servo s;

void setup() 
{
  uSensor.reserve(5);
  
  for (byte i = 0; i < 5; i++)
  {
    UltraSound us;
    us.init(8, 7);
    uSensor.push_back(us);
  }

  s.attach(9);
}

//USS for head to pet
//IR at  mouth to feed
//Sound in center "not scare away"
//Smell is random
//IR in head -> Fast movement scary

bool eye()
{
  return false;  
}

bool head()
{
  return false;
}

bool mouth()
{
  return false;
}

bool ear()
{
  return false;
}

bool nose()
{
  return false;
}

void loop() 
{  
  for (int pos = 0; pos < 180; pos += 1)
  {
    s.write(pos); 
    delay(15);
  }
   
  for (int pos = 180; pos > 0; pos -= 1)
  {
    s.write(pos);
    delay(15);
  }

  for (byte i = 0; i < 5; i++)
    elapsed[i] = max(uSensor[i].getAsMicroseconds() * 0.01, 1);

  for (byte i = 0; i < 5; i++)
    analogWrite(LAMPPIN, maximum / elapsed[i]);

  int moveSpeed = 0;

  moveSpeed += (bool)(level & SIGHT);
  moveSpeed += (bool)(level & HEAR);
  moveSpeed += (bool)(level & SMELL);
  moveSpeed += (bool)(level & TOUCH);
  moveSpeed += (bool)(level & RAND);

  moveSpeed *= 10;
}

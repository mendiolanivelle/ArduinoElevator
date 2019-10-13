#include <dht.h>
#include <Servo.h>
#include <Stepper.h> 

dht DHT;
#define DHT11_PIN 3

int numberofstep = 64*32; 
Stepper motor(numberofstep,8, 10, 9, 11);

Servo MyServo;
int ServoPosition = 0;

int Floor = 1;
int CurrentFloor = 1;

void setup() 
{
  Serial.begin(9600);
  motor.setSpeed(10);
  MyServo.attach(4);
}

void loop() 
{
  
  if(Serial.available())
  {
    char CharTargetFloor = Serial.read();
    int TargetFloor = ConvertFloorToNumber(CharTargetFloor);
    if(CurrentFloor != TargetFloor)
      {
        MoveElevator(TargetFloor);
      }

  }
}

void MoveElevator(int p_TargetFloor)
{
  int Direction;
  int MotorStep;
  if( p_TargetFloor > Floor )
  {
    Serial.print("The elevator is on it's way up...");
    Direction = 1;
    MotorStep = 5200;
  }
  else
  {
    Serial.print("The elevator is on it's way down...");
    Direction = -1;
    MotorStep = -5200;
  }

  while(p_TargetFloor != Floor)
  {
    Floor += Direction;
    motor.step(MotorStep);
    Serial.print(Floor);
    delay(1000);
    int chk = DHT.read11(DHT11_PIN);
    Serial.print("Temperature = ");
    Serial.println(DHT.temperature);
    Serial.print("Humidity = ");
    Serial.println(DHT.humidity);
  }
  CurrentFloor = p_TargetFloor;
  OpenDoor();
  delay(1000);
  CloseDoor();
  delay(1000);
}

int ConvertFloorToNumber(char Letter)
{
  switch (Letter)
  {
    case 'a':
    return 1;
    break;

    case 'b':
    return 2;
    break;

    case 'c':
    return 3;
    break;

    case 'd':
    return 4;
    break;

    default:
    
    break;
  }
}

void OpenDoor()
{
  for (ServoPosition = 0; ServoPosition <= 85; ServoPosition += 1) 
  {
      MyServo.write(ServoPosition);
      delay(25);                       
    }
}

void CloseDoor()
{
 for (ServoPosition = 85; ServoPosition >= 0; ServoPosition -= 1) 
 { 
    MyServo.write(ServoPosition);   
    delay(25);                       
  }
}

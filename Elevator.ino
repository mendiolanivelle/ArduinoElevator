#include <Stepper.h> 

int numberofstep = 64*32; 
Stepper motor(numberofstep,8, 10, 9, 11);

int Floor = 1;
int CurrentFloor = 1;

void setup() 
{
  Serial.begin(9600);
  motor.setSpeed(10);
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
    MotorStep = 2200;
  }
  else
  {
    Serial.print("The elevator is on it's way down...");
    Direction = -1;
    MotorStep = -2200;
  }

  while(p_TargetFloor != Floor)
  {
    Floor += Direction;
    motor.step(MotorStep);
    Serial.print(Floor);
    delay(1000);
  }
  CurrentFloor = p_TargetFloor;
  Serial.println("");
  Serial.println("Door is now Open");
  delay(1000);
  Serial.println("Door is now close");
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

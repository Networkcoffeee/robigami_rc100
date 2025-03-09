#include "Balloon_Shooter_Lib.h"

#define CONCURRENT_BALLOONS_TOTAL 10

GeometryDisplayHandler dh;
JoystickAction action;
JoystickHandler joystickHandler;

int numOfBalls = CONCURRENT_BALLOONS_TOTAL;
DemoBalloon* balls[CONCURRENT_BALLOONS_TOTAL] = { 0 };

DemoGunTarget* gunTarget;

void setup() {
  Serial.begin(57600);
  randomSeed(analogRead(A3));
  
  dh.begin();
  joystickHandler.begin();
  
  gunTarget = new DemoGunTarget(&dh);
  
  numOfBalls = random(3, CONCURRENT_BALLOONS_TOTAL + 1);
  for(int k=0; k<numOfBalls; k++) {
    balls[k] = new DemoBalloon();
    balls[k]->set(&dh);
  }
}

void loop() {
  
  joystickHandler.input(&action);
  
  gunTarget->update(action.getX(), action.getY());
  
  for(int i=0; i<numOfBalls; i++) {
    balls[i]->check();
  }

  dh.firstPage();
  do {
   
    for(int i=0; i<numOfBalls; i++) {
      balls[i]->draw();
    }
    
    
    gunTarget->draw();
  } while(dh.nextPage());

  delay(50);
}
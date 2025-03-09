#include "Pokerobo_Lab_Display_Handler.h"
#include "Pokerobo_Lab_Game_Balloon_Shooter.h"

GeometryDisplayHandler displayHandler(LCD_PINS_ON_RIGHT);
JoystickHandler joystickHandler;
JoystickAction action;
ShootingTarget target(&displayHandler);

PlaySpace playSpace(&displayHandler, 6, 60, PLAY_SPACE_OPTION_STATUS_BAR);

GameBoard gameBoard(&displayHandler, &target, &playSpace);


void setup() {
  Serial.begin(57600);
  displayHandler.begin();
  joystickHandler.begin();
  gameBoard.begin();
  
}

void loop() {
  gameBoard.play(joystickHandler.input(&action));
  gameBoard.renderAndDelay(50);
}

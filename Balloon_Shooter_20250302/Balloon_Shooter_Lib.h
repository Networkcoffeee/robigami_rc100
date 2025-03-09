#ifndef __BALLOON_SHOOTER_LIB_H__
#define __BALLOON_SHOOTER_LIB_H__

#include "Pokerobo_Lab_Display_Handler.h"

class GeometryDisplayHandler;
class JoystickAction;
class JoystickHandler;

class DemoGunTarget {
  public:
    DemoGunTarget(GeometryDisplayHandler* displayHandler);

    int getX();
    int getY();

    int speedOfX(int jX);
    int speedOfY(int jY);

    void move(int dX, int dY);
    void update(int jX, int jY);
    void draw();

  private:
    int x = 64;  
    int y = 32;
    int r = 3;
    GeometryDisplayHandler* _pencil;
};

class DemoBalloon {
  public:
    DemoBalloon();
    void set(GeometryDisplayHandler* displayHandler);
    void check();
    void draw();
    
  private:
    int _x;
    int _y;
    int _r;
    GeometryDisplayHandler* _pencil;
    void init();
};

#endif
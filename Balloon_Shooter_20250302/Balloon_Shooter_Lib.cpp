#include "Balloon_Shooter_Lib.h"

DemoGunTarget::DemoGunTarget(GeometryDisplayHandler* displayHandler) {
  _pencil = displayHandler;
}

int DemoGunTarget::getX() { return x; }
int DemoGunTarget::getY() { return y; }

int DemoGunTarget::speedOfX(int jX) {
  int dX = -512 + jX;
  if (abs(dX) < 30) return 0;
  return map(dX, -512, 512, -10, 10);
}

int DemoGunTarget::speedOfY(int jY) {
  int dY = -512 + jY;
  if (abs(dY) < 30) return 0;
  return map(dY, -512, 512, 10, -10);
}

void DemoGunTarget::move(int dX, int dY) {
  int _maxX = _pencil->getMaxX();
  int _maxY = _pencil->getMaxY();
  x = x + dX > 0 ? (x + dX <= _maxX ? x + dX : _maxX) : 0;
  y = y + dY > 0 ? (y + dY <= _maxY ? y + dY : _maxY) : 0;
}

void DemoGunTarget::update(int jX, int jY) {
  move(speedOfX(jX), speedOfY(jY));
}

void DemoGunTarget::draw() {
  _pencil->drawPixel(x, y);
  _pencil->drawCircle(x, y, r);
}

DemoBalloon::DemoBalloon() {
  init();
}

void DemoBalloon::set(GeometryDisplayHandler* displayHandler) {
  _pencil = displayHandler;
}

void DemoBalloon::init() {
  _r = random(5, 11); 
  _y = 63 + _r;
  _x = random(0, 128);
}

void DemoBalloon::check() {
  if (_y + _r >= 0) {
    _y = _y - 3;
  } else {
    _y = 63 + _r;
    _x = random(0, 128);
  }
}

void DemoBalloon::draw() {
  _pencil->drawCircle(_x, _y, _r);
}
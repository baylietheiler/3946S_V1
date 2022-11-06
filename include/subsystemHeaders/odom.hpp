#include "../main.h"

double getX();
double getY();
double getHeading();

float getEncoderVal();

void clearPosition();
void setX(float x);
void setY(float y);
void setHeading(double deg);
void driveToPoint(float x, float y, int voltage, int direction);
void driveToPointAndFlywheel(float x, float y, int voltage, int direction, int val);
void turnTo(double deg, int voltage);

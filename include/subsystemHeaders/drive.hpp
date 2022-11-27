#include "../main.h"

//helper functions
void setLeftDrive(double left);
void setRightDrive(double right);
void resetDriveEncoders();
double avgDrivePosition();
double avgLeftDrivePosition();
double avgRightDrivePosition();

//driver control functions
void setDriveMotors();

//basic auton functions
void translate(float units, int voltage);
void translate(float units, int voltage, int kick);
void turn(float degrees, char direction);
void turn(float degrees, char direction, int kick);
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
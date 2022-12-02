#include "../../include/subsystemHeaders/drive.hpp"

//helper functions
void setLeftDrive(double left){
    frontLeftDrive.move_voltage(left/127*12000);
    backLeftDrive.move_voltage(left/127*12000);
}

void setRightDrive(double right){
    frontRightDrive.move_voltage(right/127*12000);
    backRightDrive.move_voltage(right/127*12000);
}

void resetDriveEncoders(){
    frontLeftDrive.tare_position();
    backLeftDrive.tare_position();
    frontRightDrive.tare_position();
    backRightDrive.tare_position();
}

double avgLeftDrivePosition(){
    return (frontLeftDrive.get_position()+
            backLeftDrive.get_position())/2;
}
double avgRightDrivePosition(){
    return (frontRightDrive.get_position()+
            backRightDrive.get_position())/2;
}
double avgDrivePosition(){
    return (fabs(frontLeftDrive.get_position())+
            fabs(backLeftDrive.get_position())+
            fabs(frontRightDrive.get_position())+
            fabs(backRightDrive.get_position()))/4;
}

//driver control
void setDriveMotors(){

    int leftJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    int rightJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    //if(abs(leftJoystick>10)) leftJoystick = 0;
    //if(abs(rightJoystick)<10) rightJoystick = 0;
    setLeftDrive(leftJoystick);
    setRightDrive(rightJoystick);

   /* int leftJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int rightJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
    if(abs(leftJoystick)<10) leftJoystick=0;
    if(abs(rightJoystick)<10) rightJoystick=0;
    setLeftDrive(leftJoystick-rightJoystick);
    setRightDrive(leftJoystick+rightJoystick);
    */
}




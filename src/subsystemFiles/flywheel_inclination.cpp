#include "../../include/subsystemHeaders/flywheel_inclination.hpp"

void setInclinator(int power){
    flywheel_inclinator.move_voltage(power/127*12000);
}

void setInclinatorMotor() {
    int liftPower = 127*(controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)-controller.get_digital(pros::E_CONTROLLER_DIGITAL_B));
    setInclinator(liftPower);
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)||controller2.get_digital(pros::E_CONTROLLER_DIGITAL_A)){
        setInclinator(127);
    }
    else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)||controller2.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
        setInclinator(-127);
    }
    else{
        flywheel_inclinator.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    }
}

void inclinateTo(int val){
    flywheel_inclinator.move_absolute(val,100);
}

void inclinatetTo(int val, int delay){
    flywheel_inclinator.move_absolute(val,100);
    wait(delay);
}



double flywheelHeight;
double h = 30.25 - flywheelHeight;
double e = sqrt((dx)*(dx)+(dy)*(dy));
double d = sqrt((e)*(e) + (h)*(h));
double a = asin(h/d);
double ia = imu_sensor.get_pitch();
double da = a-ia;
double ie = flywheel_inclinator.get_position();
//36 motors have 1800 encoder ticks per rotation
//1800/12 = 150 encoder units per 1/12 of a rotation (1 turn of pinion & ~4 degrees)

void setInclinatorMotorMathyVersion(){
    flywheel_inclinator.set_zero_position(ie);
    if(da>0) {
        double twelfthsNeeded = da/(360.0/84.0);
        int twelfthsN = (int)twelfthsNeeded;
        int rotations = twelfthsN/12;
        int encoders = rotations*150;
        flywheel_inclinator.move_absolute(encoders,100);
    }
    if(da<0){
        double twelfthsNeeded = -da/(360.0/84.0);
        int twelfthsN = (int)twelfthsNeeded;
        int rotations = twelfthsN/12;
        int encoders = rotations*150;
        flywheel_inclinator.move_absolute(-encoders,100);
    }
}
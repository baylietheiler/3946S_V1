#include "../../include/subsystemHeaders/flywheel.hpp"

void setFlywheel1(int power){
    flywheel1.move_voltage(power/127*12000);
}

void setFlywheel2(int power){
    flywheel2.move_voltage(power/127*12000);
}

void setFlywheelMotor1() {
    int flywheelPower = 127*(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)-controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2));
    setFlywheel1(flywheelPower);
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)||controller2.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        setFlywheel1(127);
    }
    else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)||controller2.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        setFlywheel1(-127);
    }
    else{
        flywheel1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    }
}

void setFlywheelMotor2() {
    int flywheelPower = 127*(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)-controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2));
    setFlywheel2(flywheelPower);
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)||controller2.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
        setFlywheel2(127);
    }
    else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)||controller2.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        setFlywheel2(-127);
    }
    else{
        flywheel2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    }
}

/*
double flywheelHeight;
double h = 30.25 - flywheelHeight;
double e = sqrt((dx)*(dx)+(dy)*(dy));
double d = sqrt((e)*(e) + (h)*(h));
double a = asin(h/d);


 * e = ((viE + vfE)/2)*t
 * vfE = 0, viE = ?, t = 1
 * e = ((viE + 0)/2)*1
 * e = viE/2
 * viE = 2e


double viE = 2 * e;


 * h = (viH * t) + (1/2 * acceleration * (t * t))
 * vfH = 0, voH = ?, t = 1, acceleration = -9/8
 * h = viH - 4.9
 * viH = h + 4.9


double viH = h + 4.9;

double vo1 = viE/(cos(a));
double vo2 = viH/(sin(a));

void setFlywheelMotorsMathyVersion() {
    if (vo1 == vo2) {
        setFlywheel1(vo1);
        setFlywheel2(vo1);
    }
}

 */
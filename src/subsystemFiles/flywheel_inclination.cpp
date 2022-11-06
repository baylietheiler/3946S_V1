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
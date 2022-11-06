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

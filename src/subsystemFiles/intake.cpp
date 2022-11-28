#include "../../include/subsystemHeaders/intake.hpp"

void setIntake(float power){
    intake.move_voltage(power/127*12000);
}
void setIntakeMotor(){
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)||controller2.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
        setIntake(127);
    }
    else if( controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)||controller2.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        setIntake(-127);
    }
    else{
        setIntake(0);
    }
}
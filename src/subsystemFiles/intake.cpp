#include "../../include/subsystemHeaders/intake.hpp"

void setIntake(float power){
    intake1.move_voltage(power/127*12000);
    intake2.move_voltage(power/127*12000);

}
void setIntakeMotors(){
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)
    ||controller2.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
        setIntake(95);
    }
    else if( controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)
    ||controller2.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        setIntake(-95);
    }
    else{
        setIntake(0);
    }
}




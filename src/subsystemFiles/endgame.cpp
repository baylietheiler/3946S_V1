#include "../../include/subsystemHeaders/endgame.hpp"

void setEndgame(bool pos){
    piston1.set_value(pos);
}
bool pressedPiston1 = false;

void setClampPiston(){
    if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)||controller2.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
        pressedPiston1 = !pressedPiston1;
        setEndgame(pressedPiston1);
    } }
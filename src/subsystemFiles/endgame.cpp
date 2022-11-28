#include "../../include/subsystemHeaders/endgame.hpp"

void setEndgame(bool pos){
    endgame.set_value(pos);
}
bool pressedendgame = false;

void setEndgamePiston(){
    if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)||controller2.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
        pressedendgame = !pressedendgame;
        setEndgame(pressedendgame);
    } }
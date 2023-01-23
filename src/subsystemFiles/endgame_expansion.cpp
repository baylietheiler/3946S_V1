#include "../../include/subsystemHeaders/endgame_expansion.hpp"

void setEndgame(bool pos){
    endgame1.set_value(pos);
    endgame2.set_value(pos);
}
bool pressedendgame = true;

void setEndgamePistons(){
    setEndgame(true);
    if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)||controller2.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
        //pressedendgame = !pressedendgame;
        setEndgame(false);
        wait(5000);
    } }
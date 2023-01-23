#include "../../include/subsystemHeaders/flywheel_indexer.hpp"

void setIndexer(bool pos){
    flywheel_indexer.set_value(pos);
}
bool pressedClamp = false;

void setIndexerPiston(){
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)||controller2.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        pressedClamp = !pressedClamp;
        setIndexer(pressedClamp);
        pros::delay(50);
        pressedClamp = false;
        setIndexer(pressedClamp);
    }
   // pros::lcd::set_text(0, ":)");
}



/*

void setIndexerMotor() {
    if(controller2.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        flywheel_indexer.move_voltage(7.2);
    }
}
    int indexPower = 127*(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) || 127*(controller2.get_digital(pros::E_CONTROLLER_DIGITAL_R2));
    //setIndexer(indexPower);
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)||controller2.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        setIndexer(indexPower);
    }
    else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)||controller2.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        setIndexer(-10);
    }
    else{

    indexTo(0, 10);
    */





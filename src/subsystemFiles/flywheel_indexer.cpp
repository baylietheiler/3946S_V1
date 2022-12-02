#include "../../include/subsystemHeaders/flywheel_indexer.hpp"

void indexTo(int val){
    flywheel_indexer.move_absolute(val,10);
}

void indexTo(int val, int delay){
    flywheel_indexer.move_absolute(val,100);
    wait(delay);
}


void setIndexer(int power){
    flywheel_indexer.move_voltage(power/127*12000);
}



void setIndexerMotor() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) ||
        controller2.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        setIndexer(127);
    }
    else(indexTo(-30,5));
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





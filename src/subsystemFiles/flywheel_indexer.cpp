#include "../../include/subsystemHeaders/flywheel_indexer.hpp"

void indexTo(int val){
    flywheel_indexer.move_absolute(val,10);
}

void indexTo(int val, int delay){
    flywheel_indexer.move_absolute(val,10);
    wait(delay);
}


void setIndexer(int power){
    flywheel_indexer.move_voltage(power/10*12000);
}

void setIndexerMotor() {
    int indexPower = 10*(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)-controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1));
    setIndexer(indexPower);
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)||controller2.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        setIndexer(10);
    }
    else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)||controller2.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        setIndexer(-10);
    }
    else{
        indexTo(0, 10);
    }
}



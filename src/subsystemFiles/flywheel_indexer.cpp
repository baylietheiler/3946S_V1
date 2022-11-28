#include "../../include/subsystemHeaders/flywheel_indexer.hpp"

void indexTo(int val){
    flywheel_indexer.move_absolute(val,100);
}

void indexTo(int val, int delay){
    flywheel_indexer.move_absolute(val,100);
    wait(delay);
}


void setIndexer(int power){
    flywheel_indexer.move_voltage(power/100*12000);
}

void setIndexerMotor() {
    int indexPower = 100*(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)-controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2));
    setIndexer(indexPower);
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)||controller2.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        setIndexer(100);
    }
    else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)||controller2.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        setIndexer(-100);
    }
    else{
        indexTo(0, 10);
    }
}



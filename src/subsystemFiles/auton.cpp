#include "../../include/subsystemHeaders/auton.hpp"

void wait (int msec){
    pros::delay(msec);
}

void lblueAWP(){
//LEFT SIDE
//spin first roller
translate(5, -80);
turn(130, 'l');
translate(65,127);
turn(30, 'r');
translate(10, 100);
//spin second roller
translate(5, -80);
turn(130, 'r');
//start intaking
translate(30, 127);
turn(90, 'r');
//shoot discs
}

void rblueAWP(){

}


void redAWP(){

}
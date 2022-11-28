#include "../../include/subsystemHeaders/auton.hpp"

//auton functions
void translate(float units, int voltage){

    clearPosition();
    driveEncoder.reset_position();
    gyro.tare();

    int direction = abs(voltage)/voltage;
    int kicker = units*1000/24;
    float gyroAdjust;

    for(int i = 0; i<kicker/10; i++) {
        gyroAdjust = gyro.get_rotation();
        setLeftDrive((abs(voltage) - gyroAdjust * direction * 2) * direction);
        setRightDrive((abs(voltage) + gyroAdjust * direction * 2) * direction);
        pros::delay(10);
        if(fabs(getEncoderVal()) > fabs(units) * .8) break;
    }

    float kP = 10;
    float kD = 100;
    float driveError;
    float driveErrorF;
    float deriv = 0;

    for(int i = 0; i<kicker/10; i++){


        driveError = units*direction- getEncoderVal();

        gyroAdjust = gyro.get_rotation();
        setLeftDrive((driveError*kP-deriv*kD)-gyroAdjust*direction*2);
        setRightDrive((driveError*kP-deriv*kD)+gyroAdjust*direction*2);

        pros::delay(10);
        driveErrorF = units*direction-getEncoderVal();
        deriv = fabs(driveErrorF-driveError)/10;
        if(fabs(driveError)<0.01)break;
        pros::lcd::print(0, "Error:%d", int(driveError));
    }

    pros::lcd::print(0, "Exited loop >>", int(driveError));

}
void translate(float units, int voltage, int kick){

    clearPosition();
    gyro.tare();

    int direction = abs(voltage)/voltage;
    int kicker = units*1000/24;
    float gyroAdjust;

    for(int i = 0; i<kicker/10; i++) {
        if(fabs(getEncoderVal()) > fabs(units) * .8) break;
        gyroAdjust = gyro.get_rotation();
        setLeftDrive((abs(voltage)- gyroAdjust * direction * 2) * direction);
        setRightDrive((abs(voltage) + gyroAdjust * direction * 2) * direction);
        pros::delay(10);
    }
    float kP = 10;
    float kD = 100;
    float driveError;
    float driveErrorF;
    float deriv = 0;

    for(int i = 0; i<kick/10; i++){


        driveError = direction*units- getEncoderVal();

        gyroAdjust = gyro.get_rotation();
        setLeftDrive(((driveError*kP-deriv*kD-gyroAdjust*2*direction)));
        setRightDrive(((driveError*kP-deriv*kD+gyroAdjust*2*direction)));

        pros::delay(10);
        driveErrorF = direction*units-getEncoderVal();
        deriv = fabs(driveErrorF-driveError)/10;
        if(fabs(driveError)==0)break;
        pros::lcd::print(0, "Error:%d", int(driveError));
    }

    pros::lcd::print(0, "Exited loop >>", int(driveError));


}



void turn(float degrees, char direction){
    clearPosition();
    gyro.tare();
    int dir;
    float turnError;
    float deriv;
    float turnErrorF;
    float kP =3.7;
    float kD = 50;
    int kicker = degrees *1000/100;

    if(direction == 'r') dir = -1;
    else dir = 1;

    for(int i = 0; i<kicker/10; i++) {
        if (direction == 'r') {
            turnError = degrees - gyro.get_rotation();
            setLeftDrive((turnError * kP - kD * deriv / 10));
            setRightDrive(-(turnError * kP - kD * deriv / 10));
            wait(10);
            turnErrorF = degrees - gyro.get_rotation();
        }
        else {

            turnError =   (degrees) +gyro.get_rotation();
            setLeftDrive( -(turnError * kP - kD * deriv / 10));
            setRightDrive( (turnError * kP - kD *deriv / 10));
            wait(10);
            turnErrorF =  (degrees) +gyro.get_rotation();
        }

        deriv = fabs(turnErrorF-turnError);

        if(turnError==0){

            break;
        }

    }


}
void turn(float degrees, char direction, int kick){
    clearPosition();
    gyro.tare();
    int dir;
    float turnError;
    float deriv;
    float turnErrorF;
    float kP =3.7;
    float kD = 50;
    int kicker = degrees *1000/100;

    if(direction == 'r') dir = -1;
    else dir = 1;

    for(int i = 0; i<kick/10; i++) {
        if (direction == 'r') {
            turnError = degrees - gyro.get_rotation();
            setLeftDrive((turnError * kP - kD * deriv / 10));
            setRightDrive(-(turnError * kP - kD * deriv / 10));
            wait(10);
            turnErrorF = degrees - gyro.get_rotation();
        }
        else {

            turnError =   (degrees) +gyro.get_rotation();
            setLeftDrive( -(turnError * kP - kD * deriv / 10));
            setRightDrive( (turnError * kP - kD *deriv / 10));
            wait(10);
            turnErrorF =  (degrees) +gyro.get_rotation();
        }

        deriv = fabs(turnErrorF-turnError);

        if(turnError==0){

            break;
        }

    }

}

//actual auton code
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


void lredAWP(){

}


void rredAWP(){

}
#include "../../include/subsystemHeaders/odom.hpp"

/*SECTION ONE: STARTING NUMBERS AND HELPER FUNCTIONS */
//original numbers
double xpos = 0;
double ypos = 0;
double globalHeading = 0;

//helper functions
double getX(){
    return xpos;
}
double getY(){
    return ypos;
}
double getHeading(){
    return gyro.get_rotation();
}
double getGlobalHeading(){
    return globalHeading;
}
float getEncoderVal(){
    float scalingFactor = 1.0/100/360*2.75*3.14159;
    float encoderVal = driveEncoder.get_position()*1.0/100/360*2.75*3.14159;
    return encoderVal;
}
void clearPosition(){
    driveEncoder.reset_position();
}

void setX(float x){
    xpos = x;
}
void setY(float y){
    ypos = y;
}
void setHeading(double deg){
    globalHeading = deg;
}

/* SECTION TWO: DRIVE TO POINT FUNCTION
 * -> determines distance between original point and new point
 * -> uses inverse trig to determine quadrant, turns to face new point
 * -> drives to new point in a straight line
 * FOR PROG AND AUTON */

void driveToPoint(float x, float y, int voltage, int direction){
    //original coordinates
    float xi = xpos;
    float yi = ypos;

    //Δ distance
    float dy = y-ypos;
    float dx = x-xpos;

    //pythagorean theorem (straight line between points)
    float targetDistance = sqrt((dx)*(dx)+(dy)*(dy));

    /* DETOUR INTO ALL OF THE ANGLE STUFF (LINES 58-100) */
    //inverse trig to find reference angle
    float thetaRelative = fabs(asin(dy/targetDistance))*180/3.14159;
    float thetaF;

    //determine a quadrant and adjust
    if(dx>=0 && dy>0)thetaF = thetaRelative;//Q2
    else if(dx<0 && dy>=0)thetaF= (180- thetaRelative);// Q3
    else if(dx<=0 && dy<0) thetaF = (180 + thetaRelative);// Q4
    else thetaF = (360- thetaRelative); //Q1
    if(direction == -1) thetaF +=180;
    while(thetaF<0)thetaF +=360;
    while(thetaF>=360) thetaF -=360;

    //call turnTo function to turn and face point
    turnTo(thetaF,500);
    wait(500);

    //equation for gyro
    float gyroAdjust;

    while(fabs(getEncoderVal())<fabs(targetDistance*.5)){
        //initial x and y positions (angles)
        float xinit = getEncoderVal()*cos(thetaF/180*3.14159);
        float yinit = getEncoderVal()*sin(thetaF/180*3.14159);
        //adjust gyro
        gyroAdjust = gyro.get_rotation();
        //sets left and right drive according to difference (angles)
        setLeftDrive((voltage-gyroAdjust)*direction);
        setRightDrive((voltage+gyroAdjust)*direction);
        //built in wait so loop can run
        wait(10);
        //sets the final x and y values
        float xfinal = getEncoderVal()* cos(thetaF/180*3.14159);
        float yfinal = getEncoderVal()* sin(thetaF/180*3.14159);
        //finds ΔX and ΔY
        float deltax = xfinal-xinit;
        float deltay = yfinal-yinit;
        //x and y position
        xpos = xpos + deltax;
        ypos = ypos + deltay;
    }

   /* NOW BACK TO LARGER PICTURE */
    //x and y initial
    xi = xpos;
    yi = ypos;
    float encoderI = getEncoderVal();
    //drive error is amount between initial and final position
    float driveError = direction*targetDistance - getEncoderVal();
    //constant (using aspects of PID to try and mitigate inaccuracy)
    float kP = 7;


    for(int i = 0; i<targetDistance*8;i++){
        gyroAdjust = direction*gyro.get_rotation();
        //initial x and y positions
        float xinit = getEncoderVal()*cos(globalHeading/180*3.14159);
        float yinit = getEncoderVal()*sin(globalHeading/180*3.14159);
        //drive error
        driveError = direction*targetDistance-getEncoderVal();
        //powers left and right drives based on magnitude of error
        setLeftDrive(direction*(fabs(driveError)*kP-gyroAdjust));
        setRightDrive(direction*(fabs(driveError)*kP+gyroAdjust));
        //built in wait so loop can run
        wait(10);
        //calculates final x and final y positions
        float xfinal = getEncoderVal()* cos(globalHeading/180*3.14159);
        float yfinal = getEncoderVal()* sin(globalHeading/180*3.14159);
        //calculates ΔX and ΔY again
        float deltax = xfinal-xinit;
        float deltay = yfinal-yinit;
        //updates robots new position
        xpos = xpos + deltax;
        ypos = ypos + deltay;
        //exits loop when robot is <= 0.2in of target position
        if(fabs(driveError)<.2)break;
    }
    //brakes robot and prints values to screen
    setLeftDrive(0);
    setRightDrive(0);
    pros::lcd::print(0, "X:%d", int(getX()));
    pros::lcd::print(1, "Y:%d", int(getY()));
    pros::lcd::print(2, "Global Heading:%d", int(getGlobalHeading()));
}


/* SECTION THREE: TURN TO  FUNCTION
 * -> determines difference in angle between original point and new point
 * -> uses inverse trig to determine quadrant, turns to face new point
 * FOR PROG AND AUTON */

void turnTo(double deg, int voltage){
    //set up: variables, constants, and kickers
    gyro.tare();

    while(globalHeading<0)globalHeading+=360;
    while(globalHeading>=360) globalHeading -=360;

    int direction;
    float turnError;
    float turnErrorF;
    float kP =3.5;
    float kD =35;
    int kicker = 1000;
    int globalheadinginitial = globalHeading;

    //for loop limits how long robot can spend turning
    for (int i = 0; i < kicker/10; i++) {
        //breaks loop when we turn correct amount
        if(int(globalheadinginitial) == int(deg))break;

        //below are different conditions that move the robot depending on how far we are from target angle

        //left
        if (globalHeading - deg > 180) {
            //only commenting this section because each condition follows the same process
            direction = 1;
            //calculates change in angle needed to reach target
            float headingI = -gyro.get_rotation();
            turnError = 360 - globalHeading + deg;

            //sets drive motors based on error & dy/dx of error
            setLeftDrive(-direction * (turnError * kP - kD * (turnErrorF - turnError) / 10));
            setRightDrive(direction * (turnError * kP - kD * (turnErrorF - turnError) / 10));
            wait(10);
            turnErrorF = 360 - globalHeading + deg;
            //updates global heading
            float headingF = -gyro.get_rotation();
            globalHeading += (headingF - headingI);

        }

        //right
        else if (globalHeading - deg > 0) {
            direction = -1;
            float headingI = -gyro.get_rotation();
            turnError = globalHeading - deg;

            setLeftDrive(-direction * (turnError * kP - kD * (turnErrorF - turnError) / 10));
            setRightDrive(direction * (turnError * kP - kD * (turnErrorF - turnError) / 10));
            wait(10);
            turnErrorF = globalHeading - deg;
            float headingF = -gyro.get_rotation();
            globalHeading += (headingF - headingI);

        }
        //left
        else if (globalHeading - deg > -180) {
            direction = 1;
            float headingI = -gyro.get_rotation();
            turnError = deg - globalHeading;

            setLeftDrive(-direction * (turnError * kP - kD * (turnErrorF - turnError) / 10));
            setRightDrive(direction * (turnError * kP - kD * (turnErrorF - turnError) / 10));
            wait(10);
            turnErrorF = deg - globalHeading;
            float headingF = -gyro.get_rotation();
            globalHeading += (headingF - headingI);

        }
        //right
        else {
            direction = -1;
            float headingI = -gyro.get_rotation();
            turnError = 360 - deg + globalHeading;

            setLeftDrive(-direction * (turnError * kP - kD * (turnErrorF - turnError) / 10));
            setRightDrive(direction * (turnError * kP - kD * (turnErrorF - turnError) / 10));
            wait(10);

            turnErrorF = 360 - deg + globalHeading;
            float headingF = -gyro.get_rotation();

            globalHeading += (headingF - headingI);
        }
        //break loop
        if (abs(int(frontLeftDrive.get_voltage())) == 0 && fabs(turnError) ==0) break;

        //print a bunch of values to screen
        pros::lcd::print(0, "X:%d", int(getX()));
        pros::lcd::print(1, "Y:%d", int(getY()));
        pros::lcd::print(2, "Global Heading:%d", int(getGlobalHeading()));
        pros::lcd::print(3, "Voltage:%d", int(frontLeftDrive.get_voltage()));
        pros::lcd::print(6, "turnError %d", int(turnError));
        pros::lcd::print(5,"deg: %d", int (deg));

    }
    //brake drive
    setLeftDrive(0);
    setRightDrive(0);
}
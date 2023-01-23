#include <iostream>
#include "../include/main.h"


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    clearPosition();
    pros::lcd::initialize();
    //  gyro.reset();
    //wait(4000);
    gyro.tare();
    //pros::lcd::set_text(0, "3946S");

    frontLeftDrive.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    backLeftDrive.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    frontRightDrive.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    backRightDrive.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    intake1.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    intake2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    flywheel1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    flywheel2.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {

}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
    //lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    gyro.tare();
    pros::lcd::set_text(0, "3946S");

    frontLeftDrive.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    backLeftDrive.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    frontRightDrive.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    backRightDrive.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    intake1.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    intake2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    flywheel1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    flywheel2.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);

}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */


void autonomous() {

  //FIRST TOURNAMENT CODE (ONE ROLLER) - 12/7/22
frontRightDrive.set_zero_position(0.0);
backRightDrive.set_zero_position(0.0);
frontLeftDrive.set_zero_position(0.0);
backLeftDrive.set_zero_position(0.0);
intake1.set_zero_position(0.0);
intake2.set_zero_position(0.0);
flywheel1.set_zero_position(0.0);
flywheel2.set_zero_position(0.0);

intake1.move_relative(500, 140);
intake2.move_relative(500, 140);
frontRightDrive.move_relative(40,100);
backRightDrive.move_relative(40,100);
frontLeftDrive.move_relative(40,100);
backLeftDrive.move_relative(40,100);
wait(300);
//intake1.move_relative(1000, 140);
//intake2.move_relative(1000, 140);
/*
frontRightDrive.move_relative(-1800,100);
backRightDrive.move_relative(-1800,100);
frontLeftDrive.move_relative(-1800,100);
backLeftDrive.move_relative(-1800,100);
wait(1500);

frontRightDrive.move_relative(1000,140);
backRightDrive.move_relative(1000,140);
frontLeftDrive.move_relative(-1000,140);
backLeftDrive.move_relative(-1000,140);

endgame1.set_value(false);
endgame2.set_value(false);

frontRightDrive.move_relative(500,140);
backRightDrive.move_relative(500,140);
frontLeftDrive.move_relative(-500,140);
backLeftDrive.move_relative(-500,140);
wait(1800);

frontRightDrive.move_relative(1800,140);
backRightDrive.move_relative(1800,140);
frontLeftDrive.move_relative(1800,140);
backLeftDrive.move_relative(1800,140);

wait(2400);
intake1.move_relative(500, 180);
intake2.move_relative(500, 180); */


}
/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
    while(true){
        setDriveMotors();
        setIntakeMotors();
        //setFlywheelMotors();
        setIndexerPiston();
        setEndgamePistons();
        setFlywheels(127);



        pros::delay(10);
    }
}
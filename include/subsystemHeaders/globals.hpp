#include "../main.h"

//motors
extern pros::Motor frontLeftDrive;
extern pros::Motor backLeftDrive;
extern pros::Motor frontRightDrive;
extern pros::Motor backRightDrive;
extern pros::Motor intake;
extern pros::Motor flywheel_inclinator;
extern pros::Motor flywheel1;
extern pros::Motor flywheel2;


//pneumatics
extern pros::ADIDigitalOut piston1;


//controllers
extern pros::Controller controller;
extern pros::Controller controller2;

//gyro and encoder
extern pros::Imu gyro;
extern pros::Rotation driveEncoder;
extern pros::Imu imu_sensor;
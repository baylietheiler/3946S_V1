#include "../../include/subsystemHeaders/globals.hpp"

pros::Motor frontLeftDrive(7,pros::E_MOTOR_GEARSET_06,false,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor backLeftDrive(18,pros::E_MOTOR_GEARSET_06,false,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor frontRightDrive(9,pros::E_MOTOR_GEARSET_06,true,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor backRightDrive(21,pros::E_MOTOR_GEARSET_06,true,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor intake(1,pros::E_MOTOR_GEARSET_18,false,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor flywheel_indexer(10,pros::E_MOTOR_GEARSET_36,true,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor flywheel1(14,pros::E_MOTOR_GEARSET_06,false,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor flywheel2(13,pros::E_MOTOR_GEARSET_06,true,pros::E_MOTOR_ENCODER_COUNTS);

pros::ADIDigitalOut flywheel_inclinator ('A');
pros::ADIDigitalOut endgame ('B');


pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::Controller controller2(pros::E_CONTROLLER_PARTNER);

pros::Imu gyro(9);
pros::Rotation driveEncoder(10);
pros::Imu imu_sensor(11);
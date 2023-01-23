#include "../../include/subsystemHeaders/globals.hpp"
//coral
pros::Motor frontLeftDrive(6,pros::E_MOTOR_GEARSET_06,true,pros::E_MOTOR_ENCODER_COUNTS);
//green
pros::Motor backLeftDrive(19,pros::E_MOTOR_GEARSET_06,false,pros::E_MOTOR_ENCODER_COUNTS);
//yellow
pros::Motor frontRightDrive(10,pros::E_MOTOR_GEARSET_06,false,pros::E_MOTOR_ENCODER_COUNTS);
//purple
pros::Motor backRightDrive(21,pros::E_MOTOR_GEARSET_06,true,pros::E_MOTOR_ENCODER_COUNTS);
//cornflower
pros::Motor intake1(14,pros::E_MOTOR_GEARSET_06,false,pros::E_MOTOR_ENCODER_COUNTS);
//blue
pros::Motor intake2(13,pros::E_MOTOR_GEARSET_06,false,pros::E_MOTOR_ENCODER_COUNTS);
//light pink
pros::Motor flywheel1(7,pros::E_MOTOR_GEARSET_06,false,pros::E_MOTOR_ENCODER_COUNTS);
//hot pink
pros::Motor flywheel2(1,pros::E_MOTOR_GEARSET_06,false,pros::E_MOTOR_ENCODER_COUNTS);

pros::ADIDigitalOut flywheel_indexer ('A');
pros::ADIDigitalOut endgame1 ('B');
pros::ADIDigitalOut endgame2 ('C');


pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::Controller controller2(pros::E_CONTROLLER_PARTNER);

pros::Imu gyro(9);
pros::Rotation driveEncoder(10);
pros::Imu imu_sensor(11);
#include "../../include/subsystemHeaders/globals.hpp"

pros::Motor frontLeftDrive(1,pros::E_MOTOR_GEARSET_06,true,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor backLeftDrive(2,pros::E_MOTOR_GEARSET_06,true,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor frontRightDrive(3,pros::E_MOTOR_GEARSET_06,true,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor backRightDrive(4,pros::E_MOTOR_GEARSET_06,false,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor intake(5,pros::E_MOTOR_GEARSET_06,false,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor flywheel_inclinator(6,pros::E_MOTOR_GEARSET_06,false,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor flywheel1(7,pros::E_MOTOR_GEARSET_06,true,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor flywheel2(8,pros::E_MOTOR_GEARSET_06,true,pros::E_MOTOR_ENCODER_COUNTS);

pros::ADIDigitalOut piston1 ('A');



pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::Controller controller2(pros::E_CONTROLLER_PARTNER);

pros::Imu gyro(9);
pros::Rotation driveEncoder(10);
pros::Imu imu_sensor(11);
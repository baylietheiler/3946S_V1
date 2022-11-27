#include "../../include/subsystemHeaders/globals.hpp"

pros::Motor frontLeftDrive(7,pros::E_MOTOR_GEARSET_36,true,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor backLeftDrive(8,pros::E_MOTOR_GEARSET_36,true,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor frontRightDrive(9,pros::E_MOTOR_GEARSET_36,true,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor backRightDrive(6,pros::E_MOTOR_GEARSET_36,false,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor intake(5,pros::E_MOTOR_GEARSET_18,false,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor flywheel_inclinator(6,pros::E_MOTOR_GEARSET_06,false,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor flywheel1(11,pros::E_MOTOR_GEARSET_36,true,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor flywheel2(12,pros::E_MOTOR_GEARSET_36,true,pros::E_MOTOR_ENCODER_COUNTS);

pros::ADIDigitalOut piston1 ('A');



pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::Controller controller2(pros::E_CONTROLLER_PARTNER);

pros::Imu gyro(9);
pros::Rotation driveEncoder(10);
pros::Imu imu_sensor(11);
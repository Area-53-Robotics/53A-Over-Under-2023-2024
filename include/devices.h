#pragma once
#include "main.h"

//Controller
inline pros::Controller master(pros::E_CONTROLLER_MASTER);

//Drive Train motors (front, back bottom, back top)
inline pros::MotorGroup left_motors ({-4, 12, -11});
inline pros::MotorGroup right_motors ({10, -19, 20});

//Intake motor
inline pros::Motor intake_motor (3);

//Catapult motor
inline pros::Motor slapper_motor (-18);

//Sensors
inline pros::Imu imu_sensor(8);
inline pros::Rotation rotation_sensor(16);

//Pneumatics
inline pros::adi::Pneumatics leftWingPistons('B', false);
inline pros::adi::Pneumatics rightWingPistons('A', false);
inline pros::adi::Pneumatics frontrightWingPistons('D', false);
inline pros::adi::Pneumatics frontleftWingPistons('E', false);
inline pros::adi::Pneumatics blockerPistons('C', false);

//Led
inline pros::adi::LED color('G', 12);
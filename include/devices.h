#pragma once
#include "main.h"

//Controller
inline pros::Controller master(pros::E_CONTROLLER_MASTER);

//Drive Train motors (front, back bottom, back top)
inline pros::MotorGroup left_motors ({-2, 12, -11});
inline pros::MotorGroup right_motors ({10, -19, 20});

//Intake motor
inline pros::Motor intake_motor (3);

//Catapult motor
inline pros::Motor slapper_motor (-18);

//Sensors
inline pros::Imu imu_sensor(19);
inline pros::Rotation rotation_sensor(16);

//Pneumatics
inline pros::adi::Pneumatics hWingPistons('A', false);
inline pros::adi::Pneumatics vWingPistons('B', false);
inline pros::adi::Pneumatics blockerPistons('C', false);

//Led
inline pros::adi::LED color('D', 12);
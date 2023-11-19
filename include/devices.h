#pragma once
#include "main.h"

//Motors
inline pros::Controller master(pros::E_CONTROLLER_MASTER);
inline pros::MotorGroup left_motors ({-1, 20, -11});
inline pros::MotorGroup right_motors ({10, -12, 17});

//Intake motors: left, right
inline pros::Motor intake_motor (9);
inline pros::Motor cata_motor (-13);

//Sensors
inline pros::Imu imu_sensor(19);
inline pros::Rotation rotation_sensor(16);

//Pneumatics
inline pros::adi::Pneumatics flapPistons('A', false);
inline pros::adi::Pneumatics armPiston('H', false);
#include "main.h"
#pragma once

//Motors
inline pros::Controller master(pros::E_CONTROLLER_MASTER);
inline pros::Motor_Group left_motors ({-1, 20, -11});
inline pros::Motor_Group right_motors ({10, -12, 17});

//Intake motors: left, right
inline pros::Motor_Group intake_motors ({-9, 4});

inline pros::Motor cata_motor (-13);

//Sensors
inline pros::Imu imu_sensor(19);
inline pros::Rotation rotation_sensor(16);

//Pneumatics
inline pros::ADIDigitalOut flapPistons ('A');
inline pros::ADIDigitalOut armPiston ('H');
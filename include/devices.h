#include "main.h"
#pragma once

//Motors
inline pros::Controller master(pros::E_CONTROLLER_MASTER);
inline pros::Motor_Group left_motors ({-1, 20, -11});
inline pros::Motor_Group right_motors ({10, -12, 17});

inline pros::Motor_Group intake_motors ({-5, 3});

inline pros::Motor cata_motor (-13);

//Sensors
inline pros::Imu imu_sensor(4);
inline pros::Rotation rotation_sensor(14);

//Pneumatics
inline pros::ADIDigitalOut flapPistons ('B');
inline pros::ADIDigitalOut armPiston ('C');
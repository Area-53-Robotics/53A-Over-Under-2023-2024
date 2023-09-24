#include "main.h"
#pragma once

inline pros::Controller master(pros::E_CONTROLLER_MASTER);
inline pros::Motor_Group left_motors ({-10, 2, -11});
inline pros::Motor_Group right_motors ({20, -12, 1});

inline pros::Motor_Group intake_motors ({-5, 3});

inline pros::Imu imu_sensor(4);

inline pros::ADIDigitalOut pistons ('B');
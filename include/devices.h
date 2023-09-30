#include "main.h"
#pragma once

//Motors
inline pros::Controller master(pros::E_CONTROLLER_MASTER);
inline pros::Motor_Group left_motors ({-10, 2, -11});
inline pros::Motor_Group right_motors ({20, -12, 1});

inline pros::Motor_Group intake_motors ({-5, 3});

inline pros::Motor_Group cata_motors ({-6, 7});

//Sensors
inline pros::Imu imu_sensor(4);
inline pros::Rotation rotation_sensor(8);

//Pneumatics
inline pros::ADIDigitalOut pistons ('B');
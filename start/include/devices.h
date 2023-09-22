#include "main.h"
#pragma once

inline pros::Controller master(pros::E_CONTROLLER_MASTER);
inline pros::Motor_Group left_motors ({-10, 2, -11});
inline pros::Motor_Group right_groups ({20, -12, 1});

inline pros::Motor left_intake_mtr(5, true);
inline pros::Motor right_intake_mtr(3, false);

inline pros::Imu imu_sensor(4);

inline pros::ADIAnalogOut left_flap_piston (6);
inline pros::ADIAnalogOut right_flap_piston (7);

inline pros::ADIAnalogOut left_piston (8);
inline pros::ADIAnalogOut right_piston (9);
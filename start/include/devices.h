#include "main.h"
#pragma once

inline pros::Controller master(pros::E_CONTROLLER_MASTER);
inline pros::Motor front_left_mtr(10, true);
inline pros::Motor middle_left_mtr(2, false);
inline pros::Motor back_left_mtr(11, true);
inline pros::Motor front_right_mtr(20, false);
inline pros::Motor middle_right_mtr(12, true);
inline pros::Motor back_right_mtr(1, false);

inline pros::Motor left_intake_mtr(5, true);
inline pros::Motor right_intake_mtr(3, false);
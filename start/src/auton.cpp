#include "main.h"
#include "devices.h"
#include "auton.h"

void moveBot (float msecs, int left_motor_speed, int right_motor_speed) {
    front_left_mtr = left_motor_speed;
	middle_left_mtr = left_motor_speed;
	back_left_mtr = left_motor_speed;
	front_right_mtr = right_motor_speed;
	middle_right_mtr = right_motor_speed;
	back_right_mtr = right_motor_speed;

    pros::delay(msecs);

    front_left_mtr = 0;
	middle_left_mtr = 0;
	back_left_mtr = 0;
	front_right_mtr = 0;
	middle_right_mtr = 0;
	back_right_mtr = 0;
}


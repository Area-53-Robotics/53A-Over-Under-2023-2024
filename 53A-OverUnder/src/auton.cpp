#include "main.h"
#include "devices.h"
#include "auton.h"

void moveBot (float distancin) {
    
	while (true) {
		float error = distancein - ;
		float kP = 0.5;
		float previousError = error;
		float derivative = error - previousError;
		float kD = 0.5;
		float power = error*kP + derivative*kD;

		front_left_mtr = power;
		middle_left_mtr = power;
		back_left_mtr = power;
		front_right_mtr = power;
		middle_right_mtr = power;
		back_right_mtr = power;
	}
}


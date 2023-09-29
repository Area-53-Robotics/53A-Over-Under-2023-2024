#include "main.h"
#include "devices.h"
#include "auton.h"
#include <cmath>

void moveBot (float distancein) {
    
	while (true) {
		
		float getRotation = imu_sensor.get_heading();

		float pi = M_PI;
		float circumference = pi*2*2;
		float position = (getRotation/360)*circumference;

		float error = distancein - position;
		float kP = 0.5;
		float previousError = error;
		float derivative = error - previousError;
		float kD = 0.5;
		float power = error*kP + derivative*kD;

		right_motors = power;
		left_motors  = power;
	}
}
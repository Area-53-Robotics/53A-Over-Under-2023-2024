#include "main.h"
#include "devices.h"
#include "auton.h"
#include <cmath>

void moveBot (float targetDistance, int timeout, int maxPower, bool reversed) {
	imu_sensor.tare();
	left_motors.tare_position();

	int movePower;
	const float kP = 0.6;
	const float kD = 0;
	int time_at_target = 0;
	int delay_time = 20;
	int start_time = pros::millis();
	int end_time = start_time + 1000 * timeout;

	float previousMoveError;

	while (true) {

		double getRotation = left_motors.get_position();

		float radius = 2;
		float circumference = M_PI*radius*2;
		float position = (getRotation/360)*circumference;

		float moveError = targetDistance - position;
		printf("%f\n", moveError);
		float moveDerivative = moveError - previousMoveError;
		float previousMoveError = moveError;
		movePower = (moveError*kP) + moveDerivative + 15;

		movePower += 20;
    	if (movePower > maxPower) {
      		movePower = maxPower;
    	}

		if (reversed) {
			movePower = -movePower;
		} else {
			movePower = movePower;
		}
    
		right_motors = movePower;
		left_motors  = movePower;

		if (moveError < 0.5 and moveError > -0.5) {
      		time_at_target += delay_time;
      		if (time_at_target > 500) {  // 500 Milliseconds
        		printf("move_pid met the target\n");
        		break;
      		}
    	} else {
      		time_at_target = 0;
    	}

		// Timeout
    	if (pros::millis() > end_time) {
      		printf("move_pid timed out\n");
      		break;
    	}

	}
}

void turnBot (float targetRotation, int timeout, int maxPower) {
	imu_sensor.tare();
	left_motors.tare_position();

	float delay_time = 10;
  	double end_time = pros::millis() + timeout * 1000;
  	double time_elapsed = 0;
  	double time_at_target = 0;
	float previousTurnError;

  	const double kp = 0.8;
  	const double kd = 0.5;

	while (true) {

		float getSensorData = imu_sensor.get_rotation();

		float turnError = targetRotation - getSensorData;
		float turnDerivative = turnError - previousTurnError;
		float previousTurnError = turnError;
		float power = turnError*kp + turnDerivative*kd;

		if (power > maxPower) {
			power = maxPower;
		}

		/*
		if (reversed) {
			power = -power;
		} else {
			power = power;
		}
		*/

		int leftPower = power;
		int rightPower = -power;

		right_motors = rightPower;
		left_motors  = leftPower;

		// check exit conditions
    	if (turnError < 0.5 and turnError > -0.5) {
    		time_at_target += delay_time;
    		if (time_at_target > 500) { 
        		printf("turn_pid met the target\n");
        		break;
    		}
    	} else {
      		time_at_target = 0;
    	}

    	// Timeout
    	if (pros::millis() > end_time) {
      		printf("turn_pid timed out\n");
     		break;
    	}
	}
}


void runIntake (bool running, int power) {

	if (running) {

		intake_motor = power;

	} else {

		intake_motor.brake();
	}

}

void runCata (float msecs, int power) {

	bool cata = true;

	while (cata) {

		cata_motor = power;
		pros::delay(msecs);
		cata_motor = 0;

		break;
	}

}


void cataRotationReset (float time) {
    const float MIN_CATA_READY_ANGLE = 35200;
	const float MAX_CATA_READY_ANGLE = 37000;

	bool isCataReady = false;

	float timeStart = pros::millis();
	float timeEnd = timeStart + time;
	
	while (pros::millis() < timeEnd) {
		int catapultPosition = rotation_sensor.get_position();

		if (catapultPosition < MIN_CATA_READY_ANGLE or
      		catapultPosition > MAX_CATA_READY_ANGLE) {
    		isCataReady = false;
  		} else {
    		isCataReady =  true;
		}

		if (!isCataReady) {
			cata_motor.move(60);
		} else {
			cata_motor.move(0);
		}

		if (pros::millis() > timeEnd) {
			break;
		}

	}
  	
}


void climbArm (bool state) {

	armPiston.set_value(state);

}

void wings (bool state) {

	flapPistons.set_value(state);

}

void noAuton () {

}

void resetandCata (bool onOff) {
	imu_sensor.tare();
	float initialSensorData = imu_sensor.get_rotation();
	const double kp = 0.8;
	float sensorData;
	float error;
	float derivative;
	float previousError;
	float power;

	while (onOff) {
		sensorData = imu_sensor.get_rotation();
		if (sensorData != initialSensorData) {
			error = initialSensorData - sensorData;
			derivative = error - previousError;
			previousError = error;
			power = error*kp + derivative;

			int leftPower = power;
			int rightPower = -power;

			right_motors = rightPower;
			left_motors  = leftPower;

			cata_motor = 100;
			
			break;
		} else {
			power = 0;
			cata_motor = 0;
			break;
		}
	}
}
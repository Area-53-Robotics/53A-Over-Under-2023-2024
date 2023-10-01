#include "main.h"
#include "devices.h"
#include "auton.h"
#include <cmath>

float kP = 0.5;
float kD = 0.5;

void moveBot (float distancein) {

	float movePower = 100;

	while (movePower > 0) {
		
		imu_sensor.reset();

		float getRotation = imu_sensor.get_heading();

		float pi = M_PI;
		float circumference = pi*2*2;
		float position = (getRotation/360)*circumference;

		float moveError = distancein - position;
		float previousMoveError = moveError;
		float moveDerivative = moveError - previousMoveError;
		movePower = moveError*kP + moveDerivative*kD;

		right_motors = movePower;
		left_motors  = movePower;
	}
}

void turnBot (float turnDegree) {

	float turnPower = 100;

	while (turnPower > 0) {

		imu_sensor.reset();

		float getSensorData = imu_sensor.get_rotation();

		float turnError = turnDegree - getSensorData;
		float previousTurnError = turnError;
		float turnDerivative = turnError - previousTurnError;
		float turnPower = turnError*kP + turnDerivative*kD;

		right_motors = -turnPower;
		left_motors  = turnPower;
	}
}

void runIntake (float runmsec, bool speed) {

	intake_motors = speed;

	pros::delay(runmsec);

	intake_motors = 0;

}

void runCata () {

	rotation_sensor.reset();
	cata_motor = 127;
	pros::delay(40);
	cata_motor = 0;

}
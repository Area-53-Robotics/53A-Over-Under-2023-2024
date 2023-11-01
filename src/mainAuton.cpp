#include "main.h"
#include "devices.h"
#include "auton.h"
#include <cmath>

float kP = 0.27;
float kD = 0.35;

void moveBot (float distancein) {

	float movePower = 100;

	while (movePower > 0) {

		double getRotation = left_motors.get_positions()[0];

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

		float getSensorData = imu_sensor.get_rotation();

		float turnError = turnDegree - getSensorData;
		float previousTurnError = turnError;
		float turnDerivative = turnError - previousTurnError;
		float turnPower = turnError*kP + turnDerivative*kD;

		right_motors = -turnPower;
		left_motors  = turnPower;
	}
}

void runIntake (float runmsec, int speed) {

	intake_motors = speed;

	pros::delay(runmsec);

	intake_motors = 0;

}

void runCata (float msecs, int speed) {

	cata_motor = speed;
	pros::delay(msecs);
	cata_motor = 0;

}

void cataRotationReset (float time) {
	int rotationPosition = rotation_sensor.get_position();
    int target = 0;

	while (rotationPosition > 0) {
		float rotationError = target - rotationPosition;
		float previousRotationError = rotationError;
		float rotationDerivative = rotationError - previousRotationError;
		float rkP = 0.5;
		float rkD = 0.5;
		float rotationPower = rotationError*rkP + rotationDerivative*rkD;
        cata_motor = rotationPower;
	}
}

void climbArm (bool open) {

	armPiston.set_value(open);

}

void flaps (bool value) {

	flapPistons.set_value(value);

}
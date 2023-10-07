#include "main.h"
#include "devices.h"
#include "auton.h"

void autonFromLSP () {

    while (true) {

        //Gets position of rotation sensor
		int rotationPosition = rotation_sensor.get_position();

		//resets cata if it's not in launching position
		if (rotationPosition != 0) {
			rotation_sensor.set_position(0);
        }

    }
    
    turnBot(-90);
    moveBot(12);
    turnBot(-45);
    moveBot(1);
    runIntake(500, 127);
    turnBot(180);
    moveBot(24);
    runIntake(500, -127);
    turnBot(180);
    moveBot(48);
    runIntake(500, 127);
    turnBot(180);
    moveBot(48);
    runIntake(500, -127);
    turnBot(90);
    moveBot(72);
    turnBot(90);
    moveBot(24);
    turnBot(180);
    climbArm(true);


}
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
    
    moveBot(10);
    turnBot(10);


}
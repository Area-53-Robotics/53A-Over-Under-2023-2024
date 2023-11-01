#include "main.h"
#include "devices.h"
#include "cata.h"

/*
enum class CatapultState {
	Resetting,
    Ready,
	ShortFire,
    ConstantFire,
};

CatapultState state = CatapultState::Resetting;

void cataDefine() {

    bool cataReady = false;
    
    if (state == CatapultState::Resetting) {
        //Gets position of rotation sensor
        int rotationPosition = rotation_sensor.get_position();

        if (rotationPosition > 0 and rotationPosition < 35000) {
	        cata_motor = 50;
            cataReady = false;
        }
        else {
            state = CatapultState::Ready;
            cataReady = true;
        }
	} else if (state == CatapultState::Ready) {
		cata_motor = 0;
	} else if (state == CatapultState::ShortFire) {
		if (cataReady == true) {
		    cata_motor = 127;
			pros::delay(20);
			cataReady = false;
		} else if (cataReady == false) {
			state = CatapultState::Resetting;
		}
	} else if (state == CatapultState::ConstantFire) {
		cata_motor = 127;
	}

}
    

void cata () {

    while (true) {
        if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
			cataSpin = !cataSpin;
    	}

		//Shoots cata when pressed
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
			shortFire = true;
    	}
		else {
			shortFire = false;
		}

		if (cataSpin == true) {
			state == CatapultState::ConstantFire;
		} else if (shortFire == true) {
			state == CatapultState::ShortFire;
		}
		else {
			state = CatapultState::Resetting;
		}

    }

}
*/
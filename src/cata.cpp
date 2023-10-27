#include "main.h"
#include "devices.h"
#include "cata.h"

enum class CatapultState {
	Resetting,
    Ready,
	ShortFire,
    ConstantFire,
};

CatapultState state = CatapultState::Resetting;

void cata () {

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
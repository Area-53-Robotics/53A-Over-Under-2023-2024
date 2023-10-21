#include "main.h"
#include "devices.h"
#include "cata.h"

bool cataSpin = false;
bool cataSpinOnce = false;

void cataReset () {

    enum class CatapultState {
	        Loading,
	        Ready,
	        FireOnce,
	        ConstantFire,
        };
		
        CatapultState state = CatapultState::Loading;

        //Catapult
        //Gets position of rotation sensor
        int rotationPosition = rotation_sensor.get_position();
    
    if (rotationPosition > 0 and rotationPosition < 35000) {
	        state = CatapultState::Loading;
}
void cata () {
    while (true) {
        //Catapult classes
        enum class CatapultState {
	        Loading,
	        Ready,
	        FireOnce,
	        ConstantFire,
        };
		
        CatapultState state = CatapultState::Loading;

        //Catapult
        //Gets position of rotation sensor
        int rotationPosition = rotation_sensor.get_position();

        if (state == CatapultState::Loading) {
	        // load the catapult
	        cata_motor = 50;
        } else if (state == CatapultState::Ready) {
	        cata_motor = 0;
        } else if (state == CatapultState::FireOnce) {
	        cata_motor = 127;
	        pros::delay(100);
	        cata_motor = 0;
        } else if (state == CatapultState::ConstantFire) {
	        cata_motor = 127;
        }
		
        //printf("%i\n",rotationPosition);
        //printf("%i\n", state);
		
        //Always shoots cata
        if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
	       cataSpin = !cataSpin;
        }

        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
	        cataSpin = false;
	        cataSpinOnce = !cataSpinOnce;
	        pros::delay(100);
	        cataSpinOnce = false;
        }
	
        printf("%i\n", cataSpin);

        if (cataSpin == true) {
	        state = CatapultState::ConstantFire;
        } else if (rotationPosition > 0 and rotationPosition < 35000) {
	        state = CatapultState::Loading;
        } else if (cataSpinOnce == true) {
	        //shoots cata when pressed
	        state = CatapultState::FireOnce;
	        pros::delay(100);
	        state = CatapultState::Ready;
        } else {
	        state = CatapultState::Ready;
        }       
    }
}


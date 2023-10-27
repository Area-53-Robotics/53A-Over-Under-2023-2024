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

//Example from 53E

/*
#include "main.h"
#include "devices.h"
#include "cata.h"

void Catapult::fire() {
  if (get_state() == CatapultState::Ready) {
    printf("firing\n");
    set_state(CatapultState::Firing);
  }
}

void Catapult::toggle_repeating() {
  if (!(get_state() == CatapultState::Repeating)) {
    set_state(CatapultState::Repeating);
  } else {
    set_state(CatapultState::Loading);
  }
}

void Catapult::loop() {
  switch (get_state()) {
    case CatapultState::Idle: {
      // This mode is meant to to completely disable the catapult
      motor->move(0);
      break;
    }

    case CatapultState::Loading: {
      if (limit_switch->get_value()) {
        set_state(CatapultState::Ready);
      }

      motor->move(100);
      break;
    }

    case CatapultState::Ready: {
      if (!limit_switch->get_value()) {
        set_state(CatapultState::Loading);
      }

      motor->move(0);
      break;
    }

    case CatapultState::Firing: {
      printf("Firing\n");
      while (limit_switch->get_value()) {
        motor->move(127);
      }
      set_state(CatapultState::Loading);
      break;
    }

    case CatapultState::Repeating: {
      // motor->move(127);
      break;
    }
  }
  pros::delay(20);

*/

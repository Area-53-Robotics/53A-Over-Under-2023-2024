#include "main.h"
#include "auton.h"
#include "leds.h"
#include "devices.h"
#include <sys/_intsup.h>
#include <iostream>
#include "robodash/views/selector.hpp"
#include "robodash/views/image.hpp"


int starting_point = 0;


/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */

void on_center_button() {
  static bool pressed = false;
  pressed = !pressed;
  if (pressed) {
	starting_point = 3;
    pros::lcd::set_text(1, "Programming Skills");
  } 
}

void on_right_button() {
  static bool pressed = false;
  pressed = !pressed;
  if (pressed) {
	starting_point = 2;
    pros::lcd::set_text(1, "Right Auton");
  } 
}

void on_left_button() {
  static bool pressed = false;
  pressed = !pressed;
  if (pressed) {
	starting_point = 1;
    pros::lcd::set_text(1, "Left Auton");
  } 
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  /*
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)) {
    starting_point++;
  }
  if (starting_point > 3) {
	starting_point = 0;
  }

  printf("%i\n", starting_point);
  */
  if (starting_point == 0) {
	pros::lcd::set_text(1, "No Auton");
  } else if (starting_point == 1) {
	pros::lcd::set_text(1, "Left Auton");
  } else if (starting_point == 2) {
	pros::lcd::set_text(1, "Right Auton");
  } else {
	pros::lcd::set_text(1, "Skills Auton");
  }
  pros::lcd::initialize();
  pros::lcd::set_text(1, "Started");

  pros::lcd::register_btn0_cb(on_left_button);
  pros::lcd::register_btn1_cb(on_center_button);
  pros::lcd::register_btn2_cb(on_right_button);

  imu_sensor.reset();
  pros::lcd::set_text(3, "IMU Calibrated");

  blockerPistons.set_value(false);

  /*
  rd::initialize();
  rd::register_views({ &console, &selector });
  selector.add_autons({
      {"Left Starting Point", &autonFromLSP},
      {"Right Starting Point", &autonFromRSP},
	  {"Skills Auton", &skillsAuton},
	  {"No Auton", &noAuton}
   });
  */
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {

  if (starting_point == 1) {
    pros::lcd::set_text(2, "Auton from Left Starting Point");
    autonFromLSP();
  }

  if (starting_point == 2) {
    pros::lcd::set_text(2, "Auton from Right Starting Point");
    autonFromRSP();
  }

  if (starting_point == 3) {
	  pros::lcd::set_text(2, "Skills Auton Start");
	  skillsAuton();
  }

  if (starting_point == 0) {
	  pros::lcd::set_text(2, "Do Nothing");
    noAuton();
  }

  //selector.do_auton();
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

// Angles are in centidegrees

const float MIN_CATA_READY_ANGLE = 4000;
const float MAX_CATA_READY_ANGLE = 5500;

bool isCataReady(float slapperPosition) {
  if (slapperPosition < MIN_CATA_READY_ANGLE or
      slapperPosition > MAX_CATA_READY_ANGLE) {
    return false;
  } else {
    return true;
  }
}

void opcontrol() {

  slapper_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  // User Control State Variables
  bool leftWingsPistonValue = false;
  bool rightWingsPistonValue = false;
  bool wings = false;
  bool blockerPistonValue = false;
  bool frontWings = false;

  //LEDs
  bool ledsOn = false;

  //time stuff
  int count = 1;
  int timeCount = 0;

  //slapper
  bool slapperstate = false;

  blockerPistons.set_value(false);
  
  enum class SlapperState {
    Resetting,
    Ready,
    ConstantFire,
  };

  SlapperState slapperState = SlapperState::Resetting;

  while (true) {
    // Drivetrain
    // Arcade Drive
    int left =
        master.get_analog(ANALOG_LEFT_Y) + master.get_analog(ANALOG_RIGHT_X);
    int right =
        master.get_analog(ANALOG_LEFT_Y) - master.get_analog(ANALOG_RIGHT_X);

    left_motors = left;
    right_motors = right;

    // Controls Intake
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      intake_motor.move(-127);
    } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      intake_motor.move(127);
    } else {
      intake_motor.move(0);
    }

    // Pistons
    // Controls Wings
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)) {
      leftWingsPistonValue = !leftWingsPistonValue;
      leftWingPistons.set_value(leftWingsPistonValue);
    }
    printf("%i", leftWingsPistonValue);

    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) {
      rightWingsPistonValue = !rightWingsPistonValue;
      rightWingPistons.set_value(rightWingsPistonValue);
    }

    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
      frontWings = !frontWings;
      frontrightWingPistons.set_value(frontWings);
      frontleftWingPistons.set_value(frontWings);
    }

    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
      wings = !wings;
      rightWingPistons.set_value(wings);
      leftWingPistons.set_value(wings);
    }

    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
      blockerPistonValue = !blockerPistonValue;
      blockerPistons.set_value(blockerPistonValue);
    }

    //Slapper
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
      slapperstate = !slapperstate;
    } 

    //Blocker/Climb
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
      blockerPistonValue = !blockerPistonValue;
      blockerPistons.set_value(blockerPistonValue);
    }

    if (slapperstate == true) {
      slapperState = SlapperState::ConstantFire;
    } else {
      slapperState = SlapperState::Resetting;
    }

    int slapperPosition = rotation_sensor.get_angle();
  
    switch (slapperState) {
    case SlapperState::Resetting:
      slapper_motor.move(80);
      if (isCataReady(slapperPosition)) {
        slapperState = SlapperState::Ready;
      }
      break;
    case SlapperState::Ready:
      if (!isCataReady(slapperPosition)) {
        slapperState = SlapperState::Resetting;
      }
      slapper_motor.brake();
      break;
    case SlapperState::ConstantFire:
      slapper_motor.move(127);
      break;
    }
	
/*
  // Print out the temperature of Motors
  
  double rightDriveTemperatures = right_motors.get_temperature();
	
	//pros::lcd::print(5, , 2);

	if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
      ledsOn = !ledsOn;
    }

	if (ledsOn == true) {
		blueLEDs();
		
	} else {
		color.clear_all();
	}

    pros::delay(20); 
  }
*/
  }
}
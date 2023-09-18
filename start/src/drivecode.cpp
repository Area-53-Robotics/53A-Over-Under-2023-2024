#include "main.h"
#include "devices.h"
#include "auton.h"

bool starting_point = true;

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
		pros::lcd::set_text(1, "Left Starting Point");
		starting_point = true;
	} else {
		pros::lcd::set_text(1, "Right Starting Point");
		starting_point = false;
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Started");

	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {

}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {

}

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
	if (starting_point == true) {
		moveBot(20, -127, 127);
		pros::lcd::set_text(2, "Auton from Left Starting Point");
	}

	if (starting_point == false) {
		pros::lcd::set_text(2, "Auton from Right Starting Point");
	}
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

void opcontrol() {
	
	while (true) {

    	int left = master.get_analog(ANALOG_RIGHT_Y) + master.get_analog(ANALOG_LEFT_X);
		int right = master.get_analog(ANALOG_RIGHT_Y) - master.get_analog(ANALOG_LEFT_X);

		front_left_mtr = left;
		middle_left_mtr = left;
		back_left_mtr = left;
		front_right_mtr = right;
		middle_right_mtr = right;
		back_right_mtr = right;

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      		left_intake_mtr = -50;
			right_intake_mtr = -50;
    	}
		else {
			left_intake_mtr = 0;
			right_intake_mtr = 0;
		}
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      		left_intake_mtr = 50;
			right_intake_mtr = 50;
    	}
		else {
			left_intake_mtr = 0;
			right_intake_mtr = 0;
		}

		pros::delay(20);
	}
}
#include "main.h"
#include "devices.h"
#include "auton.h"

static bool starting_point = true;

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

  	imu_sensor.reset();
	pros::lcd::set_text(3, "IMU Calibrated");

	rotation_sensor.reset();
	pros::lcd::set_text(4, "Rotation Sensor Calibrated");

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
	//resets sensors
	imu_sensor.reset();
	rotation_sensor.reset();

	if (starting_point == true) {
		pros::lcd::set_text(2, "Auton from Left Starting Point");
		autonFromLSP();
	}

	if (starting_point == false) {
		pros::lcd::set_text(2, "Auton from Right Starting Point");
		autonFromRSP();
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

	//User Control Booleans
	bool flapsPistonValue = false;
	bool cataSpin = false;
	bool armPistonValue = false;
	bool shooting = false;
	bool cataSpinOnce = false;

	//Catapult classes
	enum class CatapultState {
			Loading,
			Ready,
			FireOnce,
			ConstantFire,
		};
		
		CatapultState state = CatapultState::Loading;
	
	while (true) {
		
		//Motors
		//Arcade Drive
    	int left = master.get_analog(ANALOG_RIGHT_Y) + master.get_analog(ANALOG_LEFT_X);
		int right = master.get_analog(ANALOG_RIGHT_Y) - master.get_analog(ANALOG_LEFT_X);

		left_motors = left;
		right_motors = right;

		//Controls Intake
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      		intake_motors = 127;
    	}
		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
			intake_motors = -127;
		}
		else {
			intake_motors = 0;
		}

		//Pistons
		//Controls Flaps
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
      		flapsPistonValue = !flapsPistonValue;
			flapPistons.set_value(flapsPistonValue);
    	}

		//Controls arm
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) {
      		armPistonValue = !armPistonValue;
			armPiston.set_value(armPistonValue);
    	}

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

		pros::delay(20);
	}

}
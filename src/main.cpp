#include "main.h"
#include "auton.h"
#include "cata.h"
#include "devices.h"
#include <cstdio>
#include <functional>

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

// Angles are in centidegrees
const float MIN_CATA_READY_ANGLE = 32000;
const float MAX_CATA_READY_ANGLE = 30000;

bool isCataReady(float cataPosition) {
  if (cataPosition > MIN_CATA_READY_ANGLE or
      cataPosition < MAX_CATA_READY_ANGLE) {
    return false;
  } else {
    return true;
  }
}

void opcontrol() {
  cata_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  // User Control State Variables
  bool flapsPistonValue = false;
  bool armPistonValue = false;

  enum class CatapultState {
    Resetting,
    Ready,
    SingleFire,
    ConstantFire,
  };

  CatapultState catapultState = CatapultState::Resetting;

  // FIXME: use these
  float cP = 0.5;
  float cD = 0.5;

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
      intake_motors = 127;
    } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      intake_motors = -127;
    } else {
      intake_motors = 0;
    }

    // Pistons
    // Controls Flaps
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
      flapsPistonValue = !flapsPistonValue;
      flapPistons.set_value(flapsPistonValue);
    }

    // Controls arm
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) {
      armPistonValue = !armPistonValue;
      armPiston.set_value(armPistonValue);
    }

    // Toggle repeatedly firing the catapult
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
      if (catapultState == CatapultState::ConstantFire) {
        catapultState = CatapultState::Resetting;
      } else {
        catapultState = CatapultState::ConstantFire;
      }
    }

    // Shoots catapult when pressed
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
      if (catapultState == CatapultState::Ready) {
        catapultState = CatapultState::SingleFire;
      }
    }

    float catapultPosition = catapult_rotation_sensor.get_angle();

    switch (catapultState) {
    case CatapultState::Resetting:
      cata_motor.move(127);
      if (isCataReady(catapultPosition)) {
        catapultState = CatapultState::Ready;
      }
      break;
    case CatapultState::Ready:
      if (!isCataReady(catapultPosition)) {
        catapultState = CatapultState::Resetting;
      }
      cata_motor.brake();
      break;
    case CatapultState::SingleFire:
      cata_motor.move(127);
      if (!isCataReady(catapultPosition)) {
        catapultState = CatapultState::Resetting;
      }
      break;
    case CatapultState::ConstantFire:
      cata_motor.move(127);
      break;
    }

    // Print out the temperature of Motors
    std::vector<double> temperatures = left_motors.get_temperatures();
    std::vector<double> temperatures2 = right_motors.get_temperatures();

    master.print(0, 0, "Temperature %f", temperatures);
    master.print(1, 0, "Temperature %f", temperatures2);

    pros::delay(50); // FIXME: change back to 20
  }
}


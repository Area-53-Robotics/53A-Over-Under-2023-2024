#include "main.h"
#include "devices.h"
#include "auton.h"

void autonFromLSP () {
    
    runIntake(true, -127);
    pros::delay(100);
    runIntake(true, 127);
    moveBot(42, 1, 127, false);
    pros::delay(500);
    moveBot(30, 1, 100, true);
    turnBot(70, 1, 50);
    runIntake(true, -127);
    pros::delay(500);
    turnBot(-55, 1, 50);
    runIntake(true, 127);
    moveBot(340, 1, 127, false);

}
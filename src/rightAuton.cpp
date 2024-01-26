#include "main.h"
#include "devices.h"
#include "auton.h"

void autonFromRSP () {

    runIntake(true, 127);
    moveBot(40, 1, 127, false);
    pros::delay(500);
    moveBot(35, 1, 100, true);
    turnBot(50, 1, 60);
    runIntake(true, -127);
    pros::delay(500);
    runIntake(true, 127);
    turnBot(-120, 1, 100);
    moveBot(20, 1, 127, false);
    pros::delay(1000);
    moveBot(20, 1, 127, true);
    rightwings(true);
    turnBot(-40, 1, 50);
    moveBot(5, 1, 50, true);
    rightwings(false);
    moveBot(5, 1, 50, true);
    turnBot(-100, 1, 50);
    moveBot(20, 1, 127, true);

}
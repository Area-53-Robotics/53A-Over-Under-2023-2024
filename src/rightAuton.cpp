#include "main.h"
#include "devices.h"
#include "auton.h"

void autonFromRSP () {

    blocker(false);
    runIntake(true, -127);
    pros::delay(100);
    runIntake(true, 127);
    moveBot(5, 1, 127, false);
    moveBot(8, 1, 127, true);
    runIntake(false, 0);
    turnBot(-30, 1, 50);
    leftwings(true);
    moveBot(5, 1, 50, true);
    leftwings(false);
    turnBot(-70, 1, 50);
    moveBot(40, 1, 127, true);
    moveBot(3, 1, 50, false);
    pros::delay(50);
    moveBot(40, 1, 127, true);
    moveBot(3, 1, 50, false);
    turnBot(170, 1, 127);
    runIntake(true, -127);
    moveBot(45, 1, 127, false);
    moveBot(3, 1, 127, true);

}
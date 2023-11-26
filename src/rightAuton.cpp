#include "main.h"
#include "devices.h"
#include "auton.h"

void autonFromRSP () {

    moveBot(20, 2, 100, false);
    runIntake(true, -60);
    pros::delay(750);
    runIntake(false, 0);
    turnBot(-45, 2, 50);
    moveBot(20, 2, 127, false);
    runIntake(true, 127);
    moveBot(10, 1, 100, false);
    turnBot(-45, 2, 50);
    runIntake(false, 0);
    wings(true);
    moveBot(30, 2, 100, true);
    wings(false);
    moveBot(10, 2, 100, false);
    turnBot(180, 2, 50);
    runIntake(true, -60);
    moveBot(8, 2, 100, false);
    pros::delay(500);
    runIntake(false, 0);
    turnBot(135, 2, 50);
    moveBot(25, 2, 100, false);
    runIntake(true, 127);
    turnBot(20, 1, 50);
    moveBot(10, 2, 100, false);
    pros::delay(500);
    turnBot(180, 2, 60);
    runIntake(true, -127);
    moveBot(25, 2, 100, false);
    pros::delay(100);
    runIntake(false, 0);
    moveBot(10, 1, 100, true);

}
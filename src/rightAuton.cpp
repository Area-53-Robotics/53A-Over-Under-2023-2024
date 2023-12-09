#include "main.h"
#include "devices.h"
#include "auton.h"

void autonFromRSP () {

    moveBot(14, 1, 127, false);
    runIntake(true, -60);
    pros::delay(750);
    runIntake(false, 0);
    moveBot(5, 1, 127, true);
    turnBot(-37, 1, 50);
    moveBot(15, 1, 127, false);
    runIntake(true, 127);
    moveBot(8, 1, 127, false);
    turnBot(-45, 1, 50);
    runIntake(false, 0);
    wings(true);
    moveBot(30, 1, 127, true);
    wings(false);
    moveBot(10, 1, 127, false);
    turnBot(180, 1, 50);
    runIntake(true, -60);
    moveBot(8, 1, 127, false);
    pros::delay(500);
    runIntake(false, 0);
    turnBot(135, 1, 50);
    moveBot(25, 1, 127, false);
    runIntake(true, 127);
    turnBot(20, 1, 50);
    moveBot(10, 1, 127, false);
    pros::delay(500);
    turnBot(150, 1, 60);
    runIntake(true, -127);
    moveBot(25, 1, 127, false);
    pros::delay(100);
    runIntake(false, 0);
    moveBot(10, 1, 127, true);

}
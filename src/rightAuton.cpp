#include "main.h"
#include "devices.h"
#include "auton.h"

void autonFromRSP () {

    blocker(false);
    runIntake(true, 127);
    moveBot(5, 1, 127, false);
    moveBot(8, 1, 127, true);
    runIntake(false, 0);
    turnBot(-30, 1, 50);
    leftwings(true);
    moveBot(10, 1, 50, true);
    leftwings(false);
    moveBot(5, 1, 50, true);
    turnBot(-60, 1, 50);
    moveBot(40, 1, 127, true);
    moveBot(3, 1, 50, false);
    pros::delay(50);
    moveBot(40, 1, 127, true);
    moveBot(3, 1, 50, false);
    turnBot(168, 1, 127);
    runIntake(true, -127);
    moveBot(40, 1, 127, false);
    moveBot(2, 1, 30, true);
    runIntake(false, 0);
    turnBot(-165, 1, 127);
    moveBot(40, 1, 127, true);
    moveBot(3, 1, 50, false);
    turnBot(90, 1, 50);
    moveBot(20, 1, 127, false);
    /*
    turnBot(-63, 1, 50);
    moveBot(10, 2, 127, false);
    turnBot(-47, 1, 50);
    moveBot(23, 1, 50, false);
    rightwings(true);
    turnBot(180, 1, 127);
    */

}
#include "main.h"
#include "devices.h"
#include "auton.h"

void autonFromLSP () {
    
    blocker(false);
    runIntake(true, -127);
    pros::delay(100);
    runIntake(true, 127);
    moveBot(38, 1, 127, false);
    pros::delay(700);
    moveBot(32, 1, 127, true);
    turnBot(70, 1, 50);
    runIntake(true, -127);
    pros::delay(500);
    moveBot(2, 1, 15, true);
    turnBot(55, 1, 50);
    moveBot(3, 1, 127, true);
    leftwings(true);
    moveBot(20, 1, 127, false);
    leftwings(false);
    moveBot(2, 1, 20, true);
    turnBot(-47, 1, 50);
    moveBot(28, 1, 127, false);
    
}
#include "main.h"
#include "devices.h"
#include "auton.h"

void autonFromRSP () {
    
    runIntake(true, -127);
    pros::delay(100);
    runIntake(true, 127);
    moveBot(40, 1, 127, false);
    pros::delay(500);
    moveBot(35, 1, 100, true);
    turnBot(50, 1, 60);
    runIntake(true, -127);
    pros::delay(500);
    runIntake(true, 127);
    turnBot(-120, 1, 100);
    moveBot(18, 1, 127, false);
    pros::delay(500);
    moveBot(10, 1, 127, true);
    rightwings(true);
    swing(false, -50, 1, 50);
    moveBot(5, 1, 50, true);
    rightwings(false);
    moveBot(10, 1, 50, true);
    moveBot(4, 1, 50, false);
    swing(false, -90, 1, 50);
    moveBot(40, 1, 127, true);
    moveBot(7, 1, 50, false);
    moveBot(40, 1, 127, true);
    moveBot(7, 1, 50, false);
    turnBot(185, 1, 127);
    runIntake(true, -127);
    moveBot(40, 1, 127, false);
    moveBot(3, 1, 127, true);
    moveBot(40, 1, 127, false);
    moveBot(5, 1, 127, true);

}
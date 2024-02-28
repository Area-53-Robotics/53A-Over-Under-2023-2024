#include "main.h"
#include "devices.h"
#include "auton.h"

void autonFromLSP () {
    
    blocker(false);
    runIntake(true, -127);
    pros::delay(100);
    runIntake(false, 0);
    moveBot(5, 1, 20, true);
    rightwings(true);
    turnBot(-90, 1, 50);
    rightwings(false);
    turnBot(45, 1, 50);
    curveBot(10, 1, 90, false, 40, true);
    turnBot(-40, 1, 50);
    runIntake(true, -127);
    moveBot(15, 1, 100, false);
    //moveBot(15, 1, 50, false);
    
}
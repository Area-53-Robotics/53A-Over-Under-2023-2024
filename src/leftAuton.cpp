#include "main.h"
#include "devices.h"
#include "auton.h"

void autonFromLSP () {
    
    
    runIntake(true, -127);
    pros::delay(100);
    runIntake(true, 127);
    moveBot(45, 1, 127, false);
    pros::delay(500);
    moveBot(55, 1, 127, true);
    turnBot(70, 1, 50);
    runIntake(true, -127);
    pros::delay(500);
    /*
    moveBot(1, 1, 15, true);
    turnBot(-55, 1, 50);
    runIntake(true, 127);
    moveBot(53, 1, 127, false);
    pros::delay(500);
    //swing(true, 20, 1, 50);
    moveBot(40, 1, 127, true);
    turnBot(70, 1, 50);
    runIntake(true, -127);
    pros::delay(500);
    */
    swing(true, 20, 1, 50);
    moveBot(40, 1, 127, false);
    
}
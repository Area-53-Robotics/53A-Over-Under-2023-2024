#include "main.h"
#include "devices.h"
#include "auton.h"

void autonFromLSP () {
    
    blocker(false);
    runIntake(true, -127);
    pros::delay(100);
    runIntake(true, 127);
    moveBot(40, 1, 127, false);
    pros::delay(700);
    moveBot(32, 1, 127, true);
    turnBot(70, 1, 50);
    runIntake(true, -127);
    pros::delay(500);
    moveBot(2, 1, 15, true);
    turnBot(60, 1, 50);
    moveBot(6, 1, 127, true);
    /*
    moveBot(5, 1, 100, false);
    moveBot(30, 1, 127, true);
    */
    moveBot(3, 1, 100, false);
    leftwings(true);
    moveBot(14, 1, 100, false);
    leftwings(false);
    turnBot(-70, 1, 50);
    moveBot(10, 1, 50, false);
    moveBot(15, 1, 50, false);


    /*
    swing(true, -15, 1, 35);
    leftwings(true);
    runIntake(true, -127);
    moveBot(3, 1, 50, false);
    leftwings(false);
    turnBot(-60, 1, 50);
    moveBot(18, 1, 60, false);
    */
}
#include "main.h"
#include "devices.h"
#include "auton.h"

void autonFromRSP () {

    moveBot(8, 1, 100, false);
    runIntake(true, -60);
    pros::delay(1500);
    runIntake(false, 0);
    moveBot(3, 1, 20, true);
    turnBot(-37, 1, 50);
    moveBot(15, 1, 127, false);
    runIntake(true, 127);
    moveBot(8, 1, 127, false);
    turnBot(-45, 1, 50);
    runIntake(false, 0);
    leftwings(true);
    rightwings(true);
    moveBot(30, 1, 127, true);
    leftwings(false);
    rightwings(false);
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
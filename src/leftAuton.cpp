#include "main.h"
#include "devices.h"
#include "auton.h"

void autonFromLSP () {
    
    moveBot(20, 2, 90, false);
    turnBot(-90, 1, 50);
    leftwings(true);
    rightwings(true);
    moveBot(20, 1, 127, true);
    leftwings(false);
    rightwings(false); 
    moveBot(10, 1, 100, false);
    runIntake(true, -100);
    pros::delay(1000);
    moveBot(10, 1, 100, false);
    runIntake(false, 0);
    moveBot(3, 1, 20, true);
    turnBot(-85, 1, 50);
    moveBot(15, 1, 127, false);
    turnBot(60, 1, 40);
    moveBot(5, 1, 100, false);
    leftwings(true);
    rightwings(true);
    moveBot(10, 1, 100, false);
    turnBot(-160, 2, 20);
    leftwings(false);
    rightwings(false);
    turnBot(90, 1, 50);
    moveBot(5, 1, 50, false);
    turnBot(-65, 1, 40);
    blocker(true);
    moveBot(7, 1, 100, false);

}
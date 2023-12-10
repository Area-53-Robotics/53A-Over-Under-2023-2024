#include "main.h"
#include "devices.h"
#include "auton.h"

void autonFromLSP () {

    moveBot(3, 1, 50, false);
    turnBot(-90, 1, 50);
    moveBot(10, 1, 50, false);
    /*
    moveBot(25, 1, 100, false);
    turnBot(-90, 1, 50);
    wings(true);
    moveBot(15, 1, 127, true);
    wings(false);
    moveBot(10, 1, 100, false);
    runIntake(true, -100);
    moveBot(10, 1, 100, false);
    runIntake(false, 0);
    moveBot(5, 1, 50, true);
    turnBot(180, 1, 60);
    */
    
}
#include "main.h"
#include "devices.h"
#include "auton.h"

void autonFromLSP () {

    moveBot(25, 2, 100, false);
    turnBot(-90, 1, 50);
    wings(true);
    moveBot(15, 2, 127, true);
    wings(false);
    moveBot(10, 2, 100, false);
    runIntake(true, -100);
    moveBot(10, 2, 100, false);
    runIntake(false, 0);
    moveBot(5, 1, 50, true);
    turnBot(180, 2, 60);
    
}
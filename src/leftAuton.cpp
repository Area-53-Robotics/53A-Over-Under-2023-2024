#include "main.h"
#include "devices.h"
#include "auton.h"

void autonFromLSP () {

    moveBot(30, 2, 100, false);
    turnBot(-90, 1, 50);
    wings(true);
    moveBot(15, 2, 100, true);
    wings(false);
    moveBot(15, 2, 100, false);
    runIntake(true, -100);
    moveBot(15, 2, 100, false);
    runIntake(false, 0);
    moveBot(5, 2, 100, true);
}
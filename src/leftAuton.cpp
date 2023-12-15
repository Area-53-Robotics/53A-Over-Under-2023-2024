#include "main.h"
#include "devices.h"
#include "auton.h"

void autonFromLSP () {
    
    moveBot(25, 2, 100, false);
    turnBot(-90, 1, 50);
    wings(true);
    moveBot(15, 1, 127, true);
    wings(false);
    moveBot(10, 1, 100, false);
    runIntake(true, -100);
    pros::delay(1000);
    moveBot(10, 1, 100, false);
    runIntake(false, 0);
    moveBot(3, 1, 50, true);
    turnBot(180, 1, 60);

}

//Trial #1: Code was incorrect, lurned left instead of going straight (incorrect code removed)
//Trial #2: Triball did not outtake into goal
//Trial #3: Field broke, causing robot to go under goal
//Trial #4: Worked
//Trial #5: Worked
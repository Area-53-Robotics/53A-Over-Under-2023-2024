#include "main.h"
#include "devices.h"
#include "auton.h"

void autonFromLSP () {
    
    moveBot(20, 2, 90, false);
    turnBot(-90, 1, 50);
    wings(true);
    moveBot(20, 1, 127, true);
    wings(false);
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
    wings(true);
    moveBot(10, 1, 100, false);
    turnBot(-160, 2, 20);
    wings(false);
    turnBot(90, 1, 50);
    moveBot(5, 1, 50, false);
    turnBot(-65, 1, 40);
    climbArm(true);
    moveBot(7, 1, 100, false);

}

//Trial #1: Code was incorrect, lurned left instead of going straight (incorrect code removed)
//Trial #2: Triball did not outtake into goal
//Trial #3: Field broke, causing robot to go under goal
//Trial #4: Worked
//Trial #5: Worked
#include "main.h"
#include "devices.h"
#include "auton.h"

void autonFromRSP () {
    
    /*
    moveBot(40, 3, 60, false);
    turnBot(80, 2, 60);
    runIntake (1000, -50);
    moveBot(9, 2, 60, true);
    moveBot(20, 2, 127, false);
    */
    moveBot(40, 3, 60, true);
    moveBot(10, 2, 127, false);
    turnBot(55, 2, 60);
    moveBot(9, 2, 60, false);
    turnBot(80, 2, 60);
    moveBot(20, 2, 127, false);
    runIntake (1000, 50);
    turnBot(80, 2, 60);
    moveBot(20, 2, 127, false);
    runIntake (1000, -50);
    moveBot(9, 2, 60, true);
    moveBot(20, 2, 127, false);

    //moveBot(10, 2, 50, false);
    /*
    runIntake(1000, 50);
    
    turnBot(215, 2, 40);
    moveBot(-3, 1, 40);
    
    runIntake(3000, 127);
    turnBot(180, 2, 60);
    moveBot(17);
    runIntake(500, -127);
    turnBot(180);
    moveBot(41);
    runIntake(500, 127);
    turnBot(180);
    moveBot(41);
    runIntake(500, -127);
    turnBot(90);
    moveBot(65);
    turnBot(90);
    moveBot(17);
    turnBot(180);
    */
}
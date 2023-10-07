#include "main.h"
#include "devices.h"
#include "auton.h"

void autonFromRSP () {

    while (true) {

        moveBot(72);
        turnBot(-90);
        moveBot(1);
        runIntake(500, 127);
        turnBot(180);
        moveBot(24);
        runIntake(500, -127);
        turnBot(180);
        moveBot(48);
        runIntake(500, 127);
        turnBot(180);
        moveBot(48);
        runIntake(500, -127);
        turnBot(90);
        moveBot(72);
        turnBot(90);
        moveBot(24);
        turnBot(180);
        climbArm(true);

    }

}
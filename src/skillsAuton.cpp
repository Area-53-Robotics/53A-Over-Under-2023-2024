#include "main.h"
#include "devices.h"
#include "auton.h"

void skillsAuton () {

    cataRotationReset(1000);
    turnBot(-90);
    moveBot(3);
    runIntake(500, 127);
    moveBot(24);
    turnBot(90);
    moveBot(72);
    turnBot(90);
    runCata(1000, 127);
    cataRotationReset(1000);
    moveBot(1);
    runIntake(500, 127);
    runCata(1000, 127);
    cataRotationReset(1000);
    moveBot(-10);
    turnBot(90);
    moveBot(18);

}
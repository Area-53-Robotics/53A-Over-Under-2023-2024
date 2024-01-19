#include "main.h"
#include "devices.h"
#include "auton.h"
#include "pros/rtos.hpp"

void skillsAuton () {
    
    runCata(44000, 105);
    turnBot(100, 1, 50);
    runIntake(true, -127);
    moveBot(20, 2, 127, false);
    moveBot(3, 1, 20, true);
    runIntake(false, 0);
    turnBot(100, 2, 50);
    moveBot(10, 2, 100, false);
    turnBot(-90, 1, 60);
    moveBot(18, 2, 127, false);
    turnBot(-70, 1, 50);
    leftwings(true);
    rightwings(true);
    moveBot(40, 2, 127, true);

}
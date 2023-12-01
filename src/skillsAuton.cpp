#include "main.h"
#include "devices.h"
#include "auton.h"
#include "pros/rtos.hpp"

void skillsAuton () {

    turnBot(-90, 2, 50);
    moveBot(15, 2, 100, false);
    turnBot(-20, 1, 60);
    moveBot(5, 1, 100, false);
    runCata(30000, 127);
    turnBot(-45, 2, 50);
    moveBot(40, 3, 127, true);
    turnBot(-90, 2, 50);
    wings(true);

}
#include "main.h"
#include "devices.h"
#include "auton.h"
#include "pros/rtos.hpp"

void skillsAuton () {
    
    blocker(false);
    shoot(45000, 127);
    moveBot(2, 1, 15, true);
    shoot(300, 127);
    turnBot(40, 1, 50);
    moveBot(60, 2, 127, true);
    leftwings(true);
    turnBot(-40, 1, 50);
    rightwings(true);
    moveBot(30, 1, 50, true);


}
#include "main.h"
#include "devices.h"
#include "auton.h"
#include "pros/rtos.hpp"

void skillsAuton () {
    
    blocker(false);
    shoot(2000, 100);
    turnBot(-20, 1, 50);
    moveBot(20, 1, 127, false);
    turnBot(50, 1, 50);
    frontrightwings(true);
    frontleftwings(true);
    moveBot(40, 2, 127, false);
    
}
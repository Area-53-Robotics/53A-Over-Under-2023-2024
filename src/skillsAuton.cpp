#include "main.h"
#include "devices.h"
#include "auton.h"
#include "pros/rtos.hpp"

void skillsAuton () {
    
    blocker(false);
    swing(true, -19.2, 1, 50);
    shoot(10000, 105);
    turnBot(40, 1, 50);
    moveBot(40, 1, 127, true);
    leftwings(true);
    rightwings(true);
    turnBot(-30, 1, 50);
    moveBot(30, 1, 50, true);


}
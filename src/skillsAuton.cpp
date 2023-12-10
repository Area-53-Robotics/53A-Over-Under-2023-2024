#include "main.h"
#include "devices.h"
#include "auton.h"
#include "pros/rtos.hpp"

void skillsAuton () {
    
    //resetandCata(true);
    //pros::delay(45000);
    //resetandCata(false);
    turnBot(90, 1, 50);
    runIntake(true, -127);
    moveBot(20, 2, 127, false);
    moveBot(3, 1, 50, true);
    moveBot(10, 1, 100, false);
    runIntake(false, 0);
    pros::delay(2000);
    turnBot(120, 2, 50);
    moveBot(13, 2, 100, false);
    turnBot(-90, 1, 60);
    moveBot(15, 2, 100, false);
    turnBot(-70, 1, 50);
    wings(true);
    moveBot(20, 2, 127, true);
    
}

//test #1: added new reset function, tested catapult (worked)
//created starter, removed move function at the beginning because starter has been created
//test #2: wings did not work
//test #3, did not get over the barrier, right wing broke
//test #4: did not go far enough into the center
//test #5: went too far into the center 
//changed route a bit, since angled approach was complicated

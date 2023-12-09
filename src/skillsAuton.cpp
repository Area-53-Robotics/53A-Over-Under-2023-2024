#include "main.h"
#include "devices.h"
#include "auton.h"
#include "pros/rtos.hpp"

void skillsAuton () {
    
    //resetandCata(true);
    //pros::delay(1000);
    resetandCata(false);
    turnBot(35, 2, 127);
    moveBot(5, 1, 50, true);
    turnBot(90, 2, 50);
    moveBot(10, 2, 100, false);
    turnBot(-90, 1, 60);
    wings(true);
    moveBot(10, 2, 127, true);
    
}

//test #1: added new reset function, tested catapult (worked)
//created starter, removed move function at the beginning because starter has been created
//test #2: wings did not work
//test #3, did not get over the barrier, right wing broke
//test #4: did not go far enough into the center
//test #5: went too far into the center 
//changed route a bit, since angled approach was complicated

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
    wings(true);
    moveBot(40, 2, 127, true);
}

//Trial #1: Catapult did not stop running (program ended)
//Trial #2: Catapult did not stop running (program ended)
//Trial #3: Catapult did not run, bot got stuck under the goal, did not move for the rest of the time
//Trial #4: Angle of second turn was off (did not turn enough), ended in a crash with the wall, also cata didn't turn off 
//Trial #5: Spun randomly
//Trial #6: Angle of second turn was off (did not turn enough)
//Trial #7: Worked but triball did not make it into the goal
//Trial #8: Worked, but triball didn't make it to the goal
//Trial #9: Second turn turned too far, triball didn't make it into the goal
//Made new starter
//Trial #10: Wing got stuck on barrier
//Trial #11: Bot did not make it across the barrier
//Trial #12: WIng got stuck on barrier


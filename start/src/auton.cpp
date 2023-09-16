#include "main.h"
#include "devices.h"
#include "auton.h"

void moveBot(float msecs, int x) {
    front_left_mtr = x;
    middle_left_mtr = x;
    back_left_mtr = x;
    front_right_mtr = x;
    middle_right_mtr = x;
    back_right_mtr = x;

    pros::delay(20);

    front_left_mtr.brake();
    middle_left_mtr.brake();
    back_left_mtr.brake();
    front_right_mtr.brake();
    middle_right_mtr.brake();
    back_right_mtr.brake();
    
}


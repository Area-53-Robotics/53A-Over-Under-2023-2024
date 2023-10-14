#pragma once
#include <type_traits>
//mainAuton.cpp
//Moving/Turning the bot

void moveBot (float distancein);
void turnBot (float turnDegree);

//Intake
void runIntake (float runmsec, int speed);

//Catapult
void runCata (float msec, int speed);
void cataRotationReset (float time);

//Pistons
void climbArm (bool open);
void flaps (bool value);

//leftAuton.cpp
void autonFromLSP ();

//rightAuton.cpp
void autonFromRSP ();

//skillsAuton.cpp
void skillsAuton();
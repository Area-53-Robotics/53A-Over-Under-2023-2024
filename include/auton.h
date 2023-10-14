#pragma once

//mainAuton.cpp
//Moving/Turning the bot
#include <type_traits>
void moveBot (float distancein);
void turnBot (float turnDegree);

//Intake
void runIntake (float runmsec, int speed);

//Catapult
void runCata (float msec, int speed);
void rotationReset (float time);

//Pistons
void climbArm (bool open);
void flaps (bool value);

//leftAuton.cpp
void autonFromLSP ();

//rightAuton.cpp
void autonFromLSP ();

//skillsAuton.cpp
void skillsAuton();
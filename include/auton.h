#pragma once
#include <type_traits>

//mainAuton.cpp
//Moving/Turning the bot
void moveBot (float targetDistance, int timeout, int maxPower, bool reversed);
void turnBot (float turnDegree, int timeout, int maxPower);

//Intake
void runIntake (bool running, int power);

//Catapult
void runCata (float msec, int power);
void cataRotationReset (float time);

//Pistons
void blocker (bool state);
void hwings (bool state);
void vwings (bool state);

//leftAuton.cpp
void autonFromLSP ();

//rightAuton.cpp
void autonFromRSP ();

//skillsAuton.cpp
void skillsAuton();

//Nothing
void noAuton();

//reset to rotation
void resetandCata (bool onOff);

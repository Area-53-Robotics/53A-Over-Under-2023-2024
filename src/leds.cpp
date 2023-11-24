#include "main.h"
#include "devices.h"
#include "leds.h"
#include <cmath>
#include <iostream>

using namespace std;
 
string rgbToHex(int num){
    
    char hexaDeciNum[2];
 
    int i = 0;
    while (num != 0) {
 
        int temp;
        temp = num % 16;

        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
 
        num = num / 16;
    }
 
    string hexCode = "";
    if (i == 2) {
        hexCode.push_back(hexaDeciNum[0]);
        hexCode.push_back(hexaDeciNum[1]);
    }
    else if (i == 1) {
        hexCode = "0";
        hexCode.push_back(hexaDeciNum[0]);
    }
    else if (i == 0)
        hexCode = "00";
		return hexCode;
}

/*
// Function to convert the
// RGB code to Hex color code
string convertRGBtoHex(int R, int G, int B) {
    if ((R >= 0 && R <= 255)
        && (G >= 0 && G <= 255)
        && (B >= 0 && B <= 255)) {
 
        string hexCode = "#";
        hexCode += rgbToHex(R);
        hexCode += rgbToHex(G);
        hexCode += rgbToHex(B);
 
        return hexCode;
    } else {
		return 
	}
}
*/
void gradient (int red, int green, int blue) {

	int maxRed = 255;
	int maxGreen = 255;
	int maxBlue = 255;
	int minRed = 0;
	int minGreen = 0;
	int minBlue = 0;
	
	enum class LEDState {
    	redToYellow,
		yellowToGreen,
    	greenTolBlue,
		lBlueTodBlue,
		dBlueToPurple,
    	purpleToRed,
  	};

	LEDState RGB = LEDState::redToYellow;

	while (true) {
		switch (RGB) {
    	case LEDState::redToYellow:
      		if (red == maxRed && green != maxGreen && blue != maxBlue) {
        		green++;
      		} else {
				LEDState RGB = LEDState::yellowToGreen;
	  		}
      		break;
    	case LEDState::yellowToGreen:
      		if (red != minRed && green == maxGreen && blue != maxBlue) {
        		red--;
      		} else {
				LEDState RGB = LEDState::greenTolBlue;
	  		}
      		break;
    	case LEDState::greenTolBlue:
      		if (red == minRed && green == maxGreen && blue != maxBlue) {
        		blue++;
      		} else {
				LEDState RGB = LEDState::lBlueTodBlue;
			}
      		break;
		case LEDState::lBlueTodBlue:
      		if (red == minRed && green != minGreen && blue == maxBlue) {
        		green--;
      		} else {
				LEDState RGB = LEDState::dBlueToPurple;
			}
      		break;
		case LEDState::dBlueToPurple:
      		if (red != maxRed && green == minGreen && blue == maxBlue) {
        		red++;
      		} else {
				LEDState RGB = LEDState::purpleToRed;
			}
      		break;
		case LEDState::purpleToRed:
      		if (red == maxRed && green == minGreen && blue != minBlue) {
        		blue--;
      		} else {
				LEDState RGB = LEDState::redToYellow;
			}
      		break;
    	}

		pros::delay(20);
	}
	
}
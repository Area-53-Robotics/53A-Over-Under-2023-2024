#include "main.h"
#include "devices.h"
#include "leds.h"
#include <cmath>
#include <iostream>
/*
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
*/
/*
bool counter() {
	int timeCount = 0;
	int count = 1;

	while (true) {
		timeCount++;

		if ((timeCount % 30) == 0) {
			count++;
		}

		if (count > 60) {
			count = 1;
		}

		pros::delay(20);
	}
}
*/

void blueLEDs () {
  int count = 1;
  int timeCount = 0;

  while (true) {
		timeCount++;

		if ((timeCount % 30) == 0) {
			count++;
		}

		if (count > 60) {
			count = 1;
		}
		
		if (count == 1) {
			color.set_all(0x003399);
		} else if (count == 2) {
			color.set_all(0x003cb3);
		} else if (count == 3) {
			color.set_all(0x0044cc);
		} else if (count == 4) {
			color.set_all(0x004de6);
		} else if (count == 5) {
			color.set_all(0x0055ff);
		} else if (count == 6) {
			color.set_all(0x1a66ff);
		} else if (count == 7) {
			color.set_all(0x3377ff);
		} else if (count == 8) {
			color.set_all(0x4d88ff);
		} else if (count == 9) {
			color.set_all(0x6699ff);
		} else if (count == 10) {
			color.set_all(0x80aaff);
		} else if (count == 11) {
			color.set_all(0x99bbff);
		} else if (count == 12) {
			color.set_all(0xb3ccff);
		} else if (count == 13) {
			color.set_all(0xccddff);
		} else if (count == 14) {
			color.set_all(0xe6eeff);
		} else if (count == 15) {
			color.set_all(0xffffff);
		} else if (count == 16) {
			color.set_all(0x9ABDDC);
		} else if (count == 17) {
			color.set_all(0xBCD2E8);
		} else if (count == 18) {
			color.set_all(0x91BAD6);
		} else if (count == 19) {
			color.set_all(0x73A5C6);
		} else if (count == 20) {
			color.set_all(0x528AAE);
		} else if (count == 16) {
			color.set_all(0xe6ffe6);
		} else if (count == 17) {
			color.set_all(0xccffcc);
		} else if (count == 18) {
			color.set_all(0xb3ffb3);
		} else if (count == 19) {
			color.set_all(0x99ff99);
		} else if (count == 20) {
			color.set_all(0x80ff80);
		} else if (count == 21) {
			color.set_all(0x66ff66);
		} else if (count == 22) {
			color.set_all(0x4dff4d);
		} else if (count == 23) {
			color.set_all(0x33ff33);
		} else if (count == 24) {
			color.set_all(0x1aff1a);
		} else if (count == 25) {
			color.set_all(0x00ff00);
		} else if (count == 26) {
			color.set_all(0x00e600);
		} else if (count == 27) {
			color.set_all(0x00cc00);
		} else if (count == 28) {
			color.set_all(0x00b300);
		} else if (count == 29) {
			color.set_all(0x009900);
		} else if (count == 30) {
			color.set_all(0x008000);
		} else if (count == 31) {
			color.set_all(0x006600);
		} else if (count == 31) {
			color.set_all(0x008000);
		} else if (count == 32) {
			color.set_all(0x009900);
		} else if (count == 33) {
			color.set_all(0x00b300);
		} else if (count == 34) {
			color.set_all(0x00cc00);
		} else if (count == 35) {
			color.set_all(0x00e600);
		} else if (count == 36) {
			color.set_all(0x00ff00);
		} else if (count == 37) {
			color.set_all(0x1aff1a);
		} else if (count == 38) {
			color.set_all(0x33ff33);
		} else if (count == 39) {
			color.set_all(0x4dff4d);
		} else if (count == 40) {
			color.set_all(0x66ff66);
		} else if (count == 41) {
			color.set_all(0x80ff80);
		} else if (count == 42) {
			color.set_all(0x99ff99);
		} else if (count == 43) {
			color.set_all(0xb3ffb3);
		} else if (count == 44) {
			color.set_all(0xccffcc);
		} else if (count == 45) {
			color.set_all(0xe6ffe6);
		} else if (count == 46) {
			color.set_all(0xffffff);
		} else if (count == 47) {
			color.set_all(0xe6eeff);
		} else if (count == 48) {
			color.set_all(0xccddff);
		} else if (count == 49) {
			color.set_all(0xb3ccff);
		} else if (count == 50) {
			color.set_all(0x99bbff);
		} else if (count == 51) {
			color.set_all(0x80aaff);
		} else if (count == 52) {
			color.set_all(0x6699ff);
		} else if (count == 53) {
			color.set_all(0x4d88ff);
		} else if (count == 54) {
			color.set_all(0x3377ff);
		} else if (count == 55) {
			color.set_all(0x1a66ff);
		} else if (count == 56) {
			color.set_all(0x0055ff);
		} else if (count == 57) {
			color.set_all(0x004de6);
		} else if (count == 58) {
			color.set_all(0x0044cc);
		} else if (count == 59) {
			color.set_all(0x003cb3);
		} else if (count == 60) {
			color.set_all(0x003399);
		}

		pros::delay(20);
  }
}

void redLEDs () {
  int count = 1;
  int timeCount = 0;

	while (true) {
		timeCount++;

		if ((timeCount % 30) == 0) {
			count++;
		}

		if (count > 60) {
			count = 1;
		}
		
		if (count == 1) {
			color.set_all(0x990000);
		} else if (count == 2) {
			color.set_all(0xb30000);
		} else if (count == 3) {
			color.set_all(0xcc0000);
		} else if (count == 4) {
			color.set_all(0xe60000);
		} else if (count == 5) {
			color.set_all(0xff0000);
		} else if (count == 6) {
			color.set_all(0xff1a1a);
		} else if (count == 7) {
			color.set_all(0xff3333);
		} else if (count == 8) {
			color.set_all(0xff4d4d);
		} else if (count == 9) {
			color.set_all(0xff6666);
		} else if (count == 10) {
			color.set_all(0xff8080);
		} else if (count == 11) {
			color.set_all(0xff9999);
		} else if (count == 12) {
			color.set_all(0xffb3b3);
		} else if (count == 13) {
			color.set_all(0xffb3b3);
		} else if (count == 14) {
			color.set_all(0xffe6e6);
		} else if (count == 15) {
			color.set_all(0xffffff);
		} else if (count == 16) {
			color.set_all(0xe6ffe6);
		} else if (count == 17) {
			color.set_all(0xccffcc);
		} else if (count == 18) {
			color.set_all(0xb3ffb3);
		} else if (count == 19) {
			color.set_all(0x99ff99);
		} else if (count == 20) {
			color.set_all(0x80ff80);
		} else if (count == 21) {
			color.set_all(0x66ff66);
		} else if (count == 22) {
			color.set_all(0x4dff4d);
		} else if (count == 23) {
			color.set_all(0x33ff33);
		} else if (count == 24) {
			color.set_all(0x1aff1a);
		} else if (count == 25) {
			color.set_all(0x00ff00);
		} else if (count == 26) {
			color.set_all(0x00e600);
		} else if (count == 27) {
			color.set_all(0x00cc00);
		} else if (count == 28) {
			color.set_all(0x00b300);
		} else if (count == 29) {
			color.set_all(0x009900);
		} else if (count == 30) {
			color.set_all(0x008000);
		} else if (count == 31) {
			color.set_all(0x006600);
		} else if (count == 31) {
			color.set_all(0x008000);
		} else if (count == 32) {
			color.set_all(0x009900);
		} else if (count == 33) {
			color.set_all(0x00b300);
		} else if (count == 34) {
			color.set_all(0x00cc00);
		} else if (count == 35) {
			color.set_all(0x00e600);
		} else if (count == 36) {
			color.set_all(0x00ff00);
		} else if (count == 37) {
			color.set_all(0x1aff1a);
		} else if (count == 38) {
			color.set_all(0x33ff33);
		} else if (count == 39) {
			color.set_all(0x4dff4d);
		} else if (count == 40) {
			color.set_all(0x66ff66);
		} else if (count == 41) {
			color.set_all(0x80ff80);
		} else if (count == 42) {
			color.set_all(0x99ff99);
		} else if (count == 43) {
			color.set_all(0xb3ffb3);
		} else if (count == 44) {
			color.set_all(0xccffcc);
		} else if (count == 45) {
			color.set_all(0xe6ffe6);
		} else if (count == 46) {
			color.set_all(0xffffff);
		} else if (count == 47) {
			color.set_all(0xffe6e6);
		} else if (count == 48) {
			color.set_all(0xffb3b3);
		} else if (count == 49) {
			color.set_all(0xffb3b3);
		} else if (count == 50) {
			color.set_all(0xff9999);
		} else if (count == 51) {
			color.set_all(0xff8080);
		} else if (count == 52) {
			color.set_all(0xff6666);
		} else if (count == 53) {
			color.set_all(0xff4d4d);
		} else if (count == 54) {
			color.set_all(0xff3333);
		} else if (count == 55) {
			color.set_all(0xff1a1a);
		} else if (count == 56) {
			color.set_all(0xff0000);
		} else if (count == 57) {
			color.set_all(0xe60000);
		} else if (count == 58) {
			color.set_all(0xcc0000);
		} else if (count == 59) {
			color.set_all(0xb30000);
		} else if (count == 60) {
			color.set_all(0x990000);
		}

		pros::delay(20);
	}

}
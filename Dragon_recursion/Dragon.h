/* Mark Moerdyk
CSS 342 Assignment 3
Dragon.h Allows Dragon to inherit Turtle.h so that
Dragon can be drawn using a left and right curve.
*/
#include "Turtle.h"
#include <iostream>
#include <math.h>
using namespace std;

// Allows the Dragon to inherit Turtle functions draw, move, and turn so that the Dragon can be drawn
class Dragon : Turtle {

public:
	Dragon(float initX = 0.0, float initY = 0.0, float initAngle = 0.0);
	void leftCurve(int l, float d);  //draw a level-l left curve with dist d
	void rightCurve(int l, float d); //draw a level-l right curve with dist d
};

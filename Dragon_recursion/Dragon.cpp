/*Mark Moerdyk
CSS 342 Assignment 3
Dragon.cpp Creates a level 1 right curve and left curve
Depending on level, uses recursion to draw more curves
*/
#include "Dragon.h"

/* Initializes the Dragon to contain an X point, Y point, and
an angle that will be stored for each dragon. Dragon inherits Turtle
so that the Dragon can be drawn.
*/
Dragon::Dragon(float initX, float initY, float initAngle)
: Turtle(initX, initY, initAngle) {
}

/*Creates a left curve for the Dragon
Input: level and draw distance
Depending on level, will use recursion to draw appropriate shape */
void Dragon::leftCurve(int level, float d) {
	if (level > 1) {
		leftCurve(level - 1, d);
		turn(90);
		leftCurve(level - 1, d);
		turn(-90);
		leftCurve(level - 1, d);
		turn(-90);
		leftCurve(level - 1, d);
		turn(90);
		leftCurve(level - 1, d);
	
	}
	else
		draw(d);
}

/*Creates a right curve for the Dragon
Input: level and draw distance
Depending on level, will use recursion to draw appropriate shape */
void Dragon::rightCurve(int level, float d) {
	if (level > 0) {
		turn(-90);
		leftCurve(level - 1, d);
		turn(-90);
		rightCurve(level - 1, d);
	}
	else
		draw(d);
}
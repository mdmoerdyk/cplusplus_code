//Mark Moerdyk
//CSS 342 Assignment 3
//turtle.h file done in class

#include <iostream>
#include <fstream>
using namespace std;
#include <math.h>
const float PI = 3.1459265; //for calculating dX and dY

class Turtle{

public:
	Turtle(float initx = 0, float y = 0, float initAngle = 0.0);
	~Turtle();
	void draw(float d);
	void move(float d);
	void turn(float a);

private:
	ofstream out;
	float angle;

};
//Mark Moerdyk
//CSS 342 Assignment 3
//turtle that helps draw, move and turn to create shapes.
#include "Turtle.h"

/*Creates a turtle that places the running code into an output.ps
file, that can then be converted to a pdf file with the given drawing.*/

Turtle::Turtle(float initX, float initY, float initAngle){
	out.open("output.ps", ios::app);
	angle = initAngle;
	out << "%!PS-Adobe-2.0" << endl;
	out << initX << "\t" << initY << "\tmoveto" << endl;
}

Turtle::~Turtle(){
	out << "stroke" << endl;
	out << "showpage" << endl;
	out.close();
}
/*draws the line from current position to new position based on float d*/
void Turtle::draw(float d){
	float dX, dY;
	dX = d * cos(PI * angle / 180);
	dY = d * sin(PI * angle / 180);
	out << dX << "\t" << dY << "\trlineto" << endl;
}
/*moves the turtle like draw, but does not create a line*/
void Turtle::move(float d){
	float dX, dY;
	dX = d * cos(PI * angle / 180);
	dY = d * sin(PI * angle / 180);
	out << dX << "\t" << dY << "\trmoveto" << endl;
}

/*allows the turtle to turn to a new angle, and stores that new angle*/
void Turtle::turn(float a){
	angle += a;
}
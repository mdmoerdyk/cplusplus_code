/*Mark Moerdyk
CSS 342 Assignment 1
Complex Class
A complex number contains a real and imaginary part.
*/

#include "complex.h"


/* Complex
Parameters: X + Yi, where X is real and Y is imaginary
Both parameters are doubles
*/
complex::complex(double r, double imag)
{
	real = r;
	imaginary = imag;
}
/***************************************************************************************************************************************************************/
/* getReal()
Returns the real part of the complex number
*/
double complex::getReal()
{
	return real;
}

/* getImaginary()
Returns the imaginary part of the complex number
*/
double complex::getImaginary()
{
	return imaginary;
}

/*conjugate
returns the conjugate of a complex number. For example, x+yi => x - yi
*/
complex complex::conjugate()
{
	complex con;//stores the value of the conjugated complex number
	con.real = real; 
	con.imaginary = imaginary * -1;
	return con;
}
/*************************************************************************************************************************************************************/

/* operator +
adds two complex numbers together.
Returns sum of complex numbers
*/
complex complex::operator+(const complex& a) const
{
	complex sum; //stores the sum of the two complex number
	sum.real = a.real + real;
	sum.imaginary = a.imaginary + imaginary;
	return sum;
}

/* operator -
subtraction of 2 complex numbers
Returns difference of complex numbers
*/
complex complex::operator-(const complex& s) const
{
	complex sub;

	sub.real = real - s.real;
	sub.imaginary = imaginary - s.imaginary;

	return sub;
}
/*operator *
 multiplies two complex numbers together
 Returns multiplicaition of complex numbers
*/
complex complex::operator*(const complex& m) const
{
	complex mult;
	
	mult.real = ((real)* (m.real)) - ((imaginary)* (m.imaginary));
	mult.imaginary = ((real)* (m.imaginary)) + ((m.real) * (imaginary));

	return mult;
}

/*operator /
divides two complex number
if divide by zero, prints out error message
*/
complex complex::operator/(const complex& d) const
{
	complex div;

	if (d.real == 0 && d.imaginary == 0)
	{
		cout << "Divide by zero error" << endl;
	}

	div.real = (((real)*(d.real)) + ((imaginary)*(d.imaginary)))/(pow(d.real,2) + pow(d.imaginary,2));
	div.imaginary = (((d.real)*(imaginary))-((real) * (d.imaginary))) / (pow(d.real,2) + pow(d.imaginary,2));

	return div;
}
/**************************************************************************************************************************************************************/
//Comparisons

//operator ==
// compares two complex numbers to see if they are equal to each other.
//Returns true if equal, else returns false.

bool complex::operator==(const complex& r) const
{
	return (real == r.real && imaginary == r.imaginary);
}

/* Operator !=
compares two complex numbers to see if they are NOT equal to each other
Returns false if they are not equal to each other, else returns true
*/

bool complex::operator!=(const complex& r) const
{
	return !(real == r.real && imaginary == r.imaginary);
}
/**************************************************************************************************************************************************************/
//Assignments

/* operator +=
current object = current object + parameter
*/

complex& complex::operator+=(const complex& a)
{
	real = a.real + real;
	imaginary = a.imaginary + imaginary;
	return *this;
}

/* operator -=
current object = current object - parameter
*/

complex& complex::operator-=(const complex& s)
{
	real = real - s.real;
	imaginary = imaginary - s.imaginary;
	return *this;
}

/* operator *=
current object = current object * parameter
*/
complex& complex::operator*=(const complex& m)
{
	complex mult;

	mult.real = ((real)* (m.real)) - ((imaginary)* (m.imaginary));
	mult.imaginary = ((real)* (m.imaginary)) + ((m.real) * (imaginary));

	real = mult.real;
	imaginary = mult.imaginary;

	return *this;

}

/* operator /=
current object = current object / parameter
*/
complex& complex::operator/=(const complex& d)
{
	complex div;

	if (d.real == 0 && d.imaginary == 0)
	{
		cout << "Divide by zero error" << endl;
	}

	div.real = (((real)*(d.real)) + ((imaginary)*(d.imaginary))) / (pow(d.real, 2) + pow(d.imaginary, 2));
	div.imaginary = (((d.real)*(imaginary)) - ((real)* (d.imaginary))) / (pow(d.real, 2) + pow(d.imaginary, 2));

	real = div.real;
	imaginary = div.imaginary;

	return *this;
}

/**************************************************************************************************************************************************************/
/* Operator <<
allows the user to print out any complex number defined my class complex
printout: X + Yi
Different paramters printout different results.
*/
ostream& operator<<(ostream &output, const complex &r)
{
	
	if (r.imaginary == 0)
	{
		output << r.real;
	}
	else if (r.real == 0)
	{
		output << r.imaginary << "i";
	}
	else if (r.imaginary < 0)
	{
		output << r.real << r.imaginary << "i";
	}
	else
	{
		output << r.real << "+" << r.imaginary << "i";
	}
	
	return output;
}

/*Operator >>
allows the user to input complex numbers in complex variables
*/
istream& operator>>(istream &input, complex &r)
{
	input >> r.real >> r.imaginary;

	return input;
}
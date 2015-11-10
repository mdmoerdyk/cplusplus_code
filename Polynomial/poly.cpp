/*Mark Moerdyk
CSS343 Assignment 1
Creates and implements all required functions for polynomials.
Done with an array and size of the array.
*/
#include "poly.h"

/*Construction for poly as defined as Poly(x,y) Poly(x)
and Poly(). Initially defined as (0,0) 
*/
Poly::Poly(int base, int exponent)
{
	if (exponent < 0)
	{
		base = exponent = 0;
	}
	size = exponent + 1;
	polynomial = new int[size]();
	for (int i = 0; i < size; i++)
	{
		polynomial[i] = 0;
	}
	polynomial[exponent] = base;
}
/*Construction that defines Poly(A). Copies a polynoimal to another
polynomial.
*/
Poly::Poly(const Poly &p)
{
	polynomial = new int[p.size]();
	size = p.size;

	for (int i = 0; i < size; i++)
	{
		polynomial[i] = p.polynomial[i];
	}
}

/*Deconstructor. Deletes polynomial and sets it to NULL.
*/
Poly::~Poly()
{
	delete[] polynomial;
	polynomial = NULL;
}

/*setCoeff
Function that sets the base and exponent into the polynomial array
Checks to see if exponent is bigger than array size. If bigger, changes arrary
size and fills in array with value and 0's to not have memory leak*/
void Poly::setCoeff(int base, int exponent)
{
	
	if (exponent >= 0) 
	{
		if ((exponent + 1) > size) //checks to see whether to increase array size
		{
			int *temp = new int[exponent + 1]; 

			for (int i = 0; i < size; i++)
			{
				temp[i] = polynomial[i]; //Copy old values into temp 
			}
				

			for (int j = size; j < (exponent + 1); j++) //fill in added array slots with 0's
			{
				temp[j] = 0; 
			}
			
			temp[exponent] = base; //sets value wanted by input

			delete[] polynomial; 
			polynomial = NULL;
			polynomial = temp; //copy all values into polynomial
			temp = NULL;
			size = exponent + 1; //set new size
		}
		else
		{
			polynomial[exponent] = base; 
		}
			
	}
	
}

/*getCoeff()
Gets one term's coefficient, and returns the value of the base
determined by the exponent
In: p = the exponet of the polynomial value
Returns: base value 
*/
int Poly::getCoeff(int p)
{
	//check limits
	if (p < 0 || p >= size)
	{
		return 0;
	}
	return polynomial[p];
}

/* Operator +
Adds two polynomials together and returns value
Returns: Total value of polynomial added together
*/
Poly Poly::operator+(const Poly &rhs) const
{
	int largest = (size > rhs.size) ? size : rhs.size; //checks to see which is bigger array size
	Poly temp(0, largest - 1);

	for (int i = 0; i < temp.size; i++) //fill in array with 0's
	{
		temp.polynomial[i] = 0;
	}
	for (int i = 0; i < size; i++) //fill in array with lhs values
	{
		temp.polynomial[i] = polynomial[i];
	}
	for (int i = 0; i < rhs.size; i++)
	{
		temp.polynomial[i] = temp.polynomial[i] + rhs.polynomial[i];
	}
	return temp;
}

/* Operator -
Subtracts the lhs polynomial from the rhs polynomial
Return: Polynomial with lhs - rhs
*/
Poly Poly::operator-(const Poly &rhs) const
{
	int largest = (size > rhs.size) ? size : rhs.size; //checks to see which is bigger array size
	Poly temp(0, largest - 1);

	for (int i = 0; i < temp.size; i++) //fills in array with 0's for memeory leak purposes
	{
		temp.polynomial[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		temp.polynomial[i] = polynomial[i];
	}
	for (int i = 0; i < rhs.size; i++)
	{
		temp.polynomial[i] = temp.polynomial[i] - rhs.polynomial[i];
	}
	return temp;
}

/* Operator *
Multiplies the two polynomials together
Returns: polynomial with multiplied lhs and rhs together
*/
Poly Poly::operator*(const Poly &rhs) const
{
	int totalSize = (size + rhs.size - 2);

	Poly temp(0, totalSize);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < rhs.size; j++)
		{
			temp.polynomial[i + j] += (polynomial[i] * rhs.polynomial[j]);
		}
	}
	return temp;

}

/* Operator ==
Checks to see if two polynomials are the same in all values
Returns: true if same or false if different
*/
bool Poly::operator==(const Poly &rhs) const
{
	if (size != rhs.size)
	{
		return false;
	}
	for (int i = 0; i < size; i++)
	{
		if (polynomial[i] != rhs.polynomial[i])
		{
			return false;
		}
	}
	return true;
}

/*Operator !=
Checks to see the opposite of operator ==
Returns: true is not same, or false if same values
*/
bool Poly::operator!=(const Poly &rhs)const
{
	return !(*this == rhs);
}

/*Operator =
Copies the values from the rhs polynomial to the lhs polynomial
Returns lhs polynomial with new values equal to the rhs
*/
const Poly& Poly::operator=(const Poly &rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	if (size < rhs.size)
	{
		delete[] polynomial;
		polynomial = new int[rhs.size]();
		size = rhs.size;
	}
	else if (size > rhs.size) //fills entire array with 0's for memory leak purposes
	{
		for (int i = 0; i < size; i++)
		{
			polynomial[i] = 0;
		}
	}
	for (int i = 0; i < rhs.size; i++) //lhs = rhs
	{
		polynomial[i] = rhs.polynomial[i];
	}

	return *this;
}

/* Operator +=
Adds the lhs and rhs polynomials together, and puts the values into the lhs polynomial
Returns: lhs Polynomial with added value of lhs + rhs
	*/
Poly& Poly::operator+=(const Poly &rhs)
{
	*this = *this + rhs;
	return *this;
}
/* Operator -=
Subtracts the lhs and rhs polynomials together, and puts the values into the lhs polynomial
Returns: lhs Polynomial with subtracted value of lhs - rhs
*/
Poly& Poly::operator-=(const Poly &rhs)
{
	*this = *this - rhs;
	return *this;
}
/* Operator *=
Multiplies the lhs and rhs polynomials together, and puts the values into the lhs polynomial
Returns: lhs Polynomial with added value of lhs + rhs
*/
Poly& Poly::operator*=(const Poly &rhs)
{
	*this = *this * rhs;
	return *this;
}
/* Operator >>
Overrides the input of >> for polynomials
Takes input of integers, and divides them into pairs. When the pair
is -1 -1, it ends the input and exits the loop.
*/
istream &operator>>(istream &in, Poly &rhs)
{
	int base;
	int exponent;
	bool run = true;

	for (int i = 0; i < rhs.size; i++)
	{
		rhs.polynomial[i] = 0;
	}
	while (run)
	{
		in >> base;
		in >> exponent;
		if (base == -1 && exponent == -1) //end of input
		{
			run = false;
		}
		else
		{
			rhs.setCoeff(base, exponent);
		}
	}
	return in;
}
/*Operator <<
Overrides the operator << and prints out polynomials 
Goes through the array, and depending on base value, will 
print out correct values. Goes from end of array to beginning.
*/
ostream &operator<<(ostream &out, const Poly &rhs)
{
	bool empty = true;

	for (int i = 0; i < rhs.size; i++)
	{
		if (rhs.polynomial[i] != 0)
		{
			empty = false;
		}
	}

	if(empty) //nothing in polynomial
	{
		out << "0";
		return out;
	}

	for (int i = rhs.size - 1; i >= 0; i--)
	{
		if (i > 1) //x^i
		{
			if (rhs.polynomial[i] != 0)
			{
				if (rhs.polynomial[i] > 0)
				{
					out << " +";
				}
				else
				{
					out << " ";
				}
				out << rhs.polynomial[i] << "x^" << i;
			}
		}

		else if (i == 1) //x
		{
			if (rhs.polynomial[i] != 0)
			{
				if (rhs.polynomial[i] > 0)
				{
					out << " +";
				}
				else
				{
					out << " ";
				}
				out << rhs.polynomial[i] << "x";
			}
		}
		else if (i == 0) //no x
		{
			if (rhs.polynomial[i] != 0)
			{
				if (rhs.polynomial[i] > 0)
				{
					out << " +";
				}
				else
				{
					out << " ";
				}
				out << rhs.polynomial[i];
			}
		}
	}
	return out;
}
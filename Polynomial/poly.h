/* Mark Moerdyk
CSS 343 Assignment 1
Header file for poly.h that helps create all calls for class
poly.cpp. Includes overloads, constructors, deconstructors, and operations.
*/
#ifndef POLY_H
#define POLY_H
#include <iostream>

using namespace std;

class Poly
{
	friend istream& operator>>(istream &in, Poly &rhs);
	friend ostream& operator<<(ostream &out, const Poly &rhs);

	public:
		//constructors
		Poly(int base = 0, int exponent = 0);
		Poly(const Poly &p);

		//Destructor
		~Poly();

		//set method
		void setCoeff(int base, int exponent);

		//get method
		int getCoeff(int p);

		//Overload Operators
		Poly operator+(const Poly &rhs) const;
		Poly operator-(const Poly &rhs) const;
		Poly operator*(const Poly &rhs) const;

		//Assignment operators
		const Poly&operator=(const Poly &rhs);
		Poly& operator+=(const Poly &rhs);
		Poly& operator-=(const Poly &rhs);
		Poly& operator*=(const Poly &rhs);

		//Logical binary operators
		bool operator==(const Poly &rhs) const;
		bool operator!=(const Poly &rhs) const;

	private:
		int size;
		int *polynomial;

};
#endif // POLY_H
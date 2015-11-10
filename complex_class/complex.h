/*Mark Moerdyk
CSS 342 
header file for complex number operator
*/
#include <iostream>
#include <cmath> //for pow for division functions
using namespace std;

class complex{

	friend ostream& operator<<(ostream&, const complex&);
	friend istream& operator>>(istream&, complex&);

public:
	complex(double = 0.0, double = 0.0);
	
	//returns value specified (member functions)
	double getReal();
	double getImaginary();
	complex conjugate();

	//arithmetic operators
	complex operator+(const complex &) const;
	complex operator-(const complex &) const;
	complex operator*(const complex &) const;
	complex operator/(const complex &) const;

	//boolean operators
	bool operator==(const complex &) const;
	bool operator!=(const complex &) const;

	//assignment operators
	complex& operator+=(const complex &);
	complex& operator-=(const complex &);
	complex& operator*=(const complex &);
	complex& operator/=(const complex &);

private:
	double real;
	double imaginary;
};
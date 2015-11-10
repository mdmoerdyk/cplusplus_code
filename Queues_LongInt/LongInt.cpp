/*Mark Moerdyk
CSS 342 Assignment 7
Implement all operators to allow basic math
and comparisons between longints*/

#include "longint.h"

//Constructors

//Creates the input to a LongInt where looks at first char to see if negative
//then input characters from 0 to 9 in digits
LongInt:: LongInt( const string str)
{
	int i = 0;
	digits.clear();
	if(str[0] == '-')
	{
		negative = true;
		i++;
	}
	else
    {
        negative = false;
    }

    for(i; i < str.length(); i++)
	{
		char c = str[i];
        int ci = c - '0';
        if (ci > -1 && ci < 10) //make sure ci is 0 < ci < 9
        {
            digits.addBack(str[i]);
        }
    }
}

LongInt::LongInt (const LongInt & rhs)
{
	digits = rhs.digits;
	negative = rhs.negative;
}

LongInt::LongInt() 
{
    //when no input, defaults to zero
    LongInt temp("0");
    digits = temp.digits;
    negative = temp.negative;
}

//Deconstructor
LongInt::~LongInt() 
{
    //gets rid of all digits
    while(!digits.isEmpty())
        digits.removeFront();
}
/**********************************Assignment Operators*****************************/
/* Operator =
Assigns a LongInt to another LongInt
*/
const LongInt& LongInt::operator=( const LongInt &rhs )
{
    //make this objects equal to rhs objects
    digits = rhs.digits;
    negative = rhs.negative;
    return *this;
}

/*********************************Logical Binary operators****************************/
/*Operator <
Compares signs, then size, then individual characters from back to front.
Returns boolean
*/
bool LongInt::operator< (const LongInt & rhs) const
{
	LongInt temp;
	temp.digits = digits;
	temp.negative = negative;
	
	LongInt temp_rhs;
	temp_rhs.digits = rhs.digits;
	temp_rhs.negative = rhs.negative;
	
	if(temp.negative == true && rhs.negative == false) // - < +
	{
		return true;
	}
	else if(temp.negative == false && rhs.negative == true) // + < -
	{
		return false;
	}
	else //same sign
	{
		bool r_State = true;
		if(digits.size() != rhs.digits.size()) //sizes don't match
		{
			if (digits.size() < rhs.digits.size())
			{
				r_State = true;
			}
			else if(digits.size() > rhs.digits.size())
			{
				r_State = false;
			}
			
			if (negative && rhs.negative) // both negative
			{
				return (!r_State);
			}
			else
			{
				return r_State;
			}
		}
		else //same size, check contents.
		{
			Deque<char> left = digits;
			Deque<char> right = rhs.digits;
			for (int i = 0; i < rhs.digits.size(); i++)
			{
				int l = left.removeFront() - '0';
				int r = right.removeFront() - '0';
				
				if (l > r)
				{
					
					 if (!negative && !rhs.negative) //positive
					 {
						 
						return false;
					 }
					 else
					 {
						 return true;
					 }
				}
			}
		}
		return (r_State);
	}
		
}

/* Operator ==
Compares the signs, size, then checks to see if all characters match.
Returns boolean
*/
bool LongInt::operator==(const LongInt & rhs) const
{
	if(!negative && rhs.negative || negative && !rhs.negative) //signs not equal
	{
		return false;
	}
	else
	{
		if(digits.size() != rhs.digits.size())
		{
			return false;
		}
		else
		{
			bool r_State = true;
			Deque<char> left = digits;
			Deque<char> right = rhs.digits;
			for (int i = 0; i < rhs.digits.size(); i++)
			{
				char l = left.removeFront();
				char r = right.removeFront();
				if(l != r)
				{
					r_State = false;
				}
			}
			return (r_State);
		}
	}
}

/*Operator <=
Based upon the combination of operators < and ==, create a truth based table to get accurate results
Returns boolean
*/
bool LongInt::operator<=( const LongInt & rhs) const
{
	LongInt temp;
	temp.digits = digits;
	temp.negative = negative;
	
	if(temp < rhs)
	{
		return true;
	}
	if(temp == rhs)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*Operator >
Based upon the combination of operators < and ==, create a truth based table to get accurate results
Returns boolean
*/
bool LongInt::operator>( const LongInt & rhs) const
{
	LongInt temp;
	temp.digits = digits;
	temp.negative = negative;
	
	if(temp < rhs)
	{
		return false;
	}
	if(temp == rhs)
	{
		return false;
	}
	else
	{
		return true;
	}
}

/*Operator >=
Based upon the combination of operators < and ==, create a truth based table to get accurate results
Returns boolean
*/
bool LongInt::operator>=( const LongInt & rhs) const
{
	LongInt temp;
	temp.digits = digits;
	temp.negative = negative;
	
	if(temp > rhs)
	{
		return true;
	}
	if(temp == rhs)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*Operator !=
The results will be the opposite of operator ==
Returns boolean
*/
bool LongInt::operator!=( const LongInt & rhs) const
{
	LongInt temp;
	temp.digits = digits;
	temp.negative = negative;
	
	return !(temp == rhs);
}

/************************************Math Operators**************************************************/
/* Operator +
Considers the four different cases for addition. Then makes Deque same size and does the addition.
Returns a LongInt
*/
LongInt LongInt::operator+( const LongInt &rhs) const
{
	LongInt sumVal;
	string str = "";
	//A + -B => A - B
	if(!negative && rhs.negative)
	{
		LongInt lhs;
		LongInt newrhs;
		
		lhs.digits = digits;
		lhs.negative = false;
		
		newrhs.digits = rhs.digits;
		newrhs.negative = false;
		
		sumVal = lhs - newrhs;
		return sumVal;
		
	}
	//-A + B =>  B - A
	else if(negative && !rhs.negative)
	{
		LongInt lhs;
		LongInt newrhs;
		
		lhs.digits = digits;
		lhs.negative = false;
		
		newrhs.digits = rhs.digits;
		newrhs.negative = false;
		
		sumVal = newrhs - lhs;
		return sumVal;
		
	
	}
	//-A + -B => -(A + B)
	else if(negative && rhs.negative)
	{
		LongInt lhs;
		LongInt newrhs;
		
		lhs.digits = digits;
		lhs.negative = false;
		
		newrhs.digits = rhs.digits;
		newrhs.negative = false;
		
		sumVal = lhs + newrhs;
		sumVal.negative = true;
		return sumVal;
	}
	
	//A+B
	Deque<char> leftDigits = digits;
	Deque<char> rightDigits = rhs.digits;
	
	//make both left and right hand sides equal to each other for addition
	for(int i = rightDigits.size(); i < leftDigits.size(); i++)
	{
		rightDigits.addFront('0');
	}
	for(int i = leftDigits.size(); i < rightDigits.size(); i++)
	{
		leftDigits.addFront('0');
	}
	
	Deque<char> countNum = leftDigits;
	
	int carry = 0;
	//gets back integer and adds them together. Over 9, -10 and carry the 1
	for(int i = 0; i < countNum.size(); i++)
	{
		int num1 = leftDigits.removeBack() - '0';
		int num2 = rightDigits.removeBack() - '0';
		
		int sum = num1 + num2 + carry;
		carry = 0;
		if (sum >= 10)
		{
			carry = 1;
			sum -= 10;
		}
		str = string(1, (char)(((int)'0')+sum) ) + str;
        
	}
	
	if (carry > 0)
	{
		str = "1" + str;
	}
	
	Deque<char> sumDeque;
	for(int i = 0; i < str.length(); i++)
	{
		sumDeque.addBack(str[i]);
	}
	sumVal.digits = sumDeque;
	sumVal.negative = false;
	return sumVal;
	
}

/* Operator -
Considers the four different cases for subtraction, then makes Deque size the same. Depending on size and content,
may flip the subtraction.
Return LongInt
*/
LongInt LongInt::operator-( const LongInt &rhs) const
{
	LongInt diffVal;
	Deque<char> tempLeft;
	Deque<char> tempRight;
	// A - (-B)
	if(!negative && rhs.negative)
	{
		LongInt lhs;
		LongInt newrhs;
		
		lhs.digits = digits;
		lhs.negative = false;
		
		newrhs.digits = rhs.digits;
		newrhs.negative = false;
		
		diffVal = lhs + newrhs;
		return diffVal;
	}
	// -A - B => -(A + B)
	else if(negative && !rhs.negative)
	{
		LongInt lhs;
		LongInt newrhs;
		
		lhs.digits = digits;
		lhs.negative = false;
		
		newrhs.digits = rhs.digits;
		newrhs.negative = false;
		
		diffVal = lhs + newrhs;
		diffVal.negative = true;
		return diffVal;
	}
	//-A - (-B) => B - A 
	else if(negative && rhs.negative)
	{
		LongInt lhs;
		LongInt newrhs;
		
		lhs.digits = digits;
		lhs.negative = false;
		
		newrhs.digits = rhs.digits;
		newrhs.negative = false;
		
		if(lhs > rhs)
		{
			diffVal = lhs - newrhs;
			diffVal.negative = true;
			return diffVal;
		}
		else if(lhs < rhs)
		{
			diffVal = newrhs - lhs;
			diffVal.negative = false;
			return diffVal;
		}
		else
		{
			Deque<char> diffDeque;
			diffDeque.addBack('0');
			diffVal.digits = diffDeque;
			diffVal.negative = false;
			return diffVal;
		}
		
	}
	//A - B
	else if(!negative && !rhs.negative)
	{
		LongInt lhs;
		LongInt newrhs;
		
		lhs.digits = digits;
		lhs.negative = false;
		
		newrhs.digits = rhs.digits;
		newrhs.negative = false;
		
		if (lhs > rhs) 
		{
			tempLeft = lhs.digits;
			tempRight = newrhs.digits;
			diffVal.negative = false;
		}
		else if(lhs < rhs)
		{
			tempLeft = newrhs.digits;
			tempRight = lhs.digits;
			diffVal.negative = true;
		}
		else
		{
			Deque<char> diffDeque;
			diffDeque.addBack('0');
			diffVal.digits = diffDeque;
			diffVal.negative = false;
			return diffVal;
		}
		
	}
	
	string str = "";
	//make both same size Deques
	for(int i = tempRight.size(); i < tempLeft.size(); i++)
	{
		tempRight.addFront('0');
	}
	for(int i = tempLeft.size(); i < tempRight.size(); i++)
	{
		tempLeft.addFront('0');
	}
	
	Deque<char> countNum = tempLeft;
	int borrow = 0;
	//takes back integers and subtracts them. Less than 0, +10 and borrow=1
	for(int i = 0; i < countNum.size(); i++)
	{
		int num1 = tempLeft.removeBack() - '0';
		int num2 = tempRight.removeBack() - '0';
				
		int sum = num1 - num2 - borrow;
		borrow = 0;
		
		if(sum < 0)
		{
			sum = sum + 10;
			borrow = 1;
		}
		str = string(1, (char)(((int)'0')+sum) ) + str;
	}
	Deque<char> diffDeque;
	for(int i = 0;i < str.length(); i++)
	{
		diffDeque.addBack(str[i]);
	}
	diffVal.digits = diffDeque;
	return diffVal;
	
}

/*********************************************************************************************/
// << and >> for storing and printing out longints

/*Operator >>
Allows the user to input a long int variable, and will be placed 
into LongInt
*/
istream &operator>>( istream &in, LongInt &rhs)
{
	string word;
	in >> word;
	LongInt placeHolder(word);
	rhs = placeHolder;
	return in;
}

/*Operator <<
Allows the user to printout LongInts. Will look to see if
there is a negative value or nothing.
*/
ostream &operator<<(ostream &out, const LongInt &rhs)
{
	string longIntOut;
	LongInt temp = rhs;
	bool nonZero = false;
	//pulling characters out of LongInt, and placing them as characters in a string so they can be printed out
	for(int i = 0; i < rhs.digits.size(); i++)
	{
		
		int num = temp.digits.removeFront() - '0';
		if(num == 0 && nonZero == false)
		{
			//null
		}
		else
		{
			nonZero = true;
			longIntOut = longIntOut + string(1, (char)(((int)'0')+ num));
		}

	}
	
	//check for conditionals
	if(longIntOut.length() == 0)
	{
		out << "0";
		return out;
	}
	else if(longIntOut.length() == 1)
	{
		if(longIntOut[0] == '0')
		{
			out << "0";
			return out;
		}
		else if(rhs.negative)
		{
			out << "-";
			out << longIntOut;
			return out;
		}
		else
		{
			out << longIntOut;
			return out;
		}
	}
	else
	{
		if(rhs.negative)
		{
			out << "-";
			out << longIntOut;
			return out;
		}
		else
		{
			out << longIntOut;
			return out;
		}
	}
	out << longIntOut;
	return out;
}
/*Mark Moerdyk*
CSS 342 Assignment 2
analyses the worst-case performance of the Euclidean algorithm
also prints out run time of entire program and each iteration  */

#include <iostream>
#include <sys/time.h>

using namespace std;

/*Euclidean()
Input: int a and b two numbers where we are trying to find gdc between a and b
Input: &counter: The address of the counter so that we can bring results out of function
return: gdc of the two numbers a and b*/
int euclidean(int a, int b, int &counter)
{
	int t; //temp holder
	
	while (b != 0)
	{
		t = a%b;
		a = b;
		b = t;
		counter++;		 
	}
	return a;
}

int main()
{
	struct timeval start, end, start1, end1; //stores time values for calculating time
	int n;
	cout << "please enter an integer. ";
	cin >> n;

	//stores values for gdc with max operations
	int gcdMax = 0;
	int maxA, maxB;
	int maxCounter = 0;

	int counter = 0;
	bool prevResults = false;
	
	gettimeofday(&start, NULL);
	for (int i = 8; i <= n; i++)
	{
		cout << "At i=" << i;
		gettimeofday(&start1, NULL);
		if (prevResults == false) //handles all combinations from 1-8
		{
			for (int a = 1; a <= i; a++)
			{
				for (int b = 1; b <= a; b++)
				{
					counter = 0;
					int gcd = euclidean(a, b, counter);

					if (counter > maxCounter)
					{
						maxA = a;
						maxB = b;
						gcdMax = gcd;
						maxCounter = counter;
					}
				}
			}
		}
		else //only have to go through combinations of new i with each number from 1 to i
		{
			for (int b = 1; b <= i; b++)
			{
				counter = 0;
				int gcd = euclidean(i, b, counter);

				if (counter > maxCounter)
				{
					maxA = i;
					maxB = b;
					gcdMax = gcd;
					maxCounter = counter;
				}
			}
		}
		gettimeofday(&end1, NULL);
		cout << "; gcd(" << maxA << "," << maxB << ") = " << gcdMax << " took " << maxCounter << " modulus operations. Time = ";
		cout <<((end1.tv_sec * 1000000 + end1.tv_usec) - (start1.tv_sec * 1000000 + start1.tv_usec)) << " usec" <<  endl;
		prevResults = true;
	}
	
	gettimeofday(&end, NULL);
	//prints total time of program
	cout <<((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)) << " usec" << endl;
}

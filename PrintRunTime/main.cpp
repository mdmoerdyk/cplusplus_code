/* Mark Moerdyk
lab 2 Sieve of Eratosthenes
Runs through the algorithm and prints out run time 
*/

#include <iostream>
#include <vector>

using namespace std;

/* Function Sieve
Inputs: Integer N that is user defined of range or vector. 
Vector that includes if prime or not for all of N.
Returns: total number of array sweeping operations*/

int sieve( int n, vector<int> &prime)
{
	int counter = 0;
	for( int i = 0; i <=n; i++)
	{
		prime[i] = true;
	}
	prime[0] = false; // sets number 1 to not be included in prime
	
	for( int i = 2; i <= n; i++)
	{
		for(int j = i * i; j < n; j += i)
		{
			prime[j-1] = false;
			counter++;
		}
	}
	return counter;
}

int main() {

	int number;
	cout << "please enter an integer. ";
	cin >> number;
	char printOption = 'n';
	cout << "print all primes (y|n)? ";
	cin >> printOption;
	
	int total = 0;
	vector<int> prime (number);
	
	total = sieve(number, prime);
	
	if(printOption == 'y')
	{
		for (int i = 1; i < number; i++)
		{
			if (prime[i - 1] == 1)
			{
				cout << i << endl;
			}
		}
	}
	cout << "run time = "<< total << endl;
}
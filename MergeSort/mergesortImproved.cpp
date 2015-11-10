/*Mark Moerdyk
CSS 342 Assignment 4*
An improved mergesort that does a merge sort
through iteration, not recursion*/

#include <vector>
#include <math.h> // may need to use pow( )
using namespace std;

template <class Comparable>
void mergesortImproved(vector<Comparable> &a) {

	int size = a.size();
	vector<Comparable> b(size);  // this is only one temporary array.     

	//pointers to the array so they can swap without copying array
	vector<Comparable> &fromArray = a;
	vector<Comparable> &toArray = b;
	
	for (int i = 1; i <= size ; i *= 2)
	{
		//loop through each set of comparators
		for(int start = 0; start <= size; start += 2 * i)
		{
			int middle = start + i;
			int end =  int(fmin(middle + i, size));
			int leftend = int(fmin(middle, size));
			int left = start, right = middle, k = start;

			//compares two sets of numbers and puts lowest in other array
			while (left < leftend  && right < end )
			{
				if ( right >= size || fromArray[left] <= fromArray[right])
				{
					toArray[k] = fromArray[left];
					left++;
				}
				else
				{
					toArray[k] = fromArray[right];
					right++;
				}
				k++;
			}
			//placing all left over numbers into array
			while (right < end)
			{
				toArray[k] = fromArray[right];
				right++;
				k++;
			}
			while (left <leftend)
			{
				toArray[k] = fromArray[left];
				left++;
				k++;
			}
		}
		
		//swap arrays so that old moves to new without making new array
		vector<Comparable> &hold = fromArray;
		fromArray = toArray;
		toArray = hold;
	}
}
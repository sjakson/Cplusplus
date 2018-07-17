/*Algorithm for dispensing stamps for a postage stamp vending machine.
Uses a function that returns the minimum number of stamps for a given value.*/

#include <iostream>
using namespace std;

int min_number_of_stamps (const int* array, size_t array_size, int request); //function that returns the minimum number of stamps for a given value
int request;

int array [] = {90,30,24,15,12,10,5,3,2,1}; //array of sorted stamp values

int main ()
{
	cout << "Welcome to the postage stamp dispensing machine" <<endl <<endl;

	cout << "What value stamp would you like: "; //prompt user for desired stamp value
	cin >> request;

	//output minimum number of stamps needed
	cout << endl << "The minimum number of stamps needed is: " << 	min_number_of_stamps (array, sizeof(array)/sizeof(array[0]) , request) << endl << endl;

  return 0;
}

int min_number_of_stamps (const int* array, size_t array_size, int currentRequest)
{
	int stampCount=0; //initialize stamp count
	int currentValue=0; //initialize current stamp value

	while(currentRequest > 0) //stay in loop until the current request value reaches zero
	{
		for (int i=0; i<array_size; i++) //cycle through array of sorted stamp values
		{
			if ((array[i] > currentValue) && (array[i] <= currentRequest)) //find the largest stamp value that is less than or equal to the current request size 
				currentValue = array[i]; //set the value from the array to the current stamp value
		}

		currentRequest = currentRequest - currentValue; //subtract the current stamp value from the current request size
		stampCount++; //increment the stamp count
		currentValue=0; //set the current stamp value back to zero

	}

return stampCount; //return the minimum number of stamps needed
}
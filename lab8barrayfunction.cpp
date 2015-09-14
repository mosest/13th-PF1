//Tara Moses
//March 7, 2015
//Lab 8b: Arrays and Functions

#include <cstdlib>
#include <iostream>
using namespace std;

void init_array(int array[], int size, int range)
{
   for (int index = 0; index < size; index++)
      array[index] = rand() % range;
}

void print_array(int array[], int size)
{
   for (int index = 0; index < size; index++)
      cout << array[index] << " ";
   cout << endl;
}

int find_max(int array[], int size) {
	int max=array[0];
	
	for (int index = 0; index < size; index++)
	{
	  if (array[index] > max)
		 max = array[index];
	}
	
	return max;
}

int find_min(int array[], int size) {
	int max=array[0];
	
	for (int index = 0; index < size; index++)
	{
	  if (array[index] < max)
		 max = array[index];
	}
	
	return max;
}

int main() {
	// Declare array of integers
	const int DATA_SIZE = 20;
	int data[DATA_SIZE] = {0};

	// Initialize and print array
	init_array(data, DATA_SIZE, 100);
	print_array(data, DATA_SIZE);
	
	int max = data[0];
	for (int index = 0; index < DATA_SIZE; index++)
	{
	  if (data[index] > max)
		 max = data[index];
	}
	cout << "max = " << find_max(data, DATA_SIZE) << endl;
	cout << "min = " << find_min(data, DATA_SIZE) << endl;
	
	return 0;
}

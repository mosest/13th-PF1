//Tara Moses
//March 7, 2015
//Lab 8a: Declaring and Using Arrays

#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
	// Declare array of integers
	const int DATA_SIZE = 20;
	int data[DATA_SIZE] = {0};
	
	//print lets go
	for (int index = 0; index < DATA_SIZE; index++)
	  cout << data[index] << " ";
	cout << endl;
	
	// Initialize array
	for (int index = 0; index < DATA_SIZE; index++)
	  data[index] = rand() % 100;

	// Print array
	for (int index = 0; index < DATA_SIZE; index++)
	  cout << data[index] << " ";
	cout << endl;

	// Reverse array
	for (int index = 0; index < DATA_SIZE/2; index++)
	{
	  int temp = data[index];
	  data[index] = data[DATA_SIZE-1-index];
	  data[DATA_SIZE-1-index] = temp;
	}

	// Print array
	for (int index = 0; index < DATA_SIZE; index++)
	  cout << data[index] << " ";
	cout << endl;

	return 0;
}

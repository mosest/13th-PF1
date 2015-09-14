//Tara Moses
//February 8, 2015
//Lab 6a: Generating Random Numbers

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int count = 1000;
	int range = 100;
	int value = 42;
	int found = 0;
	
	int seed;
	cout << "Enter seed: ";
	cin >> seed;
	srand(seed);
	for (int i=0; i < count; i++)
	{
		int num = rand() % range;
		cout << num << " ";
		if (num==value) found++;
	}
	cout << "\nthe value " << value 
		<< " was found " << found << " times\n";
	
	return 0;
}

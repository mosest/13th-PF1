//Tara Moses
//February 8, 2015
//Lab 5c: Nested For Loops

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int size = 12;
	for (int outer = 1; outer <= size; outer++)
	{
		for (int inner = 1; inner <= size; inner++)
		{
			cout << setw(5) << inner*outer << " ";
		}
		cout << endl;
	}
	
	return 0;
}

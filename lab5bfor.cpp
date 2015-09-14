//Tara Moses
//February 8, 2015
//Lab 5b: For Loops

#include <iostream>
using namespace std;

int main() {
	// Get number from user
	int input = 0;
	cout << "Enter a number:\n";
	cin >> input;

	// Print numbers from [1..input]
	for (int num = 1; num <= input; num++)
		cout << num << " ";
	cout << endl;

	// Print EVEN numbers from [0..input-1] (FIX)
	for (int i=0;i<input;i+=2) cout << i << " ";
	cout << endl;

	// Print ODD numbers from [input..1] (FIX)
	for (int i=input;i>0;i-=2) {
		if (i%2==1) cout << i << " ";
		else cout << i-1 << " ";
	}
	cout << endl;
	
	return 0;
}

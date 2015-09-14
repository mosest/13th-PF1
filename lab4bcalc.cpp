//Tara Moses
//January 29, 2015
//Lab 4b: Calculation Loops

#include <iostream>
using namespace std;

int main() {
	//get number from user
	int input = 0;
	cout << "Enter a number:\n";
	cin >> input;

	//print some numbers
	cout << "Here are some numbers:\n";
	int number = 1;
	while (number <= input) {
		cout << number << " " << number * number << " " << number * number * number << endl;
		number = number + 1;
	}

	return 0;
}

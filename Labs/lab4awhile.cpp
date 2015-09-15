//Tara Moses
//January 29, 2015
//Lab 4a: While Loops

#include <iostream>
using namespace std;

int main() {
	//get number from user
	int input = 0;
	cout << "Enter a number:\n";
	cin >> input;

	//print some numbers
	cout << "Here are some odd numbers:\n";
	int number = 1;
	while (number <= input) {
		cout << number << endl;
		number = number + 2;
	}
	cout << "Here are some even numbers:\n";
	number = 2;
	while (number <= input) {
		cout << number << endl;
		number = number + 2;
	}

	return 0;
}

//Tara Moses
//Jan 20, 2015
//Lab 2b: Data Types

#include <iostream>
using namespace std;

int main() {
	//constant declaration
	int x = 100;

	// Get user input
	int y = 0;
	cout << "Enter value for y: " << endl;
	cin >> y;

	// Perform arithmetic operations
	int sum = x + y;
	int difference = x - y;
	float quotient = 1.0 * x / y;	
	int remainder = int(x) % int(y);
	int product = x * y;
	
	// Print results 
	cout << "The sum (x + y) is: " << sum << endl;
	cout << "The difference (x - y) is: " << difference << endl;
	cout << "The quotient (x / y) is: " << quotient << endl;
	cout << "The remainder (x % y) is: " << remainder << endl;
	cout << "The product (x * y) is: " << product << endl;

	return 0;
}

//Tara Moses
//February 8, 2015
//Lab 5a: Do While Loops

#include <iostream>
using namespace std;

int main() {
	int num = 0;
	do {
		cout << "Enter a positive even number:\n";
		cin >> num;
	}
	while (num <= 0 || num%2!=0);
	cout << "num = " << num << endl;
	
	return 0;
}

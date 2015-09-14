//Tara Moses
//January 25, 2015
//Lab 3c: Switch Statements

#include <iostream>
using namespace std;

int main() {
	//read day number
	int Day = 0;
	cout << "Enter day number:\n";
	cin >> Day;

	//print day of week
	switch (Day) {
		case 1:
			cout << "Sunday\n";
			break;
		case 2:
			cout << "Monday\n";
			break;
		case 3:
			cout << "Tuesday\n";
			break;
		case 4:
			cout << "Wednesday\n";
			break;
		case 5:
			cout << "Thursday\n";
			break;
		case 6:
			cout << "Friday\n";
			break;
		case 7:
			cout << "Saturday\n";
			break;
		default: 
			cout << "Error\n";
			break;
	}
	
	return 0;
}

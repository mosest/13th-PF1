//Tara Moses
//January 25, 2015
//Lab 3b: If Statements

#include <iostream>
using namespace std;

int main() {
	//read test score
	float Score = 0;
	cout << "Enter test score:\n";
	cin >> Score;

	//check test score
	if (Score > 100)
		cout << "You are better than perfect!\n";
	else if (Score >= 90)
		cout << "Your grade is A\n";
	else if (Score >= 80)
		cout << "Your grade is B\n";
	else if (Score >= 70)
		cout << "Your grade is C\n";
	else if (Score >= 60)
		cout << "Your grade is D\n";
	else 
		cout << "Your grade is F\n";
	
	return 0;
}

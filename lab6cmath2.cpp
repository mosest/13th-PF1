//Tara Moses
//February 8, 2015
//Lab 6c: Using Math Functions II

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	int step = 20;
	
	cout << "Enter step size: " << endl;
	cin >> step;
	if (step<=0) return 0;
	
	cout << setw(10) << "degrees"
		<< setw(10) << "radians"
		<< setw(10) << "cos"
		<< setw(10) << "sin"
		<< endl;

	for (int degrees = 0; degrees <= 360; degrees += step)
	{
		double radians = degrees * M_PI / 180.0;
		cout << setw(10) << degrees
			<< setw(10) << setprecision(5) << fixed << radians
			<< setw(10) << setprecision(5) << fixed << cos(radians) 
			<< setw(10) << setprecision(5) << fixed << sin(radians) 
			<< endl;
	}
	
	return 0;
}

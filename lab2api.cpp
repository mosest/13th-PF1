//Tara Moses
//Jan 20, 2015
//Lab 2a: Pi

#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	//actual program stuff
	cout << setprecision(15);
	cout << "Here are some approximations of PI:" << endl;

	//Archimedes 225 BC
	cout << "22 / 7 = " << 22.0 / 7.0 << endl;

	//Zu Chongzhi 480 AD
	cout << "355 / 113 = " << 355.0 / 113.0 << endl;

	//Indiana law 1897 AD
	cout << "16 / 5 = " << 16.0 / 5.0 << endl;

	//C++ math library
	cout << "M_PI = " << M_PI << endl;

	return 0;
}

//Tara Moses
//January 25, 2015
//Lab 3a: Program Debugging

#include <iostream>
using namespace std;

int main() {
	//calculate area and volume of a cube
	double Height = 3.0;
	double Area = 6 * Height * Height;
	double Volume = Height * Height * Height;

	//print results
	cout << "Height = " << Height << "\n";
	cout << "Area = " << Area << "\n";
	cout << "Volume = " << Volume << "\n";

	return 0;
}

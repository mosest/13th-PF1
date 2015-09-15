//Tara Moses
//January 21, 2015
//Homework 1: Quarterback Rating

#include <iostream>
using namespace std;

int main() {
	//declare input variables
	string surname;
	string team;
	int passesAttempted;
	int passesCompleted;
	int yards;
	int touchdowns;
	int interceptions;

	//gather input
	cout << "---GATHERING INPUT---\n";
	cout << "Input quarterback surname >> ";
	cin >> surname;
	cout << "Input team name >> ";
	cin >> team;
	cout << "Input # of passes attempted >> ";
	cin >> passesAttempted;
	cout << "Input # of passes completed >> ";
	cin >> passesCompleted;
	cout << "Input # of yards thrown for >> ";
	cin >> yards;
	cout << "Input # of touchdowns >> ";
	cin >> touchdowns;
	cout << "Input # of interceptions >> ";
	cin >> interceptions;
	
	//check variable input!
	cout << "\n---CHECKING VARIABLE INPUT---\n";
	cout << "Surname >> " << surname << endl;
	cout << "Team >> " << team << endl;
	cout << "Passes attempted >> " << passesAttempted << endl;
	cout << "Passes completed >> " << passesCompleted << endl;
	cout << "Yards >> " << yards << endl;
	cout << "Touchdowns >> " << touchdowns << endl;
	cout << "Interceptions >> " << interceptions << endl;
	
	//calculate intermediate steps
	float pointRating = (100.0 * passesCompleted / passesAttempted - 30) * 0.05;
	float yardRating = (1.0 * yards / passesAttempted - 3) * 0.25;
	float touchdownRating = 20.0 * touchdowns / passesAttempted;
	float interceptionRating = 2.375 - (25.0 * interceptions / passesAttempted);
	float quarterbackRating = 100 * (pointRating + yardRating + touchdownRating + interceptionRating) / 6;
	
	//announce intermediate steps
	cout << "\n---STATISTICS---\n";
	cout << "Point rating >> " << pointRating << endl;
	cout << "Yard rating >> " << yardRating << endl;
	cout << "Touchdown rating >> " << touchdownRating << endl;
	cout << "Interception rating >> " << interceptionRating << endl;
	cout << "\nFINAL QUARTERBACK RATING >> " << quarterbackRating << endl;
	
	return 0;
}

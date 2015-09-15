//Tara Moses
//February 1, 2015
//Homework 2: Wide Receiver and Running Back

#include <iostream>
using namespace std;

int main() {
	//declare and initialize input variables
	//(they're only initialized because i didn't 
	//want to type in all the test cases every time)
	string team = "TeamName";
	string qbName = "TateQB";
	int passesAttempted = 461;
	int passesCompleted = 324;
	int qbYards = 3969;
	int qbTouchdowns = 35;
	int interceptions = 10;
	
	string wrName = "KitWR";
	int receptions = 20;
	int wrYards = 4000;
	int wrTouchdowns = 25;
	int wrFumbles = 2;
	
	string rbName = "KyleRB";
	int rushes = 5;
	int rbYards = 2000;
	int rbTouchdowns = 19;
	int rbFumbles = 21;

	//gather input
	cout << "---GATHERING INPUT---\n";
	cout << "Input team name >> ";
	cin >> team;
	cout << "Input quarterback surname >> ";
	cin >> qbName;
	cout << "Input # of passes attempted >> ";
	cin >> passesAttempted;
	cout << "Input # of passes completed >> ";
	cin >> passesCompleted;
	cout << "Input # of yards QB has thrown for >> ";
	cin >> qbYards;
	cout << "Input # of touchdowns QB made >> ";
	cin >> qbTouchdowns;
	cout << "Input # of interceptions >> ";
	cin >> interceptions;	
	
	cout << "\nInput wide receiver surname >> ";
	cin >> wrName;
	cout << "Input # of receptions >> ";
	cin >> receptions;
	cout << "Input # of yards WR has thrown for >> ";
	cin >> wrYards;
	cout << "Input # of touchdowns WR made >> ";
	cin >> wrTouchdowns;
	cout << "Input # of fumbles WR made >> ";
	cin >> wrFumbles;
	
	cout << "\nInput running back surname >> ";
	cin >> rbName;
	cout << "Input # of rushes >> ";
	cin >> rushes;
	cout << "Input # of yards RB has thrown for >> ";
	cin >> rbYards;
	cout << "Input # of touchdowns RB made >> ";
	cin >> rbTouchdowns;
	cout << "Input # of fumbles RB made >> ";
	cin >> rbFumbles;
	
	//check variable input!
	cout << "\n---CHECKING VARIABLE INPUT---\n";
	cout << "Team >> " << team << endl;
	cout << "Quarterback >> " << qbName << endl;
	cout << "Passes attempted >> " << passesAttempted << endl;
	cout << "Passes completed >> " << passesCompleted << endl;
	cout << "QB Yards >> " << qbYards << endl;
	cout << "QB Touchdowns >> " << qbTouchdowns << endl;
	cout << "Interceptions >> " << interceptions << endl;
	
	cout << "\nWide Receiver >> " << wrName << endl;
	cout << "Receptions >> " << receptions << endl;
	cout << "WR Yards >> " << wrYards << endl;
	cout << "WR Touchdowns >> " << wrTouchdowns << endl;
	cout << "WR Fumbles >> " << wrFumbles << endl;
	
	cout << "\nRunning Back >> " << rbName << endl;
	cout << "Rushes >> " << rushes << endl;
	cout << "RB Yards >> " << rbYards << endl;
	cout << "RB Touchdowns >> " << rbTouchdowns << endl;
	cout << "RB Fumbles >> " << rbFumbles << endl;
	
	//calculate statistics
	float completions = (100.0 * passesCompleted / passesAttempted - 30) * 0.05;
	float yardsPerAttempt = (1.0 * qbYards / passesAttempted - 3) * 0.25;
	float tdPasses = 20.0 * qbTouchdowns / passesAttempted;
	float interceptionPercentage = 2.375 - (25.0 * interceptions / passesAttempted);
	float wrYardsPerCatch = 1.0 * wrYards / passesCompleted;
	float rbYardsPerRush = 1.0 * rbYards / rushes;
	
	//if some numbers are out of range, then change them
	if (completions < 0) {
		completions = 0;
	} else if (completions > 2.375) {
		completions = 2.375;
	}
	
	if (yardsPerAttempt < 0) {
		yardsPerAttempt = 0;
	} else if (yardsPerAttempt > 2.375) {
		yardsPerAttempt = 2.375;
	}
	
	if (tdPasses > 2.375) {
		tdPasses = 2.375;
	}
	
	if (interceptionPercentage < 0) {
		interceptionPercentage = 0;
	}
	
	//calculate QBR with the updated numbers :3
	float quarterbackRating = 100.0 * (completions + yardsPerAttempt + tdPasses + interceptionPercentage) / 6;
	
	//announce statistics!!
	cout << "\n---STATISTICS---\n";
	cout << "Percentage of Completions >> " << completions << endl;
	cout << "Average Yards Gained Per Attempt >> " << yardsPerAttempt << endl;
	cout << "Percentage of Touchdown Passes >> " << tdPasses << endl;
	cout << "Percentage of Interceptions >> " << interceptionPercentage << endl;
	cout << "Wide Receiver: YPC >> " << wrYardsPerCatch << endl;
	cout << "Running Back: YPR >> " << rbYardsPerRush << endl;
	cout << "Quarterback Rating >> " << quarterbackRating << endl;
	
	//start finding winners
	string mostTurnoversName = qbName;
	string highestYardsName = qbName;
	string mostTouchdownsName = qbName;
	int mostTurnovers = interceptions;
	int highestYards = qbYards;
	int mostTouchdowns = qbTouchdowns;
	
	/*
	 * okay so the way i'm finding the max of each of these is:
	 * 1. assume the max is the quarterback
	 * 2. check whether WR is better than max
	 * 3. if they are, set them as max
	 * 4. check whether RB is better than max
	 * 5. if they are, set them as max
	 */
	
	if (mostTurnovers < wrFumbles) {
		mostTurnoversName = wrName;
		mostTurnovers = wrFumbles;
	}
	if (mostTurnovers < rbFumbles) {
		mostTurnoversName = rbName;
		mostTurnovers = rbFumbles;		
	}
	
	if (highestYards < receptions) {
		highestYardsName = wrName;
		highestYards = receptions;
	}
	if (highestYards < rushes) {
		highestYardsName = rbName;
		highestYards = rushes;		
	}
	
	if (mostTouchdowns < wrTouchdowns) {
		mostTouchdownsName = wrName;
		mostTouchdowns = wrTouchdowns;
	}
	if (mostTouchdowns < rushes) {
		mostTouchdownsName = rbName;
		mostTouchdowns = rbTouchdowns;		
	}
	
	//ANNOUNCE THE WINNERS OMG I'M SO PUMPED FOR WHO WON
	cout << "\n---THE WINNERS---\n";
	cout << mostTurnoversName << " had the most turnovers.\n";
	cout << highestYardsName << " had the highest yards per attempt.\n";
	cout << mostTouchdownsName << " had the most touchdowns.\n\n"; 
	
	return 0;
}

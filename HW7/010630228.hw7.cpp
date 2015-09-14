//----------------------------------------------------
// Author:     Tara Moses
// Student ID: 010630228
// Purpose:    Translates between URLs and IP 
//             using arrays loaded from a file
//----------------------------------------------------
#include "010630228.hw7.Continent.h"
#include <iostream>
#include <string>
#include <iomanip>

const int EXIT = 0;

//----------------------------------------------------
// Purpose: Find out what the user wants to do.
// Arguments: None.
// Returns: A character which indicates the users choice.
//----------------------------------------------------
int getChoice()
{
	int Choice;
	do 
	{
        cout << "\n\nEnter '1' to fill the continent from a file\n"
             << "      '2' to add a country to the continent\n"
             << "      '3' to find the country with the top GDP\n"
             << "      '4' to calculate the continent's total GDP\n"
             << "      '5' to calculate a country's percentage of the continent's total GDP\n"
             << "      '6' to find the country with the top population\n"
             << "      '7' to calculate the continent's total population\n"
             << "      '8' to calculate a country's percentage of the continent's total population\n"
             << "      '9' to print the information for all countries in the continent\n"
		     << "      '0' to quit the program\n"
             << "Selection: ";
		cin >> Choice;
	} while (Choice < 0 || Choice > 9);
	return Choice;
}


int main()
{
	Continent NorthAmerica ("NorthAmerica");
	int Choice;
	string filename;
	string name;
	float gdp;
	int population;

//  Optional - BONUS testing of Copy Constructor
    NorthAmerica.AddCountry( "USA", 3000000, 4444.7 );
    NorthAmerica.AddCountry( "Costa Rica", 40000, 12.0 );
    NorthAmerica.Print();

    Continent Duplicate (NorthAmerica);
    Duplicate.Print();
  
    NorthAmerica.Print();  // test that default constructor works
    
    do {
		Choice = getChoice();
		cout << "You picked " << Choice << endl;
		
		//switch statement!
		switch(Choice) {
			case 1:
				cout << "Enter name of file to read from: ";
				cin >> filename;
				if (NorthAmerica.ReadFromFile(filename)) cout << "Success!";
				break;
			case 2:
				cout << "Enter name of country to add: ";
				cin.ignore(); //flush the input??
				getline(cin, name);
				cout << "Enter GDP of country: ";
				cin >> gdp;
				cout << "Enter population of country: ";
				cin >> population;
				if (NorthAmerica.AddCountry(name, population, gdp)) cout << "Success!";
				break;
			case 3:
				cout << "The country with the top GDP is " << NorthAmerica.TopGDP().GetName() << ".";
				break;
			case 4:
				cout << NorthAmerica.GetName() << " has a total GDP of $" << NorthAmerica.TotalGDP() << " million.";
				break;
			case 5:
				cout << "Enter name of country: ";
				cin.ignore(); //flush the input??
				getline(cin, name);
				cout << name << " is " << NorthAmerica.GDPPercentage(name) << " percent of " << NorthAmerica.GetName() << "'s total GDP.";
				break;
			case 6:
				cout << "The country with the top population is " << NorthAmerica.TopPopulation().GetName() << ".";
				break;
			case 7:
				cout << NorthAmerica.GetName() << " has a total population of " << NorthAmerica.TotalPopulation() << " people.";
				break;
			case 8:
				cout << "Enter name of country: ";
				cin.ignore(); //flush the input??
				getline(cin, name);
				cout << name << " is " << NorthAmerica.PopulationPercentage(name) << " percent of " << NorthAmerica.GetName() << "'s total population.";
				break;
			case 9:
				NorthAmerica.Print();
				break;
			default:
				cout << "Goodbye!\n\n";
				break;
		}
	} while (Choice != EXIT);
	
	return 0;
}

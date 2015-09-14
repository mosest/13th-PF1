//-----------------------------------------------------------
// Author:     Tara Moses
// Student ID: 010630228
// Purpose:    Stores and retrieve information about continents
//-----------------------------------------------------------
#include <fstream>
#include <iostream>
#include <iomanip>
#include "010630228.hw7.Continent.h"

//---------- Constructors and Destructors -------------------
//-----------------------------------------------------------
// Name:  Default Constructor
// Sets all the entries in the country table to base values.
// Each country has 0.0 GDP, 0 population and the name is "Country"
//-----------------------------------------------------------
Continent::Continent(const string Name)
{
    name = Name;
	for (int i =0; i < MAX; i++)
	{
		countries[i].SetGDP(0.0);
		countries[i].SetPopulation(0);
		countries[i].SetName("Country");
	}
	numCountries = 0;
}


//-----------------------------------------------------------
// Name:  Copy Constructor
// Sets all the entries in the country table to values
// that match a Continent to copy from.
// Arguments:  ?
//-----------------------------------------------------------
Continent::Continent(Continent &oldContinent)
{
	cout << "Copy Constructor\n";
	
	name = oldContinent.GetName();
	for (int i=0;i<MAX;i++) {
		Country currentCountry = oldContinent.GetACountry(i);
		
		float oldGDP = currentCountry.GetGDP();
		int oldPopulation = currentCountry.GetPopulation();
		string oldName = currentCountry.GetName();
		
		countries[i].SetGDP(oldGDP);
		countries[i].SetPopulation(oldPopulation);
		countries[i].SetName(oldName);
	}
	numCountries = oldContinent.GetNumCountries();
}
//-----------------------------------------------------------
// Name:  Destructor
// This does nothing since there is no dynamic memory.
//-----------------------------------------------------------
Continent::~Continent()
{
	cout << "Destructor\n";
}

//------------------ Mutators -------------------
//-----------------------------------------------------------
// Name: ReadFromFile 
// Purpose: Fills the country array by calling the country
//	    ReadFromFile function
// Arguments: ?
// Returns: True if the file could be read and data added to
//          the array, false otherwise
//-----------------------------------------------------------

bool Continent::ReadFromFile(string filename)
{
   cout << "Read From File\n";

   //variables!
	int gdp;
	int pop;
	string name;
	
	fstream fin;
	fin.open(filename.c_str());
	
	if (fin.fail()) return false;
	while (fin >> gdp >> pop) {
		fin.ignore(); //ignore the space before name
		getline(fin, name);
		fin.ignore(); //ignore the \n
		
		//check what you read in!
		//cout << "name(" << name << "), gdp(" << gdp << "), pop(" << pop << ")\n";
		
		//add to countries[]
		countries[numCountries].SetGDP(gdp);
		countries[numCountries].SetPopulation(pop);
		countries[numCountries].SetName(name);
		
		numCountries++;
	}
	fin.close();
	return true;
}

//-----------------------------------------------------------
// Name: AddCountry
// Purpose: Adds an entry to the countries array (based on the 
//  arguments passed).
// Arguments: ?
// Returns: True if the country was successfully added, and
//  false otherwise.
//-----------------------------------------------------------

bool Continent::AddCountry(string newName, int newPop, float newGDP)
{
   cout << "Add Country\n";

   if (numCountries>=MAX) return false;
   
   countries[numCountries].SetGDP(newGDP);
   countries[numCountries].SetPopulation(newPop);
   countries[numCountries].SetName(newName);
   
   numCountries++;
   
   return true;
}
	
//------------------ Accessors -------------------
//-----------------------------------------------------------
// Name: GetName
// Purpose: Returns the name of the continent
// Arguments: none
// Returns: the name
//-----------------------------------------------------------

string Continent::GetName() const
{
   return name;
}

//-----------------------------------------------------------
// Name: GetNumCountries
// Purpose: Returns the number of contries in the continent
// Arguments: none
// Returns: the number of countries
//-----------------------------------------------------------

int Continent::GetNumCountries() const
{
   return numCountries;
}

//-----------------------------------------------------------
// Name: TopGDP
// Purpose: Finds the country with the highest GDP. Returns
//	the GDP as well as the name of the country with the
//	highest GDP
// Arguments: ?
// Returns:   The Country with the top GDP
//-----------------------------------------------------------

Country Continent::TopGDP() const
{
   Country Temp = countries[0];
   cout << "Top GDP\n";

   for (int i=0;i<numCountries;i++) {
	   if (countries[i].GetGDP()>Temp.GetGDP()) Temp=countries[i];
   } 

   return Temp;
}

//-----------------------------------------------------------
// Name: GetACountry
// Purpose: Finds the nth country in the continent.
//   This is pretty much only used for the copy constructor,
//   which i didn't know was bonus until like five seconds ago D:
// Arguments: int n, which country in the continent to return
// Returns:   The nth country
//-----------------------------------------------------------
Country Continent::GetACountry(int n) {
	return countries[n];
}

//-----------------------------------------------------------
// Name: TotalGDP
// Purpose: Calculates the continents total GDP. 
// Arguments: ?
// Returns:   A float of the Total GDP
//-----------------------------------------------------------

float Continent::TotalGDP() const
{
   cout << "Total GDP\n";

   float totalGDP = 0.0;
   for (int i=0;i<numCountries;i++) {
	   totalGDP+=countries[i].GetGDP();
   }
   return totalGDP;
}

//-----------------------------------------------------------
// Name: GDPPercentage
// Purpose: Searches for a country based on the argument passed
//	and calculates its percentage of the continents GDP
// Arguments: ?
// Returns:   A float of the percentage of the GDP or 0.0
//	if the country isn't in the list
// NOTE:	It could call TotalGDP
//-----------------------------------------------------------

float Continent::GDPPercentage(string countryName) const
{
   cout << "GDP Percentage\n";

   Country c;
   float percent=0.0;
   
   for (int i=0;i<numCountries && c.GetName()==" ";i++) {
	   if (countries[i].GetName()==countryName) c = countries[i];
   }
   
   //now we know c is the country we've been looking for
   percent = 100 * c.GetGDP() / TotalGDP();

   return percent;
}

//-----------------------------------------------------------
// Name: TopPopulation
// Purpose: Finds the country with the highest population. 
// Arguments: ?
// Returns:   The country 
//-----------------------------------------------------------

Country Continent::TopPopulation() const
{
   Country Temp;

   cout << "Top Population\n";

   for (int i=0;i<numCountries;i++) {
	   if (countries[i].GetPopulation()>Temp.GetPopulation()) Temp=countries[i];
   } 

   return Temp;
}

//-----------------------------------------------------------
// Name: TotalPopulation
// Purpose: Calculates the continents total Population. 
// Arguments: ?
// Returns:   An int of the Total Population
//-----------------------------------------------------------

int Continent::TotalPopulation() const
{
   cout << "Total Population\n";

   int totalPop = 0;
   for (int i=0;i<numCountries;i++) {
	   totalPop+=countries[i].GetPopulation();
   }
   return totalPop;
}

//-----------------------------------------------------------
// Name: PopulationPercentage
// Purpose: Searches for a country based on the argument passed
//	and calculates its percentage of the continents Population
// Arguments: ?
// Returns:   A float of the percentage of the Population or 0.0
//	if the country isn't in the list
// NOTE:	Calls TotalGDP
//-----------------------------------------------------------

float Continent::PopulationPercentage(string countryName) const
{
   cout << "Population Percentage\n";

   Country c;
   float percent=0.0;
   
   for (int i=0;i<numCountries && c.GetName()==" ";i++) {
	   if (countries[i].GetName()==countryName) c = countries[i];
   }
   
   //now we know c is the country we've been looking for
   percent = 100 * c.GetPopulation() / TotalPopulation();

   return percent;
}

//------------------  Other Useful Functions ----------------

//-----------------------------------------------------------
// Name:  Print
// Purpose: Prints out the contents of the lookup table
// 	 to the screen.
// Arguments: None
// Returns : void
//-----------------------------------------------------------
void Continent::Print() const
{
    cout << "The countries in continent " << name << " are:\n";
	for(int i=0; i < numCountries; i++)
		countries[i].Print();
}





//-----------------------------------------------------------
// Author:     Ben Gooding
// Purpose:    Stores a country's name, gdp and population 
//	DO NOT CHANGE THIS FILE
//-----------------------------------------------------------
#include "010630228.hw7.Country.h"
#include <fstream>
#include <iostream>

//---------- Constructors and Destructors -------------------
//-----------------------------------------------------------
// Name:  Default Constructor
// Sets the country's GDP to 0.0, Population to 0 and
// Name to " "
//-----------------------------------------------------------
Country::Country()
{
	//cout << "Constructor\n";
	gdp = 0.0;
	population = 0;
	name = " ";
}

//-----------------------------------------------------------
// Name:  Copy Constructor
// Sets the country's instance variables to be the same as
// the provided parameter's
//-----------------------------------------------------------
Country::Country(const Country &OtherCountry)
{
	//cout << "Copy Constructor\n";
	gdp = OtherCountry.gdp;
	population = OtherCountry.population;
	name = OtherCountry.name;
}
//-----------------------------------------------------------
// Name:  Destructor
// This does nothing since there is no dynamic memory.
//-----------------------------------------------------------
Country::~Country()
{
	//cout << "Destructor\n";
}

//------------------ Mutators -------------------
//-----------------------------------------------------------
// Name: ReadFromFile 
// Purpose: Fills Country's GDP, Name and Population
// from an open stream passed as an arg.
// Arguments: The stream from which we should read
// Return:	True if there was data to be read,
//   False otherwise.
//-----------------------------------------------------------

bool Country::ReadFromFile(ifstream &din)
{
bool Success = false;
float temp;
  // cout << "ReadFromFile\n";
   din >> temp;
   if (!din.eof())
   {
      gdp = temp;
      din >> population;
      getline(din, name);
      Success = true;
   }
   return Success;
}

//-----------------------------------------------------------
// Name: SetAll 
// Purpose: Set the Country's Name, Population, and GDP 
// based on the information passed as parameters 
// Arguments: The name, population, and  gross domestic product
// Return:	void
//-----------------------------------------------------------

void Country::SetAll(const string Name, const int Population, const float GDP)
{
   //cout << "SetAll\n";
    SetName (Name); 
    SetPopulation(Population);
    SetGDP(GDP);
}

//-----------------------------------------------------------
// Name: SetGDP 
// Purpose: Set the Country's GDP based on the information
// passed as an arg. If the GDP is less than 0 set it to 0.
// Arguments: The gross domestic product
// Return:	void
//-----------------------------------------------------------

void Country::SetGDP(const float GDP)
{
	//cout << "Set GDP\n";
	if(GDP > 0)
		gdp = GDP;
	else
		gdp = 0;
}

//-----------------------------------------------------------
// Name: SetPopulation 
// Purpose: Set the Country's population based on the information
// passed as an arg. If the popluation is less than 0 set it to 0
// Arguments: The population
// Return:	void
//-----------------------------------------------------------

void Country::SetPopulation(const int Population)
{
	//cout << "Set Population\n";
	if(Population > 0)
		population = Population;
	else
		population = 0;
}

//-----------------------------------------------------------
// Name: SetName 
// Purpose: Set the Country's name based on the information
// passed as an arg.
// Arguments: The name of the country
// Return:	void
//-----------------------------------------------------------

void Country::SetName(const string Name)
{
	//cout << "Set Name\n";
	name = Name;
}
	
//------------------ Accessors -------------------
//-----------------------------------------------------------
// Name: GetGDP
// Purpose: Get the country's GDP
// Arguments: None
// Returns:   GDP, float
//-----------------------------------------------------------

float Country::GetGDP() const
{
	//cout << "Get GDP\n";
	return gdp;
}

//-----------------------------------------------------------
// Name: GetPopulation
// Purpose: Get the country's population
// Arguments: None
// Returns:   Population
//-----------------------------------------------------------

int Country::GetPopulation() const
{
	//cout << "Get Population\n";
	return population;
}

//-----------------------------------------------------------
// Name: GetName
// Purpose: Get the country's Name
// Arguments: None
// Returns:   Name, string
//-----------------------------------------------------------

string Country::GetName() const
{
	//cout << "Get Name\n";
	return name;
}

//-----------------------------------------------------------
// Name: GetInfo
// Purpose: Gets all the country's info
// Arguments: Name, GDP and 
//            Population. All of which are reference
//	      parameters.
// Returns:   void
//-----------------------------------------------------------

void Country::GetInfo(string &Name, int &Population, float &GDP) const
{
	//cout << "Get Info\n";
	Name = name;
	Population = population;
	GDP = gdp;
}

//------------------  Other Useful Functions ----------------

//-----------------------------------------------------------
// Name:  Print
// Purpose: Prints out the country's information in the same
//	    format as the countries.txt file;  Note that the GDP
//      in is stored in millions (e.g., 143 means 143 million)
// Arguments: None
// Returns : void
//-----------------------------------------------------------

void Country::Print() const
{
	cout << "   " << name << " has a population of " << population 
         << " and a GDP of $" << gdp << " million." << endl;
}

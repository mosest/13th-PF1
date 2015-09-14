//-----------------------------------------------------
// Author:    Ben Gooding
// Purpose:    Stores a country's name, gdp and population 
//	DO NOT CHANGE THIS FILE
//-----------------------------------------------------
#include <string>
#include <fstream>

using namespace std;
class Country
{
	public:
        // Constructors and Destructors
		Country();    // Default Constructor
		Country(const Country &OtherCountry);    // Copy Constructor
		~Country();   // Destructor
        
        // Mutators
		bool ReadFromFile(ifstream &din);
		void SetAll(const string Name, const int Population, const float GDP);
		void SetName(const string Name); 
		void SetPopulation(const int Population);
		void SetGDP(const float GDP);
   
        // Accessors
		string GetName() const;
		int GetPopulation() const;
		float GetGDP() const;
		void GetInfo(string &Name, int &Population, float &GDP) const;

        // Other Useful Methods
      	void Print() const;

	private:
		float gdp;   // stores gdp in millions
		string name;
		int population;
};

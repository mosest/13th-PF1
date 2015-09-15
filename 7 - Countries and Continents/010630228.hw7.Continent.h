//-----------------------------------------------------
// Author:     Tara Moses
// Student ID: 010630228
// Purpose:    Translates between URLs and IP addresses 
//             using arrays filled from files
//-----------------------------------------------------
#include "010630228.hw7.Country.h"

class Continent
{
	public:
        // Constructors and Destructors
		Continent(const string Name = "Continent");    // Default Constructor
        Continent (Continent &c);  // Copy Constructor 
		~Continent();   // Destructor
        
        // Mutators
		bool ReadFromFile(string filename); 
		bool AddCountry(string name, int pop, float gdp);
   
        // Accessors
        string GetName() const;
        int GetNumCountries() const;
        Country GetACountry(int i);
		
        // Other Useful Methods
       	void Print() const;
		Country TopGDP() const;
		float TotalGDP() const;
		float GDPPercentage(string name) const;
		Country TopPopulation() const;
		int TotalPopulation() const;
		float PopulationPercentage(string name) const;

	private:
		static const int MAX = 100; // Maximum number of countries
        string name;
		Country countries[MAX];
		int numCountries;	        // Current number of entries array
};

//-----------------------------------------------------
// Author:     Tara Moses
// Student ID: 010630228
// Purpose:    Translates between URLs and IP addresses 
//             using arrays filled from files
//-----------------------------------------------------
#include <string>
using namespace std;
class DNS
{
	public:
        // Constructors and Destructors
		DNS();    // Default Constructor
		~DNS();   // Destructor
        
        // Mutators
		bool FillArraysFromFile(const string Filename); 
		bool AddWebsite(const string IP, const string Website);
   
        // Accessors
		string LookupWebsiteURL(const string query) const;
		string LookupIPAddress(const string query) const;

        // Other Useful Methods
        void Print() const;
		bool IsValidURL(const string query) const;
		bool IsValidIP(const string query) const;

	private:
		static const int MAX = 20; // Capacity of the lookup table
		int numentries;		        // Current number of entries in the lookup table
		string ipAddresses[MAX];    // Array that holds the ip addresses
		string websiteURLs[MAX];    // Array that holds the web URLs
};

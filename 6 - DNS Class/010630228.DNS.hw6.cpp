//-----------------------------------------------------------
// Author:     Tara Moses
// Student ID: 010630228
// Purpose:    Translates between website urls and IP 
//             addresses using the file list.txt for
// 	           translation.
//-----------------------------------------------------------
#include <fstream>
#include <iostream>
#include <iomanip>
#include "010630228.DNS.hw6.h"

using namespace std;

//---------- Constructors and Destructors -------------------
//-----------------------------------------------------------
// Name:  Default Constructor
// Sets all the entries in the lookup table to the empty 
// string and sets the number of entries equal to 0.
//-----------------------------------------------------------
DNS::DNS()
{
	for (int i=0;i<MAX;i++) {
		ipAddresses[i] = "";
		websiteURLs[i] = "";
	}
	numentries = 0;
}

//-----------------------------------------------------------
// Name:  Destructor
// This does nothing since there is no dynamic memory.
//-----------------------------------------------------------
DNS::~DNS()
{
}

//------------------ Mutators -------------------
//-----------------------------------------------------------
// Name: FillArraysFromFile 
// Purpose: Fills in the lookup table with addresses
// from the filename passed as an arg.
// Arguments: The filename of the file we should 
//   use to populate the lookup table.
// Return:	True if the file opened successfully and
//   the lookup table was successfully 
//   populated. False otherwise.
//-----------------------------------------------------------
bool DNS::FillArraysFromFile(const string filename) {
	//variables!
	string ip;
	string url;
	
	fstream fin;
	fin.open(filename.c_str());
	
	if (fin.fail()) return false;
	while (fin >> ip >> url) {
		ipAddresses[numentries] = ip;
		websiteURLs[numentries] = url;
		numentries++;
	}
	fin.close();
	return true;
}
	
//------------------ Accessors -------------------
//-----------------------------------------------------------
// Name: LookupWebsiteURL
// Purpose: Finds the address of the Website associated with
// 	 the IP address passed in as an argument.  If the
// 	 IP address passed in as an argument does not exist
// 	 in the table, the function returns "nonexistent".
// Arguments: An IP address (pass by value string)
// Returns:   A string which is either a Website
// 	  address or the string "nonexistent".
//-----------------------------------------------------------
string DNS::LookupWebsiteURL(const string ip) const {
	for (int i=0;i<numentries;i++) {
		if (ipAddresses[i]==ip) return websiteURLs[i];
	}
	return "nonexistent";
}

//-----------------------------------------------------------
// Name:  LookupIPAddress
// Purpose: Finds the address of the IP associated with the
// 	 web address passed in as an argument.  If the web
// 	 address passed in as an argument does not exist in
// 	 the table, the function returns "nonexistent".
// Arguments: A web address (pass by value string).
// Returns: A string which is either an IP address or
// 	 the string "nonexistent".
//-----------------------------------------------------------
string DNS::LookupIPAddress(const string url) const {
	for (int i=0;i<numentries;i++) {
		if (websiteURLs[i]==url) return ipAddresses[i];
	}
	return "nonexistent";
}

//------------------  Other Useful Functions ----------------

//-----------------------------------------------------------
// Name:  IsValidIP - OPTIONAL BONUS (do last)
// Purpose: Checks to make sure the argument is in the proper
// IP address format.  For simplicity, just check that the
// string parameter is between 7 and 15 characters long,
// contains exactly 3 '.'s, that all other
//   characters in the string are digits.  
// Arguments: String (pass by value)
// Returns:   true if the arguments is in the proper format
//   and false otherwise.
//-----------------------------------------------------------
bool DNS::IsValidIP(const string ip) const {
	return true;
}

//-----------------------------------------------------------
// Name:  IsValidURL - OPTIONAL BONUS (do last)
// Purpose: Checks to make sure the argument is in the format of a
// 	 web address.  For simplicity, the string should 
//   begin with www. and contain exactly 2 periods
// Arguments: A string (pass by value)
// Returns  : true if the argument is in the proper web address
// 	   format and false otherwise.
//-----------------------------------------------------------
bool DNS::IsValidURL(const string url) const {
	return true;
}

//-----------------------------------------------------------
// Name: AddWebsite
// Purpose: Adds an entry to the lookup table (based on the 
//  arguments passed).
// Arguments: an IP address (pass by value string) and a Website
//    name (pass by value string)
// Returns: True if the Website was successfully added, and
//  false otherwise.
//-----------------------------------------------------------
bool DNS::AddWebsite(const string ip, const string url) {
	if (numentries>=MAX) return false;
	if (!IsValidIP(ip) || !IsValidURL(url)) return false;
	ipAddresses[numentries] = ip;
	websiteURLs[numentries] = url;
	numentries++;
	return true;
}

//-----------------------------------------------------------
// Name:  Print
// Purpose: Prints out the contents of the lookup table
// 	 to the screen.
// Arguments: None
// Returns : void
//-----------------------------------------------------------
void DNS::Print() const
{
	for (int i=0;i<numentries;i++) {
		cout << ipAddresses[i] << " " << websiteURLs[i] << endl;
	}
}


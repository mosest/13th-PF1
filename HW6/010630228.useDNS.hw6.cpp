//----------------------------------------------------
// Author:     Tara Moses
// Student ID: 010630228
// Purpose:    Translates between URLs and IP 
//             using arrays loaded from a file
//----------------------------------------------------

#include <iostream>
#include <string>
#include <cctype>
#include "010630228.DNS.hw6.cpp"

using namespace std;

const char EXIT = 'Q';

//----------------------------------------------------
// Purpose: Find out what the user wants to do.
// Arguments: None.
// Returns: A character which indicates the users choice.
//----------------------------------------------------
char getChoice()
{
	char choice = ' ';
	do 
	{
        cout << "\n\nEnter 'F' to fill the lookup table from a file\n"
             << "      'A' to add an entry to the lookup table\n"
             << "      'U' to find a URL for a given IP address\n"
             << "      'I' to find an IP address for a given URL\n"
             << "      'P' to print the contents of the lookup table\n"
		     << "      'Q' to quit the program\n"
             << "Selection: ";
		cin >> choice;
		choice = toupper(choice);
	} while (choice != 'F' && choice != 'A' && choice != 'U' && choice != 'I' && choice != 'P' && choice != 'Q');
	return choice;
}

//----------------------------------------------------
// Purpose: Add an entry to the lookup table associated
// 	 with the argument.
// It prompts the user for the ip address and URL to add
// OPTION:  it checks that the ip address and URL
// are valid before adding them to the table
// It calls the AddWebsite method with the user-provided
// strings.
// Argument: A DNS object (pass by reference)
// Returns: Void
//----------------------------------------------------
void AddWebsite(DNS &Dns)
{
	string ip, url;
	
	cout << "IP to add: ";
	cin >> ip;
	cout << "URL to add: ";
	cin >> url;
	
	Dns.AddWebsite(ip, url);
}

int main()
{
	//variables!
	char c;
	string filename;
	string ip;
	string url;	
	DNS Dns;
	
	cout << "Hello! This is a program that relates IP addresses to URLs.";
	
	do {
		c = getChoice();
		switch (c) {
			case 'F':
				cout << "Give me a file to read from: ";
				cin >> filename;
				if (Dns.FillArraysFromFile(filename.c_str()))
					cout << "The file has been read!";
				break;
			case 'A':
				AddWebsite(Dns);
				break;
			case 'U':
				cout << "Give me an IP to find the URL of: ";
				cin >> ip;
				url = Dns.LookupWebsiteURL(ip);
				cout << "The url that matches that is: " << url << endl;
				break;
			case 'I':
				cout << "Give me a URL to find the IP of: ";
				cin >> url;
				ip = Dns.LookupIPAddress(url);
				cout << "The ip that matches that is: " << ip << endl;
				break;
			case 'P':
				Dns.Print();
				break;
			case 'Q':
				cout << "Goodbye!\n\n";
				break;
			default:
				cout << "I don't know what's going on ;_;\n";
		}
	} while (c!='Q');
	
	return 0;
}

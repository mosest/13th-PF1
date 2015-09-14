//Tara Moses
//February 10, 2015
//Lab 7b: Functions with Value Parameters

#include <iostream>
using namespace std;

char GetConcert()
{
   char Concert;
   cout << "The following concerts are available:\n";
   cout << "     B for Beyonce\n";
   cout << "     L for Lady Gaga\n";
   cout << "     T for Taylor Swift\n";
   cout << "Enter the letter for the concert you want:\n";
   cin >> Concert;
   return Concert;
}

int GetNumTickets()
{
   int NumTickets;
   cout << "Enter the number of tickets you want:\n";
   cin >> NumTickets;
   while ((NumTickets < 0) || (NumTickets > 10))
   {
      if (NumTickets < 0)
         cout << "You can not sell tickets here.\n";
      else if (NumTickets > 10)
         cout << "You may not purchase more than 10 tickets.\n";
      cout << "Enter the number of tickets you want:\n";
      cin >> NumTickets;
   }
   return NumTickets;
}

float GetCost(char show, int num)
{
   float Cost = 0;
   
   // Beyonce tickets are $35 each
   if (show=='B') Cost = 35.0 * num;
   
   // Lady Gaga tickets are $45 each
   if (show=='L') Cost = 45.0 * num;
   
   // Taylor Swift tickets are $40 each
   if (show=='T') Cost = 40.0 * num;
   
   // Give 10% discount on 5 or more tickets
   if (num >= 5) Cost*=0.9;
   
   return Cost;
}

int main() {
	// Declare variables 
	char Concert = 0;
	int NumTickets = 0;
	float Cost = 0;

	// Call function to find out the concert they want to attend
	Concert = GetConcert();

	// Call function to find out how many tickets they want
	NumTickets = GetNumTickets();

	// Call function to get total cost
	Cost = GetCost(Concert, NumTickets);

	// Print out the information you have collected.
	cout << "\nThe customer has placed the following order:\n";
	cout << "Concert: " << Concert << endl;
	cout << "Number of Tickets: " << NumTickets << endl;
	cout << "Total Cost: " << Cost << endl;
	
	return 0;
}

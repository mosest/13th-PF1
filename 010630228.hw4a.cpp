//---------------------------------------------------------------------------
// Program:  hw4a.cpp
// Purpose:  This program simulates purchasing Airline seats
//---------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

const float CARGO_PRICE = 22.38;
const float PASSENGER_PRICE = 82.00;
const float BUSINESS_PRICE = 100.00;
const float FIRST_CLASS_PRICE = 120.00;
const float PREMIUM_PRICE = 70.00;

//---------------------------------------------------------------------------
// Name: GetYorN
// Parameters: Questions, string, input, the YN question to ask
// Returns: char; the character the user entered.  Must be 'y' or 'Y' or 'n' or 'N'
// Purpose: This function returns the user's response to a yes/no question
//---------------------------------------------------------------------------
char GetYorN(const string Question)
{
   char Choice;

   cout << Question << "  Enter Y or N: ";
   cin >> Choice;
   Choice = toupper(Choice);

   while (Choice != 'Y' && Choice != 'N')
   {
      cout << "Invalid character. Please enter either (Y) for yes or (N) for no.\n";
      cout << Question << "  Enter Y or N: ";
      cin >> Choice;
      Choice = toupper(Choice);
   }

   return (Choice);
}

//---------------------------------------------------------------------------
// Name: CalculatePrice
// Parameters:  SeatName:  string, pass by value, name of seat type
//              PricePerSeat: float, pass by value, cost of one seat
//              NumSeats, int, input, number of seats to purchase.
// Returns: float - the total cost of the seats purchased
// Purpose: This function calculates and returns the cost of the seats;
//          It also prints out that cost to the user.
//---------------------------------------------------------------------------
float CalculatePrice(const string SeatName, const float PricePerSeat, const float NumSeats)
{
   float Amount;

   Amount = NumSeats * PricePerSeat;

   cout << "\n--------------------------------------------------------------------------\n";
   cout << "You have chosen to order " << noshowpoint << setprecision(0) << NumSeats 
        << " "  << SeatName << " tickets.\n";
   cout << fixed << showpoint << setprecision(2);
   cout << "Each ticket costs $" << PricePerSeat << ".\n";
   cout << "The price for these tickets is $" << Amount << endl;
   cout << "--------------------------------------------------------------------------\n\n";
   
   return Amount;
}

//---------------------------------------------------------------------------
// Name: AddPremium
// Parameters: Price, float, input/output, current cost of the seats
//             It gets updated if the user selects the premium upgrade
//             NumSeats, const int, input, the number of seats.
// Returns: none
// Purpose: This function adds the cost of the premium upgrade, if the patron
//          chooses to purchase it
//---------------------------------------------------------------------------
void AddPremium(float &Price, const int NumSeats)
{
char Choice;

    cout << "\n----------------------------------------------------------------------------------------------\n";
    cout << "You have chosen to order First Class seat tickets.\n";
    cout << "You can add a premium package that includes a souvenir and free Bose Headphones.\n"
         << "This costs $" << PREMIUM_PRICE << " per ticket.\n";
    cout << "----------------------------------------------------------------------------------------------\n\n";

    Choice = GetYorN("Would you like to add the premium package?");
	
	if (Choice == 'Y')
	{
	    Price = Price + NumSeats * PREMIUM_PRICE;
            cout << "Your First Class seats with the premium upgrade cost $"
                 << fixed << showpoint << setprecision(2) << Price
                 << " for " << noshowpoint << setprecision (0) << NumSeats << " seat.\n";
	}	
}

//---------------------------------------------------------------------------
// Name: MainMenu
// Parameters: none
// Returns: none
// Purpose: This function prints the main menu describing various seats
//          offered by Razorback Airlines
//---------------------------------------------------------------------------
void MainMenu()
{
    char MoreInfo;

    cout << "The Razorback Airlines offers its patrons an assortment\n"
         << "of seats to fit different budgets.\n"
         << "There are four kinds of seats that the Razorback Airlines offers:\n"
         << "Cargo, Passenger, Business, and First Class seats.\n\n";

    MoreInfo = GetYorN("Would you like more information about each seat type?");

    if(MoreInfo == 'Y')
    {
        cout << "The Cargo seats are the cheapest, because the seats"
             << " are located with all of the cargo!\n";
			 
        cout << "The Passenger seats are a fair price. These seats are where "
             << "majority of airline passengers sit.\n";

        cout << "The Business seats are for the travelling executive, "
             << "because the seats are very comfortable and suited for completing work.\n";
			 
        cout << "The First Class seats are the most expensive, "
             << "because the seats are very comfortable, include free food, and luxury massages.\n"
             << "First class seat purchasers can also add other options (souvenirs and Bose headphones)"
             << " to their purchase.\n\n";
   }
}

//---------------------------------------------------------------------------
// Name: SeatType
// Parameters: none
// Returns: char; the selection of ticket to be purchased
// Purpose: This function asks the user which ticket they would like to buy
//---------------------------------------------------------------------------
char GetSeatType()
{
    char SeatType;

    cout << "\nWhich seat would you like to purchase next?\n";
    cout << "Type C for cargo, P for passenger, B for business, or F for first class: ";
    cin >> SeatType;
    SeatType = toupper(SeatType);   //convert to uppercase

    //User I/O error-checking
    while(SeatType != 'C' && SeatType != 'P' && SeatType != 'B' && SeatType != 'F')
    {
        cout << SeatType << " is invalid input.\n";
        cout << "Type C for cargo, P for passenger, B for business, or F for first class: ";
        cin >> SeatType;
        SeatType = toupper(SeatType);
    }

    return SeatType;
}

//---------------------------------------------------------------------------
// Name: CargoSeat
// Parameters: none
// Returns: bool; whether the seat was purchased
// Purpose: This function alerts the user to selecting cargo seats
//---------------------------------------------------------------------------
bool CargoSeat()
{
   cout << "\n--------------------------------------------------------------------------\n";
   cout << "You have chosen to order one cargo seat (only one seat available at a time).\n"
        << "You will be sitting with all the luggage...\n";

   char answer = GetYorN("Are you sure you want to purchase this seat?");

   if(answer == 'Y')
   {
      cout << "\nYou have chosen to order one cargo seat.\n";
      cout << fixed << showpoint << setprecision(2);
      cout << "The seat costs $" << CARGO_PRICE << ".\n";
      cout << "--------------------------------------------------------------------------\n\n";
      return true;
   }
   else
   {
      cout << "You have chosen NOT to purchase a cargo seat.\n";
      cout << "--------------------------------------------------------------------------\n\n";
      return false;
   }
}

//---------------------------------------------------------------------------
// Name: FirstClassSeat
// Parameters: none
// Returns: none
// Purpose: This function thanks the user for purchasing First class seats
//---------------------------------------------------------------------------
void FirstClassSeat()
{
   cout << "\n--------------------------------------------------------------------------\n";
   cout << "You have chosen to order one first class seat (only one seat available at a time)."
        << " You will be sitting with all the celebrities! Maybe you will see Bill Gates!!!!\n";
   cout << "A first class seat costs: $" << FIRST_CLASS_PRICE << ".\n";
   cout << "--------------------------------------------------------------------------\n\n";
}

//---------------------------------------------------------------------------
// Name: PassengerSeat
// Parameters: price; float, the cost of a seat
//             NumSeats; int, the number of seats purchased
// Returns: nothing
// Purpose: This function processes a passenger seats order
//---------------------------------------------------------------------------
void PassengerSeat(float &Price, int &NumSeats)
{
   cout << "\n--------------------------------------------------------------------------\n";
   cout << "You have chosen to order standard passenger seats.\n";
   cout << "How many seats would you like to order? ";
   cin >> NumSeats;
   cout << endl;

   while(NumSeats < 1)
   {
      cout << "You need to order at least one seat.\n"
           << "How many seats would you like to order? ";
      cin >> NumSeats;
      cout << endl;
   }
   
   cout << endl;
   Price = CalculatePrice("Passenger", PASSENGER_PRICE, float(NumSeats));
   cout << "Thank you for purchasing passenger seats.\n";
   cout << "--------------------------------------------------------------------------\n\n";

}

//---------------------------------------------------------------------------
// Name: BusinessSeat
// Parameters: none
// Returns: int; number of seats purchased
// Purpose: This function processes a business class seat order
//---------------------------------------------------------------------------
int BusinessSeat()
{
   int NumSeats = 0;
   cout << "\n--------------------------------------------------------------------------\n";
   cout << "You have chosen to order business class seats.\n";
   cout << "How many seats would you like to order? ";
   cin >> NumSeats;
   cout << endl;

   while(NumSeats < 1)
   {
      cout << "You need to order at least one seat.\n"
           << "How many seats would you like to order? ";
      cin >> NumSeats;
      cout << endl;
   }

   cout << endl;
   cout << "Thank you for purchasing " << NumSeats << " business class seats.";
   cout << "--------------------------------------------------------------------------\n\n";

   return NumSeats;
}

//---------------------------------------------------------------------------
// 	This is the main program that you need to write
//---------------------------------------------------------------------------
int main ()
{
   // Variable Declarations
   char Choice = 'a';  // what the user enters
   int NumSeats = 0; // how many seats they want to buy
   int TotalSeats = 0; // total number of seats sold so far
   float Price = 0.0; // the price of one set of seat
   float TotalPrice = 0.0; // the total price of all seats
   char ExitChoice = 'N'; //whether or not the user wants to exit

   // Print your name and UAID
   cout << "Name: Tara Moses\n"
        << "UAID: 010630228\n\n";
		
   // Loop until the user is done
   do {   
       // Print the main menu describing the tickets offered
       MainMenu();
	   
       // Ask the user type what seat they want to purchase next
       Choice = GetSeatType();
       
       switch(Choice) { 	   
		   case 'B':
			   // If the user selects business class calculate the price of tickets
			   NumSeats = BusinessSeat();
			   Price = CalculatePrice("Business Class", BUSINESS_PRICE, NumSeats);
			   break;
			   
		   case 'P':
			   // if the user selects passenger class be sure to note the reference parameters
			   PassengerSeat(Price, NumSeats);
			   break;
			   
		   case 'F':
			   // If the user selects First Class seats, ask if they want the premium package
			   NumSeats = 1;
			   FirstClassSeat();
			   Price = FIRST_CLASS_PRICE;
			   AddPremium(Price, NumSeats);
			   break;
			   
		   case 'C':
			   // If the user selected cargo seats make sure they decided to order them
			   if (CargoSeat()) {
				   NumSeats = 1;
				   Price = CARGO_PRICE;
			   }
			   break;		   
	   }
	   
       // Add the seat price and number of tickets to a running total
       TotalPrice += Price;
       TotalSeats += NumSeats;

       // Ask if they want to continue (Y or N)
       ExitChoice = GetYorN("Would you like to purchase more tickets?");
       cout << endl;

       // When the loop is done
   } while (ExitChoice != 'N');

   // Print out the total number of tickets sold 
   // and the amount of all the tickets and parking passes 
   // that the participant has purchased to 2 decimal places, with a $
   cout << "-----------------------------------------------\n";
   cout << "Total number of tickets: " << TotalSeats << endl;
   cout << "Total price: $" << setprecision(2) << fixed << TotalPrice << endl << endl;
   
   return 0;
}

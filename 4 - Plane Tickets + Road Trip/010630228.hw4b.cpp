
// Purpose:  This program allows a user to calculate moving costs
//---------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

// City Options
const char KANSAS_CITY = 'K';
const char ANCHORAGE = 'A';
const char PANAMA_CITY = 'P';

// City Distances
const float KANSAS_CITY_DISTANCE = 236.7;
const float ANCHORAGE_DISTANCE = 3766.3;
const float PANAMA_CITY_DISTANCE = 818.7;

// Vehicle types
const char HYBRID = 'H';                
const char TRUCK = 'T';
const char CAR = 'C';
const char SUV = 'S';

// Vehicle MPG
const int HYBRID_MPG = 37;                
const int TRUCK_MPG = 20;
const int SUV_MPG = 23;
const int CAR_MPG = 30;

// AVG Gas Cost
const float GAS_COST = 3.12;

// AVG Speed in Miles Per Hour
const int AVG_SPEED = 70;

//---------------------------------------------------------------------------
// Name: GetVehicleType
// Parameters: None
// Returns: char; The type of vehicle selected
// Purpose: Display Vehicle Menu and get 
//---------------------------------------------------------------------------
char GetVehicleType() {
	char vehicleChar;
	
	cout << "---VEHICLE SELECTION---\n";
	cout << "Hey buddy, do you want a (H)ybrid, (T)ruck, (C)ar, or (S)UV? ";
	cin >> vehicleChar;
	vehicleChar = toupper(vehicleChar);
	
	while (vehicleChar!=HYBRID && vehicleChar!=TRUCK && vehicleChar!=CAR && vehicleChar!=SUV) {
		cout << "Unacceptable input. Choose H, T, C, or S: ";
		cin >> vehicleChar;
		vehicleChar = toupper(vehicleChar);
	}
	
	switch(vehicleChar) {
		case HYBRID:
			cout << "You chose a hybrid.";
			break;
		case TRUCK:
			cout << "You chose a truck.";
			break;
		case CAR:
			cout << "You chose a car.";
			break;
		case SUV:
			cout << "You chose a SUV.";
			break;
	}
	
	cout << endl << endl;
	return vehicleChar;
}

//---------------------------------------------------------------------------
// Name: GetGallonsNeeded
// Parameters: VehicleMPG, int; TravelDistance, float
// Returns: float; gallons of gas that will be used on the trip
// Purpose: Get the type of vehicle and the type of rental the user chose 
// NOTE:  Called by GetTotalGasCost
//---------------------------------------------------------------------------
float GetGallonsNeeded(int VehicleMPG, float TravelDistance) {
	return TravelDistance / VehicleMPG;
}

//---------------------------------------------------------------------------
// Name: GetMPG
// Parameters: VehicleType, char;
// Returns: int; vehicles miles per gallons
// Purpose: Gets the vehicles miles per gallon
// NOTE:  Called by GetTotalGasCost
//---------------------------------------------------------------------------
int GetMPG(char VehicleType) {
	switch(VehicleType) {
		case CAR:
			return CAR_MPG;
			break;
		case HYBRID:
			return HYBRID_MPG;
			break;
		case SUV:
			return SUV_MPG;
			break;
	}
	return TRUCK_MPG;
}

//---------------------------------------------------------------------------
// Name: GetGasCost
// Parameters: VehicleType, char, TravelDistance, float;
//             GallonsNeeded, float (reference parameter)
// Returns: float The total cost of gas to get to the destination
// Purpose: Calculates the Total Cost of Gas for the trip
// NOTE:  Calls GetGallonsNeeded and GetMPG (call before GetGallonsNeeded)
//---------------------------------------------------------------------------
float GetGasCost(char VehicleType, float TravelDistance, float &GallonsNeeded) {
	GallonsNeeded = GetGallonsNeeded(GetMPG(VehicleType), TravelDistance);
	return GallonsNeeded * GAS_COST;
}

//---------------------------------------------------------------------------
// Name: MainMenu
// Parameters: none
// Returns: none
// Purpose: Display some message about Spring Break coming up and needing
//            to choose a vehicle and destination.
//---------------------------------------------------------------------------
void MainMenu() {
	cout << "SPRING BREAK IS HERE NERDS. PICK A VEHICLE AND A DESTINATION." << endl << endl;
}

//---------------------------------------------------------------------------
// Name: GetHours
// Parameters: Distance, float;
// Returns: int, Hours it takes to get to the destination
// Purpose: Calculates the number of hours it take to get to the destination
//---------------------------------------------------------------------------
int GetHours(float Distance) {
	return Distance / AVG_SPEED;
}

//---------------------------------------------------------------------------
// Name: GetDestination
// Parameters: Destination, char; Distance, float (reference parameter)
// Returns: none
// Purpose: Display and get the user's destination choice and passes
//          the distance of the destination back to main
//---------------------------------------------------------------------------
void GetDestination(char &Destination, float &Distance) {
	cout << "---DESTINATION DECISION---\n";
	cout << "Hey buddy, do you want to go to (A)nchorage, (P)anama City, or (K)ansas City? ";
	cin >> Destination;
	Destination = toupper(Destination);
	
	while (Destination!=ANCHORAGE && Destination!=KANSAS_CITY && Destination!=PANAMA_CITY) {
		cout << "Unacceptable input. Choose A, P, or K: ";
		cin >> Destination;
		Destination = toupper(Destination);
	}
	
	cout << "Your destination choice is ";
	switch(Destination) {
		case ANCHORAGE:
			cout << "Anchorage.";
			Distance = ANCHORAGE_DISTANCE;
			break;
		case KANSAS_CITY:
			cout << "Kansas City.";
			Distance = KANSAS_CITY_DISTANCE;
			break;
		case PANAMA_CITY:
			cout << "Panama City.";
			Distance = PANAMA_CITY_DISTANCE;
			break;
	}
	
	cout << endl << endl;
}

//---------------------------------------------------------------------------
// Main program
//---------------------------------------------------------------------------
int main ()
{
   // Declarations
   char Destination;	// The destination chosen
   char VehicleType;        // The vehicle type you wish to drive from
   float Cost;              // The cost of your gas 
   float Distance; // The distance that will be travelled
   float GallonsNeeded;     // The number of gallons needed to get to the destination
   int Hours;		// How many hours it takes to get to the destination

   // print name and UAID
   cout << "###################\n";
   cout << "###  Tara Moses ###\n";
   cout << "###  010630228  ###\n";
   cout << "###################\n\n";

   // Display MainMenu
   MainMenu();
   
   // Get Destination  
   GetDestination(Destination, Distance);

   // Get Vehicle Type
   VehicleType = GetVehicleType();   

   // Calculate the cost of Gas
   Cost = GetGasCost(VehicleType, Distance, GallonsNeeded); 


   // Calculate the time it takes to get there (rounded down because of int)
   Hours = GetHours(Distance);

   // Display the Cost of Gas, Gallons Needed, Vehicle Type, Destination
   // and travel time.
   cout << "You will need " << GallonsNeeded << " gallons which will cost you\n"
        << "$" << fixed << setprecision(2) << Cost << ".\n";
   cout << "It will take you about " << Hours << " hours to get to ";

   if(Destination == KANSAS_CITY)
      cout << "Kansas City in a ";
   else if(Destination == ANCHORAGE)
      cout << "Anchorage in a ";
   else
      cout << "Panama City Beach in a ";

   if(VehicleType == HYBRID)
      cout << "Hybrid.\n";
   else if(VehicleType == CAR)
      cout << "Car.\n";
   else if(VehicleType == TRUCK)
      cout << "Truck.\n";
   else
      cout << "SUV.\n";

   return 0;
}


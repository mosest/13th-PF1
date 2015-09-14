//Tara Moses
//March 8, 2015
//Lab 10c: Extending the Temperature Class 

#include <iostream>
using namespace std;

// Interface for Temperature class
class Temperature
{
public:
   Temperature();
   Temperature(const Temperature & Temp);
   ~Temperature();
   double getCelsius() const;
   double getFahrenheit() const;
   void setCelsius(double Temp);
   void setFahrenheit(double Temp);
   void print();
   void read();

private:
   static const double ABSOLUTE_ZERO = -273.15;
   double CelsiusTemperature;
};

// Implementation of Temperature class
Temperature::Temperature()
{
   CelsiusTemperature = 0;
}

Temperature::Temperature(const Temperature & Temp)
{
   CelsiusTemperature = Temp.CelsiusTemperature;
}

Temperature::~Temperature()
{
}

double Temperature::getCelsius() const
{
   return CelsiusTemperature;
}

double Temperature::getFahrenheit() const
{
   return 9.0 * CelsiusTemperature / 5.0 + 32.0;
}

void Temperature::setCelsius(double Temp)
{
   CelsiusTemperature = Temp;
   if (CelsiusTemperature < ABSOLUTE_ZERO)
      CelsiusTemperature = ABSOLUTE_ZERO;
}

void Temperature::setFahrenheit(double Temp)
{
   CelsiusTemperature = (Temp - 32.0) * 5.0 / 9.0 ;
   if (CelsiusTemperature < ABSOLUTE_ZERO)
      CelsiusTemperature = ABSOLUTE_ZERO;
}

void Temperature::print() {
	cout << getFahrenheit() << "F = " << CelsiusTemperature << "C\n";
}

void Temperature::read() {
	char CorF;
	int temp;
	
	cin >> temp;
	cin >> CorF;
	
	if (CorF=='f' || CorF=='F') setFahrenheit(temp);
	else if (CorF=='c' || CorF=='C') setCelsius(temp);
}

// Program to test Temperature class
int main()
{
   Temperature Start, End;
   cout << "Enter start temperature: ";
   Start.read();
   cout << "Enter end temperature: ";
   End.read();

   cout.precision(3);
   for (double F = Start.getFahrenheit(); F <= End.getFahrenheit(); F++)
   {
      Temperature Temp;
      Temp.setFahrenheit(F);
      Temp.print();
   }
   return 0;
}

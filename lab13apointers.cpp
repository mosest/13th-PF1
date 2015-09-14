//Tara Moses
//August 21, 2015
//Lab 13a: Declaring and Using Pointers

// Include statements
#include <cstdlib>
#include <iostream>
using namespace std;

// Main function
int main()
{
   // Declare variables
   float var1 = 4.2;
   float var2 = 1.7;
   float *ptr1 = &var1;
   float *ptr2 = &var2;
   string tba = "tba";

   // Print messages
   cout << "value of var1 = " << var1 << endl;
   cout << "value of var2 = " << var2 << endl;
   /*cout << "address of var1 = " << &var1 << endl;
   cout << "address of var2 = " << &var2 << endl;
   cout << "value of ptr1 = " << ptr1 << endl;
   cout << "value of ptr2 = " << ptr2 << endl;*/
   cout << "value that ptr1 points to = " << *ptr1 << endl;
   cout << "value that ptr2 points to = " << *ptr2 << endl;
   
   *ptr2 = *ptr1;
   
   cout << "value of var1 = " << var1 << endl;
   cout << "value of var2 = " << var2 << endl;
   
   return 0 ;
}

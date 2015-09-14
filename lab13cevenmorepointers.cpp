//Tara Moses
//August 21, 2015
//Lab 13c: More Dynamic Allocation of Arrays

// Include statements
#include <cstdlib>
#include <iostream>
using namespace std;

// Main function
int main()
{
   // Get user input
   int size1 = 0;
   cout << "Enter size of array1:\n";
   cin >> size1;
   if (size1 < 0) 
      size1 = 0;

   // Get user input
   int size2 = 0;
   cout << "Enter size of array2:\n";
   cin >> size2;
   if (size2 < 0) 
      size2 = 0;

   // Process array1
   int * array1 = new int[size1];
   cout << "array1:\n";
   for (int i = 0; i < size1; i++)
   {
      array1[i] = 17;
      cout << array1[i] << " ";
   }
   cout << endl;

   // Location A
   //Return memory to OS
   delete [] array1;

   // Process array2
   int * array2 = new int[size2];
   cout << "array2:\n";
   for (int i = 0; i < size2; i++)
   {
      cout << array2[i] << " ";
      array2[i] = 42;
   }
   cout << endl;

   // Location B
   // Print array1
   cout << "array1:\n";
   for (int i = 0; i < size1; i++)
      cout << array1[i] << " ";
   cout << endl;

   // Location C
   // Print array1
   array1 = NULL;
   
   // Return memory to O/S
   delete [] array2;
   array2 = NULL;
   return 0 ;
}

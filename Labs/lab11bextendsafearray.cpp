//Tara Moses
//April 5, 2015
//Lab 11b: Extending the SafeArray Class

#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

// Interface for SafeArray class
//--------------------------------
class SafeArray
{
public:
   SafeArray();
   SafeArray(const SafeArray & copy);
   ~SafeArray();

   bool GetElement(const int i, float & Value) const;
   bool SetElement(const int i, float Value);
   bool ReadArray(const string Filename);
   bool WriteArray(const string Filename) const;
   void Print() const;
   void Randomize();
   void GetMinimum(float &n);
   void GetMaximum(float &n);
   static const int SIZE = 20;

private:
   float Array[SIZE];
};

// Implementation for SafeArray class
//-----------------------------------
SafeArray::SafeArray()
{
   for (int i = 0; i < SIZE; i++)
      Array[i] = 0;
}

SafeArray::SafeArray(const SafeArray & copy)
{
   for (int i = 0; i < SIZE; i++)
      Array[i] = copy.Array[i];
}

SafeArray::~SafeArray()
{
}

bool SafeArray::GetElement(const int i, float & Value) const
{
   bool Success = false;
   if ((i >= 0) && (i < SIZE))
   {
      Success = true;
      Value = Array[i];
   }
   return Success;
}

bool SafeArray::SetElement(const int i, float Value)
{
   bool Success = false;
   if ((i >= 0) && (i < SIZE))
   {
      Success = true;
      Array[i] = Value;
   }
   return Success;
}

bool SafeArray::ReadArray(const string Filename)
{
   ifstream infile;
   infile.open(Filename.c_str());
   if (infile.fail())
      return false;

   for (int i = 0; i < SIZE; i++)
      infile >> Array[i];
   infile.close();
   return true;
}

bool SafeArray::WriteArray(const string Filename) const
{
   ofstream outfile;
   outfile.open(Filename.c_str());
   if (outfile.fail())
      return false;

   for (int i = 0; i < SIZE; i++)
      outfile << Array[i] << endl;
   outfile.close();
   return true;
}

void SafeArray::Print() const
{
   for (int i = 0; i < SIZE; i++)
      cout << "Array[" << i << "] = " << Array[i] << endl;
}

void SafeArray::Randomize() {
   for (int i = 0; i < SIZE; i++)
   {
      float value = (rand() % 100) / 100.0; 
      SetElement(i, value);
   }
   Print();
}

void SafeArray::GetMinimum(float &n) {
	GetElement(0,n);
	for (int i = 1; i < SIZE; i++)
   {
      float value; 
      GetElement(i, value);
      if (value < n)
         n = value;
   }
}

void SafeArray::GetMaximum(float &n) {
	GetElement(0,n);
	for (int i = 1; i < SIZE; i++)
   {
      float value; 
      GetElement(i, value);
      if (value > n)
         n = value;
   }
}

// Program to demonstrate SafeArray class
//---------------------------------------
int main()
{
   SafeArray data1;
   
   data1.Randomize();
   data1.Randomize();
   
   // Find minimum value
   float min;
   float max;
   data1.GetMinimum(min);
   data1.GetMaximum(max);
   cout << "min value = " << min << endl;
   cout << "max value = " << max << endl;
   return 0;
}

//Tara Moses
//April 5, 2015
//Lab 11a: Using the SafeArray Class

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

private:
   static const int SIZE = 20;
   float Array[SIZE];
};

// Implementation for SafeArray class
//-----------------------------------
SafeArray::SafeArray()
{
   cout << "construct\n";
   for (int i = 0; i < SIZE; i++)
      Array[i] = 0;
}

SafeArray::SafeArray(const SafeArray & copy)
{
   cout << "copy\n";
   for (int i = 0; i < SIZE; i++)
      Array[i] = copy.Array[i];
}

SafeArray::~SafeArray()
{
   cout << "destruct\n";
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

// Program to demonstrate SafeArray class
//---------------------------------------
int main()
{
   SafeArray data1, data2;
   float n;
   
   //data1 stuff!
   for (int i = -5; i < 25; i++)
	{
	   data1.SetElement(i, i * 0.1);
	   if (data1.SetElement(i, i * 0.1)) cout << "set " << i << " " << i * 0.1 << endl;
	}
	data1.Print();
   for (int i = -5; i < 25; i++)
	{
	   data1.GetElement(i, n);
	   if (data1.GetElement(i, n)) cout << "get " << i << " " << n << endl;
	}
   
   //data2 business :D
   data2.ReadArray("data2.in");
   data2.Print();
   data2.WriteArray("data2.out");   
   
   return 0;
}

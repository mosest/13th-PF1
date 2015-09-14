//Tara Moses
//April 5, 2015
//Lab 11c: Improving the SafeArray Class

#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// Interface for SafeArray class
//--------------------------------
class SafeArray
{
public:
   SafeArray(int a);
   SafeArray(const SafeArray & copy);
   ~SafeArray();

   bool GetElement(const int i, float & Value) const;
   bool SetElement(const int i, float Value);
   bool ReadArray(const string Filename);
   bool WriteArray(const string Filename) const;
   void Print() const;
   void Randomize();
   void Sort();
   int GetSize();

private:
   int Size;
   vector<float> Array;
};

// Implementation for SafeArray class
//-----------------------------------
SafeArray::SafeArray(int n)
{
   Size = n;
   Array.resize(Size, 0);
}

SafeArray::SafeArray(const SafeArray & copy)
{
   Size = copy.Size;
   Array = copy.Array;
}

SafeArray::~SafeArray()
{
}

bool SafeArray::GetElement(const int i, float & Value) const
{
   bool Success = false;
   if ((i >= 0) && (i < Size))
   {
      Success = true;
      Value = Array[i];
   }
   return Success;
}

bool SafeArray::SetElement(const int i, float Value)
{
   bool Success = false;
   if ((i >= 0) && (i < Size))
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

   for (int i = 0; i < Size; i++)
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

   for (int i = 0; i < Size; i++)
      outfile << Array[i] << endl;
   outfile.close();
   return true;
}

void SafeArray::Print() const
{
   for (int i = 0; i < Size; i++)
      cout << "Array[" << i << "] = " << Array[i] << endl;
}

void SafeArray::Randomize()
{
   for (int i = 0; i < Size; i++)
      Array[i] = (rand() % 100) / 100.0; 
}

void SafeArray::Sort()
{
   // Simple but slow bubble sort 
   for (int i = 0; i < Size; i++)
      for (int j = i + 1; j < Size; j++)
	 if (Array[j] < Array[i])
	 {
	    float temp = Array[i];
	    Array[i] = Array[j];
	    Array[j] = temp;
	 }
}

int SafeArray::GetSize() {
	return Size;
}

// Program to demonstrate SafeArray class
//---------------------------------------
int main()
{
   int size;
   cout << "Enter size: ";
   cin >> size;
   SafeArray data1(size);

   // Randomize values
   data1.Randomize();
   data1.Print();

   // Sort values
   data1.Sort();
   data1.Print();
   
   cout << "size = " << data1.GetSize() << endl;
   return 0;
}

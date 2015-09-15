//Tara Moses
//March 8, 2015
//Lab 9c: Advanced File I/O

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char rot13(char ch)
{
   if ((ch >= 'a') && (ch <= 'z'))
      return char((13 + ch - 'a') % 26 + 'a');
   else if ((ch >= 'A') && (ch <= 'Z'))
      return char((13 + ch - 'A') % 26 + 'A');
   else
      return ch;
}

string rot13(string str)
{
   for (unsigned int i = 0; i < str.length(); i++)
      str[i] = rot13(str[i]);
   return str;
}

int main()
{
	ifstream fin;
	fin.open("message.in");
	
	ofstream fout;
	fout.open("message.out");
	
	int count = 1;
	char line[100];
	while (fin.getline(line, 100))
	   cout << count++ << ":" << rot13(line) << endl;
	   
	return 0;
}

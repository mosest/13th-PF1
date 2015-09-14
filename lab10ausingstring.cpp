//Tara Moses
//March 8, 2015
//Lab 10a: Using the String Class

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string phrase = "A quick brown fox jumps over the lazy dog.";
	string copy(phrase);
	string part(phrase, 8, 9);

	cout << "phrase = " << phrase << endl;
	cout << "length = " << phrase.length() << endl;
	cout << "copy = " << copy << endl;
	cout << "length = " << copy.length() << endl;
	cout << "part = " << part << endl;
	cout << "length = " << part.length() << endl;
	
	part.assign("black");
	part.append(" cat");
	part = "sleek " + part;
	cout << "part = " << part << endl;
	cout << "length = " << part.length() << endl;
	
	string word = "lazy";
	int pos = copy.find(word, 0);
	copy.insert(pos, "old ");
	cout << "pos = " << pos << endl;
	cout << "copy = " << copy << endl;
	cout << "length = " << copy.length() << endl;
	
	word = "quick";
	pos = copy.find(word,0);
	copy.erase(pos,5);
	copy.insert(pos, "frisky");
	cout << "copy = " << copy << endl;
	cout << "length = " << copy.length() << endl;
	
	for (int i = 0; i < phrase.length(); i++)
		if (phrase[i] == ' ')
		{
		  phrase.erase(i,1);
		  cout << "phrase = " << phrase << endl;
		  cout << "length = " << phrase.length() << endl;
		}
	return 0;
}

//Tara Moses (010630228) and William Shattuck (ID)
//February 22, 2015
//Homework 3: Caesar Cipher

#include <iostream> 
#include <math.h> 
#include <string> 
using namespace std; 

/*
 * takes in Msg (a capital letter)
 * 			Prime (a prime number), and
 * 			Type (encode or decode).
 * 
 * returns the letter of the alphabet
 * that is Prime letters before/after Msg
 * (depending on Type)
 */
char Shift(int Prime, char Msg, char Type) { 
	Prime = Prime % 26;
	
	if (Type=='d') { 
		if (Msg+Prime < 91) Msg = Msg + Prime;
		else Msg = Msg - 26 + Prime; 
	} 
	if (Type=='e') { 
		if (Msg-Prime > 64) Msg = Msg - Prime;
		else Msg = Msg + 26 - Prime;
	} 
	return Msg;
}

/*
 * checks whether num is prime!
 * divides num by every number between 2 and sqrt(num)
 * and if it's divisible by any of those, then stop
 * checking and return false. if it's not divisible
 * by any of those, then ITS PRIME YAY return true
 */
bool isPrime(int num) {
	if (num<2) return false; //i added this :3
	for (int I=2; I<=sqrt(num); I++) { 
		if (num%I == 0) return false; 
	}
	return true;
}

/*
 * asks user for a prime number, checks whether
 * it's actually prime (and asks for a new number
 * if it's not), and returns the prime number
 */
int getPrime() { 
	int Prime; 
	
	cout << "Please enter a prime number please: ";
	cin >> Prime; 
	while (!isPrime(Prime)) {
		cout << "That's not prime!" << endl;
		cout << "Please enter a prime number: ";
		cin >> Prime; 
	}
	return Prime;
} 

/*
 * asks user to input an E to encode a message
 * or a D to decode a message. makes sure the 
 * user doesn't input anything else
 */
char getType() {
	char Type;
	
	cout << "Do you want to (e)ncode, or (d)ecode? "; 
	cin >> Type; 
	Type = tolower(Type);	
	while (Type!='e' && Type!='d') {
		cout << "I'm sorry, that wasn't one of the options. Please input either an E or a D. " << endl; 
		cout << "Do you want to (e)ncode, or (d)ecode? "; 
		cin >> Type; 
		Type = tolower(Type); //so while loop doesn't see 'E' or 'D' as wrong input
	}
	return Type;	
}

/*
 * takes in primeKey (the prime number for the shift),
 * 			and type (encode or decode).
 * 
 * references changedMsg by parameter :3 
 * asks user for 4 letters, checks whether they're
 * actually letters, shifts them, and adds them to 
 * the changedMsg in main() :D
 */
string getMsg(string& changedMsg, int primeKey, char type) {
	char Msg;
	string originalMsg;
	
	cout << "Give me four letters please!\n"; 
	for (int I=0;I<4;I++) {
		cout << "Letter #" << I+1 << ": ";
		cin >> Msg; 
		Msg = toupper(Msg);
		
		while (Msg <= 64 || Msg >= 91) {  
			cout << "That's not a letter, buddy. Try again." << endl;
			cout << "Letter #" << I+1 << ": ";
			cin >> Msg;
			Msg = toupper(Msg);
		} 
		originalMsg = originalMsg + Msg;
		changedMsg = changedMsg + Shift(primeKey, Msg, type);
	}
	return originalMsg;
}

int main() { 
	//figure out whether user wants to encode or decode
	char Type = getType();
	cout << endl;
	 
	//obtain prime # from user
	int Prime = getPrime();
	cout << endl;
	
	//obtain message from user
	string newMsg;
	string originalMsg = getMsg(newMsg, Prime, Type);
	cout << endl;
	
	//echo input message
	cout << "The original message was: " << originalMsg << endl; 
	
	//output either the encoded or decoded msg
	if (Type=='e') cout <<"The encoded message is: " << newMsg << endl; 
	else cout << "The decoded message is: " << newMsg << endl << endl; 
	
	return 0; 
}

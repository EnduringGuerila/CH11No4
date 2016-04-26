// CISP 1610  Programming in C++
// Programming and Problem Solving with C++ 6th Edition  (Dale and Weems)
// Chapter 11 Number 4
// by Tim Kirtland
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Function prototypes
void InitializeArray(string AlphabetArray[]);
void GetInput(string& inData);
void GenerateOutput(string AlphabetArray[], string inputStr);
string ConvertLetter(string AlphabetArray[], char inCH);
bool Continue();

struct UberStructure {
	string AlphabetArray[26];
};

int main()
{
	cout << "     *********************************************************************" << endl;
	cout << "     *                                                                   *" << endl;
	cout << "     *          This program converts text to the ICAO alphabet          *" << endl;
	cout << "     *                                                                   *" << endl;
	cout << "     *********************************************************************" << endl << endl;

	string AlphabetArray[26];
	bool cont = false;

	InitializeArray(AlphabetArray);

	do {
		string inputStr;
		GetInput(inputStr);
		GenerateOutput(AlphabetArray, inputStr);

		cont = Continue();
	} while (cont); // main loop

    return 0;
}


void InitializeArray(string AlphabetArray[])
// Pre:  AlphabetArray defined as type string
// Post: indexes 0-25 set to string of ICAO
{
	AlphabetArray[0] = "Alpha"; // starting at 65 instead of 0 would have been fine too, wouldnt have to subtract 'A' aka 65 later
	AlphabetArray[1] = "Bravo";
	AlphabetArray[2] = "Charlie";
	AlphabetArray[3] = "Delta";
	AlphabetArray[4] = "Echo";
	AlphabetArray[5] = "Foxtrot";
	AlphabetArray[6] = "Golf";
	AlphabetArray[7] = "Hotel";
	AlphabetArray[8] = "India";
	AlphabetArray[9] = "Juliet";
	AlphabetArray[10] = "Kilo";
	AlphabetArray[11] = "Lima";
	AlphabetArray[12] = "Mike";
	AlphabetArray[13] = "November";
	AlphabetArray[14] = "Oscar";
	AlphabetArray[15] = "Papa";
	AlphabetArray[16] = "Quebec";
	AlphabetArray[17] = "Romeo";
	AlphabetArray[18] = "Sierra";
	AlphabetArray[19] = "Tango";
	AlphabetArray[20] = "Uniform";
	AlphabetArray[21] = "Victor";
	AlphabetArray[22] = "Whiskey";
	AlphabetArray[23] = "X-ray";
	AlphabetArray[24] = "Yankee";
	AlphabetArray[25] = "Zulu";
	return;
}


void GetInput(string& inData)
// Pre:  input string declared
// Post: saves users input in same string it was passed
{
	cout << "Enter text to be converted! (word or several words)" << endl;
	getline(cin, inData);

}

void GenerateOutput(string AlphabetArray[], string inputStr)
// Pre:  AlphabetArray and test char predifined
// Post: outputs letter loop on screen 
{
	char tempCH;
	
	cout << endl;

	for (int counter = 0; counter < inputStr.length(); counter++)
	{
		tempCH = inputStr.at(counter);
		if (isalpha(tempCH)) {
			tempCH = toupper(tempCH);
			cout << ConvertLetter(AlphabetArray, tempCH) << " ";
		} 
		else
			cout << endl;
	}
	cout << endl << endl;
}


string ConvertLetter(string AlphabetArray[], char inCH)
// Pre:  AlphabetArray and test char predifined
// Post: returns string containing the ICAO word
{
	char letter = inCH - 'A';
	string alpha = AlphabetArray[letter];

	return alpha;
}

bool Continue()
// Pre:  
// Post: return bool if user wants to continue
{
	char contCh;
	string contStr;
	
	do { // loop to continue and verify valid entry
		cout << "\nAgain? (y or n)" << endl;
		cin >> contStr;		// entered as string incase they type 'yes' or 'no'
		cin.ignore();
		contCh = contStr.at(0);
		contCh = toupper(contCh);
		if (contCh != 'Y' && contCh != 'N')
			cout << "Invalid entry, please enter either 'Y' or 'N'" << endl;
	} while (contCh != 'Y' && contCh != 'N');
	cout << endl;
	if(contCh == 'Y')
		return true;
	else
		return false;
}
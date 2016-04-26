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
void InitializeArray(string AlphaAr[]);
void GetInput(string& inData);
void GenerateOutput(string AlphabetArray[], string inputStr);
string ConvertLetter(string AlphabetArray[], char inCH);
bool Continue();

struct UberStructure {
	//const int arraySize = 26;
	string AlphabetArray[26];
	string inputStr;
};

int main()
{
	cout << "     *********************************************************************" << endl;
	cout << "     *                                                                   *" << endl;
	cout << "     *          This program converts text to the ICAO alphabet          *" << endl;
	cout << "     *                                                                   *" << endl;
	cout << "     *********************************************************************" << endl << endl;

	UberStructure Uber;

	bool cont = false;

	InitializeArray(Uber.AlphabetArray);

	do {
		GetInput(Uber.inputStr);
		GenerateOutput(Uber.AlphabetArray, Uber.inputStr);
	} while (Continue()); // main loop

    return 0;
}


void InitializeArray(string AlphaAr[])
// Pre:  AlphabetArray defined as type string
// Post: indexes 0-25 set to string of ICAO
{
	AlphaAr[0] = "Alpha"; // starting at 65 instead of 0 would have been fine too, wouldnt have to subtract 'A' aka 65 later
	AlphaAr[1] = "Bravo";
	AlphaAr[2] = "Charlie";
	AlphaAr[3] = "Delta";
	AlphaAr[4] = "Echo";
	AlphaAr[5] = "Foxtrot";
	AlphaAr[6] = "Golf";
	AlphaAr[7] = "Hotel";
	AlphaAr[8] = "India";
	AlphaAr[9] = "Juliet";
	AlphaAr[10] = "Kilo";
	AlphaAr[11] = "Lima";
	AlphaAr[12] = "Mike";
	AlphaAr[13] = "November";
	AlphaAr[14] = "Oscar";
	AlphaAr[15] = "Papa";
	AlphaAr[16] = "Quebec";
	AlphaAr[17] = "Romeo";
	AlphaAr[18] = "Sierra";
	AlphaAr[19] = "Tango";
	AlphaAr[20] = "Uniform";
	AlphaAr[21] = "Victor";
	AlphaAr[22] = "Whiskey";
	AlphaAr[23] = "X-ray";
	AlphaAr[24] = "Yankee";
	AlphaAr[25] = "Zulu";
	return;
}


void GetInput(string& inData)
// Pre:  input string declared
// Post: saves users input in same string it was passed
{
	cout << "Enter text to be converted! (word or several words)" << endl;
	getline(cin, inData);
	return;
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
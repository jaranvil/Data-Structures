#include <conio.h>
#include <iostream>

#include <regex>
#include <windows.h> // for color
#include <fstream> // for file IO
#include <string> // for getline() input method

#include "LinkedList.h"
#include "Node.h"

/**
	Prototypes for this class.
		TODO - setup header
*/
void setupCombo();
void useDefault();
void refreshScreen();
void getInput();
void exit();
void gotoPos(string);
void swap(string);
void deleteVal();
void reset();
bool matchRegEx(string, string);

/**
	Globals
*/
int COMBINATION_SIZE = 7;			// fixed combo size
LinkedList list;					// the list objhest
int currentPosition = 0;			// the current position on the list
string fileName;					// choosen file name. default.txt or from main agrv
string integer = "^(0|[1-9][0-9]*)$";// integer
string windowsFileName = "[a-z]+";	// filename

/**
	Entry Point.
		- Set a output filename is one is specified in the args.
		- Create the combination list and set everything to 0.
		- Display the screen.
*/
int main(int argc, char *argv[]) {
	int i = 1;
	if (argc < 2) {
		useDefault();
	}
	else {		
		if (matchRegEx(windowsFileName, argv[1]))
			fileName = argv[1];
		else
			useDefault();
	}

	setupCombo();

	refreshScreen();

	_getch();
	return 0;
}

/**
	If no args were passed in or they didn't pass the filename regex:
		- set a default name for the text file
		- display a notice to user, _getch for confirmation
*/
void useDefault()
{
	fileName = "default.txt";
	cout << "No or an invalid filename was entered." << endl;
	cout << "Conbinations will be stored to ";
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 3);
	cout << "default.txt";
	SetConsoleTextAttribute(hConsole, 7);

	_getch();
}

/**
	Main function that is called after every action
	 - Clear screen
	 - Display the combination, current position, and available options
	 - call getInput() for the next action
*/
void refreshScreen()
{
	system("cls");

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 6);
	cout << "Linked-List Combination Manager" << endl << endl;

	SetConsoleTextAttribute(hConsole, 3);
	cout << "Combination : \t\t";

	SetConsoleTextAttribute(hConsole, 7);
	cout << list;

	SetConsoleTextAttribute(hConsole, 3);
	cout << endl << "Current Position: \t";

	SetConsoleTextAttribute(hConsole, 7);
	for (int i = 0; i < currentPosition * 4; i++)
	{
		cout << " ";
	}
	cout << "^";

	SetConsoleTextAttribute(hConsole, 6);
	cout << endl << endl << "Options:" << endl;

	SetConsoleTextAttribute(hConsole, 3);
	cout << "  Q \t QUIT\t\t wihtout saving." << endl;
	cout << "  E \t EXIT\t\t and save." << endl;
	cout << "  G # \t GOTO\t\t position in list" << endl;
	cout << "  S # \t SUBSTITUTE\t current value with input" << endl;
	cout << "  D \t DELETE\t\t current value" << endl; 
	cout << "  R \t RESET\t\t list to all 0s" << endl;

	SetConsoleTextAttribute(hConsole, 7);
	getInput();
}

/**
	Called after the screen is refreshed to get next input.
		- get a line of input from user
		- seperate it at the first space to get the command as the first variable and an optional param as the second.
		- compare inputted command to availble options
		- call requested method or provide input error and loop back
*/
void getInput()
{
	cout << endl << "Enter command: " << endl;

	// get input
	string input;
	getline(cin, input);

	// parse values
	string delimeter = " ";
	size_t pos = 0;
	string token;

	pos = input.find(delimeter);
	string cmd = input.substr(0, pos);
	input.erase(0, pos + delimeter.length());
	string param = input;

	if (cmd == "q" || cmd == "Q")		// QUIT
		exit(0);
	else if (cmd == "e" || cmd == "E")	// EXIT
		exit();
	else if (cmd == "g" || cmd == "G")	// GOTO
		gotoPos(param);
	else if (cmd == "s" || cmd == "S")	// SUBSTITUE
		swap(param);
	else if (cmd == "d" || cmd == "D")	// DELETE
		deleteVal();	
	else if (cmd == "r" || cmd == "R")	// RESET
		reset();
	else
	{
		cout << "invalid command" << endl;
		getInput();
	}
}

/**
	Exit the program and save to file
		- Open choosen file (set in main())
		- write current combination to the file
		- close file and exit program.
*/
void exit()
{
	ofstream outfile;
	outfile.open(fileName + ".txt", ios::out | ios::trunc);
	
	string combination;
	for (int i = 0; i < COMBINATION_SIZE; i++)
	{
		// string value of current node
		string s = to_string(list.getNodeNum(i));

		if (i % 2 == 0)
			combination = combination + "R" + s + " ";
		else
			combination = combination + "L" + s + " ";		
	}

	outfile << combination << endl;
	outfile.close();
	cout << "saved to " + fileName + ".txt";
	exit(0);
}

/**
	GOTO function to set current list position
		- valudate user param as an integer between 1-7
		- set current position to that num or send relavent error
		- refresh screen.
*/
void gotoPos(string num)
{
	int x = -1;
	if (matchRegEx(integer, num))
		x = atoi(num.c_str());
	else
	{
		cout << "Invalid number" << endl;
		_getch();
		refreshScreen();
	}

	if (x >= 1 && x <= 7)
	{
		currentPosition = x - 1;
		refreshScreen();
	}
	else 
	{
		cout << "Invalid position parameter" << endl;
		_getch();
		refreshScreen();
	}
}

/**
	Replace current list value with inputed number
		- validate interger 0-49
		- update and refresh if valid
*/
void swap(string num)
{
	int x = -1;
	if (matchRegEx(integer, num))
		x = atoi(num.c_str());
	else
	{
		cout << "Invalid number" << endl;
		_getch();
		refreshScreen();
	}

	if (x >= 0 && x <= 49)
	{
		list.changeNode(currentPosition, x);
		refreshScreen();
	}
	else
	{
		cout << "Invalid number" << endl;
		_getch();
		refreshScreen();
	}
}

/**
	Reset current value to 0.
*/
void deleteVal() 
{
	list.changeNode(currentPosition, 0);
	refreshScreen();
}

/**
	Reset all values to 0
*/
void reset()
{
	for (int i = 0; i < COMBINATION_SIZE; i++)
	{
		list.changeNode(i, 0);
	}
	refreshScreen();
}

/**
	Setup list with postiions and 0s
*/
void setupCombo()
{	
	for (int i = 0; i < COMBINATION_SIZE; i++)
	{
		if (i%2 == 0)
			list.addValue(0, "R");
		else
			list.addValue(0, "L");
	}
}

/**
	Return true if any match found between the inputted regex and string.
*/
bool matchRegEx(string pattern, string input)
{	
	string s = input;
	smatch m;
	regex e(pattern);

	while (regex_search(s, m, e)) {
		for (auto x : m) return true;
	}

	return false;
}

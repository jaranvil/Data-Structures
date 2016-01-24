#include <stdio.h>
#include <conio.h>
#include <iostream>

#include <fstream> // for file IO
#include <sstream> // for interger parsing
#include <string> // for getline() input method

#include "LinkedList.h"

// prototypes
// TODO created header for source.cpp
void setupCombo();
void refreshScreen();
void getInput();
void exit();
void gotoPos(string);
void swap(string);
void deleteVal();
void reset();

int COMBINATION_SIZE = 7;
LinkedList list;
int currentPosition = 0;
string fileName;

// main program
int main(int argc, char *argv[]) {
	int i = 1;
	//// decode arguments
	if (argc < 2) {
		fileName = "example.txt";
	}
	else {
		fileName = argv[1];
	}

	setupCombo();

	refreshScreen();

	_getch();
	return 0;
}

void refreshScreen()
{
	system("cls");

	cout << "Combination : \t\t";
	cout << list;

	cout << endl << "Current Position: \t";
	for (int i = 0; i < currentPosition * 4; i++)
	{
		cout << " ";
	}
	cout << "^";

	cout << endl << endl << "Options:" << endl;
	cout << "  Q \t: QUIT wihtout saving." << endl;
	cout << "  E \t: EXIT and save." << endl;
	cout << "  G # \t: GOTO position in list" << endl;
	cout << "  S # \t: SUBSTITUTE current value with input" << endl;
	cout << "  D \t: DELETE current value" << endl; 
	cout << "  R \t: RESET list to all 0s" << endl;

	getInput();
}

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

	if (cmd == "q" || cmd == "Q")
	{
		// QUIT
		exit(0);
	}
	else if (cmd == "e" || cmd == "E")
	{
		// EXIT
		exit();
	}
	else if (cmd == "g" || cmd == "G")
	{
		// GOTO
		gotoPos(param);
	}
	else if (cmd == "s" || cmd == "S")
	{
		// SUB
		swap(param);
	}
	else if (cmd == "d" || cmd == "D")
	{
		// DELETE
		deleteVal();
	}
	else if (cmd == "r" || cmd == "R")
	{
		// RESET
		reset();
	}
	else
	{
		cout << "invalid command" << endl;
		getInput();
	}
}

void exit()
{
	ofstream outfile;
	outfile.open(fileName + ".txt", ios::out | ios::trunc);
	
	string combination;
	for (int i = 0; i < COMBINATION_SIZE; i++)
	{
		// string value of current node
		stringstream sstm;
		sstm << list.getNode(i);
		string result = sstm.str();

		if (i % 2 == 0)
			combination = combination + "R" + result + " ";
		else
			combination = combination + "L" + result + " ";		
	}

	outfile << combination << endl;
	outfile.close();
	cout << "saved to " + fileName + ".txt";
	exit(0);
}

void gotoPos(string num)
{
	int x = -1;
	stringstream convert(num);
	convert >> x; 
	
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

void swap(string num)
{
	int x = -1;
	stringstream convert(num);
	convert >> x;

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

void deleteVal() 
{
	list.changeNode(currentPosition, 0);
	refreshScreen();
}

void reset()
{
	for (int i = 0; i < COMBINATION_SIZE; i++)
	{
		list.changeNode(i, 0);
	}
	refreshScreen();
}

void setupCombo()
{
	// TODO Read conbination from file (or does it only save?)

	// make all values 0
	for (int i = 0; i < COMBINATION_SIZE; i++)
	{
		list.addValue(0);
	}
}

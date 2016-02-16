
#include <iostream>
#include <conio.h>
#include <string>    
#include <iostream>
#include <fstream>      
#include <windows.h> // for color
#include "Maze.h"

using namespace std;

Maze::Maze() 
{
}

Maze::~Maze()
{
}

void Maze::loadMaze(string filePath)
{
	// outputing a file

	//ofstream outputFile;
	//outputFile.open("temp.txt");
	//outputFile << 0;
	//outputFile << 0;
	//outputFile << 0;
	//outputFile << 0;
	//outputFile.close();


	// TODO - get deminsions

	std::ifstream file("maze2.txt");
	std::string line;
	rows = 51;
	cols = 51;
	int row = 0;
	int col = 0;

	

	//  COUNT DEMENSIONS

	ifstream inFile("maze.txt");


	int temp = 0;
	int temp2 = 0;

	while (getline(inFile, line)) {

		temp++;

		char tab2[1024];
		strcpy_s(tab2, line.c_str());

		temp2 = strlen(tab2);
	}
	
	cout << temp << temp2 << endl;
	_getch();

	// POPULATE ARRAY

	// WORKING with fixed demensions
	/*while (std::getline(file, line, '\0'))
	{
	for (char character : line)
	{
	charArray[row][col] = character;

	if (character == ' ')
	maze[row][col] = false;
	else
	maze[row][col] = true;

	col++;
	if (col == 52)
	{
	++row;
	col = 0;
	}
	}

	}*/
		
}

void Maze::draw()
{
	system("cls");
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	

	//StackNode *node = stack._top;

	//while (node != NULL)
	//{
	//	charArray[node->getRow()][node->getCol()] = '#';
	//	node = node->getNext();
	//}

	for (int r = 0; r < 51; r++)
	{
		for (int c = 0; c < 51; c++)
		{
			if (charArray[r][c] == 'B')
				SetConsoleTextAttribute(hConsole, 3);
			else
				SetConsoleTextAttribute(hConsole, 7);

			cout << charArray[r][c];

			/*	if (maze[r][c])
			cout << "*";
			else
			cout << " ";*/
		}

		cout << endl;
	}
}

void Maze::clearPath()
{
	for (int r = 0; r < 51; r++)
	{
		for (int c = 0; c < 51; c++)
		{
			if (charArray[r][c] == '#')
				charArray[r][c] = ' ';
		}
	}
}

bool Maze::getVal(int row, int col)
{
	return maze[row][col];
}

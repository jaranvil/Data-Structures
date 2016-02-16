
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

void Maze::loadMaze(int mazeChoice)
{
	string filename = "";
	if (mazeChoice == 1)
		filename = "maze.txt";
	if (mazeChoice == 2)
		filename = "maze2.txt";
	if (mazeChoice == 3)
		filename = "maze3.txt";
	if (mazeChoice == 4)
		filename = "maze4.txt";
	if (mazeChoice == 5)
		filename = "mazex.txt";

	std::ifstream file(filename);
	std::string line;
	int row = 0;
	int col = 0;

	//  COUNT DEMENSIONS
	rows = 0;
	cols = 0;
	while (getline(file, line)) {

		rows++;

		char tab2[1024];
		strcpy_s(tab2, line.c_str());

		cols = strlen(tab2);
	}

	maze = new bool*[rows];
	for (int i = 0; i < rows; i++)
		maze[i] = new bool[cols];

	charArray = new char*[rows];
	for (int i = 0; i < rows; i++)
		charArray[i] = new char[cols];

	// POPULATE ARRAY


	std::ifstream inFile(filename);
	while (std::getline(inFile, line, '\0'))
	{
		for (char character : line)
		{
			charArray[row][col] = character;

			if (character == ' ')
				maze[row][col] = false;
			else
				maze[row][col] = true;

			col++;
			if (col > cols)
			{
				++row;
				col = 0;
			}
			
		}
	}
		
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

	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			if (charArray[r][c] == 'B')
				SetConsoleTextAttribute(hConsole, 6);
			else
				SetConsoleTextAttribute(hConsole, 8);

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

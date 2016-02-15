
#include <iostream>
#include <conio.h>
#include <string>    
#include <iostream>
#include <fstream>      
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

	std::ifstream file("maze.txt");
	std::string line;

	char charArray[51][51];
	int row = 0;
	int col = 0;

	while (std::getline(file, line, '\0')) {
		for (char character : line) {
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
		
	}
	
	// draw maze from array
	
	for (int r = 0; r < 51; r++)
	{
		for (int c = 0; c < 51; c++)
		{
			//cout << charArray[r][c];
			
			if (maze[r][c])
				cout << "*";
			else
				cout << " ";
				//if (r == 50 && c == 50)
				//_getch();
		}
			
		cout << endl;
	}
	
	
		
}

bool Maze::getVal(int row, int col)
{
	return maze[row][col];
}

#pragma once
#pragma once
#ifndef _MAZE_H
#define _MAZE_H

#include <iostream>
#include <conio.h>

using namespace std;
class Maze
{
private:
	bool** maze;

public:
	char** charArray;
	int rows;
	int cols;

	Maze();
	virtual ~Maze();

	void loadMaze(int);
	void draw();
	void clearPath();

	bool getVal(int, int);

};

#endif

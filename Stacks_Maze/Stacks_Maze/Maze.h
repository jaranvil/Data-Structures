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
	bool maze[51][51];
	

public:
	char charArray[51][51];
	int rows;
	int cols;

	Maze();
	virtual ~Maze();

	void loadMaze(string);
	void draw();
	void clearPath();

	bool getVal(int, int);

};

#endif

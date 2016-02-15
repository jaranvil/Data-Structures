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
	Maze();
	virtual ~Maze();

	void loadMaze(string);

	bool getVal(int, int);

};

#endif

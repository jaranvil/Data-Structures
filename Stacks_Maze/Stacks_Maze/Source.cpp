//#include "stdafx.h"

#include <iostream>
#include "stack.h"
#include "Maze.h"

using namespace std;

// prototypes
bool isBranch(Maze maze, int row, int col);

void pr_error(myerror_code err)
// Generic error print routine
{
	switch (err) {
	case overflow: {
		cout << "Error encountered: stack overflow" << endl;
	}
	case underflow: {
		cout << "Error encountered: stack underflow" << endl;
	}
	}

}

int main()
{
	Stack stack;
	Maze maze;
	maze.loadMaze("");

	int currentRow = 1;
	int currentCol = 0;

	bool branch = isBranch(maze, currentRow, currentCol);
	stack.Push(currentRow, currentCol, branch);

	while (true)
	{
		// draw stuff
		StackNode *node = stack._top;

		while (node != NULL)
		{
			maze.charArray[node->getRow()][node->getCol()] = '#';
			node = node->getNext();
		}

		maze.draw();

		cout << "Current Pos: " << currentRow << " " << currentCol << endl;
		// stack top is current position

		bool moveDetermined = false;
		// try to move right
		if (!moveDetermined && currentCol + 1 <= maze.cols) // right is within maze
		{
			if (!maze.getVal(currentRow, currentCol+1)) // right is a empty space
			{
				// not previous position
				if (!(currentRow == stack.PeekPrevRow() && currentCol+1 == stack.PeekPrevCol()))
				{
					//move right
					currentCol++;
					bool branch = isBranch(maze, currentRow, currentCol);
					stack.Push(currentRow, currentCol, branch);

					moveDetermined = true;
					cout << "Moving right" << endl;
				}
			}
		}
		// try to move down
		if (!moveDetermined && currentRow + 1 <= maze.rows)
		{
			if (!maze.getVal(currentRow+1, currentCol)) // down is a empty space
			{
				// not previous position
				if (!(currentRow+1 == stack.PeekPrevRow() && currentCol == stack.PeekPrevCol()))
				{
					//move down
					currentRow++;
					bool branch = isBranch(maze, currentRow, currentCol);
					stack.Push(currentRow, currentCol, branch);

					moveDetermined = true;
					cout << "Moving down" << endl;
				}
			}
		}
		// try to move left
		if (!moveDetermined && currentCol - 1 >= 0)
		{
			if (!maze.getVal(currentRow, currentCol-1)) // left is a empty space
			{
				// not previous position
				if (!(currentRow == stack.PeekPrevRow() && currentCol-1 == stack.PeekPrevCol()))
				{
					//move left
					currentCol--;
					bool branch = isBranch(maze, currentRow, currentCol);
					stack.Push(currentRow, currentCol, branch);

					moveDetermined = true;
					cout << "Moving left" << endl;
				}
			}
		}
		// try to move up
		if (!moveDetermined && currentRow - 1 >= 0)
		{
			if (!maze.getVal(currentRow - 1, currentCol)) // up is a empty space
			{
				// not previous position
				if (!(currentRow-1 == stack.PeekPrevRow() && currentCol == stack.PeekPrevCol()))
				{
					//move up
					currentRow--;
					bool branch = isBranch(maze, currentRow, currentCol);
					stack.Push(currentRow, currentCol, branch);

					moveDetermined = true;
					cout << "Moving up" << endl;
				}
			}
		}
		
		if (!moveDetermined)
		{
			// no where to go
			// return to last branch

			stack.ReturnToBranch();
			cout << stack;
			break;
			// clear out hashes on the drawing array
			maze.clearPath();
		}			

		//_getch();
	} // end while

	_getch();

	//// test 1: push on to stack
	//Stack stack;
	//Stack stack2; // use this one just to force errors

	//myerror_code err;

	//err = stack.Push(32);
	//if (err != success) pr_error(err); // just a sample of catching a returning error code
	//stack.Push(12);
	//stack.Push(87);
	//stack.Push(26);
	//stack.Push(91);

	//// verify contents of stack
	//cout << stack;

	//// test 2: peek/pop from stack
	//cout << "The first node on the stack is: ";
	//cout << stack.Peek() << endl;

	//// remove the first node
	//cout << "First node removed." << endl;
	//stack.Pop();

	//// show new top of stack
	//cout << "The new first node on the stack is: ";
	//cout << stack.Peek() << endl;
	//cin.ignore();

	//// Now going to force an underflow error with stack2
	//// There is no data, so a Pop should fail
	//err = stack2.Pop();
	//if (err != success) pr_error(err); // just a sample of catching a returning error code

	//cout << "Ending..." << endl;
	//cin.ignore();

	_getch();
	return 0;
}


bool isBranch(Maze maze, int row, int col)
{
	int paths = 0;

	// top
	if (row - 1 >= 0)
		if (!maze.getVal(row - 1, col))
			++paths;
	// bottom
	if (row + 1 <= maze.rows)
		if (!maze.getVal(row + 1, col))
			++paths;
	// left
	if (col - 1 >= 0)
		if (!maze.getVal(row, col - 1))
			++paths;
	// right
	if (col + 1 <= maze.cols)
		if (!maze.getVal(row, col + 1))
			++paths;

	if (paths > 1)
		return true;
	else
		return false;
}


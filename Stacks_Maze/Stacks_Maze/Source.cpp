#include <iostream>
#include "stack.h"
#include "Maze.h"

using namespace std;

// prototypes
bool isBranch(Maze, int, int, int, int);
void tryToMoveRight();
void tryToMoveLeft();
void tryToMoveDown();
void tryToMoveUp();

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

Stack stack;
Maze maze;
int currentRow;
int currentCol;
bool moveDetermined = false;

int main()
{
	cout << "Select a maze: (1-5)" << endl;
	int choice;
	cin >> choice; 
	maze.loadMaze(choice);

	// starting position
	currentRow = 1;
	currentCol = 0;

	// push start position to stack
	bool branch = isBranch(maze, currentRow, currentCol, -1, -1);
	stack.Push(currentRow, currentCol, branch);

	while (true)
	{
		// draw stuff
		StackNode *node = stack._top;
		/*
		while (node != NULL)
		{
			if (node->isBranch())
				maze.charArray[node->getRow()][node->getCol()] = 'B';
			else
				maze.charArray[node->getRow()][node->getCol()] = '#';
			node = node->getNext();
		}
		maze.draw();*/
		//system("cls");
		//cout << currentRow << " " << currentCol << endl;

		moveDetermined = false;

		node = stack._top;
		if (node->isBranch())
		{
			if (node->branchDirection == 0 && !moveDetermined)
			{
				node->branchDirection = 1;
				tryToMoveRight();			
			}	
			if (node->branchDirection == 1 && !moveDetermined)
			{
				node->branchDirection = 2;
				tryToMoveDown();				
			}				
			if (node->branchDirection == 2 && !moveDetermined)
			{
				node->branchDirection = 3;
				tryToMoveLeft();		
			}				
			if (node->branchDirection == 3 && !moveDetermined)
			{
				node->branchDirection = 4;
				tryToMoveUp();
			}
				
			if (!moveDetermined)
				node->branch = false;
		}
		else
		{
			tryToMoveRight();
			tryToMoveDown();
			tryToMoveLeft();
			tryToMoveUp();
			
		} // end !node is branch

		if (!moveDetermined)
		{
			// no where to go
			// return to last branch

			stack.ReturnToBranch();
			currentRow = stack.PeekRow();
			currentCol = stack.PeekCol();

			// clear out hashes on the drawing array
			//maze.clearPath();
		}			

		if (currentRow >= maze.rows - 2 && currentCol >= maze.cols -2)
		{
			while (node != NULL)
			{
				if (node->isBranch())
					maze.charArray[node->getRow()][node->getCol()] = 'B';
				else
					maze.charArray[node->getRow()][node->getCol()] = '#';
				node = node->getNext();
			}
			maze.draw(); 

			break;
			
		}
			
	} // end while

	_getch();
	return 0;
}


void tryToMoveRight()
{
	// try to move right
	if (!moveDetermined && currentCol + 1 <= maze.cols) // right is within maze
	{
		if (!maze.getVal(currentRow, currentCol + 1)) // right is a empty space
		{
			// not previous position
			if (!(currentRow == stack.PeekPrevRow() && currentCol + 1 == stack.PeekPrevCol()))
			{
				//move right
				currentCol++;
				bool branch = isBranch(maze, currentRow, currentCol, stack.PeekRow(), stack.PeekCol());
				stack.Push(currentRow, currentCol, branch);

				moveDetermined = true;
				
			}
		}
	}
}

void tryToMoveDown()
{
	// try to move down
	if (!moveDetermined && currentRow + 1 <= maze.rows)
	{
		if (!maze.getVal(currentRow + 1, currentCol)) // down is a empty space
		{
			// not previous position
			if (!(currentRow + 1 == stack.PeekPrevRow() && currentCol == stack.PeekPrevCol()))
			{
				//move down
				currentRow++;
				bool branch = isBranch(maze, currentRow, currentCol, stack.PeekRow(), stack.PeekCol());
				stack.Push(currentRow, currentCol, branch);

				moveDetermined = true;
				
			}
		}
	}
}

void tryToMoveLeft()
{
	// try to move left
	if (!moveDetermined && currentCol - 1 >= 0)
	{
		if (!maze.getVal(currentRow, currentCol - 1)) // left is a empty space
		{
			// not previous position
			if (!(currentRow == stack.PeekPrevRow() && currentCol - 1 == stack.PeekPrevCol()))
			{
				//move left
				currentCol--;
				bool branch = isBranch(maze, currentRow, currentCol, stack.PeekRow(), stack.PeekCol());
				stack.Push(currentRow, currentCol, branch);

				moveDetermined = true;
				
			}
		}
	}
}

void tryToMoveUp()
{
	// try to move up
	if (!moveDetermined && currentRow - 1 >= 0)
	{
		if (!maze.getVal(currentRow - 1, currentCol)) // up is a empty space
		{
			// not previous position
			if (!(currentRow - 1 == stack.PeekPrevRow() && currentCol == stack.PeekPrevCol()))
			{
				//move up
				currentRow--;
				bool branch = isBranch(maze, currentRow, currentCol, stack.PeekRow(), stack.PeekCol());
				stack.Push(currentRow, currentCol, branch);

				moveDetermined = true;
				
			}
		}
	}
}

bool isBranch(Maze maze, int row, int col, int prevRow, int prevCol)
{
	int paths = 0;

	// top
	if (row - 1 >= 0)
		if (!maze.getVal(row - 1, col))
			if (!(row - 1 == prevRow && col == prevCol))
				++paths;
	// bottom
	if (row + 1 <= maze.rows)
		if (!maze.getVal(row + 1, col))
			if (!(row + 1 == prevRow && col == prevCol))
				++paths;
	// left
	if (col - 1 >= 0)
		if (!maze.getVal(row, col - 1))
			if (!(row == prevRow && col - 1 == prevCol))
			++paths;
	// right
	if (col + 1 <= maze.cols)
		if (!maze.getVal(row, col + 1))
			if (!(row == prevRow && col + 1== prevCol))
				++paths;

	if (paths > 1)
		return true;
	else
		return false;
}


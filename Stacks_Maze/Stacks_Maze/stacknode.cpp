//#include "stdafx.h"
#include <iostream>
#include "stacknode.h"
#include "Maze.h"

using namespace std;

StackNode::StackNode() 
{
}

StackNode::StackNode(int _row, int _col, bool _branch, StackNode* next) : row(_row), col(_col), branch(_branch), _next(next)
{
}

StackNode::~StackNode()
{
}

int StackNode::getRow()
{
	return row;
}

int StackNode::getCol()
{
	return col;
}

bool StackNode::isBranch()
{
	return branch;
}

StackNode* StackNode::getNext()
{
	return _next;
}

void StackNode::setNext(StackNode *next)
{
	_next = next;
}



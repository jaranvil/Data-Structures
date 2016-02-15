//#include "stdafx.h"
#include <iostream>
#include "stacknode.h"
#include "stack.h"

using namespace std;


Stack::Stack() : _top(NULL)
{
}

Stack::~Stack()
{
	while (_top != NULL)
	{
		Pop();
	}
}

myerror_code Stack::Push(int row, int col, bool branch)
{
	_top = new StackNode(row, col, branch, _top);
	return(success);
}

int Stack::PeekRow()
{
	return _top->getRow();
}

int Stack::PeekCol()
{
	return _top->getCol();
}

int Stack::PeekPrevRow()
{
	if (_top->getNext())
	{
		return _top->getNext()->getRow();
	}
	else
		return 0;
}

int Stack::PeekPrevCol()
{
	if (_top->getNext())
	{
		return _top->getNext()->getCol();
	}
	else
		return 0;
}



void Stack::ReturnToBranch()
{
	while (_top != NULL && !_top->isBranch())
	{
		Pop();
	}
}

myerror_code Stack::Pop()
{
	if (_top != NULL) {

		StackNode* node = _top;
		_top = _top->getNext();
		delete node;
		return(success);
	}
	else {
		return(underflow);
	}
}

ostream& operator<<(ostream& output, Stack& stack)
{
	StackNode *node = stack._top;

	while (node != NULL)
	{
		cout << node->getRow() << ", " << node->getCol() << endl;
		node = node->getNext();
	}

	return output;
}


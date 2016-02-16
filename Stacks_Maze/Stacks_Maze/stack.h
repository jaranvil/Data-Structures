#pragma once
#ifndef _STACK_H
#define _STACK_H

#include <iostream>
#include "stacknode.h"

using namespace std;
enum myerror_code { success, underflow, overflow };

class Stack
{	
public:
	StackNode *_top;

	Stack();
	virtual ~Stack();

	myerror_code Push(int, int, bool);

	int PeekRow();
	int PeekCol();
	int PeekPrevRow();
	int PeekPrevCol();
	int PeekBranch();

	void ReturnToBranch();
	myerror_code Pop();

	friend ostream& operator<<(ostream& output, Stack& stack);
};

#endif

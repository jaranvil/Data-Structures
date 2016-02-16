#pragma once
#ifndef _STACKNODE_H
#define _STACKNODE_H

class StackNode
{
private:
	StackNode *_next;
	int row;
	int col;		

public:
	int branchDirection = 0;
	bool branch;

	StackNode();
	StackNode(int, int, bool, StackNode* next);
	virtual ~StackNode();

	int getRow();
	int getCol();
	bool isBranch();

	StackNode* getNext();
	void setNext(StackNode *next);
};

#endif

#pragma once
#ifndef _STACKNODE_H
#define _STACKNODE_H

class StackNode
{
private:
	int row;
	int col;
	bool branch;
	StackNode *_next;

public:
	

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

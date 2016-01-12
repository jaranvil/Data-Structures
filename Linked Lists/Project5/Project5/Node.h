#ifndef _NODE_H
#define _NODE_H
#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;

	Node() : next(NULL), data(-1) {}
};

#endif
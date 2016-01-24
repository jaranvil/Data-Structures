#ifndef _NODE_H
#define _NODE_H
#include <iostream>
using namespace std;

class Node
{
public:
	int num;
	string direction;
	Node *next;

	Node() : next(NULL), num(-1) {}
};

#endif
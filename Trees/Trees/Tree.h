
#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;

struct Node
{
	int key;
	string word;
	Node *left;
	Node *right;
	Node *parent;
	char balanceFactor;
};

class Tree
{
private:
	Node   *root;

public:
	Tree();            // Constructor
	~Tree();           // Destructor
	void Insert(Node *n);
	void restore(Node *ancestor, Node *newNode);
	void adjustBalanceFactors(Node *end, Node *start);
	void rotateLeft(Node *n);
	void rotateRight(Node *n);
	void adjustLeftRight(Node *end, Node *start);
	void adjustRightLeft(Node *end, Node *start);
	void PrintTree();
private:
	void ClearTree(Node *n);
	void Print(Node *n);
};

#endif
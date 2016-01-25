#include <iostream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

// delete list
LinkedList::~LinkedList()
{
	Node *node = first;

	while (node != NULL)
	{
		Node *temp = node;
		node = node->next;
		delete temp;
	}
}

void LinkedList::addValue(int num, string direction)
{
	Node *node = new Node();

	// combination direction and value
	node->num = num;
	node->direction = direction;

	if (first == NULL)
		first = node;
	else
	{
		Node *currNode = first;
		Node *prevNode = NULL;

		while (currNode != NULL)
		{
			prevNode = currNode;
			currNode = currNode->next;
		}

		if (prevNode != NULL)
			prevNode->next = node;		
	}
}

int LinkedList::getNodeNum(int nodenum)
{
	int index = -1;

	Node *node = first;
	Node *prev = NULL;

	while (node != NULL)
	{
		index++;

		if (index == nodenum)
			break;

		prev = node;
		node = node->next;
	}

	if (index >= 0)
		return node->num;
}

void LinkedList::changeNode(int nodenum, int num)
{
	int index = -1;

	Node *node = first;
	Node *prev = NULL;

	while (node != NULL)
	{
		index++;

		if (index == nodenum)
			break;

		prev = node;
		node = node->next;
	}

	if (index >= 0)
		node->num = num;
}

ostream& operator<<(ostream& output, LinkedList& list)
{
	Node *currNode = list.first;

	int counter = 0; // or odd/even check for direction R/L
	while (currNode != NULL)
	{
		char direction;
		if (counter % 2 == 0)
			direction = 'R';
		else
			direction = 'L';
		
		if (currNode->num < 10)
			output << direction << currNode->num << "  ";
		else 
			output << direction << currNode->num << " ";

		counter++;
		currNode = currNode->next;
	}

	return output;
}



















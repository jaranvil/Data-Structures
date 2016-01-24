#include <iostream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

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

void LinkedList::addValue(int num)
{
	Node *node = new Node();
	node->data = num;

	if (first == NULL)
	{
		first = node;
	}
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
		{
			prevNode->next = node;
		}
	}
}

void LinkedList::deleteValue(int value)
{
	Node *node = first;
	Node *prev = NULL;

	while (node != NULL)
	{
		if (node->data == value)
		{
			break;
		}

		prev = node;
		node = node->next;
	}

	if (node != NULL)
	{
		if (node == first)
		{
			first = node->next;
		}
		else
		{
			prev->next = node->next;
		}

		delete node;
	}
}

int LinkedList::getNode(int nodenum)
{
	int index = -1;

	Node *node = first;
	Node *prev = NULL;

	while (node != NULL)
	{
		index++;

		if (index == nodenum)
		{
			break;
		}

		prev = node;
		node = node->next;
	}

	if (index >= 0)
	{
		return node->data;
	}
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
		{
			break;
		}

		prev = node;
		node = node->next;
	}

	if (index >= 0)
	{
		node->data = num;
	}
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
		
		if (currNode->data < 10)
			output << direction << currNode->data << "  ";
		else 
			output << direction << currNode->data << " ";

		counter++;
		currNode = currNode->next;
	}

	return output;
}



















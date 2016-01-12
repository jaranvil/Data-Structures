#include <iostream>
#include "Node.h"

using namespace std;

class LinkedList
{
public:
	Node *first;

	LinkedList() : first(NULL) {}

	virtual ~LinkedList();

	void addValue(int num);

	void deleteValue(int value);

	void deleteNode(int nodenum);

	void insertAfterValue(int value, int num);

};

ostream& operator<<(ostream& output, LinkedList& list);















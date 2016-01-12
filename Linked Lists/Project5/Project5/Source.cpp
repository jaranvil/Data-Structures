#include <stdio.h>
#include <iostream>
#include <conio.h>
#include "LinkedList.h"

// main program
int main(int argc, char *argv[]) {
	//int i = 1;
	//// decode arguments
	//if (argc < 2) {
	//	printf("You must provide at least one argument\n");

	//}
	//// report settings
	//for (; i<argc; i++) printf("Argument %d:%s\n", i, argv[i]);

	//_getch();
	

	// test 1: adding new nodes

	LinkedList list;

	list.addValue(3);
	list.addValue(5);
	list.addValue(1);
	list.addValue(7);
	list.addValue(9);

	cout << "The list contains the following numbers: " << endl << endl;
	cout << list;

	// test 2: delete a node

	cout << "\nDeleting...." << endl;

	list.deleteValue(1);
	list.deleteNode(2);

	cout << "The list contains the following numbers: " << endl << endl;
	cout << list;

	// test 3: insert a node

	cout << "\nInserting...." << endl;

	// tests to insert after valid node
	list.insertAfterValue(3, 10);
	// test to insert after non-existent node
	list.insertAfterValue(11, 12);

	cout << "The list contains the following numbers: " << endl << endl;
	cout << list;

	_getch();
	return 0;
}

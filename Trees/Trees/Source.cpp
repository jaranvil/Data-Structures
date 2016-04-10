#include "Tree.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

Node *createNewNode(int, string);

int main()
{
	Tree *theTree = new Tree();

	ifstream infile("C:\\Users\\s0739107\\Documents\\words.txt");

	string line;
	int counter = 0;
	while (getline(infile, line))
	{
		counter++;
		theTree->Insert(createNewNode(counter, line));	
		
	}


	theTree->PrintTree();


	//// Add 70
	//cout << "\nAdding Node 70\n";
	//theAVLTree->Insert(createNewNode(70));
	//theAVLTree->PrintTree();
	//// Add 30
	//cout << "\nAdding Node 30\n";
	//theAVLTree->Insert(createNewNode(30));
	//theAVLTree->PrintTree();
	//// Add 10
	//cout << "\nAdding Node 10\n";
	//theAVLTree->Insert(createNewNode(10));
	//theAVLTree->PrintTree();
	//// Add 90
	//cout << "\nAdding Node 90\n";
	//theAVLTree->Insert(createNewNode(90));
	//theAVLTree->PrintTree();
	//// Add 60
	//cout << "\nAdding Node 60\n";
	//theAVLTree->Insert(createNewNode(60));
	//theAVLTree->PrintTree();
	//cout << "\n***** Adding Node to trigger test of case 1\n";
	//// Add 55
	//cout << "\nAdding Node 55\n";
	//theAVLTree->Insert(createNewNode(55));
	//theAVLTree->PrintTree();
	//cout << "\nEND TESTING CASE 1\n\n";
	delete theTree;
	cout << "-----------------------------------------------\n";
	cout << "-----------------------------------------------\n";



	_getch();

	//cout << "\nPress Enter to start the next test.\n\n";
	//gets(ans);

	//// Create a tree and test case 3
	//theAVLTree = new Code203_Tree();
	//cout << "-----------------------------------------------\n";
	//cout << "TESTING CASE 3\n\n";
	//// Add 50
	//cout << "\nAdding Node 50\n";
	//theAVLTree->Insert(createNewNode(50));
	//theAVLTree->PrintTree();
	//// Add 20
	//cout << "\nAdding Node 20\n";
	//theAVLTree->Insert(createNewNode(20));
	//theAVLTree->PrintTree();
	//// Add 70
	//cout << "\nAdding Node 70\n";
	//theAVLTree->Insert(createNewNode(70));
	//theAVLTree->PrintTree();
	//// Add 10
	//cout << "\nAdding Node 10\n";
	//theAVLTree->Insert(createNewNode(10));
	//theAVLTree->PrintTree();
	//// Add 90
	//cout << "\nAdding Node 90\n";
	//theAVLTree->Insert(createNewNode(90));
	//theAVLTree->PrintTree();
	//// Add 60
	//cout << "\nAdding Node 60\n";
	//theAVLTree->Insert(createNewNode(60));
	//theAVLTree->PrintTree();
	//// Add 80
	//cout << "\nAdding Node 80\n";
	//theAVLTree->Insert(createNewNode(80));
	//theAVLTree->PrintTree();
	//// Add 98
	//cout << "\nAdding Node 98\n";
	//theAVLTree->Insert(createNewNode(98));
	//theAVLTree->PrintTree();
	//cout << "\n***** Adding Node to trigger test of case 3\n";
	//// Add 93
	//cout << "\nAdding Node 93\n";
	//theAVLTree->Insert(createNewNode(93));
	//theAVLTree->PrintTree();
	//cout << "\nEND TESTING CASE 3\n\n";
	//delete theAVLTree;
	//cout << "-----------------------------------------------\n";
	//cout << "-----------------------------------------------\n";

	//cout << "\nPress Enter to start the next test.\n\n";
	//gets(ans);

	//// Create a tree and test case 4
	//theAVLTree = new Code203_Tree();
	//cout << "-----------------------------------------------\n";
	//cout << "TESTING CASE 4\n\n";
	//// Add 50
	//cout << "\nAdding Node 50\n";
	//theAVLTree->Insert(createNewNode(50));
	//theAVLTree->PrintTree();
	//// Add 20
	//cout << "\nAdding Node 20\n";
	//theAVLTree->Insert(createNewNode(20));
	//theAVLTree->PrintTree();
	//// Add 70
	//cout << "\nAdding Node 70\n";
	//theAVLTree->Insert(createNewNode(70));
	//theAVLTree->PrintTree();
	//// Add 10
	//cout << "\nAdding Node 10\n";
	//theAVLTree->Insert(createNewNode(10));
	//theAVLTree->PrintTree();
	//// Add 30
	//cout << "\nAdding Node 30\n";
	//theAVLTree->Insert(createNewNode(30));
	//theAVLTree->PrintTree();
	//// Add 90
	//cout << "\nAdding Node 90\n";
	//theAVLTree->Insert(createNewNode(90));
	//theAVLTree->PrintTree();
	//// Add 60
	//cout << "\nAdding Node 60\n";
	//theAVLTree->Insert(createNewNode(60));
	//theAVLTree->PrintTree();
	//// Add 5
	//cout << "\nAdding Node 5\n";
	//theAVLTree->Insert(createNewNode(5));
	//theAVLTree->PrintTree();
	//// Add 15
	//cout << "\nAdding Node 15\n";
	//theAVLTree->Insert(createNewNode(15));
	//theAVLTree->PrintTree();
	//// Add 25
	//cout << "\nAdding Node 25\n";
	//theAVLTree->Insert(createNewNode(25));
	//theAVLTree->PrintTree();
	//// Add 35
	//cout << "\nAdding Node 35\n";
	//theAVLTree->Insert(createNewNode(35));
	//theAVLTree->PrintTree();
	//cout << "\n***** Adding Node to trigger test of case 4\n";
	//// Add 13
	//cout << "\nAdding Node 13\n";
	//theAVLTree->Insert(createNewNode(13));
	//theAVLTree->PrintTree();
	//cout << "\nEND TESTING CASE 4\n\n";
	//delete theAVLTree;
	//cout << "-----------------------------------------------\n";
	//cout << "-----------------------------------------------\n";

	//cout << "\nPress Enter to start the next test.\n\n";
	//gets(ans);

	//// Create a tree and test case 5
	//theAVLTree = new Code203_Tree();
	//cout << "-----------------------------------------------\n";
	//cout << "TESTING CASE 5\n\n";
	//// Add 50
	//cout << "\nAdding Node 50\n";
	//theAVLTree->Insert(createNewNode(50));
	//theAVLTree->PrintTree();
	//// Add 20
	//cout << "\nAdding Node 20\n";
	//theAVLTree->Insert(createNewNode(20));
	//theAVLTree->PrintTree();
	//// Add 90
	//cout << "\nAdding Node 90\n";
	//theAVLTree->Insert(createNewNode(90));
	//theAVLTree->PrintTree();
	//// Add 10
	//cout << "\nAdding Node 10\n";
	//theAVLTree->Insert(createNewNode(10));
	//theAVLTree->PrintTree();
	//// Add 40
	//cout << "\nAdding Node 40\n";
	//theAVLTree->Insert(createNewNode(40));
	//theAVLTree->PrintTree();
	//// Add 70
	//cout << "\nAdding Node 70\n";
	//theAVLTree->Insert(createNewNode(70));
	//theAVLTree->PrintTree();
	//// Add 100
	//cout << "\nAdding Node 100\n";
	//theAVLTree->Insert(createNewNode(100));
	//theAVLTree->PrintTree();
	//// Add 5
	//cout << "\nAdding Node 5\n";
	//theAVLTree->Insert(createNewNode(5));
	//theAVLTree->PrintTree();
	//// Add 15
	//cout << "\nAdding Node 15\n";
	//theAVLTree->Insert(createNewNode(15));
	//theAVLTree->PrintTree();
	//// Add 30
	//cout << "\nAdding Node 30\n";
	//theAVLTree->Insert(createNewNode(30));
	//theAVLTree->PrintTree();
	//// Add 45
	//cout << "\nAdding Node 45\n";
	//theAVLTree->Insert(createNewNode(45));
	//theAVLTree->PrintTree();
	//cout << "\n***** Adding Node to trigger test of case 5\n";
	//// Add 35
	//cout << "\nAdding Node 35\n";
	//theAVLTree->Insert(createNewNode(35));
	//theAVLTree->PrintTree();
	//cout << "\nEND TESTING CASE 5\n\n";
	//delete theAVLTree;
	//cout << "-----------------------------------------------\n";
	//cout << "-----------------------------------------------\n";

	//cout << "\nPress Enter to start the next test.\n\n";
	//gets(ans);

	//// Create a tree and test case 6
	//theAVLTree = new Code203_Tree();
	//cout << "-----------------------------------------------\n";
	//cout << "TESTING CASE 6\n\n";
	//// Add 50
	//cout << "\nAdding Node 50\n";
	//theAVLTree->Insert(createNewNode(50));
	//theAVLTree->PrintTree();
	//// Add 20
	//cout << "\nAdding Node 20\n";
	//theAVLTree->Insert(createNewNode(20));
	//theAVLTree->PrintTree();
	//// Add 80
	//cout << "\nAdding Node 80\n";
	//theAVLTree->Insert(createNewNode(80));
	//theAVLTree->PrintTree();
	//// Add 70
	//cout << "\nAdding Node 70\n";
	//theAVLTree->Insert(createNewNode(70));
	//theAVLTree->PrintTree();
	//// Add 90
	//cout << "\nAdding Node 90\n";
	//theAVLTree->Insert(createNewNode(90));
	//theAVLTree->PrintTree();
	//cout << "\n***** Adding Node to trigger test of case 6\n";
	//// Add 75
	//cout << "\nAdding Node 75\n";
	//theAVLTree->Insert(createNewNode(75));
	//theAVLTree->PrintTree();
	//cout << "\nEND TESTING CASE 6\n\n";
	//delete theAVLTree;
	//cout << "-----------------------------------------------\n";
	//cout << "-----------------------------------------------\n";

	//cout << "\nAll testing complete.\n";
	//cout << "\nPress Enter to terminate the application.\n\n";
	//gets(ans);
}


Node *createNewNode(int key, string word)
{
	Node *temp = new Node();
	temp->key = key;
	temp->word = word;
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = NULL;
	temp->balanceFactor = '=';
	return temp;
}

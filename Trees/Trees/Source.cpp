#include "Tree.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

Node *createNewNode(string);
string cleanString(string word);

int main()
{
	Tree *theTree = new Tree();

	ifstream infile("C:\\Users\\w0269431\\Desktop\\words.txt");	

	string line;
	int counter = 0;
	while (getline(infile, line))
	{
		counter++;
		theTree->Insert(createNewNode(line));	
		/*if (counter == 7)
			break;*/
	}


	theTree->PrintTree();

	cout << endl << "Press Enter to check file" << endl;
	_getch(); 
	
	ifstream file;
	file.open("C:\\Users\\w0269431\\Desktop\\document.txt");
	string word;
	while (file >> word)
	{
		theTree->find(cleanString(word), theTree->root);
	}



	_getch();

	
}


string cleanString(string s)
{
	char chars[] = "()-,<>\".123456789#&";
	string word = s;
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	for (unsigned int i = 0; i < strlen(chars); ++i)
	{
		// you need include <algorithm> to use general algorithms like std::remove()
		word.erase(remove(word.begin(), word.end(), chars[i]), word.end());
	}
	return word;
}

Node *createNewNode(string word)
{
	Node *temp = new Node();
	temp->key = word;
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = NULL;
	temp->balanceFactor = '=';
	return temp;
}

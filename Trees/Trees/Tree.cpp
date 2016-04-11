#include "Tree.h"
#include "string"
using namespace std;

Tree::Tree()
{
	root = NULL;   
}

Tree::~Tree()
{
	ClearTree(root);
}

void Tree::find(string target, Node *node)
{
	
	if (node == NULL)
	{
		if (target != "")
			cout << "Misspelled: " << target << endl;
	}
	else
	{
		if (target < node->key)
		{
			find(target, node->left);
		}
		else
		{
			if (target > node->key)
			{
				find(target, node->right);
			}
			else
			{
				//cout << "Element found!" << endl;
			}
		}
	}
}

void Tree::ClearTree(Node *n)
{
	if (n != NULL)
	{
		ClearTree(n->left);   
		ClearTree(n->right);   
		delete n;         
	}
}

void Tree::Insert(Node *newNode)
{
	Node *temp, *back, *ancestor;

	temp = root;
	back = NULL;
	ancestor = NULL;

	// Check for empty tree first
	if (root == NULL)
	{
		root = newNode;
		return;
	}

	while (temp != NULL) // Loop till temp falls out of the tree 
	{
		back = temp;

		if (temp->balanceFactor != '=')
			ancestor = temp;
		if (newNode->key < temp->key)
			temp = temp->left;
		else
			temp = temp->right;
	}


	newNode->parent = back;   // Set parent
	if (newNode->key < back->key)  // Insert at left
	{
		back->left = newNode;
	}
	else     // Insert at right
	{
		back->right = newNode;
	}

	
	//restore(ancestor, newNode);
}

void Tree::restore(Node *ancestor, Node *newNode)
{

	// ancestor is NULL, i.e. balanceFactor of all ancestors' is '='

	if (ancestor == NULL)
	{
		if (newNode->key < root->key)      
			root->balanceFactor = 'L';
		else
			root->balanceFactor = 'R';   
									
		adjustBalanceFactors(root, newNode);
	}

	else if (((ancestor->balanceFactor == 'L') && (newNode->key > ancestor->key)) ||
		((ancestor->balanceFactor == 'R') && (newNode->key < ancestor->key)))
	{
		ancestor->balanceFactor = '=';
		
		adjustBalanceFactors(ancestor, newNode);
	}

	else if ((ancestor->balanceFactor == 'R') && (newNode->key > ancestor->right->key))
	{
		ancestor->balanceFactor = '='; 
		rotateLeft(ancestor);       
									
		adjustBalanceFactors(ancestor->parent, newNode);
	}



	else if ((ancestor->balanceFactor == 'L') && (newNode->key < ancestor->left->key))
	{
		ancestor->balanceFactor = '='; 
		rotateRight(ancestor);       
								
		adjustBalanceFactors(ancestor->parent, newNode);
	}


	else if ((ancestor->balanceFactor == 'L') && (newNode->key > ancestor->left->key))
	{
		rotateLeft(ancestor->left);
		rotateRight(ancestor);
		// Adjust the balanceFactor for all nodes from newNode back up to ancestor
		adjustLeftRight(ancestor, newNode);
	}

	else
	{
		// Perform double left rotation (actually a right followed by a left)
		rotateRight(ancestor->right);
		rotateLeft(ancestor);
		adjustRightLeft(ancestor, newNode);
	}
}


void Tree::adjustBalanceFactors(Node *end, Node *start)
{
	Node *temp = start->parent; // Set starting point at start's parent

	while (temp != end)
	{
		if (start->key < temp->key)
			temp->balanceFactor = 'L';
		else
			temp->balanceFactor = 'R';
		temp = temp->parent;

	} // end while
}




void Tree::rotateLeft(Node *n)
{
	Node *temp = n->right;  
	n->right = temp->left;      
	if (temp->left != NULL)      
		temp->left->parent = n;// Reset the left child's parent
	if (n->parent == NULL)     
	{
		root = temp;      // Make temp the new root
		temp->parent = NULL;   // Root has no parent
	}
	else if (n->parent->left == n) // If n was the left child of its' parent
		n->parent->left = temp;   // Make temp the new left child
	else              
		n->parent->right = temp;// Make temp the new right child

	temp->left = n;      
	n->parent = temp;         // Reset n's parent
}

void Tree::rotateRight(Node *n)
{
	Node *temp = n->left;   //Hold pointer to temp
	n->left = temp->right;    
	if (temp->right != NULL)      
		temp->right->parent = n;
	if (n->parent == NULL)       // If n was root
	{
		root = temp;     
		temp->parent = NULL;   
	}
	else if (n->parent->left == n) 
		n->parent->left = temp;  
	else             
		n->parent->right = temp;

	temp->right = n;         // Move n to right child of temp
	n->parent = temp;         // Reset n's parent
}

void Tree::adjustLeftRight(Node *end, Node *start)
{
	if (end == root)
		end->balanceFactor = '=';
	else if (start->key < end->parent->key)
	{
		end->balanceFactor = 'R';
		adjustBalanceFactors(end->parent->left, start);
	}
	else
	{
		end->balanceFactor = '=';
		end->parent->left->balanceFactor = 'L';
		adjustBalanceFactors(end, start);
	}
}


// adjustRightLeft
// @param end- last node back up the tree that needs adjusting
// @param start - node just inserted 

void Tree::adjustRightLeft(Node *end, Node *start)
{
	if (end == root)
		end->balanceFactor = '=';
	else if (start->key > end->parent->key)
	{
		end->balanceFactor = 'L';
		adjustBalanceFactors(end->parent->right, start);
	}
	else
	{
		end->balanceFactor = '=';
		end->parent->right->balanceFactor = 'R';
		adjustBalanceFactors(end, start);
	}
}


// PrintTree()
// Intiate a recursive traversal to print the tree

void Tree::PrintTree()
{
	cout << "\nPrinting the tree...\n";
	cout << "Root Node: " << root->key << " balanceFactor is " << root->balanceFactor << "\n\n";
	Print(root);
}


// Print()
// Perform a recursive traversal to print the tree

void Tree::Print(Node *n)
{
	if (n != NULL)
	{
		cout << " key: " << n->key << " balance: " << n->balanceFactor << "\n";

		if (n->left != NULL)
		{
			cout << "\t moving left\n";
			Print(n->left);
			cout << "\nReturning to Node" << n->key << " from its' left subtree\n\n";
		}
		else
		{
			cout << "\t left subtree is empty\n";
		}

		//cout << "Node: " << n->key << " balanceFactor is " << n->balanceFactor << "\n";

		if (n->right != NULL)
		{
			cout << "\t moving right\n";
			Print(n->right);
			cout << "\nReturning to Node" << n->key << " from its' right subtree\n\n";
		}
		else
		{
			cout << "\t right subtree is empty\n";
		}
	}

	
}
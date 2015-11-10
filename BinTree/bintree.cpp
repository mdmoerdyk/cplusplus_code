/*Mark Moerdyk
CSS 343 Assignment 2
Creates and implements all required functions for
a binary search tree.
Binary tree uses structure with NodeData*/

#include "bintree.h"
#include <algorithm>

using namespace std;

/*Constructor for BinTree()
Creates an empty binary tree*/
BinTree::BinTree()
{
	root = NULL;
}

/*Constructor for BinTree(bintree copy)
Copies one BinTree to another
Calls buildTree that helps copy the BinTree*/
BinTree::BinTree(const BinTree &old)
{
	if (old.isEmpty())
	{
		root = NULL;
		return;
	}
	//not empty tree
	root = new Node;
	root->data = new NodeData(*old.root->data);
	root->left = NULL;
	root->right = NULL;
	buildTree(root, old.root);

}

/* check to see if the binary tree is empty. 
If so, returns true else returns false*/
bool BinTree::isEmpty() const
{
	if (root == NULL)
	{
		return true;
	}
	return false;
}

/*Function that copies the node of the original to a new Node.
Used to copy an entire binary tree. Calls recursive so that code can
go through entire binary tree
Puts Nulls in so no memory leaks when creating new Node*/
void BinTree::buildTree(Node *newNode, const Node *orig) 
{
	if(orig->left != NULL){
        newNode->left = new Node;
        newNode->left->data = new NodeData(*orig->left->data); //copies old data value to new data  
		newNode->left->left = NULL;
		newNode->left->right = NULL;
        buildTree(newNode->left,orig->left);
    }
     if(orig->right != NULL){
        newNode->right = new Node;
        newNode->right->data = new NodeData(*orig->right->data); //copies old data value to new data
		newNode->right->left = NULL;
		newNode->right->right = NULL;
        buildTree(newNode->right,orig->right);
    }
}

//destructor calls makeEmpty()
BinTree::~BinTree()
{
	if (!isEmpty())
	{
		makeEmpty();
	}
}

/*Functions that call deleteTree and sets the root to Null
so there are no memory leaks*/
void BinTree::makeEmpty()
{
	deleteTree(root);
	root = NULL;
}
/*Function that delete all Nodes of the BinTree. Recursive
call is used so that it starts at the lowest part of the BinTree so
there is no memory leakage and sets to Null*/
void BinTree::deleteTree(Node *d)
{
	if (d != NULL)
	{
		//recursive call to go to all points of the tree
		deleteTree(d->left);
		deleteTree(d->right);
		delete d->data;
		d->data = NULL;
		delete d;
		d = NULL;
	}
}

/*Operator that compares two binary trees
Calls isEqualHelper and returns boolean value*/
bool BinTree::operator==(const BinTree &rhs) const
{
	return isEqualHelper(this->root, rhs.root);
}

/*Function that compares same node on two different BinTrees
Created for recursive calling so that function can compare all values
Returns true if all values same, or false if at least one is different*/
bool BinTree::isEqualHelper(const Node*lhs, const Node*rhs)const
{
	if (lhs == NULL && rhs == NULL)
	{
		return true;
	}
	if (lhs != NULL && rhs == NULL)
	{
		return false;
	}
	if (lhs == NULL && rhs != NULL)
	{
		return false;
	}
	//goes through all branches of the binTree
	return ((*lhs->data == *rhs->data) && isEqualHelper(lhs->left, rhs->left) && isEqualHelper(lhs->right, rhs->right));
}

/*Operator that compares two binary trees Compares opposite of == operator
Returns boolean.*/
bool BinTree::operator!=(const BinTree &rhs) const
{
	return !(*this == rhs);
}

/*Opeartor that copies binary tree. Very similar to constructor
deletes BinTree that is going to be copied, then call buildTree()
to create a copy of the binTree*/
BinTree& BinTree::operator=(const BinTree &rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	makeEmpty();
	//create new Node to start copy of binTree
	root = new Node;
	root->data = new NodeData(*rhs.root->data);
	root->left = NULL;
	root->right = NULL;
	buildTree(root, rhs.root);
	return *this;
}

/*Function that inserts new Node into a binTree
Assume binTree is a binary search tree. Compares data values of nodes
and if bigger goes right, smaller goes left, and same ends loop*/
bool BinTree::insert(NodeData* newData)
{
	if (isEmpty())
	{
		root = new Node;
		root->data = newData;
		root->left = NULL;
		root->right = NULL;
		return true;
	}

	Node *current = root; //comparison node

	while (current->data != NULL)
	{
		//inserted data is already on binary tree
		if (*newData == *current->data)
		{
			return false;
		}
		
		//inserted data is smaller than current data comparison
		else if (*newData < *current->data)
		{
			if (current->left == NULL)
			{
				current->left = new Node;
				current->left->data = newData;
				current->left->left = NULL;
				current->left->right = NULL;
				return true;
			}
			current = current->left;
		}
		//inserted data is bigger than current data comparison
		else if (*newData > *current->data)
		{
			if (current->right == NULL)
			{
				current->right = new Node;
				current->right->data = newData;
				current->right->right = NULL;
				current->right->left = NULL;
				return true;
			}
			current = current->right;
		}
	}
	return false;
}

/*Function that looks through binTree to see if tree contains
data value requested. Assume binary search tree. If found, value is stored and 
returns true. Else value is NULL and returned false. Similar structure to insert()*/
bool BinTree::retrieve(const NodeData &dataItem, NodeData *&dataFound) const
{
	if (!isEmpty())
	{
		Node *current = root;
		while (current->data != NULL)
		{
			//found data
			if (dataItem == *current->data)
			{
				dataFound = current->data;
				return true;
			}
			//data smaller than comparison, go left
			else if (dataItem < *current->data)
			{
				if (current->left == NULL)
				{
					return false;
				}
				current = current->left;
			}
			//data bigger than comparison, go right
			else if (dataItem > *current->data)
			{
				if (current->right == NULL)
				{
					return false;
				}
				current = current->right;
			}
		}
	}
	//Could not find NodeData
	dataFound = NULL;
	return false;
}

/*Function that finds the height of the data value given.
First finds the data Item in tree. Then if found, returns height.
Else returns 0*/
int BinTree::getHeight(const NodeData &dataItem) const
{
	Node *temp = NULL;
	findNodeLocation(root, dataItem, temp);
	if (temp != NULL)
	{
		return count(temp);
	}
	return 0;
}

/*Function that finds and stores data item within the binary tree.
If data item is found, it stores the data into tempItem for finding the height.
Goes through entire tree as to assume that tree is not a binary search tree*/
void BinTree::findNodeLocation(Node *n, const NodeData &dataItem, Node*& tempItem) const
{
	if (n != NULL)
	{
		findNodeLocation(n->left, dataItem, tempItem);
		if (*n->data == dataItem)
		{
			tempItem = n;
		}
		findNodeLocation(n->right, dataItem, tempItem);
	}
}

/*Function that returns the height of the found values in findNodeLocation()
From Node found, goes through all possible branches and calulates the max number to find
the true height of the data node. Uses <algorithm> to calualte max of int values.
Returns int value*/
int BinTree::count(Node *dataItem) const
{
	if (!dataItem)
	{
		return 0;
	}
	return 1 + max(count(dataItem->left), count(dataItem->right));
}

/*Function that converts binTree to array
calls bstreeToArrayHelper, then deletes binary tree so no memory leak*/
void BinTree::bstreeToArray(NodeData* tempArray[])
{
	bstreeToArrayHelper(root, tempArray);
	makeEmpty();
}

/*Function that places values of Bintree into array in order.
Calls recursive so that all values can be placed.
Array will have all values of BinTree in order*/
void BinTree::bstreeToArrayHelper(Node *current, NodeData* tempArray[]) const
{
	if (current != NULL)
	{
		bstreeToArrayHelper(current->left, tempArray);
		for (int i = 0; i < 100; i++) //set to 100 as arraysize is defined in lab2.cpp
		{
			if (tempArray[i] == NULL)
			{
				tempArray[i] = current->data;
				current->data = NULL;
				i = 100;
			}
		}
		bstreeToArrayHelper(current->right, tempArray);
	}
	
}

/*Function that converts an array to a binTree
First finds the size of the array, then calls 
arrayToBSTreeHelper to help convert into binTree*/
void BinTree::arrayToBSTree(NodeData *tempArray[])
{
	int min = 0;
	int max = 0;
	for (int i = 0; i < 100; i++)
	{
		if (tempArray[i] != NULL)
		{
			max = i;
		}
		
	}
	arrayToBSTreeHelper(min, max, tempArray);
}

/*Function that takes arrary and uses a formula to insert specific points
into the array so that the array can be turned into a binary search tree
Calls insert() to insert value into the binary search tree*/
void BinTree::arrayToBSTreeHelper(int min, int max, NodeData *tempArray[])
{
	int mid = (min + max) / 2;
	if (min <= max)
	{
		insert(tempArray[mid]);
		arrayToBSTreeHelper(min, mid - 1, tempArray);
		arrayToBSTreeHelper(mid + 1, max, tempArray);
	}
}

//------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::displaySideways() const {
	sideways(root, 0);
}

//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::sideways(Node* current, int level) const {
	if (current != NULL) {
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level 
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *current->data << endl;        // display information of object
		sideways(current->left, level);
	}
}

/*Overload operator that prints values of BinTree in order
ends with an end line call.*/
ostream& operator<<(ostream &out, const BinTree &rhs)
{
	rhs.inOrderDisplay(rhs.root);
	out << endl;
	return out;
}

/*Function that goes throughout BinTree and displays values of BinTree
Recursive call so that function can go through all values of tree in order*/
void BinTree::inOrderDisplay(Node* curData) const
{
	if (curData != NULL)
	{
		inOrderDisplay(curData->left);
		cout << *curData->data << " ";
		inOrderDisplay(curData->right);
	}
}
/*Mark Moerdyk
CSS 343 Assignment 2
Header file for bintree.h and helps create all clesses for
bintree.cpp. Includes overloads, constructors, deconstructors, 
operations, global functions, structures for nodeData, and private functions*/

#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>
#include "nodedata.h"

using namespace std;

class BinTree
{
	friend ostream& operator<< (ostream &out, const BinTree &rhs);

public:
	
	//default constructor
	BinTree();
	
	//copy constructor 
	BinTree(const BinTree &old);

	//deconstructor
	~BinTree();

	//Assignment Operators
	BinTree& operator =(const BinTree &rhs);

	//Equality operators
	bool operator==(const BinTree &rhs) const;
	bool operator!=(const BinTree &rhs) const;

	//Function that retrieve data from a BSTree
	bool retrieve(const NodeData &, NodeData* &)const;
	
	//Function that gets height of specific value
	int getHeight(const NodeData &) const;

	//Converts BinTree to array
	void bstreeToArray(NodeData* []);

	//Converts array into BinTree
	void arrayToBSTree(NodeData* []);

	//call to see if BinTree is NULL
	bool isEmpty() const;
	
	// makes BinTree empty, help for deconstructor
	void makeEmpty();

	//insert node into BinTree
	bool insert(NodeData*);

	//display BinTree sideways
	void displaySideways() const;

private:

	//Structure that uses nodeData to store values and pointers for BinTree
	struct Node {
		NodeData* data = NULL;
		Node* left = NULL;
		Node* right = NULL;
	};
	Node* root;
	
	//Helps with copying BinTree to another BinTree
	void buildTree(Node *copy, const Node *orig) ;

	//Helps deconstructor by deleting nodes
	void deleteTree(Node *d);

	//Helps operators to see if BinTree are equal to each other
	bool isEqualHelper(const Node* lhs, const Node* rhs) const;

	//Helps getHeight by finding seacrh node in BinTree
	void findNodeLocation(Node*, const NodeData&, Node *&) const;

	//Helps get Height by counting how high the value is
	int count(Node*) const;

	//Helps bsteeToArray by using a recursive function
	void bstreeToArrayHelper(Node* current, NodeData* tempArray[])const;

	//Helps arrayToBSTree by using a recursive function
	void arrayToBSTreeHelper(int, int, NodeData*[]);

	//Helps with DisplaySideways
	void sideways(Node*, int) const;

	//Helps << overload with a recursive function
	void inOrderDisplay(Node*) const;
};

#endif
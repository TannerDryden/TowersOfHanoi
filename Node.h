/* Name: Tanner Dryden
Description: This Class creates a linked list
*/

#pragma once
#include <iostream>
using namespace std;

class Node
{
private:
	// Data elements
	int payload;
	Node* node;

public:
	friend ostream& operator <<(ostream& outStream, const Node& node);

	// constructor - note no default
	Node(int newPayload, Node* newNext);

	// accessors
	int getPayload() const;
	Node* getNext() const;

	// mutators
	void setPayload(int newPayload);
	void setNext(Node* next);

	// destructor
	~Node();
};


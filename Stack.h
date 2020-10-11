/* Name: Tanner Dryden
Description: this class works in conjuntion with my Node class to create a stack
*/

#pragma once
#include "Node.h"

class Stack
{

private:

	// Data Elements
	Node* top;
	int numNodes;

	// Helper methods

	// display stack in reverse order
	void printStackReverseHelper(Node* tempPtr) const;
	
public:
	
	friend ostream& operator <<(ostream& outStream, const Stack& stack);

	// constructor
	Stack();

	// push/pop methods
	void push(int newPayload);
	int pop();

	// top accessor
	int readTop() const;

	// displays the stack
	void displayStack() const;

	// number of nodes in the stack accessor
	int size() const;

	// pops everything off the stack
	void clearStack();
	
	// destructor
	~Stack();

};


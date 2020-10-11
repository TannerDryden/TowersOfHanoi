// Name: Tanner Dryden

#include "Stack.h"
#include <assert.h>

ostream& operator <<(ostream& outStream, const Stack& stack)
{
	if (stack.top != nullptr)
	{
		stack.printStackReverseHelper(stack.top);
	}
	return(outStream);
}

// constructor
Stack::Stack()
{
	top = nullptr;
	numNodes = 0;
};

// pushes onto the stack
void Stack::push(int newPayload)
{
	top = new Node(newPayload, top);
	numNodes++;
};

// pops off the stack
int Stack::pop()
{
	assert(top != nullptr);
	int tempPayload = top->getPayload();
	Node* tempNode = top->getNext();
	delete top;
	top = tempNode;
	numNodes--;

	return tempPayload;
};

// reads what is on top of the stack
int Stack::readTop() const
{
	// ensures there is a disk on the stack
	assert(top->getPayload() != NULL);

	return top->getPayload();
};


// prints out the stack in reverse
void Stack::printStackReverseHelper(Node* tempPtr) const
{
	if (tempPtr != nullptr)
	{
		printStackReverseHelper(tempPtr->getNext());
		cout << tempPtr->getPayload() << " ";
	}

}

// number of nodes in the stack accessor
int Stack::size() const
{
	return numNodes;
}

// pops everything off the stack
void Stack::clearStack()
{
	while (top != nullptr)
	{
		pop();
	}
};

// destructor
Stack::~Stack()
{
	clearStack();
};
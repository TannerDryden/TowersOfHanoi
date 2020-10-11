// Name: Tanner Dryden

#include "Node.h"

ostream& operator <<(ostream& outStream, const Node& node) 
{
	outStream << node.getPayload();
	return(outStream);
};

// constructor
Node::Node(int newPayload, Node* newNext)
{
	setPayload(newPayload);
	setNext(newNext);
};

 //accessors
int Node::getPayload() const
{
	return payload;
};

Node* Node::getNext() const
{
	return node;
};

// mutators
void Node::setPayload(int newPayload)
{
	payload = newPayload;
};

void Node::setNext(Node* next)
{
	node = next;
};

Node::~Node()
{

};
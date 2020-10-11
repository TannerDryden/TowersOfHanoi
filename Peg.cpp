// Name: Tanner Dryden

#include "Peg.h"
#include <assert.h>
#include <iostream>

ostream& operator <<(ostream& outStream, const Peg& peg)
{
	outStream << peg.getName() << " contains disks: " << peg.stackContents << endl;
	return(outStream);
}

// Constructors - user can specify the peg name and the initial disk count if desired
Peg::Peg(string inputName, int numDisks)
{
	name = inputName;
	
	// loads disks if neccessary
	for (int i = numDisks; i > 0; i--) 
	{
		assert(numDisks > 0);
		stackContents.push(i);
	}
}

 // loads disks on to the peg and asserts loading to be called only once
void Peg::loadDisks(int numDisks)
{
	assert(numDisks > 0);
	for (int i = numDisks; i > 0; i--) {
		stackContents.push(i);
	}
}

// adds a disk to the top of the peg
void Peg::addDisk(int inputDisks)
{
	stackContents.push(inputDisks);
}

// get number of disks
unsigned int Peg::getNumDisks() const
{
	return stackContents.size();
}


// returns the disk on the top of the peg
int Peg::topDisk() const
{
	assert(stackContents.size() > 0);
	int topOfPeg = stackContents.readTop();

	return topOfPeg;
}

// removes the top disk from the peg
int Peg::removeDisk()
{
	assert(stackContents.size() > 0);
	int removedDisk = stackContents.readTop();
	stackContents.pop();

	return removedDisk;
}

// returns name of the peg
string Peg::getName() const
{
	return name;
}

// Destructors
Peg::~Peg() 
{

};
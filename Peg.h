// Name: Tanner Dryden
// Description: This is the interface for my peg class that has various
// functions that can be used in creating peg style games and solutions

#pragma once
#include "Stack.h"
#include <string>

class Peg
{

private:
	// Data Elements
	string name;
	Stack stackContents;

	// Methods
		// Function to add disks to the peg
	void loadDisks(int diskNum);

public:

	friend ostream& operator <<(ostream& outStream, const Peg& peg);

	// Constructors - user initializes with name and number of initial disks
	Peg(string name, int numDisks);

	// Function to display what disks are on the peg
	void printPeg() const;

	// Function that adds a disk to the peg
	void addDisk(int diskNum);

	// Function that removes disks from the peg
	int removeDisk();

	// Funtion to return the disk count
	unsigned int getNumDisks() const;

	// Accessor for the peg name
	string getName() const;

	// Function to return the value of the top disk
	int topDisk() const;

	// Destructors
	~Peg();
};

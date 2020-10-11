/*
Name: Tanner Dryden
Project 2: Towers of Hanoi
Date: 10/5/2019
Description: This is a program that utilizes my classes to 
			 create a solution to the towers of hanoi.
*/

#include "Peg.h"
#include <iostream>
#include <assert.h>

// global const of disks
const int NUM_DISKS(7);

// Fucntion declarations
int hanoi(Peg& peg1, Peg& peg3, Peg& peg2, int numDisks);
void moveDisk(Peg& peg1, Peg& peg3);

// Declaring Objects for the Peg Class
Peg peg1("Peg 1", NUM_DISKS);
Peg peg2("Peg 2", 0);
Peg peg3("Peg 3", 0);

int main()
{
	int moves = 0;

	//{
	//	Node cliffNode(123, (Node*)0x45678);
	//	Stack cliffStack; cliffStack.push(123); cliffStack.push(-456); cliffStack.push(789);
	//	Peg cliffPeg("Cliff Peg", 3);
	//	cout << cliffNode << cliffStack << cliffPeg << endl;
	//}

	cout << "Welcome to Tanners Towers of Hanoi Solution!" << endl << endl;

	// printing the state of the pegs
 	cout << peg1 << peg2 << peg3;

	cout << endl;
 	system("pause");
 	cout << endl;

	// initiates the recursive solution and also returns the number of moves used to complete
	moves = hanoi(peg1, peg3, peg2, NUM_DISKS);

	cout << endl << "It took " << moves << " moves to complete the Towers of Hanoi" << endl << endl;

	// printing the state of the pegs after the solution is complete
	cout << peg1 << peg2 << peg3;
}

// the recursive function that stacks all of the calls and then executes the solution
int hanoi(Peg& peg1, Peg& peg3, Peg& peg2, int numDisks) {
	int counter = 0;
	if (numDisks > 0) {

		// used a counter to keep track of how many moves are used in the function
		counter = hanoi(peg1, peg2, peg3, numDisks - 1);
		moveDisk(peg1, peg3);
		counter++;
		counter += hanoi(peg2, peg3, peg1, numDisks - 1);
	}
	return counter;
}

// moved a singular disk from one peg to another using popback and pushback while enforcing the rule
// that the disk being moved cannot be placed on a smaller disk by asserting
void moveDisk(Peg& peg1, Peg& peg3) {
	int disk = 0;

	// asserting the rule within towers of hanoi
	if (peg3.getNumDisks() != 0) {
		assert(peg3.topDisk() > peg1.topDisk());
	}

	disk = peg1.topDisk();
	cout << "Moving disk " << disk << " from " << peg1.getName() << " to " << peg3.getName() << endl;
	peg1.removeDisk();
	peg3.addDisk(disk);
}

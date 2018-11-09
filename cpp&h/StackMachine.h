// David Ang
// 10-29-2018
// CSC2431
// Lab 3
#ifndef stackMachine_H
#define stackMachine_H
#include <iostream>
#include <string>
#include <fstream>

#include "SimpleStack.h"

template <class T>
class stackMachine
{
public:
	stackMachine();

	// pushes the element to the stack
	// Parameters: newItem pushes the newItem onto the stack
	// Return : Type T
	T smPush(const T& newItem); 

	// pops out the element from the stack
	// Parameters: N/A
	// Return : Type T
	T smPop(); 

	// adds the last two elements from the stack
	// Parameters: N/A
	// Return : Type T
	T smAdd(); 

	// look for and returns the element inside an index
	// Parameters: index
	// Return : Type T
	T smPeek(T index); //returns an element from the array in any index takes in an index

	// subtracts the last two elements from the stack
	// Parameters: N/A
	// Return : Type T
	T smSubtract();

	// multiplies the last two elements from the stack
	// Parameters: N/A
	// Return : Type T
	T smMultiply();

	// divides the last two elements from the stack
	// Parameters: N/A
	// Return : Type T
	T smDivide();

	// reads a file the user inputs and then executes commands
	// Parameters: file (the file name)
	// Return : void
	void readFile(std::string file);
private:
	T elements[100];
	simpleStack operands;

	int size = 0;

};



#endif



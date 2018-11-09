// David Ang
// 10-29-2018
// CSC2431
// Lab 3
#ifndef simpleStack_H
#define simpleStack_H

#include "LinkedList.h"

template <class T>
class simpleStack : public linkedList
{
public:
	simpleStack(); 
	
	// pushes the top of stack
	// Parameters: newItem (the item we are adding to the stack)
	// Return : Type T
	T push(T newItem); 

	//removes the top item from the stack
	// Parameters: N/A
	// Return : Type T
	T pop(); 

	//returns the top item from the stack
	// Parameters: N/A
	// Return : Type T
	T peek(); 
	

private:

	T size; //counter

};


#endif



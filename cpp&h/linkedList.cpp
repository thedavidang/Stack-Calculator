// David Ang
// 10-29-2018
// CSC2431
// Lab 3
#include "LinkedList.h"

template <class T>
linkedList<T>::linkedList()	// Default Constructor
	: size(0), head(NULL)
{
}

template <class T>
linkedList<T>::~linkedList()	// Destructor
{
	bool success;

	while (!isEmpty())
	{
		success = deleteElement(1);  // Repeatedly delete item 1
	}
}
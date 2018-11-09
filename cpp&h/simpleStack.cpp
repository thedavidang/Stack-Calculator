// David Ang
// 10-29-2018
// CSC2431
// Lab 3
#include "SimpleStack.h"

template<class T>
simpleStack<T>::simpleStack() //Calls list and initializes size
	:linkedList(), size(0) 
{

}


template <class T>
T simpleStack<T>::push(T newItem) //insert to the head of the list
{
	listnode *newPtr = new listnode;
	newPtr->item = newItem;

	if (head == NULL) //for when the list is empty
	{
		head = newPtr;
		head->next = NULL;
		size++;
	}
	else //inserting to the head
	{
		newPtr->next = head; 
		head = newPtr;
		size++;
	}

}

template <class T>
T simpleStack<T>::pop() //remove from the head
{
	if (head == NULL) // For nothing in the list
	{
		return;
	}
	else if (head->next == NULL) //If there's only the head/one thing in the list
	{
		delete head;
		head = NULL;
		size--;
	}
	else //more than 1 thing in the list
	{
		listnode *cur;
		cur = head;
		head = head->next;
		cur->next = NULL;
		delete cur;
		cur = NULL;
		size--;
	}
	
}

template <class T>
T simpleStack<T>::peek()
{
	if (head == NULL) // For nothing in the list
	{
		return;
	}
	else
	{
		return head->item;
	}
}
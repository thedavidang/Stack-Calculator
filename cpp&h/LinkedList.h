// David Ang
// 10-29-2018
// CSC2431
// Lab 3
#ifndef linkedList_H
#define linkedList_H
 
template <class T>
typedef T listItemType;

class linkedList
{	
public:

	linkedList(); //constructor
	~linkedList(); //destructor


private:

	template <class T>
	struct listnode
	{
		T item;
		listnode *next;

	};

	template <class T>
	T size;

	template <class T>
	T * head;




};
#endif


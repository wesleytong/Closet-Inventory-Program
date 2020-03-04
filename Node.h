/* CIS 22C
*
* Terry Tzeng, Brian Lim, Deepkiran Sangha, Wesley Tong
*
* Team Project
*
* Date: 5/8/18
*/
// ****************************************************************************
// node.h , header file.
// Class declaration of Node using template
// ****************************************************************************
#ifndef NODE_H
#define NODE_H

#include <iostream>

template <class T>
class Node {
private:
	T dataVal;         // Value in this node
	Node<T>* next;     // Pointer used to point to next node
public:
	// Constructor
	Node();
	Node(T data);
	// Accessor function
	T getDataVal() { return dataVal; }
	Node<T>* getNext() const { return next; }
	// Mutator function
	void setDataVal(T data) { dataVal = data; }
	void setNext(Node<T> *nextPtr) { next = nextPtr; }

};

// ****************************************************************************
// Purpose: Default Node constructor.
// Sets member attribute dataVal to null. Sets next ptr to nullptr.
// ****************************************************************************
template <class T>
Node<T>::Node()
{
	next = nullptr;
}

// ****************************************************************************
// Purpose: Node constructor, uses template to take any data type as parameter,
// and sets member attribute dataVal. Sets next ptr to nullptr.
// Pre: data - value taken in to set attribute dataVal
// ****************************************************************************
template <class T>
Node<T>::Node(T data)
{
	dataVal = data;
	next = nullptr;
}
#endif

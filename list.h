/* CIS 22c
*
*  Terry Tzeng, Brian Lim, Deepkiran Sangha, Wesley Tong
*
*  Team Project
*
*  Date: 6/5/18
*/
// ****************************************************************************
// list.h , header file.
// Class declaration of List using template
// ****************************************************************************
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"

using namespace std;


template <class T>
class List {
private:
	int nodeCount;        // Number of existing nodes in list
	Node<T>* headPtr;     // Pointer to head of list
	Node<T>* tailPtr;     // Pointer to tail of list
public:
	// Constructor
	List();
	// Destructor
	virtual ~List();
	// Accessor function
	int getNodeCount() const { return nodeCount; }

	virtual bool isEmpty() const;
	virtual int getLength() const;
	virtual bool contains(T& someData) const;
	virtual Node<T>* findAnywhere(T& target) const;
	virtual bool insertAnywhere(int newPosition, const T &newEntry);
	virtual bool insertFront(const T &newEntry);
	virtual bool insertEnd(const T &newEntry);
	virtual bool insertInOrder(const T &newEntry);
	virtual bool removeAnywhere(T& someData);
	virtual bool removePosition(int position);
	virtual bool removeFront();
	virtual bool removeEnd();
	virtual bool emptyList();
	virtual T getEntry(int position) const;
	virtual bool setEntry(const T& existingData, const T& someData);
};

// ****************************************************************************
// Purpose: Default list constructor
// Creates empty list with nodeCount set to 0 and headPtr pointed to nullptr.
// ****************************************************************************
template <class T>
List<T>::List()
{
	nodeCount = 0;
	headPtr = nullptr;
	tailPtr = nullptr;
}

// ****************************************************************************
// Purpose: Destructor. Delete all nodes in list, delete list.
// ****************************************************************************
template <class T>
List<T>::~List()
{
	emptyList();
	delete headPtr;
	delete tailPtr;
}

// ****************************************************************************
// Purpose: Checks if list is empty.
// Return: True if list is empty, otherwise returns false.
// ****************************************************************************
template <class T>
bool List<T>::isEmpty() const
{
	bool isEmptyList = false;

	if (nodeCount == 0)
	{
		isEmptyList = true;
	}

	return isEmptyList;
}

// ****************************************************************************
// Purpose: Gets current number of items in list.
// Return: Int number of items currently in the list.
// ****************************************************************************
template <class T>
int List<T>::getLength() const
{
	return nodeCount;
}

// ****************************************************************************
// Purpose: see if the linked lists contains the value provided in the parameter
// Pre: someData - name of the data value to look for
// Return: returns true if found, false if not.
// ****************************************************************************
template <class T>
bool List<T>::contains(T& someData) const
{
	return (findAnywhere(someData) != nullptr);
}
// ****************************************************************************
// Purpose: Receives target dataVal to search list for. If found, return true.
// Pre: target - dataVal to search list for
// Return: If found, a pointer to node containing the target data. If not,
// returns nullptr.
// ****************************************************************************
template <class T>
Node<T>* List<T>::findAnywhere(T& target) const
{
	bool found = false;
	Node<T>* curPtr = headPtr;
	Node<T>* tarPtr = new Node<T>(target);

	while (!found && (curPtr != nullptr))
	{
		if (tarPtr->getDataVal() == curPtr->getDataVal())
		{
			found = true;
		}
		else
		{
			curPtr = curPtr->getNext();
		}
	}

	if (found == false)
	{
		curPtr = nullptr;
	}

	return curPtr;
}
// ****************************************************************************
// Purpose: Receives position and entry for insert at given position in list.
// Pre: newPosition - List position where newEntry is inserted.
//      newEntry - The entry being inserted into list.
// Return: True if insertion is successful, false if not.
// ****************************************************************************
template <class T>
bool List<T>::insertAnywhere(int newPosition, const T &newEntry)
{
	bool successfulInsert = false;

	Node<T>* prevNode;             // Traversal, link previous Node to new Node
	Node<T>* currNode = headPtr;   // Traversal, to find position of new Node
	Node<T>* newNode = new Node <T>(newEntry);

	// If empty list or insert position is 0, add as head of list
	if (isEmpty() || newPosition == 0)
	{

		if (isEmpty())
		{
			headPtr = newNode;
			tailPtr = newNode;
			newNode->setNext(nullptr);
		}
		else
		{
			newNode->setNext(headPtr);
			headPtr = newNode;
		}
		nodeCount++;
		successfulInsert = true;
	}
	// Add to end. If insert position greater than nodeCount, also add to end
	else if (newPosition >= nodeCount)
	{
		tailPtr->setNext(newNode);
		newNode->setNext(nullptr);
		tailPtr = newNode;
		nodeCount++;
		successfulInsert = true;
	}
	// Any other position that is not front or end
	else
	{
		int tempPosition = 0;   // Traversal position

								// Traverse list until next is nullptr, or desired position
		prevNode = currNode;
		while (currNode->getNext() && tempPosition != newPosition)
		{
			prevNode = currNode;
			currNode = currNode->getNext();
			tempPosition++;
		}

		prevNode->setNext(newNode);

		// If currNode is not last node, link to currNode
		if (currNode->getNext())
		{
			newNode->setNext(currNode);
		}
		// If currNode is last node, link to nullptr
		else
		{
			newNode->setNext(nullptr);
		}
		nodeCount++;
		successfulInsert = true;
	}

	return successfulInsert;
}

// ****************************************************************************
// Purpose: Receives entry for insert at front of list.
// Pre: newEntry - The entry being inserted into list.
// Return: True if insertion is successful, false if not.
// ****************************************************************************
template <class T>
bool List<T>::insertFront(const T &newEntry)
{
	return insertAnywhere(0, newEntry);
}

// ****************************************************************************
// Purpose: Receives entry for insert at end of list.
// Pre: newEntry - The entry being inserted into list.
// Return: True if insertion is successful, false if not.
// ****************************************************************************
template <class T>
bool List<T>::insertEnd(const T &newEntry)
{
	return insertAnywhere(nodeCount, newEntry);
}

// ****************************************************************************
// Purpose: Receives entry for insert, inserts in list in sorted position.
// Pre: newEntry - The entry being inserted into list.
// Return: True if insertion is successful, false if not.
// ****************************************************************************
template <class T>
bool List<T>::insertInOrder(const T &newEntry)
{
	bool successfulInsert = false;

	Node<T>* prevNode;             // Traversal, link previous Node to new Node
	Node<T>* currNode = headPtr;   // Traversal, to find position of new Node
	Node<T>* newNode = new Node<T>(newEntry);

	// If empty list or newEntry is smaller than obj in position 0, 
	// add as head of list
	if (isEmpty() || newNode->getDataVal() < getEntry(0))
	{
		//cout << "\nif being used\n";

		if (isEmpty())
		{
			headPtr = newNode;
			tailPtr = newNode;
			newNode->setNext(nullptr);
		}
		else
		{
			newNode->setNext(headPtr);
			headPtr = newNode;
		}
		nodeCount++;
		successfulInsert = true;
	}
	// Any other position that is not front
	else
	{
		int position = 0;   // Traversal position

							// Traverse list until next is nullptr, or correct position
		prevNode = currNode;
		while (currNode->getNext() && newNode->getDataVal() > getEntry(position))
		{
			prevNode = currNode;
			currNode = currNode->getNext();
			position++;
		}

		// If newNode is not larger than all nodes in list,
		// link from prevNode to currNode
		if (newNode->getDataVal() < getEntry(position))
		{
			prevNode->setNext(newNode);
			newNode->setNext(currNode);
		}
		// If newNode is now largest in list, link to nullptr
		else
		{
			currNode->setNext(newNode);
			newNode->setNext(nullptr);
			tailPtr = newNode;
		}
		nodeCount++;
		successfulInsert = true;
	}

	return successfulInsert;
}

// ****************************************************************************
// Purpose: traverse the list looking for the data value provided, if found
// remove node, relink list, and adjust counter.
// Pre: someData - name of the data value to look for and remove
// Return: returns true if remove successful, false if not.
// ****************************************************************************
template <class T>
bool List<T>::removeAnywhere(T& someData)
{
	bool canRemoveItem = !isEmpty() && findAnywhere(someData);

	if (canRemoveItem)
	{
		Node<T>* nodePtr = headPtr;
		Node<T>* prevNode;

		// If head
		if (headPtr->getDataVal() == someData)
		{
			headPtr = headPtr->getNext();
			delete nodePtr;

			// If only item in list
			if (nodeCount == 1)
			{
				tailPtr = nullptr;
			}
		}
		// Anywhere else
		else
		{
			prevNode = nodePtr;

			while (nodePtr->getDataVal() != someData)
			{
				prevNode = nodePtr;
				nodePtr = nodePtr->getNext();
			}

			prevNode->setNext(nodePtr->getNext());
			// removing last node if nodePtr's next is nullptr, set tailPtr
			if (nodePtr->getNext() == nullptr)
			{
				tailPtr = prevNode;
			}
			delete nodePtr;
		}
		nodeCount--;
	}
	return canRemoveItem;
}

// ****************************************************************************
// Purpose: Removes entry at a given position from the list.
// Pre: position - position in list whose entry should be removed.
// Return: True if removal is successful, false if not.
// ****************************************************************************
template <class T>
bool List<T>::removePosition(int position)
{
	bool successfulRemoval = false;
	Node<T>* currNode;   // To traverse the list
	Node<T>* prevNode;   // Travesal, to reconnect nodes

						 // Cannot delete if list is empty
	if (isEmpty())
	{
		cout << "\nEmpty list, no node to remove." << endl;
		return successfulRemoval;
	}

	// Deletes first node in list
	if (position == 0)
	{
		Node<T>* nodeToDeletePtr = headPtr;
		headPtr = nodeToDeletePtr->getNext();

		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;

		nodeToDeletePtr = nullptr;
		nodeCount--;

		// If only item in list
		if (nodeCount == 0)
		{
			tailPtr = nullptr;
		}

		successfulRemoval = true;
	}
	// Traverse list until reaching position to delete
	else
	{
		int tempPosition = 0;
		currNode = headPtr;
		prevNode = currNode;

		while (currNode->getNext() && tempPosition != position)
		{
			currNode = currNode->getNext();
			tempPosition++;
		}

		prevNode->setNext(currNode->getNext());

		// removing last node if currNode's next is nullptr, set tailPtr
		if (currNode->getNext() == nullptr)
		{
			tailPtr = prevNode;
		}

		currNode->setNext(nullptr);
		delete currNode;

		nodeCount--;
		successfulRemoval = true;
	}

	return successfulRemoval;
}

// ****************************************************************************
// Purpose: Remove node at front of list.
// Return: True if removal is successful, false if not.
// ****************************************************************************
template <class T>
bool List<T>::removeFront()
{
	return removePosition(0);
}

// ****************************************************************************
// Purpose: Remove node at end of list.
// Return: True if removal is successful, false if not.
// ****************************************************************************
template <class T>
bool List<T>::removeEnd()
{
	return removePosition(nodeCount - 1);
}

// ****************************************************************************
// Purpose: Removes all entries in the list, adjusting nodeCount to 0.
// ****************************************************************************
template <class T>
bool List<T>::emptyList()
{
	bool listEmptied = false;
	Node<T>* nodePtr;   // To traverse the list
	Node<T>* nextNode;  // To point to the next node

	nodePtr = headPtr;  // Position nodePtr at the head of the list

	if (isEmpty())
	{
		return listEmptied;
	}
	else
	{
		// Until reaching end of list
		while (nodePtr != nullptr)
		{
			nextNode = nodePtr->getNext();
			delete nodePtr;
			nodeCount--;
			nodePtr = nextNode;
		}
		listEmptied = true;
		headPtr = nullptr;
		tailPtr = nullptr;
	}

	return listEmptied;
}

// ****************************************************************************
// Purpose: Receives position and returns entry at given position in list.
// Pre: position - position in list whose entry should be returned.
// Return: Entry at given position.
// ****************************************************************************
template <class T>
T List<T>::getEntry(int position) const
{
	Node<T>* currNode = headPtr;    // Traversal, to find position of new Node

	int tempPosition = 0;

	if (isEmpty())
	{
		cout << "\nEmpty, no data to retrieve." << endl;
	}
	// Check position exists, if not then use last node
	else if (position > nodeCount)
	{
		cout << "\nPosition exceeds number of nodes, last position instead\n";
		position = nodeCount;
	}

	while (tempPosition < position)
	{
		currNode = currNode->getNext();
		tempPosition++;
	}

	return currNode->getDataVal();
}

// ****************************************************************************
// Purpose: Receives dataVal to look for and new entry for replacing it.
// Pre: existingData - existing entry to check for.
//      someData - The replacement entry for the position in list.
// ****************************************************************************
template <class T>
bool List<T>::setEntry(const T& existingData, const T& someData)
{
	bool found = false;
	Node<T>* curPtr = headPtr;

	while (!found && (curPtr != nullptr))
	{
		if (existingData == curPtr->getDataVal())
		{
			curPtr->setDataVal(someData);
			found = true;
		}
		else
		{
			curPtr = curPtr->getNext();
		}
	}

	return found;
}
#endif

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>
#include "array.h"
#include "list.h"
#include "Item.h"
#include "Miscellaneous.h"
#include "Outerwear.h"
#include "Pants.h"
#include "Shirt.h"
#include "Shoes.h"
#include "Socks.h"

using namespace std;

template <class T1, class T2 >
class HashTable {
private:
	int arraySize;
	int collisionTotal;
	int numItemsLoaded;
	int numTableLoaded;
	int longestLinkSize;
	Array<T1*>* dataEntries;

	void updateLinkStats();

public:
	// Constructor
	HashTable(int size, string filePath);

	// Destructor
	~HashTable();

	// Accessors
	int getSize() const { return arraySize; }
	int getCollisionTotal() const { return collisionTotal; }
	double getLoadFactor() const { return numTableLoaded / (double)arraySize; }
	int getNumItemsLoaded() const { return numItemsLoaded; }
	int getLongestLink() const { return longestLinkSize; }
	double getAvgLink() const { return numItemsLoaded / (double)numTableLoaded; }
	Array<T1*>* getDataEntries() const { return dataEntries; }

	// HashTable behaviors
	int hashFunction(T2 hashKey);
	void insert(Item* obj, T2 hashKey);
	bool remove(T2 hashKey);
	Item* retrieveEntry(T2 hashKey);
	void printTableStats();
	void displayTable();

};

// ****************************************************************************
// Purpose: Default constructor for HashTable. Parses file to determine number
// of data items to store, and dynamically creates appropriately sized Array.
// Then stores items in created Array.
// Pre : size - the size of the array to create
//       filePath - the filePath where to open the file to read into the array.
// Post: HashTable with dynamically created Array to store data items.
// ****************************************************************************
template<class T1, class T2>
HashTable<T1, T2>::HashTable(int size, string filePath)
{
	//Item* temp = new Item();
	collisionTotal = 0;
	numItemsLoaded = 0;
	longestLinkSize = 0;
	arraySize = size;

	dataEntries = new Array<T1*>(arraySize);

	// Create List for each element in array
	for (int i = 0; i < arraySize; i++)
	{
		dataEntries->getArray()[i] = new List<Item*>();
	}
}

// ****************************************************************************
// Purpose: Destroy the hashtable array
// ****************************************************************************
template <class T1, class T2>
HashTable<T1, T2>::~HashTable()
{
	// iterate through each element to delete all Item pointers
	for (int i = 0; i < arraySize; i++)
	{
		if (!(dataEntries->getArray()[i]->isEmpty()))
		{
			dataEntries->getArray()[i]->emptyList();
		}
	}
	delete dataEntries;
}

// ****************************************************************************
// Purpose: uses midsquare for hashing function to produce an index for 
// position in HashTable.
// Pre : hashKey - key used in hashing to produce index for insertion
// Post: Return available index for insertion.
// ****************************************************************************
template <class T1, class T2>
void HashTable<T1, T2>::updateLinkStats()
{
	int longestLinkRecount = 0;
	numTableLoaded = 0;

	for (int i = 0; i < arraySize; i++)
	{
		// count non-zero sized link lists, incrementing table elements loaded
		if (dataEntries->getArray()[i]->getLength() != 0)
		{
			numTableLoaded++;

			// gets number of largest link
			if (dataEntries->getArray()[i]->getLength() > longestLinkRecount)
			{
				longestLinkRecount = dataEntries->getArray()[i]->getLength();
			}
		}
	}

	longestLinkSize = longestLinkRecount;
}

// ****************************************************************************
// Purpose: uses midsquare for hashing function to produce an index for 
// position in HashTable.
// Pre : hashKey - key used in hashing to produce index for insertion
// Post: Return available index for insertion.
// ****************************************************************************
template <class T1, class T2>
int HashTable<T1, T2>::hashFunction(T2 hashKey)
{
	int index = 0;
	int digitPlace1 = 0;
	int digitPlace2 = 0;
	string hashSquaredStr = ""; // string version of hashKey squared
	string tempIndexStr = "";   // string version of index for string functions

								// use midSquare for new hashfunction
	index = stoi(hashKey);
	index = index * index;
	hashSquaredStr = to_string(index);

	// if hashSquaredStr contains even number of digits, take middle 2 digits
	if (hashSquaredStr.size() % 2 == 0)
	{
		digitPlace2 = hashSquaredStr.size() / 2;
		digitPlace1 = digitPlace2 - 1; // get number to left of digitPlace1

		tempIndexStr = hashSquaredStr[digitPlace1];
		tempIndexStr += hashSquaredStr[digitPlace2];

		index = stoi(tempIndexStr);

	}
	// if hashSquaredStr contains odd number of digits, take middle digit
	else
	{
		digitPlace1 = hashSquaredStr.size() / 2;
		tempIndexStr = hashSquaredStr[digitPlace1];
		index = stoi(tempIndexStr);
	}

	// if index exceeds size of array, wrap around
	if (index >= arraySize)
	{
		index %= arraySize;
	}

	return index;
}

// ****************************************************************************
// Purpose: insert obj into HashTable
// Pre : obj -  data to be added into HashTable
//       hashKey - key used in hashing to produce index for insertion
// Post: obj inserted into HashTable
// ****************************************************************************
template <class T1, class T2>
void HashTable<T1, T2>::insert(Item* obj, T2 hashKey)
{
	int index = hashFunction(hashKey);

	// increments collision total if entries already existed at index
	if (dataEntries->getArray()[index]->getLength() != 0)
	{
		collisionTotal++;
	}

	// Loads obj at designated index and increments number of items loaded
	if (dataEntries->getArray()[index]->insertInOrder(obj))
	{
		// update longestLinkSize if this insert creates new longest link
		numItemsLoaded++;
		updateLinkStats();
		printTableStats();
	}

}

// ****************************************************************************
// Purpose: remove first object that matches hashKey from HashTable
// Pre : hashKey - key used in hashing to find object to be removed
// Post: Return true if obj removed from HashTable, otherwise no object in
// HashTable shares a matching key and returns false.
// ****************************************************************************
template <class T1, class T2>
bool HashTable<T1, T2>::remove(T2 hashKey)
{
	int index = hashFunction(hashKey);
	int i = 0;
	bool itemFound = false;
	bool successfulRemove = false;

	// Loops until finds matching hashKey or end of list
	while (i < dataEntries->getArray()[index]->getLength() && itemFound == false)
	{

		if (hashKey == dataEntries->getArray()[index]->getEntry(i)->getBarcode())
		{
			cout << "\nREMOVING: ";
			cout << *(dataEntries->getArray()[index]->getEntry(i));
			dataEntries->getArray()[index]->removePosition(i);
			numItemsLoaded--;
			itemFound = true;
			successfulRemove = true;
			updateLinkStats();
		}
		i++;
	}

	if (successfulRemove == false)
	{
		cout << "\nNo matching key. Could not delete.\n";
	}

	return successfulRemove;
}

// ****************************************************************************
// Purpose: retrieve object from HashTable
// Pre : hashKey - key used in hashing to find data with matching hashKey.
// Post: Return obj with matching hashKey, otherwise no obj with matching
// haskKey exists and returns false.
// ****************************************************************************
template <class T1, class T2>
Item* HashTable<T1, T2>::retrieveEntry(T2 hashKey)
{
	int index = hashFunction(hashKey);
	int i = 0;
	bool itemFound = false;

	// Loops until finds matching hashKey or end of list
	while (i < dataEntries->getArray()[index]->getLength() && itemFound == false)
	{
		if (hashKey == dataEntries->getArray()[index]->getEntry(i)->getBarcode())
		{
			itemFound = true;
			return dataEntries->getArray()[index]->getEntry(i);
		}
		i++;
	}

	return nullptr;
}

// ****************************************************************************
// Purpose: Prints statistics relevant to hash table.
// Post: Displayed info about # elements loaded, load factor, # collisions,
// longest linked list, and average linked list size. 
// ****************************************************************************
template <class T1, class T2>
void HashTable<T1, T2>::printTableStats()
{
	cout << "\nNumber of data elements loaded: " << getNumItemsLoaded();
	cout << endl;
	cout << "Load factor: " << setprecision(2) << fixed << getLoadFactor();
	cout << endl;
	cout << "Total number of collisions: " << getCollisionTotal();
	cout << endl;
	cout << "Longest Linked List: " << getLongestLink();
	cout << endl;
	cout << "Average number of nodes in Linked List: " << getAvgLink();
	cout << endl;
}

// ****************************************************************************
// Purpose: List data in hash table sequence.
// Post: All data in hash table will be displayed
// ****************************************************************************
template <class T1, class T2>
void HashTable<T1, T2>::displayTable()
{
	// iterate through each element to display all Item data info
	for (int i = 0; i < arraySize; i++)
	{
		if (!(dataEntries->getArray()[i]->isEmpty()))
		{
			for (int j = 0; j < dataEntries->getArray()[i]->getLength(); j++)
			{
 				cout << "\nData of item " << (j+1);
				cout << " inside index " << i << " of table : ";
				cout << *(dataEntries->getArray()[i]->getEntry(j));
				cout << endl;
				cout << "*******************************" << endl;
			}
		}
		else
		{
			cout << "\nIndex " << i << " in table is empty.";
			cout << endl;
		}
	}
}

#endif

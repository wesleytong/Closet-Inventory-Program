/* CIS 22c
*
* Terry Tzeng, Brian Lim
* Partner contribution: 0 - equal work
*
* Lab 4: template Array class that can accept any type of numeric, character,
*      or string data. Array should be dynamically created based on size (max
*      size of 32) entered by the user. Contains recursive Insertion, Merge,
*      and Quick sort algorithms that sorts and prints data provided by the
*      user, as well as storing sorted data's steps into a file.
*
* Date: 5/26/18
*
*/
// ****************************************************************************
// array.h, header file
// Class declaration of Array using templates
// ****************************************************************************
#ifndef ARRAY_H
#define ARRAY_H

#include <string>
#include <iostream>
#include <cstddef>

using namespace std;

template <class T>
class Array {
private:
	T * arr;
	int size;
	string dataType;

	T getData(T &);

public:
	// Constructors
	Array(int);
	Array(int, string);
	Array(const Array<T> &);

	// Destructor
	~Array();


	// Accessors
	int getSize() const { return size; }
	T* getArray() const { return arr; }    // Returns address
	string getDataType() const { return dataType; }

	// Print arr
	void printArray() const;
};

// ****************************************************************************
// Purpose: Constructor for Array. Takes an int to dynamically create an array
// based on size from user.
// Pre: size - int array size determined by user, used in dynamic creation
// Post: Dynamically created array based on user size
// ****************************************************************************
template <class T>
Array<T>::Array(int userSize)
{
	size = userSize;
	dataType = "";
	arr = new T[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = nullptr;
	}
}

// ****************************************************************************
// Purpose: Constructor for Array. Takes an int to dynamically create an array
// based on size from user. Populates array based on user input.
// Pre: size - int array size determined by user, used in dynamic creation
// Post: Dynamically created array based on user size, with each element
//       set by input from user.
// ****************************************************************************
template <class T>
Array<T>::Array(int userSize, string userType)
{
	arr = nullptr;
	size = userSize;
	dataType = userType;
	T userData;

	arr = new T[size];

	for (int i = 0; i < size; i++)
	{
		cout << "\nPlease enter data of position " << i + 1 << ": ";
		arr[i] = getData(userData);
	}
}

// ****************************************************************************
// Purpose: Copy Constructor for Array. Takes an existing array of any type
// and creates an identical array in size and data.
// Pre: orginalArray - reference Array object whose data is copied
// Post: a newly created Array object with identical values to originalArray
// ****************************************************************************
template <class T>
Array<T>::Array(const Array<T> &originalArray)
{
	size = originalArray.size;
	dataType = originalArray.dataType;
	arr = new T[size];

	for (int i = 0; i < size; i++)
	{
		*(arr + i) = *(originalArray.arr + i);
	}
}

// ****************************************************************************
// Purpose: Destructor for Array
// Post: deletes all allocated memory for Array
// ****************************************************************************
template <class T>
Array<T>::~Array()
{
	delete[]arr;     // free memory pointed to by arr
	arr = nullptr;    // clear arr to prevent using invalid memory reference
}

// ****************************************************************************
// Purpose: Print Array object's arr contents separated by spaces.
// Pre : an initialized Array object
// Post: all elements of Array's arr will be printed separated by spaces
// ****************************************************************************
template <class T>
void Array<T>::printArray() const
{
	cout << endl;

	cout << *(arr);

	for (int i = 1; i < size; i++)
	{
		cout << ", " << *(arr + i);
	}

	cout << endl;
}

// ****************************************************************************
// Purpose: get user input
// Pre : t - a template object to read in
// Post: returns the templated data type
// ****************************************************************************
template <class T>
T Array<T>::getData(T& t) {
	T temp;
	cin >> temp;
	return  temp;
}

// ****************************************************************************
// Purpose: get user input (specialized for strings)
// Pre : t - a string to read in
// Post: returns the string data type
// ****************************************************************************
template <>
string Array<string>::getData(string& t) {
	string temp;
	getline(cin, temp);
	return temp;
}


#endif

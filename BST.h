#pragma once
#include "Node.h"
#include "Item.h"
#include "BSTNode.h"
#include "Queue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;


template <class T>
class BST {
private:
	//BST
	BSTNode<T>* root;
	int BSTOpCounter;
	int AVLOpCounter;
	BSTNode<T>* _insert(BSTNode<T> *nodePtr, BSTNode<T> *newNode);
	BSTNode<T>* _search(BSTNode<T>*, string, bool);
	BSTNode<T>* _remove(BSTNode<T>* nodePtr, string target, bool);
	BSTNode<T>* removeLeft(BSTNode<T>* nodePtr, T &first);
	BSTNode<T>* deleteNode(BSTNode<T>* nodePtr);
	void _inorder(BSTNode<T>*);
	void _postorder(BSTNode<T>*);
	void _preorder(BSTNode<T>*);
	void _breadthfirst(BSTNode<T>*);
	void _printIndentedTree(BSTNode<T> *root, int spacing);

	ofstream output;

	//AVL
	void empty(BSTNode<T>*t);
	BSTNode<T> *insert(T x, BSTNode<T> *t);
	BSTNode<T> *singleRightRotate(BSTNode<T>* &t);
	BSTNode<T> *singleLeftRotate(BSTNode<T>* &t);
	BSTNode<T> *doubleRightRotate(BSTNode<T>* &t);
	BSTNode<T> *doubleLeftRotate(BSTNode<T>* &t);
	BSTNode<T> *findMin(BSTNode<T> *t);
	BSTNode<T> *findMax(BSTNode<T> *t);
	BSTNode<T> *remove(T x, BSTNode<T> *t);
	int height(BSTNode<T> *t);
	int getBalance(BSTNode<T> *t);
	void inOrder(BSTNode<T> *t);


public:
	//BST
	BST();
	bool search(string);
	bool insert(const T&);
	bool remove(string);
	BSTNode<T>* getNode(string);
	void inorder();
	void postorder();
	void preorder();
	void breadthfirst();

	//Indented Tree
	void printIndentedTree(int spacing);

	//Efficiency Info
	void printAVLOperationInfo();
	void printBSTOperationInfo();


	//added for AVL Tree
	void avlinsert(T x);
	void avlremove(T x);
	void display()
	{
		inOrder(root);
		cout << endl;
	}

	
};
	
template<class T>
void BST<T>::avlinsert(T x)
{
	root = insert(x, root);
}

template<class T>
void BST<T>::avlremove(T x)
{
	root = remove(x, root);
}

template <class T>
void BST<T>::empty(BSTNode<T>*t)
{
	if (t == NULL)
		return;
	empty(t->left);
	empty(t->right);
	delete t;

}

template<class T>
BSTNode<T>* BST<T>::insert(T x, BSTNode<T> *t)
{
	if (t == NULL)
	{
		t = new BSTNode<T>;
		t->data = x;
		t->height = 0;
		t->left = t->right = NULL;
	}
	else if (x.getBarcode() < t->getData().getBarcode())
	{
		t->left = insert(x, t->left);
		if (height(t->left) - height(t->right) == 2)
		{
			if (x.getBarcode() < t->left->getData().getBarcode())
				t = singleRightRotate(t);
			else
				t = doubleRightRotate(t);
		}
	}
	else if (x.getBarcode() > t->getData().getBarcode())
	{
		t->right = insert(x, t->right);
		if (height(t->right) - height(t->left) == 2)
		{
			if (x.getBarcode() > t->right->getData().getBarcode())
				t = singleLeftRotate(t);
			else
				t = doubleLeftRotate(t);
		}
	}

	t->height = max(height(t->left), height(t->right)) + 1;
	AVLOpCounter++;
	return t;
}

template<class T>
BSTNode<T>* BST<T>::singleRightRotate(BSTNode<T>* &t)
{
	BSTNode<T>* u = t->left;
	t->left = u->right;
	u->right = t;
	t->height = max(height(t->left), height(t->right)) + 1;
	u->height = max(height(u->left), t->height) + 1;
	return u;
}

template<class T>
BSTNode<T>* BST<T>::singleLeftRotate(BSTNode<T>* &t)
{
	BSTNode<T>* u = t->right;
	t->right = u->left;
	u->left = t;
	t->height = max(height(t->left), height(t->right)) + 1;
	u->height = max(height(t->right), t->height) + 1;
	return u;
}

template<class T>
BSTNode<T>* BST<T>::doubleLeftRotate(BSTNode<T>* &t)
{
	t->right = singleRightRotate(t->right);
	return singleLeftRotate(t);
}

template<class T>
BSTNode<T>* BST<T>::doubleRightRotate(BSTNode<T>* &t)
{
	t->left = singleLeftRotate(t->left);
	return singleRightRotate(t);
}

template<class T>
BSTNode<T>* BST<T>::findMin(BSTNode<T> *t)
{
	if (t == NULL)
		return NULL;
	else if (t->left == NULL)
		return t;
	else
		return findMin(t->left);
}

template<class T>
BSTNode<T>* BST<T>::findMax(BSTNode<T> *t)
{
	if (t == NULL)
		return NULL;
	else if (t->right == NULL)
		return t;
	else
		return findMax(t->right);
}

template<class T>
BSTNode<T>* BST<T>::remove(T x, BSTNode<T> *t)
{
	BSTNode<T> *temp;
	if (t == NULL)
		return NULL;
	else if (x < t->data)
		t->left = remove(x, t->left);
	else if (x > t->data)
		t->right = remove(x, t->right);

	// Element found
	// With 2 children
	else if (t->left && t->right)
	{
		temp = findMin(t->right);
		t->data = temp->data;
		t->right = remove(t->data, t->right);
	}
	// With one or zero child
	else
	{
		temp = t;
		if (t->left == NULL)
			t = t->right;
		else if (t->right == NULL)
			t = t->left;
		delete temp;
	}
	if (t == NULL)
		return t;

	t->height = max(height(t->left), height(t->right)) + 1;

	// If node is unbalanced
	// If left node is deleted, right case
	if (height(t->left) - height(t->right) == 2)
	{
		// right right case
		if (height(t->left->left) - height(t->left->right) == 1)
			return singleLeftRotate(t);
		// right left case
		else
			return doubleLeftRotate(t);
	}

	// If right node is deleted, left case
	else if (height(t->right) - height(t->left) == 2)
	{
		// left left case
		if (height(t->right->right) - height(t->right->left) == 1)
			return singleRightRotate(t);
		// left right case
		else
			return doubleRightRotate(t);
	}
	return t;
}
template<class T>
int BST<T>::height(BSTNode<T> *t)
{
	return (t == NULL ? -1 : t->height);
}
template<class T>
int BST<T>::getBalance(BSTNode<T> *t)
{
	if (t == NULL)
		return 0;
	else
		return height(t->left) - height(t->right);
}

template<class T>
void BST<T>::inOrder(BSTNode<T>*t)
{
	if (t == NULL)
		return;
	inOrder(t->left);
	cout << t->getData().getBarcode() << " ";
	inOrder(t->right);
}

string outfilename;

template <class T>
BST<T>::BST() {
	root = NULL;
	BSTOpCounter = 0;
	AVLOpCounter = 0;
}

template <class T>
BSTNode<T>* BST<T>::getNode(string target) {
	BSTNode<T> *nodePtr;
	bool searched = true;
	nodePtr = _search(root, target, searched);
	return nodePtr;
}

template <class T>
BSTNode<T>* BST<T>::_search(BSTNode<T> *nodePtr, string target, bool searched) {
	//null if root is null
	if (nodePtr == NULL) {
		return NULL;
		searched = false;
	}
	//is data in node is bigger than target
	if (nodePtr->getData().getBarcode() > target) {
		nodePtr = _search(nodePtr->getLeft(), target, searched);
		searched = true;
	}
	//if data in node is less than target
	else if (nodePtr->getData().getBarcode() < target) {
		nodePtr = _search(nodePtr->getRight(), target, searched);
		searched = true;
	}
	//else return node
	else {
		//checks to see if the search is found or not
		searched = true;
		return nodePtr;
	}
	return nodePtr;
}

//inserts data into BST
template <class T>
BSTNode<T>* BST<T>::_insert(BSTNode<T> *nodePtr, BSTNode<T> *newNode) {
	if (nodePtr == nullptr) {
		BSTOpCounter++;
		return newNode;
	}
	//if data less thran new node data
	if (nodePtr->getData().getBarcode() < newNode->getData().getBarcode()) {
		nodePtr->setRight(_insert(nodePtr->getRight(), newNode));
	}
	else {
		nodePtr->setLeft(_insert(nodePtr->getLeft(), newNode));
	}
	BSTOpCounter++;
	return nodePtr;

}

//private remove functions 
template <class T>
BSTNode<T>* BST<T>::_remove(BSTNode<T>* nodePtr, string target, bool removed) {
	//if node pointer is null return null and falsify whether it is there or not
	if (nodePtr == NULL) {
		removed = false;
		return NULL;
	}
	//if nodeptr data greater than target
	if (nodePtr->getData().getBarcode() > target) {
		//recursively remove
		nodePtr->setLeft(_remove(nodePtr->getLeft(), target, removed));
	}
	//if nodeptr data less tahn target
	else if (nodePtr->getData().getBarcode() < target) {
		nodePtr->setRight(_remove(nodePtr->getRight(), target, removed));
	}
	else {
		//otherwise deletes node
		nodePtr = deleteNode(nodePtr);
		removed = true;
	}
	return nodePtr;
}

//function to delete node to help with remove funciton
template <class T>
BSTNode<T>* BST<T>::deleteNode(BSTNode<T>* nodePtr) {
	//if node is a leaf delete the node
	if (nodePtr->getRight() == NULL && nodePtr->getLeft() == NULL) {
		delete nodePtr;
		return NULL;
	}
	//else if the left node has no value
	else if (nodePtr->getLeft() == 0) {
		BSTNode<T>* newNode = nodePtr->getRight();
		delete nodePtr;
		return newNode;
	}
	//else if the right node has no valye 
	else if (nodePtr->getRight() == 0) {
		BSTNode<T>* newNode = nodePtr->getLeft();
		delete nodePtr;
		return newNode;
	}
	//else set right to what was remove from left
	else {
		T value;
		nodePtr->setRight(removeLeft(nodePtr->getRight(), value));
		nodePtr->setData(value);
		return nodePtr;
	}
}

//helper function to remove values from the left side
template <class T>
BSTNode<T>* BST<T>::removeLeft(BSTNode<T>* nodePtr, T &first) {
	if (nodePtr->getLeft() == 0) {
		first = nodePtr->getData();
		return deleteNode(nodePtr);
	}
	else {
		nodePtr->setLeft(removeLeft(nodePtr->getLeft(), first));
		return nodePtr;
	}
}

template <class T>
//public search function
bool BST<T>::search(string data1) {
	bool searched = true;
	searched = _search(root, data1, searched);
	return searched;
}

template <class T>
//public insert function 
bool BST<T>::insert(const T & data1) {
	//new node to insert
	BSTNode<T> * newNode = new BSTNode<T>(data1);
	root = _insert(root, newNode);
	return true;
}

template <class T>
//public remove funciton so only in is the value to be removed
bool BST<T>::remove(string value) {
	bool removed = false;
	this->root = _remove(this->root, value, removed);
	return removed;
}

string outFilename;

template <class T>
void BST<T>::inorder() {
	_inorder(root);
}

template <class T>
void BST<T>::_inorder(BSTNode<T>* nodePtr) {
	if (nodePtr != nullptr) {
		_inorder(nodePtr->getLeft());
		cout << nodePtr->getData().getBarcode() << " " << endl;
		_inorder(nodePtr->getRight());
	}
}

template <class T>
void BST<T>::postorder() {
	_postorder(root);
}

template <class T>
//private postorder
void BST<T>::_postorder(BSTNode<T>* nodePtr) {
	if (nodePtr != nullptr) {
		//left right then root
		_postorder(nodePtr->getLeft(), 1);
		_postorder(nodePtr->getRight(), 1);
		cout << nodePtr->getData() << " " << endl;
		output.open(outFilename);
		output << root->getData();
		output.close();
	}
}

//public preorder
template <class T>
void BST<T>::preorder() {
	_preorder(root);
}

//privtare preorder
template <class T>
void BST<T>::_preorder(BSTNode<T>* nodePtr) {
	if (nodePtr != nullptr) {
		//root then left then right
		cout << nodePtr->getData() << " " << endl;
		output.open(outFilename);
		output << nodePtr->getData() << " " << endl;
		output.close();
		_preorder(nodePtr->getLeft(), 1);
		_preorder(nodePtr->getRight(), 1);
	}
}

//breadth first
template <class T>
void BST<T>::breadthfirst() {
	_breadthfirst(root);
}

//https://stackoverflow.com/questions/17939247/breadth-first-traversal-with-binary-search-tree-c
template <class T>
void BST<T>::_breadthfirst(BSTNode<T>* nodePtr) {
	Queue<BSTNode<T>*> queue;
	cout << "What is your outfile name? answer like this: outfile.txt" << endl;
	cin >> outFilename;
	if (nodePtr != NULL) {
		queue.enqueue(nodePtr);
	}
	else {
		cout << "NULL" << endl;
		output.open(outFilename);
		output << "NULL" << endl;
		output.close();
		//output << "NULL" << endl;
	}
	//temp node while queue is not empty
	while (!queue.isEmpty()) {
		BSTNode<T> * tempNode = queue.front();
		queue.dequeue();
		//enqueue is left node is not tempty
		if (tempNode->getLeft() != NULL)
			queue.enqueue(tempNode->getLeft());
		//enqueue if right is not empty
		if (tempNode->getRight() != NULL)
			queue.enqueue(tempNode->getRight());
		output.open(outFilename);
		output << tempNode->getData() << endl;
		cout << tempNode->getData() << endl;
		output.close();
	}
}

template <class T>
void BST<T>::_printIndentedTree(BSTNode<T> *root, int spacing) {
	int count = 10;
	// Base case
	if (root == NULL)
		return;

	// Increase distance between levels
	spacing += count;

	// Process right child first
	_printIndentedTree(root->right, spacing);

	// Print current node after spacing
	// count
	cout << endl;
	for (int i = count; i < spacing; i++)
		cout << " ";
	cout << (root->getData().getBarcode()) << endl;

	// Process left child
	_printIndentedTree(root->left, spacing);

	// To print in main:
	// printIndentedTree(root,0);
	// where root is the root node and 0 is the default spacing 
}

template <class T>
void BST<T>::printIndentedTree(int spacing) {
	_printIndentedTree(root, spacing);
}

template <class T>
void BST<T>::printAVLOperationInfo()
{
	cout << "\nTotal operation count for insertion into AVL tree: " << AVLOpCounter;
}

template <class T>
void BST<T>::printBSTOperationInfo()
{
	cout << "\nTotal operation count for insertion into BST: " << BSTOpCounter;
}
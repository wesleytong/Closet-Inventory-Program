#pragma once
#include "BSTNode.h"
template <class T>
class BSTNode {
public:
	T data;
	BSTNode<T> *left;
	BSTNode<T> *right;
	int height;
	BSTNode(const T&);
	BSTNode(const T&, BSTNode<T>*, BSTNode<T>*);
	void setData(const T&);
	void setLeft(BSTNode<T>* left1);
	void setRight(BSTNode<T>* right1);
	T getData() const;
	BSTNode<T>* getLeft() const;
	BSTNode<T>* getRight() const;
	BSTNode<T>() {};
};

//with just data contructor
template <class T>
BSTNode<T>::BSTNode(const T& data1) {
	data = data1;
	left = 0;
	right = 0;
}

//BSTNode constructor for left and right pointers
template <class T>
BSTNode<T>::BSTNode(const T& data1, BSTNode<T>* left1, BSTNode<T> *right1) {
	data = data1;
	left = left1;
	right = right1;
}

template <class T>
void BSTNode<T>::setData(const T& data1) {
	data = data1;
}

template <class T>
T BSTNode<T>::getData() const {
	return data;
}

template <class T>
void BSTNode<T>::setLeft(BSTNode<T>* left1) {
	left = left1;
}

template <class T>
BSTNode<T>* BSTNode<T>::getLeft() const {
	return left;
}

template <class T>
void BSTNode<T>::setRight(BSTNode<T>* right1) {
	right = right1;
}

template <class T>
BSTNode<T>* BSTNode<T>::getRight() const {
	return right;
}


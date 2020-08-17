#pragma once

#include "BinaryTree.h"
#include <assert.h>



template <class btElementType>
class BST : public BinaryTree<btElementType>
{
public:
	BST();
	virtual void insert(const btElementType& d);
	virtual BinaryTree<btElementType>* retrieve(const btElementType& d);

};

template < class btElementType >
BST < btElementType >
::BST() : BinaryTree < btElementType >()
{
}

template <class btElementType>
void
BST<btElementType>::insert(const btElementType& d)
{
	
	if (this->nullTree) {
		this->nullTree = false;
		this->leftTree = new BST;
		this->rightTree = new BST;
		this->treeData = d;
	}
	else if (d== this->treeData) {
		this->treeData = d;
	}
	else if (d < this->treeData) {
		this->leftTree->insert(d);
	}
	else
	{
		this->rightTree->insert(d);
	}
}

template <class btElementType>
BinaryTree<btElementType>*
BST<btElementType>::retrieve(const btElementType& d)
{
	if (this->nullTree || d == this->treeData)
		return this;
	else if (d < this->treeData)
		return ((BST <btElementType>*)this->leftTree)->retrieve(d);
	else
		return ((BST <btElementType>*)this->rightTree)->retrieve(d);
}


#pragma once

#include "BinaryTree.h"
#include <assert.h>



template <class btElementType>
class BST : public BinaryTree<btElementType>
{
public:
	BST();
	virtual void insert(const btElementType& d);
	virtual bool deleteNode(const btElementType& d);
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
bool
BST<btElementType>::deleteNode(const btElementType& d)
{
	bool searched = false;

	BST < btElementType >* currentNode;
	BST < btElementType >* parenetNode;

	currentNode = this;
	parenetNode = this;

	//삭제할 노드를 찾는 과정, 없을 시 false 반환

	while (!(currentNode->nullTree))
	{
		if (currentNode->treeData == d) {
			searched = true;
			break;
		}
		else if (d < currentNode->treeData) {
			parenetNode = currentNode;
			currentNode = (BST <btElementType>*)currentNode->leftTree;
		}
		else {
			parenetNode = currentNode;
			currentNode = (BST <btElementType>*)currentNode->rightTree;
		}
	}
	if (searched == false) {
		return false;
	}

	//case 1
	if (currentNode->leftTree == 0 && currentNode->rightTree == 0) { 
		if (d < parenetNode->treeData)
		{
			parenetNode->leftTree = 0;
		}
		else
		{
			parenetNode->rightTree = 0;
		}
		delete currentNode;
	}
	
	//case 2
	else if (currentNode->leftTree != 0 && currentNode->rightTree == 0) {
		if (d < parenetNode->treeData) {
			parenetNode->leftTree = currentNode->leftTree;
			delete currentNode;
		}
		else
		{
			parenetNode->rightTree = currentNode->leftTree;
			delete currentNode;
		}
	}
	else if (currentNode->leftTree == 0 && currentNode->rightTree != 0) {
		if (d < parenetNode->treeData) {
			parenetNode->leftTree = currentNode->rightTree;
			delete currentNode;
		}
		else
		{
			parenetNode->rightTree = currentNode->rightTree;
			delete currentNode;
		}
	}
	else if (currentNode->leftTree != 0 && currentNode->rightTree != 0) {
		BST < btElementType >* changeNode;
		BST < btElementType >* changeParentNode;
		if (d < parenetNode->treeData)
		{
			//3-1
			changeNode = (BST <btElementType>*)currentNode->rightTree;
			changeParentNode = (BST <btElementType>*)currentNode->rightTree;
			while (changeNode->leftTree!=0)
			{
				changeParentNode = changeNode;
				changeNode = (BST <btElementType>*)changeNode->leftTree;
			}
			if (changeNode->rightTree!=0)
			{
				changeParentNode->leftTree = changeNode->rightTree;
			}
			else
			{
				changeParentNode->leftTree = 0;
			}
			parenetNode->leftTree = changeNode;
			changeNode->rightTree = currentNode->rightTree;
			changeNode->leftTree = changeNode->leftTree;
			delete currentNode;
		}
		//3-2
		else
		{
			changeNode = (BST <btElementType>*)currentNode->rightTree;
			changeParentNode = (BST <btElementType>*)currentNode->rightTree;
			while (changeNode->leftTree!=0)
			{
				changeParentNode = changeNode;
				changeNode = (BST <btElementType>*)changeNode->leftTree;
			}
			if (changeNode->leftTree!=0)
			{
				changeParentNode->leftTree = changeNode->rightTree;
			}
			else
			{
				changeParentNode->leftTree = 0;
			}
			parenetNode->rightTree = changeNode;
			changeNode->rightTree = currentNode->rightTree;
			changeNode->leftTree = changeNode->leftTree;
			delete currentNode;
		}
	}

	//case 3
	return true;
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


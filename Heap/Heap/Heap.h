#pragma once
#include "BinaryTree.h"


template<class heapElementType>
class Heap : public BinaryTree<heapElementType>
{
public:
	Heap();
	virtual void insert(const heapElementType& data);
priaate:

};
template<class heapElementType>
Heap<heapElementType>::Heap()
{

}

template<class heapElementType>
void
Heap<heapElementType>::insert(const heapElementType& data)
{

}


#pragma once

#include <assert.h>
#include "LinkedList.h"


typedef int HashElementType;

class HashTable
{
public:
	HashTable();
	~HashTable();
	HashElementType hashFunc(const HashElementType& elem);


private:

};

HashTable::HashTable()
{

}

HashTable::~HashTable()
{

}

HashElementType HashTable::hashFunc(const HashElementType& elem) {
	return elem % 5;
}
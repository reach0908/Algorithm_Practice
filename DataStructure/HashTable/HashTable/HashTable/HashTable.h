#pragma once

#include <assert.h>
#include "LinkedList.h"

const int MAX_TABLE = 11;
using namespace std;


template<class tableKeyType, class tableDataType>
class HashTable
{
public:
	HashTable();
	void insert(const tableKeyType& key, const tableDataType& data);
	bool lookup(const tableKeyType& key, tableDataType& data);
	void deleteKey(const tableKeyType& key);
	void dump();
	enum slotType {Empty,Deleted,InUse};
	struct slot
	{
		slotType slotStatus;
		tableKeyType key;
		tableDataType data;
	};
	slot T[MAX_TABLE];
	int entries;
	int hash(const tableKeyType& key);
	int probe(const int pos);
	bool search(int& pos, const tableKeyType& target);
};

template<class tableKeyType, class tableDataType>
HashTable<tableKeyType,tableDataType>::HashTable()
{
	entries = 0;
	int i;
	for (i = 0; i < MAX_TABLE; i++)
	{
		T[i].slotStatus = Empty;
	}
}

template<class tableKeyType, class tableDataType>
int
HashTable<tableKeyType, tableDataType>::hash(const tableKeyType& key)
{
	return key % MAX_TABLE;
}

template<class tableKeyType, class tableDataType>
int
HashTable<tableKeyType, tableDataType>::probe(const int pos)
{
	if (pos < MAX_TABLE - 1) {
		return pos + 1;
	}
	else
	{
		return 0;
	}
}

template<class tableKeyType, class tableDataType>
bool
HashTable<tableKeyType, tableDataType>::search(int& pos, const tableKeyType& target)
{
	for (;T[pos].slotStatus!=Empty;pos=probe(pos))
	{
		if (T[pos].slotStatus == InUse&&T[pos].key==target)
		{
			return true;
		}
	}
	return false;
}

template<class tableKeyType, class tableDataType>
void
HashTable<tableKeyType, tableDataType>::insert(const tableKeyType& key, const tableDataType& data)
{
	assert(entries < MAX_TABLE - 1);
	int pos(hash(key));
	if (!search(pos, key)) {
		pos = hash(key);
		while (T[pos].slotStatus == InUse) {
			pos = probe(pos);
		}
		entries++;
	}
	T[pos].slotStatus = InUse;
	T[pos].key = key;
	T[pos].data = data;
}

template<class tableKeyType, class tableDataType>
bool
HashTable<tableKeyType, tableDataType>::lookup(const tableKeyType& key, tableDataType& data)
{
	int pos(hash(key));
	if (search(pos, key)) {
		data = T[pos].data;
		return true;
	}
	else
	{
		return false;
	}
}

template<class tableKeyType, class tableDataType>
void
HashTable<tableKeyType, tableDataType>::deleteKey(const tableKeyType& key)
{
	int pos(hash(key));
	if (search(pos, key)) {
		T[pos].slotStatus = Deleted;
		entries--;
	}
}

template<class tableKeyType, class tableDataType>
void
HashTable<tableKeyType, tableDataType>::dump()
{
	int i;
	for (i = 0; i < MAX_TABLE; i++) {
		cout << i << '\t';
		switch (T[i].slotStatus)
		{
		case InUse:
			cout << "In Use\t" << T[i].key << endl;
			break;
		case Deleted:
			cout << "Deleted\t" << T[i].key << endl;
			break;
		case Empty:
			cout << "Empty\t" << T[i].key << endl;
			break;
		}
	}
	cout << "Entries =" << entries << "\n\n";
}





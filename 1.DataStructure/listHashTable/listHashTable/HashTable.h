#pragma once

#include <assert.h>

const int MAX_TABLE = 11;
using namespace std;

template <class tableKeyType, class tableDataType>
class HashTable
{
public:
	HashTable();
	void insert(const tableKeyType& key, const tableDataType& data);
	bool lookup(const tableKeyType& key, tableDataType& data);
	void deleteKey(const tableKeyType& key);
	void dump();
private:
	struct Slot;
	typedef Slot* Link;
	struct Slot
	{
		tableKeyType key;
		tableDataType data;
		Link next;
	};
	Link T[MAX_TABLE];
	int hash(const tableKeyType& key);
	bool search(Link& slotPointer, const tableKeyType& target);
};

template <class tableKeyType, class tableDataType>
HashTable<tableKeyType,tableDataType>::HashTable()
{
	int i = 0;
	for (i = 0; i < MAX_TABLE; i++)
	{
		T[i] = 0;
	}
}

template <class tableKeyType, class tableDataType>
int
HashTable<tableKeyType, tableDataType>::hash(const tableKeyType& key)
{
	return key%MAX_TABLE;
}

template <class tableKeyType, class tableDataType>
bool
HashTable<tableKeyType, tableDataType>::search(Link& slotPointer, const tableKeyType& target)
{
	for (;slotPointer;slotPointer=slotPointer->next)
	{
		if (slotPointer->key == target) {
			return true;
		}
	}
	return false;
}


template <class tableKeyType, class tableDataType>
void
HashTable<tableKeyType, tableDataType>::insert(const tableKeyType& key, const tableDataType& data)
{
	int pos(hash(key));
	Link sp(T[pos]);
	if (!search(sp, key)) {
		Link insertedSlot = new Slot;
		insertedSlot->key = key;
		insertedSlot->data = data;
		insertedSlot->next = T[pos];
		T[pos] = insertedSlot;
	}
	else
	{
		sp->data = data;
	}
}

template <class tableKeyType, class tableDataType>
bool
HashTable<tableKeyType, tableDataType>::lookup(const tableKeyType& key,tableDataType& data)
{
	int pos(hash(key));
	Link sp(T[pos]);
	if (search(sp, key)) {
		data = sp->data;
		return true;
	}
	else {
		return false;
	}
}

template <class tableKeyType, class tableDataType>
void
HashTable<tableKeyType, tableDataType>::deleteKey(const tableKeyType& key)
{
	int pos(hash(key));
	Link p;
	if (0 == T[pos]) {
		return;
	}
	else if (T[pos]->key == key) {
		Link deleteSlot(T[pos]);
		T[pos] = T[pos]->next;
		delete deleteSlot;
	}
	else {
		for (p=T[pos];p->next; p=p->next)
		{
			if (p->next->key == key)
			{
				Link deleteSlot = p->next;
				p->next = p->next->next;
				delete deleteSlot;
				break;
			}
		}
	}
}

template <class tableKeyType, class tableDataType>
void
HashTable<tableKeyType, tableDataType>::dump()
{
	int i;
	for (i = 0; i < MAX_TABLE; i++)
	{
		cout << i << '\t';
		Link p;
		for (p=T[i];p;p=p->next)
		{
			cout << p->key << '\t';
		}
		cout << '\n';
	}
	cout << '\n';
}











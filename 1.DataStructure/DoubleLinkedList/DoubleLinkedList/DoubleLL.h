#pragma once

#include <assert.h>

typedef int ListElementType;
class DoubleLL {
public:
	DoubleLL();
	void insert(const ListElementType& e);
	bool previous(ListElementType& e);
	bool first(ListElementType& elem);
	bool next(ListElementType& elem);

	struct Node;
	typedef Node* Link;

	struct Node
	{
		ListElementType data;
		Link next;
		Link prev;
	};
	Link head;
	Link current;
	Link tail;
};

DoubleLL::DoubleLL() {
	head = 0;
	current = 0;
	tail = 0;
}

void DoubleLL::insert(const ListElementType& e) {
	Link addedNode = new Node;
	assert(addedNode); // check to make sure node was allocated
	addedNode->data = e;
	if (head == 0) // list was empty -- set head
		head = addedNode;
	else
		tail->next = addedNode;
	tail = addedNode;
	addedNode->next = 0;

}

bool DoubleLL::first(ListElementType& elem) {
	if (head == 0) { 
		return false;
	}
	else {
		current = head;
		elem = current->data;
		return true;
	}
}
bool DoubleLL::next(ListElementType& elem) {
	assert(current);
	if (current->next == 0) {
		return false;
	}
	else {
		current = current->next;
		elem = current->data;
		return true;
	}
}
bool DoubleLL::previous(ListElementType& elem) {
	assert(current);
	if (current->prev == 0) {
		return false;
	}
	else {
		current = current->prev;
		elem = current->data;
		return true;
	}
}


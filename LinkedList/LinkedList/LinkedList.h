#pragma once

#include <assert.h>

typedef int ListElementType;
class List {
public:
	List();
	void insert(const ListElementType& elem);
	void insertBetween(const ListElementType& elem);
	bool first(ListElementType& elem);
	bool next(ListElementType& elem);
	struct Node;
	typedef Node* Link;
	struct Node {
		int data;
		Link next;
	};
	Link head;
	Link tail;
	Link current;
};

List::List() {
	head = 0;
	tail = 0;
	current = 0;
}

void List::insert(const ListElementType& elem) {
	Link addedNode = new Node;
	assert(addedNode);
	addedNode->data = elem;
	if (head == 0) {
		head = addedNode;
	}
	else {
		tail->next = addedNode;
	}
	tail = addedNode;
	addedNode->next = 0;
}
void List::insertBetween(const ListElementType& elem) {
	Link addedNode = new Node;
	assert(addedNode);
	addedNode->data = elem;
	addedNode->next = current->next;
	current->next = addedNode;
}
bool List::first(ListElementType& elem) {
	
	if (head == 0) {
		return false;
	}
	else {
		elem = head->data;
		current = head;
		return true;
	}
}

bool List::next(ListElementType& elem) {

	if (current->next == 0) {
		return false;
	}
	else {
		current = current->next;
		elem = current->data;
		return true;
	}
}





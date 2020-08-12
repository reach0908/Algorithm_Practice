#pragma once

#include <assert.h>

typedef int ListElementType;
class List {
public:
	List();
	void insert(const ListElementType& elem);
	void insertBetween(const ListElementType& elem);
	void delNode(const ListElementType& elem);
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
void List::delNode(const ListElementType & target) {
	//헤드삭제, 중간삭제, 테일삭제의 경우를 생각해야함
	assert(head);
	Link pred, delNode;
	// pred starts out pointing at the dummy head
	pred = head;
	while (pred->next)
	{
		if (pred->next->data == target) {
			break;
		}
		pred = pred->next;
	}
	// at this point, check to see if we've found target --
	// if so, remove it
	// Have to check carefully to make sure we don't
	// dereference a null pointer!
	if (pred && (pred->next) && (pred->next->data == target)) {
		// remove the next node in the list
		delNode = pred->next;
		pred->next = delNode->next;
		delete delNode; // return node to memory
	}

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





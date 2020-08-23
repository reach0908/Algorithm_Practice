#pragma once

#include <assert.h>

template <class queueElementType>
class listQueue
{
public:
	listQueue();
	void enqueue(queueElementType e);
	queueElementType dequeue();
	queueElementType front();
	bool isEmpty();
private:
	struct Node;
	typedef Node* nodePtr;
	struct Node {
		queueElementType data;
		nodePtr next;
	};
	nodePtr f;
	nodePtr r;
};

template <class queueElementType>
listQueue<queueElementType>::listQueue() {
	f = 0;
	r = 0;
}

template <class queueElementType>
void
listQueue<queueElementType>::enqueue(queueElementType e) {
	nodePtr n(new Node);
	assert(n);
	n->next = 0;
	n->data = e;
	if (f != 0) {
		r->next = n;
		r = n;
	}
	else {
		f = n;
		r = n;
	}
}
template <class queueElementType>
queueElementType
listQueue<queueElementType>::dequeue() {
	assert(f);
	nodePtr n(f);
	queueElementType frontElement(f->data);
	f = f->next;
	delete n;
	if (f == 0) {
		r = 0;
	}
	return frontElement;
}
template <class queueElementType>
bool
listQueue<queueElementType>::isEmpty() {
	return bool(f == 0);
}




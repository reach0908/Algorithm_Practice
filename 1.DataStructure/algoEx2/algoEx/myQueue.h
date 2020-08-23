#pragma once
#include <assert.h>
const int maxQueue = 200;

template <class queueElementType>
class myQueue
{
public:
	myQueue();
	void enqueue(queueElementType e);
	queueElementType dequeue();
	queueElementType front();
	queueElementType rear();
	bool isEmpty();
private:
	int f;
	int r;
	queueElementType elements[maxQueue];
};

int nextPos(int p) {
	if (p == maxQueue - 1) {
		return 0;
	}
	else
	{
		return p + 1;
	}
}

template <class queueElementType>
myQueue<queueElementType>::myQueue() {
	f = 0;
	r = 0;
}

template <class queueElementType>
void myQueue<queueElementType>::enqueue(queueElementType e) {
	assert(nextPos(r) != f);
	r = nextPos(r);
	elements[r] = e;
}


template <class queueElementType>
queueElementType myQueue<queueElementType>::dequeue() {
	assert(f!=r);
	f = nextPos(f);
	return elements[f];
}

template <class queueElementType>
queueElementType myQueue<queueElementType>::front() {
	assert(f != r);
	return elements[nextPos(f)];
}

template <class queueElementType>
queueElementType myQueue<queueElementType>::rear() {
	assert(f != r);
	return elements[r];
}

template <class queueElementType>
bool myQueue<queueElementType>::isEmpty() {
	
	return bool(f==r);
}









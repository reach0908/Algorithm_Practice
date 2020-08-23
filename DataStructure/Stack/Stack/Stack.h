#pragma once

#include <assert.h>
const int maxStackSize = 1000;





//배열을 이용한 스택 구현
template<class StackElementType>
class Stack
{
public:
	Stack();
	void push(StackElementType item);
	StackElementType pop();
	StackElementType top();
	bool isEmpty();
	bool isFull();
private:
	StackElementType stackArray[maxStackSize];
	int topIndex;
};

template<class StackElementType>
Stack<StackElementType>::Stack()
{
	topIndex = -1;
}

template<class StackElementType>
void
Stack<StackElementType>::push(StackElementType item)
{
	++topIndex;
	assert(topIndex < maxStackSize);
	stackArray[topIndex] = item;
}

template<class StackElementType>
StackElementType
Stack<StackElementType>::pop()
{
	assert(topIndex >= 0); // 스택이 비어있는지 확인
	int returnIndex(topIndex);  // 배열의 인덱스는 인트형이기 때문에 스택엘리먼트타입으로 선언안해도된다.
	--topIndex;
	return stackArray[returnIndex];
}

template<class StackElementType>
StackElementType
Stack<StackElementType>::top()
{
	assert(topIndex >= 0);
	return stackArray[topIndex];
}

template<class StackElementType>
bool
Stack<StackElementType>::isEmpty()
{
	return bool(topIndex == -1);
}

template<class StackElementType>
bool
Stack<StackElementType>::isFull()
{
	return topIndex == maxStackSize - 1;
}





#pragma once

#include <assert.h>
const int maxStackSize = 1000;





//�迭�� �̿��� ���� ����
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
	assert(topIndex >= 0); // ������ ����ִ��� Ȯ��
	int returnIndex(topIndex);  // �迭�� �ε����� ��Ʈ���̱� ������ ���ÿ�����ƮŸ������ ������ص��ȴ�.
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





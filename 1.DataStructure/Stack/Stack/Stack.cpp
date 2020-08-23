

#include <iostream>
#include <random>
#include "Stack.h"

using namespace std;

#define STACK_SIZE 10

int main()
{
    Stack<int> s;
	for (int i = 0; i < STACK_SIZE; i++)
	{
		s.push(i);
	}
	cout << s.isEmpty() << endl;
	//cout << s.isFull() << endl;
	for (int i = 0; i < STACK_SIZE; i++)
	{
		cout << s.pop() << " ";
	}
	cout << endl;
	cout << s.isEmpty() << endl;
	return 0;
}


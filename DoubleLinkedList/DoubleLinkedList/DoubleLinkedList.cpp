// DoubleLinkedList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "DoubleLL.h"

using namespace std;


int main()
{
    DoubleLL dl;
	for (int i = 0; i < 10; i++)
	{
		dl.insert(i);
	}
	int elem = 0;
	dl.first(elem);
	cout << elem << endl;
	while (dl.next(elem))
	{
		cout << elem << endl;

	}
    cout << "Hello World!\n";
}


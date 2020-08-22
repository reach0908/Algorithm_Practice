

#include <iostream>
#include <random>

#define ARR_SIZE 10

using namespace std;

int factoiral(int num) {
	if (num > 1)
	{
		return num * factoiral(num - 1);
	}
	else {
		return num;
	}
}

int multiple(int num) {
	if (num <= 1) {
		return num;
	}
	else
	{
		return num * multiple(num-1);
	}
}
int sum(int arr[],int arrSize) {
	if (arrSize <= 1) {
		return arr[0];
	}
	else
	{
		return arr[arrSize - 1] + sum(arr, arrSize - 1);
	}
}

int main()
{

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 100);

	cout << factoiral(4) << endl;
	cout << multiple(4) << endl;
	
	int arr[ARR_SIZE];
	for (int i = 0; i < ARR_SIZE; i++)
	{
		arr[i] = dis(gen);
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << sum(arr, ARR_SIZE);

    return 0;
}

// 재귀호출의 일반적인 형태
/*int func1(int num) {
	if (num > 0)     - 입력한 값이 일정 값 이상이면
	{
		return func1(num - 1); // 입력보다 작은 값
	}
	else
	{
		return 0; - 재귀호출 종료
	}
}

int func2(int num) {
	if (num <= 1) - 입력한 값이 일정값보다 작으면
	{
		return num; - 재귀호출 종료
	}
	int return_Value = num*func2(num - 1); - 입력보다 작은 값 
	return return_Value; - 결과값
}*/

//재귀호출은 스택의 전형적인 예이다.
// - 함수는 내부적으로 스택처럼 관리된다.



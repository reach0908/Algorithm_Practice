

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

//회문 프로그래밍 
//문자열 슬라이싱 - 스트링라이브러리 이용 - 라이브러리를 사용못할때는 어떻게? - 포문으로 앞뒤 검사
int example(int num) {
	cout << num << endl;
	if (num <=1)
	{
		return num;
	}
	else if (num%2==1) {
		return example((3 * num) + 1);
	}
	else
	{
		return example(num / 2);
	}
}

int example2(int num) {
	if (num == 1) {
		return 1;
	}
	else if (num == 2) {
		return 2;
	}
	else if (num == 3) {
		return 4;
	}
	else {
		return example2(num - 1) + example2(num - 2) + example2(num - 3);
	} //acm-icpc 문제 1과 2와 3으로 n 을 만들어낼 수 있는 경우의 수 구하기 
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
	cout << sum(arr, ARR_SIZE) << endl;

	cout << example(3) << endl;
	cout << example2(4) << endl;
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



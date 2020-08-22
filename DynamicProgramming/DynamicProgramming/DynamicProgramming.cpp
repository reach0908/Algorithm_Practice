// DynamicProgramming.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;
// 재귀용법을 활용한 피보나치 수열
#define SIZE 1000

long long save[SIZE] = {0,1,};

int fibo(int num) {
	if (num<=1)
	{
		return num;
	}
	else { return fibo(num - 1) + fibo(num - 2); }
}

double dynamicFibo(int num) {
	if (save[num] > 0) {
		return save[num];
	}
	return 
}

//동적계획법을 이용한 피보나치 수열

int main()
{
	cout << fibo(4) << endl;
    
}


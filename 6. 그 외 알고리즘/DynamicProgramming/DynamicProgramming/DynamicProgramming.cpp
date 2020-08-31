// DynamicProgramming.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;
// 재귀용법을 활용한 피보나치 수열
#define SIZE 1000

double save[SIZE] = {0,};

int fibo(int num) {
	if (num<=1)
	{
		return num;
	}
	else { return fibo(num - 1) + fibo(num - 2); }
}

double dynamicFibo(int num) {
	save[0] = 0;
	save[1] = 1;
	for (int i = 2; i <= num+1; i++)
	{
		save[i] = save[i - 1] + save[i - 2];
	}
	return save[num];
}

//동적계획법을 이용한 피보나치 수열

int main()
{
	cout << fibo(10) << endl;
	cout << dynamicFibo(10) << endl;

	//동적계획법으로 만든 피보나치수열이 재귀로 만든 피보나치보다 훨씬 시간이 적게 걸린다. 
    
}


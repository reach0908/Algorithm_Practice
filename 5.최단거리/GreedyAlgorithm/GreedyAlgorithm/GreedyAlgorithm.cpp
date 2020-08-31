
#include <iostream>
#include <algorithm>

using namespace std;

int Coin(int num) {
	int coin[4] = { 500,100,50,1 };
	int totalCnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int coinNum = num / coin[i];
		totalCnt += coinNum;
		num -= coinNum * coin[i];
	}
	return totalCnt;
}

int knapsackP(int k) {
	int arr[5][2] = { {10,10},{15,12},{20,10},{25,8},{30,5} };
	double sorted[5];
	for (int i = 0; i < 5; i++)
	{
		sorted[i] = (double)arr[i][1] / arr[i][0];
		cout << sorted[i];
		
	}
	
	
	return k;
}
int main()
{
	cout << Coin(4720) << endl;
	int k = 25;
	cout << knapsackP(k);
}

// 탐욕 알고리즘의 이해
// 최적의 해에 가까운 값을 구하기 위해 사용됨
// 여러 경우 중 하나를 결정해야 한다. 
// 매 순간 최적이라고 생각되는 경우를 선택하는 방식으로 진행해서
// 최종적인 값을 구하는 방식

//일종의 전략이라고 생각하자
// 매순간 최적이라고 생각되는 경우 바로직전 바로 직후 단계에 대해서 최적의 경우를 고르는 전략

//동전문제
// 지불해야 하는 값이 4270원일 때 1원 50원 100원 500원 동전으로
// 동전의 수가 가장 적게 지불하시오
// - 가장 큰 동전부터 최대한 지불해야하는 값을 채우는 방식으로 구현 가능
// - 탐욕 알고리즘으로 매순간 최적이라고 생각되는 경우를 선택하면 됨

// 


//부분 배낭 문제
// 무게 제한이 k인 배낭에 최대 가치를 가지도록 물건을 넣는 문제
// 물건은 무게랑 가치로 표현됨
// 물건은 쪼갤 수 있으므로 일부분이 배낭에 넣어질 수 있음
// fractional knapsack problem

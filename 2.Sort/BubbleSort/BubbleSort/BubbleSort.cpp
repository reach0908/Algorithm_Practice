
#include <iostream>
#include <random>


using namespace std;


#define HEAP_SIZE 256
#define ARRAY_SIZE 10

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;

}



int main()
{	
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 100);
	int arr[ARRAY_SIZE];
	int arr2[10];
	for (int i = 0; i < ARRAY_SIZE; i++) {
		// 1 ~ 50까지의 난수 생성
		arr[i] = dis(gen);
		arr2[i] = i;
		
	}
	cout << "첫번째 배열 정렬 전 : ";
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << arr[i] << '\t';

	}
	cout << endl;
	cout << "두번째 배열 정렬 전 : ";
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << arr2[i] << '\t';

	}
	cout << endl;
	int swapNum = 0;
	int swapNum2 = 0;
	for (int i = 0; i < ARRAY_SIZE-1; i++)
	{
		
		for (int j = 0; j < ARRAY_SIZE-i-1; j++)
		{
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				//cout << arr[j] << " " << arr[j + 1];
				//cout << endl;
				swapNum++;
			}
			if (swapNum == 0) {
				break; // 이 구문을 통해 이미 정렬된 자료구조는 정렬을 더이상 하지않고 탈출
			}
		}
	}
	for (int i = 0; i < ARRAY_SIZE - 1; i++)
	{

		for (int j = 0; j < ARRAY_SIZE - i - 1; j++)
		{
			if (arr2[j] > arr2[j + 1]) {
				swap(arr2[j], arr2[j + 1]);
				//cout << arr[j] << " " << arr[j + 1];
				//cout << endl;
				swapNum2++;
			}
			if (swapNum2 == 0) {
				break;
			}
		}
	}
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << arr[i] << '\t';
		
	}
	cout << endl;
	cout<<"첫번째 어레이가 스왑된 횟수 : " << swapNum << endl;
	
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << arr2[i] << '\t';

	}
	cout << endl;
	cout << "두번째 어레이가 스왑된 횟수 : " << swapNum2 << endl;

	

	return 0;
}

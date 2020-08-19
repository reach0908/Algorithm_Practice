
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

int arr[ARRAY_SIZE];

int main()
{	
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 100);

	for (int i = 0; i < ARRAY_SIZE; i++) {
		// 1 ~ 50까지의 난수 생성
		arr[i] = dis(gen);
		cout << arr[i] << '\t';
	}
	cout << endl;

	for (int i = 0; i < ARRAY_SIZE-1; i++)
	{
		for (int j = 0; j < ARRAY_SIZE-i-1; j++)
		{
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				//cout << arr[j] << " " << arr[j + 1];
				//cout << endl;
			}
			
		}
	}
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << arr[i] << '\t';
	}

	

	return 0;
}

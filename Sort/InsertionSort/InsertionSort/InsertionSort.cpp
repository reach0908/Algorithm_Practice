

#include <iostream>
#include <random>

#define ARR_SIZE 10

using namespace std;

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertionSort(int arr[], int n) {
    for (int i = 0; i < ARR_SIZE-1; i++)
    {
        for (int j = i+1; j >=0 ; j--)
        {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            }
            else
            {
                break;
            }
        }
    }
}
int main()
{

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 100);

    int arr[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++)
    {
        arr[i] = dis(gen);
        cout << arr[i] << '\t';
    }
    cout << endl;

    insertionSort(arr, ARR_SIZE);

    for (int i = 0; i < ARR_SIZE; i++)
    {
        cout << arr[i] << '\t';
    }

    return 0;
}

//선택정렬
//한개를 고른다음에 들어갈 자리를 찾는다.
//맨앞이거나 내 자리가 맞다면 그자리에 삽입을 한다.

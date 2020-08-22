
#include <iostream>
#include <random>

#define MAX_SIZE 100

int sorted[MAX_SIZE];

using namespace std;
void merge_(int arr[], int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = start;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j]) {
            sorted[k] = arr[i];
            i++;
        }
        else {
            sorted[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i > mid) {
        for (int t = j; t <= end; t++)
        {
            sorted[k] = arr[t];
            k++;
        }
    }
    else
    {
        for (int t = i; t <= mid; t++)
        {
            sorted[k] = arr[t];
            k++;
        }
    }
    for (int t = start; t <= end; t++)
    {
        arr[t] = sorted[t];
    }
}
void mergeSort(int arr[],int start,int end) {
    int mid;
    if (start < end) {
        mid = (start + end) / 2;
        mergeSort(arr,start, mid);
        mergeSort(arr,mid + 1, end);
        merge_(arr,start,mid,end);
    }
}


int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 100);

    int arr[MAX_SIZE];

    for (int i = 0; i < 10; i++)
    {
        arr[i] = dis(gen);
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

//병합정렬
// 재귀용법을 활용한 정렬 알고리즘
//1. 리스트를 절반으로 잘라 비슷한 크기의 두 부분 리스트로 나눈다.
//2. 각 부분 리스트를 재귀적으로 합병 정렬을 이용해 정렬한다.
//3. 두 부분 리스트를 다시 하나의 정렬된 리스트로 합병한다.
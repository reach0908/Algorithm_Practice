
#include <iostream>
#include <random>

using namespace std;

#define ARR_SIZE 10

void swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int *data,int left,int right) {
    if (left >= right) {
        return;
    }
    int pivot = left;   // 처음에 left =0, right =9 
    int start = left + 1; // 스타트지점을 피벗 보다 한칸오른쪽
    int end = right; // 배열의 끝
    while (start<=end) // 스타트 지점이 엔드보다 커진다는 것은 분할할것이 없다는 것
    {
        while (start<=right&&data[start]<=data[pivot]) // 스타트가 끝보다 작으면서 피벗의 값이 크다면 넘어가도 되니 스타트를 옮긴다.
        {
            start++;
        }
        while (left < end && data[end] >= data[pivot]) //피벗의 값이 엔드의 값보다 작으면 넘어가도 되니 엔드를 줄인다.
        {
            end--;
        }
        if (start > end) { 
            swap(data[pivot], data[end]);
        }
        else
        {
            swap(data[start], data[end]);
        }
    }
    quickSort(data, left, end - 1);
    quickSort(data, end + 1, right);
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
        cout << arr[i] << " ";
    }
    cout << endl;
    quickSort(arr,0,9);
    for (int i = 0; i < ARR_SIZE; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

//퀵정렬 - 분할정복의 대표적인 예
// 기준점 피벗을 정해서, 기준점보다 작은데이터는 왼쪽, 큰 데이터는 오른쪽으로 모으는 함수를 작성함
// 각 왼쪽, 오른쪽은 재귀용법을 사용해서 다시 동일함수를 호출하여 위 작업을 반복함
// 함수는 왼쪽 기준점 오른쪽을 리턴함


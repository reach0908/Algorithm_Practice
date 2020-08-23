
#include <iostream>
#include <random>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define ARR_SIZE 10

void swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int swapNum = 0;
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
            cout << "바뀐스타트지점 : " << start << endl;
        }
        while (left < end && data[end] >= data[pivot]) //피벗의 값이 엔드의 값보다 작으면 넘어가도 되니 엔드를 줄인다.
        {
            end--;
            cout << "바뀐엔드지점 : " << end << endl;
        }
        if (start > end) { 
            cout << "현재 피벗값과 엔드값 :" << pivot<<" "<<end << endl;
            swap(data[pivot], data[end]);
            swapNum++;
            for (int i = 0; i < ARR_SIZE; i++)
            {
                cout << data[i] << " ";
            }
            cout << "스왑된 횟수  :" << swapNum << endl;
        }
        else
        {
            cout << "현재 스타트 엔드 값 :" << start << " " << end << endl;
            swap(data[start], data[end]);
            swapNum++;
            for (int i = 0; i < ARR_SIZE; i++)
            {
                cout << data[i] << " ";
            }
            cout << "스왑된 횟수  :" << swapNum << endl;
        }
    }
    cout << "반복문 종료 : 현재까지의 상황 " << endl;
    for (int i = 0; i < ARR_SIZE; i++)
    {
        cout << data[i] << " ";
    }
    cout << "피벗 :" << pivot << " 스타트 :" << start << " 엔드 :" << end << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    quickSort(data, left, end - 1);
    quickSort(data, end + 1, right);
}

void quickSort2(int A[], int low, int high) {
    if (low >= high) return; // base condition

    // divide process
    int i = low - 1, j = low;
    int& pivot = A[high];
    for (; j < high; ++j) {
        if (A[j] < pivot)
            swap(A[++i], A[j]);
    }
    swap(A[++i], pivot);

    // conquer process
    quickSort2(A, low, i - 1);
    quickSort2(A, i + 1, high);
}

//파티션을 이용한 퀵소트
int partition(int a[], int left, int right) {

    srand(time(NULL));
    // left ~ right 사이의 값을 랜덤으로 생성
    int pivot_index = rand() % (right + 1 - left) + left;
    int pivot_value = a[pivot_index];

    swap(&a[pivot_index], &a[right]);

    // store_index를 기준으로
    // 왼쪽에 pivot_value보다 작은 값들 위치시킴
    int store_index = left;
    for (int i = left; i < right; i++) {
        if (a[i] < pivot_value) {
            swap(&a[i], &a[store_index]);
            store_index += 1;
        }
    }

    swap(&a[store_index], &a[right]);

    return store_index;

}

void quick_sort(int a[], int left, int right) {

    if (left < right) {
        int p = partition(a, left, right);
        for (int i = 0; i < ARR_SIZE; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        quick_sort(a, left, p - 1);
        for (int i = 0; i < ARR_SIZE; i++)
        {
            cout << a[i] << " ";
        }cout << endl;
        quick_sort(a, p + 1, right);
    } 
}


int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 100);
    int arr[ARR_SIZE] = { 1,6,3,4,5,8,10,0,7,2 };
    int arr2[ARR_SIZE];
    int arr3[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++)
    {
        
        arr2[i] = dis(gen);
        arr3[i] = dis(gen);
        
    }
    cout << endl;
    quickSort(arr,0,9);
    /*quickSort2(arr2, 0, 9);
    quick_sort(arr3, 0, 9);
    for (int i = 0; i < ARR_SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < ARR_SIZE; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < ARR_SIZE; i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;*/


    return 0;
}

//퀵정렬 - 분할정복의 대표적인 예
// 기준점 피벗을 정해서, 기준점보다 작은데이터는 왼쪽, 큰 데이터는 오른쪽으로 모으는 함수를 작성함
// 각 왼쪽, 오른쪽은 재귀용법을 사용해서 다시 동일함수를 호출하여 위 작업을 반복함
// 함수는 왼쪽 기준점 오른쪽을 리턴함


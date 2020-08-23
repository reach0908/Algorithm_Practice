// BinarySearch.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <random>
#include "Sort.h"

using namespace std;
#define ARR_SIZE 50

bool BinarySearch(int arr[],int start,int end,int search) {
    if (end == 0 && search == arr[0]) {
        return true;
    }
    else if (end == 0 && search != arr[0]) {
        return false;
    }
    if (end==-1)
    {
        return false;
    }
    int mid = (start+end) / 2;
    if (search==arr[mid])
    {
        return true;
    }
    else if (search>arr[mid])
    {
        return BinarySearch(arr,mid+1,end,search);
    }
    else
    {
        return BinarySearch(arr, start, mid, search);
    }
    return false;
}

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 100);

    int arr[ARR_SIZE];

    for(int i = 0; i < ARR_SIZE; i++)
    {
        arr[i] = dis(gen);
        cout << arr[i] << " ";
    }
    cout << endl;
    quickSort(arr, 0, ARR_SIZE - 1);
    
    //bubbleSort(arr, ARR_SIZE);
    //mergeSort(arr, 0, ARR_SIZE-1);
    //insertionSort(arr, ARR_SIZE);
    //selectionSort(arr, ARR_SIZE);
    for (int i = 0; i < ARR_SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "찾을 값을 입력하세요 :";
    int search;
    cin >> search;
    
    if (BinarySearch(arr, 0, ARR_SIZE - 1, search))
    {
        cout << "찾았습니다." << endl;
    }
    else
    {
        cout << "찾지 못했습니다." << endl;
    }
    cout << endl;
    
    
}

//이진 탐색

// 탐색할 자료를 둘로 나누어 해당 데이터가 있을 만한 곳을 찾는 법
// 이미 정렬되어있어야함
// 데이터가 정렬되어 있다는 가정하에 이진탐색은 순차탐색보다 빠르다.


//분할 정복 알고리즘과 이진 탐색
// 분할 정복 알고리즘 - divide and conquer
// divide = 문제를 하나 또는 둘 이상으로 나눈다.
// conquer = 나눠진 문제가 충분히 작고, 해결이 가능하다면, 해결하고 그렇지 않다면 다시 나눈다.

//이진 탐색
//divide = 리스트를 두개의 서브 리스트로 나눈다.
//conquer = 검색할 숫자 > 중간값, 뒷 부분의 서브리스트에서 검색할 숫자를 찾는다.
//          검색할 숫자 < 중값값, 앞 부분의 서브리스트에서 검색할 숫자를 찾는다.




#include <iostream>
#include <random>

using namespace std;

#define ARR_SIZE 10

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1,100);
    int arr[ARR_SIZE];


    for (int i = 0; i < ARR_SIZE; i++)
    {
        arr[i] = dis(gen);
        cout << arr[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < ARR_SIZE-1; i++)
    {
        int min = i;
        for (int j = i+1; j < ARR_SIZE; j++)
        {
            if (arr[min]>arr[j])
            {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }

    for (int i = 0; i < ARR_SIZE; i++)
    {
        cout << arr[i] << " ";
    }
}


//선택정렬
//1. 주어진 데이터 중 최소값을 찾음
//2. 해당 최소값을 데이터 맨 앞에 위치한 값을 교체함
//3. 맨 앞의 위치를 뺀 나머지 데이터를 1~2과정을 반복
// 최소값을 선택한다고 해서 선택정렬이 된다. 

//간단한 경우부터 생각해서 종이에 작성후
// 알고리즘 구현을 공부한다. 

// 

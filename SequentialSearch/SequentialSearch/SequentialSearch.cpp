
#include <iostream>
#include <random>

using namespace std;

#define ARR_SIZE 10

bool sequentialSearch(int arr[], int search,int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i]==search)
        {
            return true;
        }
    }
    return false;
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
    cout << "찾으려는 값을 입력하세요 :";
    int search;
    cin >> search;
    if (sequentialSearch(arr, search, ARR_SIZE)) {
        cout << "찾았습니다.";
    }
    else
    {
        cout << "찾지못했습니다.";
    }
    
    return 0;
}


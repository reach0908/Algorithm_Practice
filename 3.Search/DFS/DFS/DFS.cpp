// DFS.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INT_SIZE 9
int visit[INT_SIZE];
vector<int> a[10];

void DFS(int start) {
    if (visit[start]) {
        return;
    }
    visit[start] = true;
    cout << start << " ";
    for (int i = 0; i < a[start].size(); i++)
    {
        int x = a[start][i];
        DFS(x);
    }
}

int main()
{
    a[1].push_back(2);
    a[2].push_back(1);
    a[1].push_back(3);
    a[3].push_back(1);
    a[2].push_back(3);
    a[3].push_back(2);
    a[2].push_back(4);
    a[4].push_back(2); 
    a[2].push_back(5);
    a[5].push_back(2);
    a[4].push_back(8); 
    a[8].push_back(4);
    a[5].push_back(9); 
    a[9].push_back(5);
    a[3].push_back(6); 
    a[6].push_back(3);
    a[3].push_back(7); 
    a[7].push_back(3);
    DFS(1);
    return 0;
}

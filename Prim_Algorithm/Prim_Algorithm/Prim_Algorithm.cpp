// Prim_Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


#define INF 999999999

using namespace std;

vector<vector<pair<int, int>>> edge;

//우선순위 큐의 생성 
// 자료형, 구현체, 비교연산자 로 정의된다.
//구현체는 기본적으로 벡터<자료형> 으로 정의된다. 
// 비교연산자는 기본적으로 less<자료형> 으로 정의된다.
// greater를 넣으면 작은놈부터 나온다.
priority_queue< pair<int, int>, vector<pair<int, int>>, greater<> > pq; 

bool visited[10001];
int v, e, c, k;

void prim(int v);


int main()
{
    cin >> v >> e;
    edge.resize(v + 1);
    int x, y, z;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y >> z;
        edge[x].push_back({ z,y });
        edge[y].push_back({ z,x });
    }

    prim(1);

    cout << k;
    return 0;
}

void prim(int v) {
    visited[v] = true;
    //auto 키워드를 사용하면 초기값의 형식에 맟춰 선언하는 인스턴스
    //의 형식이 자동으로 결정된다. 이것을 타입추론이라고 한다.
    // 변수를 함수의 반환값으로 초기화할 때도 사용 가능하다.
    //매개변수로는 활용이 불가능하다.
    for (auto u: edge[v]){
        if (!visited[u.second])
        {
            pq.push({ u.first,u.second });
        } 
    }
    while (!pq.empty())
    {
        auto w = pq.top();
        pq.pop();
        if (!visited[w.second])
        {
            k += w.first;
            prim(w.second);
            return;
        }
    }
}
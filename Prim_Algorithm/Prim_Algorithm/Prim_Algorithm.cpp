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
        //x 시작점
        //y 도착점
        //z 간선비용
        edge[x].push_back({ z,y });
        edge[y].push_back({ z,x });  //0. 모든 간선 정보의 저장
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
    for (auto u: edge[v]){ //1. 임의의 정점을 선택
        if (!visited[u.second]) 
        {
            pq.push({ u.first,u.second }); //2. 선택된 정점에 연결된 간선들을 간선리스트에 삽입
        } 
    }
    while (!pq.empty()) //5. 간선리스트가 없어질때까지 3~4번 반복
    {
        auto w = pq.top(); //3. 간선리스트에서 최소 가중치를 가지는 간선 추출
        pq.pop(); //추출
        if (!visited[w.second]) //방문하지 않았으면
        {
            k += w.first; //최소신장트리에 추가
            prim(w.second); // 그 다음 점을 선택
            return;
        }
    }
}

//프림 알고리즘

//0. 모든 간선 정보를 저장
//1. 임의의 정점을 선택, 연결된 노드 집합에 삽입
//2. 선택된 정점에 연결된 간선들을 간선리스트에 삽입
//3. 간선리스트에서 최소 가중치를 가지는 간선부터 추출해서
// - 해당 간선에 연결된 인접 정점이 '연결된 노드집합'에 이미 들어있다면, 스킵합
// - 해당 간선에 연결된 언접 정점이 '연결된 노드집합'에 이미 들어있지 않다면, 해당 간선을
//   선택하고, 해당 간선정보를 '최소 신장트리'에 삽입
//   - 해당 간선에 연결된 인접 정점의 간선들 중 '연결된 노드 집합'에 없는 노드와 연결된 간선들만
//     간선 리스트에 삽입
//     - 연결된 노드 집합에 있는 노드와 연결된 간선들을 간선리스트에 삽입해도, 해당 간선은 스킵될 것이기 때문
//     - 어차피 스킵될 간선을 간선리스트에 넣지 않으므로해서, 간선 리스트에서 최소 가중치를 가지는 간선부터 추출하기 위한
//       간선부터 추출하기 위한 자료구조 유지를 위한 노력을 줄일 수 있음, 최소힙 구조 사용
//4. 선택된 간선은 간선리스트에서 제거
//5. 간선리스트에 더 이상의 간선이 없을 때까지 3~4번을 반복
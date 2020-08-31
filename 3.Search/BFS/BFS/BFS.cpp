

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 9;
int visit[9];
vector<int> a[10];

void BFS(int start) {

    queue<int> q; // 방문해야할 노드를 저장할 큐 생성
    q.push(start); // 큐에 루트노드 입력
    visit[start] = true; //방문한 노드 리스트에 방문하였다고 체크

    while (!q.empty()) // 방문해야할 노드들이 하나도 없을 때까지
    {
        int x = q.front();  // 큐 맨 앞 값 가져오기
        q.pop(); // 가져온 후에 팝;
        cout << x << " "; //출력
        for (int i = 0; i < a[x].size(); i++) //방문한 노드와 인접한 노드들 확인 / 사이즈로 개수 확인 후
        {
            int y = a[x][i]; // 인접한 노드들 확인
            if (!visit[y]) { // 그 노드가 방문한 노드인지 확인
                q.push(y); //방문하지 않았다면 방문할 노드 큐 목록에 추가
                visit[y] = true; //방문했다고 체크
            }
        }
    }
}

int main()
{
    a[1].push_back(2);
    a[2].push_back(1);
    a[1].push_back(3);
    a[3].push_back(1);
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

    BFS(1);
}



//방문한리스트, 방문할리스트, 인접노드를 저장한 해쉬테이블을 이용하여 만들기
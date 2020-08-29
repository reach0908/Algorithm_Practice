// Kruskal.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//부모 노드 가져오기
int getParent(int set[], int x) {
	if (set[x] == x) return x;
	return set[x] = getParent(set, set[x]);
}

//부모노드를 병합
void unionParent(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);

	//더 숫자가 작은 부모로 병합
	if (a < b)
	{
		set[b] = a;
	}
	else
	{
		set[a] = b;
	}
}


//같은부모를 가지는지 확인 - 같은 부모를 가진다는건 같은 집합에 있다 - 같은 집합에 있다는것은 순환이 형성되기 때문에 실패
int find(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);
	if (a == b) return 1;
	else
	{
		return 0;
	}
}


//간선클래스 선언
class Edge
{
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator < (const Edge& edge )const {
		return this->distance < edge.distance;
	}
};

int main()
{
	int n = 7;
	int m = 11;

	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));
	//간선의 비용으로 오름차순 정렬 - 연산자 오버로딩이용
	sort(v.begin(), v.end());

	int *set=new int[n];

	//각 정점이 포함된 그래프가 어디인지 저장
	for (int  i = 0; i < n; i++)
	{
		set[i] = i;
	}

	//거리의 합을 0으로 초기화
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (!find(set,v[i].node[0]-1,v[i].node[1]-1))
		{
			sum += v[i].distance;
			unionParent(set, v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}
	cout << sum;
}


// Heap.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include <random>

#define HEAP_SIZE 256
#define ARRAY_SIZE 10

using namespace std;


int heap[HEAP_SIZE];
int heap_count = 0;

void swap(int* a, int* b) {
     int tmp = *a;
     *a = *b;
     *b = tmp;

}
void init() {
   heap_count = 0;
 }
int size() {
    return heap_count;
}
void push(int data) {

    heap[++heap_count] = data;
    //힙의 가장 끝에 데이터를 추가

    // 아래의 과정은 자식과 부모를 비교하면서 알맞은 위치로 하나씩 올리는 부분
    int child = heap_count;
    int parent = child / 2;
    while (child > 1 && heap[parent] < heap[child]) // 맥스힙이기때문에 자식노드가 부모노드보다 크면 계속 스왑
    {
        swap(&heap[parent], &heap[child]);
        child = parent;
        parent = child / 2;
    }
}

int pop() {

    // 힙의 가장 첫번째 원소를 반환
    // 힙은 최대값에만 관심이있다.
    // 힙의 규칙대로 삽입이 되었다면 최대값은 최상단노드에있다.
    int result = heap[1];\

    // 첫번째 원소를 힙의 가장 끝에 원소와 바꾸고
    // 가장 끝은 이제 쓰지 않을 예정이니 힙카운트를 내려준다.
    swap(&heap[1], &heap[heap_count]);
    heap_count--;

    // 아래의 과정은 자식을 부모와 비교하면서 알맞은 위치로 하나씩 내리는 부분
    

    int parent = 1;
    int child = parent * 2;
    if (child+1 <=heap_count)
    {
        child = (heap[child] > heap[child + 1]) ? child : child + 1;
    }
    while (child <= heap_count && heap[parent] < heap[child]) {
        swap(&heap[parent], &heap[child]);

        parent = child;
        child = child * 2;
        if (child <=heap_count)
        {
            child = (heap[child] > heap[child + 1]) ? child : child + 1;
        }
    }
 
    return result;
}

    //완전이진트리로 넣은 후 부모노드와 비교한 후 스왑
    //데이터 삭제하기
    //가장 마지막노드를 맨위로 올린다.
    //그 후 루트노드를 기준으로 자식 노드 중 큰값과 교환 그렇게 교환하면서 내려간다.

int main() {

    int arr[ARRAY_SIZE];
    
    // 랜덤함수를 위한 srand와 seed
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 100); // c++에서 사용되는 랜덤 라이브러리
    // 위에 세줄과 밑에 활용하는 법은 외우도록 하자
    // 배열 초기화
    for (int i = 0; i < ARRAY_SIZE; i++) {
        // 1 ~ 50까지의 난수 생성
        arr[i] = dis(gen);
    }

    // 삽입
    for (int i = 0; i < ARRAY_SIZE; i++) {
        push(arr[i]);
    }

    // pop 하면서 값들 하나씩 확인
    // Max Heap이기 때문에 값들이 내림차순으로 정렬됨 -> Heap Sort
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << pop() << '\t';
    }

    return 0;
}
 




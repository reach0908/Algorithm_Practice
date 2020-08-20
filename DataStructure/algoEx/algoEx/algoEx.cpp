// algoEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include "myQueue.h"

using namespace std;

int main()
{
    // 큐는 FIFO 먼저넣은것이 먼저나온다. 
    cout << "큐 라이브러리를 이용한 큐" << endl;
    queue<int> Q;
    for (int i = 0; i < 10; i++) {
        Q.push(i);
    }
    cout << Q.back() << endl;
    cout << Q.front() << endl;
    cout << Q.size() << endl;
    cout << Q.empty() << endl;
    for (int i = 0; i < 10; i++) {
        cout << Q.front() << endl;
        Q.pop();
    }
    //다른 정책을 쓰는 변형된 큐
    //LIFO 큐
    //priority 큐
    //데이터를 넣으면서 우선순위를 부여
    //팝 할때 우선순위대로 팝

    //큐는 어디에 많이 쓰일까?
    //멀티태스킹을 위한 프로세스 스케줄링 방식을 구현하기 위해 많이 사용됨 
    //큐의 경우에는 장단점보다(특별히 언급되는 장단점이 없다.)
    //큐의 활용예로 프로세스 스케쥴링 방식을 이해해두는 것이 좋음
    //운영체제와 함께 이해해야 한다.

    //배열을 이용하여 큐를 만들면 처음들어갔던 자료가 빠졌을 경우 그 자리가 비게되는 현상이 발생한다. 
    //따라서 자료들을 이동시켜주는 작업을 해야하는 번거로움이 생긴다.
    //이를 보완하기 위해 원형큐를 구현한다.
    //처음과 끝을 알려주는 포인터가 존재
    //자료의 push,pop에 따라 자료의 이동없이 관리가능
    cout << "배열을 이용해 만든 큐" << endl;
    myQueue<int> myQ;
    cout << "큐가 비어있는가?" << endl;
    cout << myQ.isEmpty() << endl;
    cout << "인큐-디큐" << endl;
    for (int i = 0; i < 10; i++) {
        myQ.enqueue(i);
    }
    for (int i = 0; i < 10; i++) {
        cout << myQ.front() << endl;
        myQ.dequeue();
        
    }

    return 0;
}

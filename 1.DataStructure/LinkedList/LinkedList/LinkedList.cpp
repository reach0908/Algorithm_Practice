

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{

    //링크드리스트
    //배열의 단점 : 연결된 공간을 미리 예약해야한다. 예약한공간을 넘어서는 자료를 저장할 수 없다.
    //떨어진 곳에 존재하는 데이터를 화살표로 연결해서 관리하는 데이터의 구조
    //배열의 단점을 극복한 자료구조
    //노드와 포인터로 구성되어있다.
    //노드 : 데이터의 저장단위로 구성
    //포인터 : 각 노드안에서 다음이나 이전의 노드와의 연결정보를 가지고있는 공간

    //링크드리스트의 장점 : 미리 데이터 공간을 할당할 필요가 없다.
    // 단점 : 연결을 위한 별도의 데이터 공간이 필요하므로 저장공간의 효율이 낮다.
    //        연결정보를 찾는 시간이 필요하므로 접근 속도가 느리다.
    //        중간 데이터 삭제시, 앞뒤 데이터의 연결을 재구성해야 하는 부가적인 작업 필요
    
    List l;
    for (int i = 1; i <= 10; i++) {
        l.insert(i);
    }
    int elem;
    cout << "연결리스트 자료 대입 후 출력" << endl;
    for (int i = 0; i < 10; i++) {
        if (i == 0) {
            l.first(elem);
            cout << elem << endl;
        }
        else {
            l.next(elem);
            cout << elem << endl;
        }
    }

    // 리스트의 중간에 데이터 끼워넣기
    cout << "리스트 중간에 데이터 끼워넣기" << endl;
    l.first(elem);

    while (true)
    {
        if (elem == 5)
        {
            l.insertBetween(50);
            break;
        }
        l.next(elem);
    }

    for (int i = 0; i < 11; i++) {
        if (i == 0) {
            l.first(elem);
            cout << elem << endl;
        }
        else {
            l.next(elem);
            cout << elem << endl;
        }
    }
    //노드 삭제하기
    l.delNode(5);
    cout << "노드 삭제하기" << endl;
    l.first(elem);
    cout << elem << endl;
    while (l.next(elem))
    {
        cout << elem << endl;
    }
    

    return 0;
}




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
    return 0;
}


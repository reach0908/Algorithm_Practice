

#include <iostream>
#include <algorithm>

#include "CContent.h"

using namespace std;

const int NSIZEOFARRAY = 30;
//배열 입력 함수 생성
void FillArray(CContent pContent[], int nSize);
//원하는 장르 선택
void SearchGenre(CContent pContent[], int nSize, int nCategory, int nNumberShow);
//어레이에 담긴 정보 출력
void ShowArray(CContent pContent[], int nSize);
//삽입정렬을 이용한 데이터 정렬
void sel_Sort(CContent pContent[], int nSize);

int main()
{
    //어레이 생성
    //2번문제
    CContent contentArr[NSIZEOFARRAY];
    //데이터 입력 
    FillArray(contentArr, NSIZEOFARRAY);
    //데이터 정렬
    //3번문제 
    sel_Sort(contentArr,NSIZEOFARRAY);
    //3번문제 출력
    cout << "----- 3번 문제 출력 -----" << endl;
    ShowArray(contentArr, NSIZEOFARRAY);
    int categoryNum=2;
    //카테고리 찾기
    //4번문제
    cout << "----- 4번 문제 출력 -----" << endl;
    SearchGenre(contentArr, NSIZEOFARRAY,categoryNum, 5);

}

void SearchGenre(CContent pContent[], int nSize, int nCategory, int nNumberShow) {
    int cnt = 0;
    for (int i = 0; i < nSize; i++)
    {
        int temp = pContent[i].getCContent();
        if (temp == nCategory) {
            cnt++;
            pContent[i].showCContent();
            cout << endl;
        }
        if (cnt==nNumberShow)
        {
            return;
        }
    }
}
void ShowArray(CContent pContent[], int nSize) {

    for (int i = 0; i < nSize; i++)
    {
        //데이터출력
        pContent[i].showCContent();
        cout << endl;
    }
}

void sel_Sort(CContent pContent[],int nSize) {
    for (int startIndex = 0; startIndex < nSize - 1; ++startIndex)
    {
        int smallestIndex = startIndex;

        for (int currentIndex = startIndex + 1; currentIndex < nSize; ++currentIndex)
        {
            if (pContent[currentIndex] < pContent[smallestIndex])
                smallestIndex = currentIndex;
        }
        swap(pContent[startIndex], pContent[smallestIndex]);
    }
}

void FillArray(CContent pContent[], int nSize) {
    pContent[0].setCContent(0, 1, "A", 24);
    pContent[1].setCContent(1, 1, "B", 70);
    pContent[2].setCContent(2, 1, "C", 33);
    pContent[3].setCContent(3, 1, "D", 10);
    pContent[4].setCContent(4, 1, "E", 125);
    pContent[5].setCContent(5, 1, "F", 534);
    pContent[6].setCContent(6, 1, "G", 65);
    pContent[7].setCContent(7, 1, "H", 217);
    pContent[8].setCContent(8, 1, "I", 51);
    pContent[9].setCContent(9, 1, "J", 4);
    pContent[10].setCContent(10, 2, "K", 96);
    pContent[11].setCContent(11, 2, "L", 44);
    pContent[12].setCContent(12, 2, "M", 77);
    pContent[13].setCContent(13, 2, "N", 253);
    pContent[14].setCContent(14, 2, "O", 643);
    pContent[15].setCContent(15, 2, "P", 173);
    pContent[16].setCContent(16, 2, "Q", 187);
    pContent[17].setCContent(17, 2, "R", 13);
    pContent[18].setCContent(18, 2, "S", 87);
    pContent[19].setCContent(19, 2, "T", 566);
    pContent[20].setCContent(20, 3, "U", 95);
    pContent[21].setCContent(21, 3, "V", 8);
    pContent[22].setCContent(22, 3, "W", 24);
    pContent[23].setCContent(23, 3, "Y", 56);
    pContent[24].setCContent(24, 3, "X", 90);
    pContent[25].setCContent(25, 3, "Z", 264);
    pContent[26].setCContent(26, 3, "AA", 12);
    pContent[27].setCContent(27, 3, "BB", 179);
    pContent[28].setCContent(28, 3, "CC", 276);
    pContent[29].setCContent(29, 3, "DD", 665);
}
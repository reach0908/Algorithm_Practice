

#include <iostream>



using namespace std;

int factoiral(int num) {
	if (num > 1)
	{
		return num * factoiral(num - 1);
	}
	else {
		return num;
	}
}

int main()
{

	cout << factoiral(4) << endl;
    return 0;
}

// 재귀호출의 일반적인 형태
/*int func1(int num) {
	if (num > 0)     - 입력한 값이 일정 값 이상이면
	{
		return func1(num - 1); // 입력보다 작은 값
	}
	else
	{
		return 0; - 재귀호출 종료
	}
}

int func2(int num) {
	if (num <= 1) - 입력한 값이 일정값보다 작으면
	{
		return num; - 재귀호출 종료
	}
	int return_Value = num*func2(num - 1); - 입력보다 작은 값 
	return return_Value; - 결과값
}*/
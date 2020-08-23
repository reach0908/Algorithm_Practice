#pragma once
#include <iostream>


#define ARR_SIZE 100
int tempArr[ARR_SIZE];

void swap(int *a,int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
//  기준점을 잡아 기준점보다 작은 것은 왼쪽에 큰 것은 오른쪽에 정렬하고 분할정복을 통해 
void quickSort(int *data,int left, int right) {
	if (left >= right) {
		return;
	}
	int i = left-1;
	int j = left;
	int pivot = data[right];
	for (; j < right; ++j)
	{
		if (data[j] < pivot) {
			swap(&data[++i],&data[j]);
		}
	}
	swap(&data[++i], &data[right]);

	quickSort(data, left, i - 1);
	quickSort(data, i + 1, right);

}
//하나씩 비교해가며 스왑
void bubbleSort(int *data,int size) {
	int swapnum = 0;
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size-i-1; j++)
		{
			if (data[j]>data[j+1])
			{
				swap(&data[j], &data[j + 1]);
				swapnum++;
			}
			if (swapnum==0)
			{
				break;
			}
		}
	}
}
//병합정렬 
void merge(int arr[],int left, int right) {
	
	int mid = (left + right) / 2;
	int L = left;
	int R = mid + 1;
	int K = left;
	while (L <= mid && R <= right) {
		if (arr[L]<=arr[R])
		{
			tempArr[K] = arr[L];
			L++;
		}
		else {
			tempArr[K] = arr[R];
			R++;
		}
		K++;
	}
	if (L>mid)
	{
		for (int i = R; i <= right; i++)
		{
			tempArr[K] = arr[i];
			K++;
		}
	}
	else
	{
		for (int i = L; i <= mid; i++)
		{
			tempArr[K] = arr[i];
			K++;
		}
	}
	for (int i = left; i <= right; i++)
	{
		arr[i] = tempArr[i]; // 자르고 정렬해서 임시배열에 넣은거 다시 원래배열에 복붙 
	}
}
void mergeSort(int arr[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right); // 계속 나누고 나눠서 잘게쪼개진다음에 탈출 후, 머지
		merge(arr, left, right);
	}
}
//삽입정렬
void insertionSort(int arr[],int size) {
	for (int i = 0; i <size-1; i++)
	{
		for(int j=i+1;j>=0;j--) // 두번째인덱스부터 시작
		{
			if (arr[j] < arr[j - 1]) {  // 해당 인덱스 값 앞에 있는 데이터부터 비교해서 키값이 더 작으면 
				swap(&arr[j], &arr[j - 1]);
			}
			else
			{
				break;
			}
		}
	}
}
//
void selectionSort() {


}
//
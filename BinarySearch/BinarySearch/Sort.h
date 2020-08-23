#pragma once
#include <iostream>


#define ARR_SIZE 100
int tempArr[ARR_SIZE];

void swap(int *a,int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
//  �������� ��� ���������� ���� ���� ���ʿ� ū ���� �����ʿ� �����ϰ� ���������� ���� 
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
//�ϳ��� ���ذ��� ����
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
//�������� 
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
		arr[i] = tempArr[i]; // �ڸ��� �����ؼ� �ӽù迭�� ������ �ٽ� �����迭�� ���� 
	}
}
void mergeSort(int arr[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right); // ��� ������ ������ �߰��ɰ��������� Ż�� ��, ����
		merge(arr, left, right);
	}
}
//��������
void insertionSort(int arr[],int size) {
	for (int i = 0; i <size-1; i++)
	{
		for(int j=i+1;j>=0;j--) // �ι�°�ε������� ����
		{
			if (arr[j] < arr[j - 1]) {  // �ش� �ε��� �� �տ� �ִ� �����ͺ��� ���ؼ� Ű���� �� ������ 
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
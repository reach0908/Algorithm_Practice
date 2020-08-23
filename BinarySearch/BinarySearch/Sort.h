#pragma once
#include <iostream>

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
//
void mergeSort() {


}
//
void insertionSort() {

}
//
void selectionSort() {


}
//
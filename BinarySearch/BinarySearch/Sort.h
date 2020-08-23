#pragma once
#include <iostream>

void swap(int *a,int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

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
// 분할 정복
void bubbleSort() {


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
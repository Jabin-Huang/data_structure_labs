#pragma once
#include<cstring>

void merge(elementType A[], int low,int mid,int high) {
	elementType T[MAXLEN]; //temo临时存放归并后的序列
	memset(T, 0, sizeof(T));
	int i = low, j = mid + 1; //i为A[low...mid]的下标，j为A[mid+1...high] 的下标
	int k = low; //k为temp[]的下标
	while (i <= mid && j <= high) { //两个子表都有元素时
		if (A[i].key <= A[j].key) {//若A[i]较小，则放入T中
			T[k++] = A[i++];
		}
		else {//反之A[j]放入T中
			T[k++] = A[j++];
		}
	}
	//当其中一子表还未结束时，则将其递补到T末端
	while (i <= mid) { 
		T[k++] = A[i++];
	}
	while (j <= high) {
		T[k++] = A[j++];
	}
	for (int i = low; i < k; i++) {
		A[i] = T[i];
	}
}

void mergeSort(elementType A[], int low, int high) {
	int mid;//划分点
	if (low < high) {
		mid = (low + high) / 2;
		mergeSort(A, low, mid); //左子表
		mergeSort(A, mid + 1, high); //右子表
		merge(A, low, mid, high); //合并
	}
	//print_dy(A); //用于过程演示
}
#pragma once
#include<cstring>

void merge(elementType A[], int low,int mid,int high) {
	elementType T[MAXLEN]; //temo��ʱ��Ź鲢�������
	memset(T, 0, sizeof(T));
	int i = low, j = mid + 1; //iΪA[low...mid]���±꣬jΪA[mid+1...high] ���±�
	int k = low; //kΪtemp[]���±�
	while (i <= mid && j <= high) { //�����ӱ���Ԫ��ʱ
		if (A[i].key <= A[j].key) {//��A[i]��С�������T��
			T[k++] = A[i++];
		}
		else {//��֮A[j]����T��
			T[k++] = A[j++];
		}
	}
	//������һ�ӱ�δ����ʱ������ݲ���Tĩ��
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
	int mid;//���ֵ�
	if (low < high) {
		mid = (low + high) / 2;
		mergeSort(A, low, mid); //���ӱ�
		mergeSort(A, mid + 1, high); //���ӱ�
		merge(A, low, mid, high); //�ϲ�
	}
	//print_dy(A); //���ڹ�����ʾ
}
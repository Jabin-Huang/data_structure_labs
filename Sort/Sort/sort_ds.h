#pragma once

#include<iostream>
#include<cstdlib>
#include<windows.h>
#include<ctime>
 
using namespace std;


#define MAXLEN 1000


typedef int keytype;

typedef struct list {
	keytype key;
}elementType;

int n;//Ԫ�ظ���
int cnt1, cnt2;
//cnt1�Ƚϴ���
//cnt2��������

void print(elementType A[]) {
	for (int i = 1; i <= n; i++) {
		printf("%7d\t", A[i].key);
	}
	printf("\n");
}

void print_dy(elementType A[]) {
	//system("CLS");
	printf("��%d���ƶ�: ", cnt2);
	for (int i = 1; i <= n; i++) {
		printf("%7d", A[i].key);
	}
	printf("\n");
	//Sleep(250);
}

#include"HeapSort.h"
#include"MergeSort.h"
#include"QuickSort.h"
#include"ShellSort.h"
#include"sort3.h"
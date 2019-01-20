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

int n;//元素个数
int cnt1, cnt2;
//cnt1比较次数
//cnt2交换次数

void print(elementType A[]) {
	for (int i = 1; i <= n; i++) {
		printf("%7d\t", A[i].key);
	}
	printf("\n");
}

void print_dy(elementType A[]) {
	//system("CLS");
	printf("第%d次移动: ", cnt2);
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
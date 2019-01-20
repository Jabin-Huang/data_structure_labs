#pragma once


typedef int keytype;

#include<cstdio>
#include<iostream>
using namespace std;



typedef struct searchList {
	keytype key;
} elementType;

int bin_search(elementType A[], int n, keytype x) {
	int cnt = 0; //记录比较次数
	int mid, low = 0, high = n - 1; //区间两端初始化
	while (low <= high) {//二分查找
		mid = (low + high) / 2;
		printf("第%d次比较的元素（下标）：%d（%d）\n", ++cnt, A[mid].key,mid);
		if (x == A[mid].key) return mid; 
		else if (x < A[mid].key) high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}


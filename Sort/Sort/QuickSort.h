#pragma once
 
 
//cnt1记录比较次数，cnt2记录移动次数
void partition(elementType A[], int s, int t, int &cutPoint) {
	elementType x = A[s]; //腾出空位
	int i = s, j = t; //初始化两端位置
	while (i != j) {  //当两端搜索位置未重合时
		cnt1++;
		while (i < j&&A[j].key > x.key) {//从后面找到第一个比中间元素小的元素
			j--;
			cnt1++; 
		}
		if (i < j) {  //找到后，将其调到前面的空位，同时自身腾出空位
			A[i] = A[j];
			i++;
			cnt2++;
			//print_dy(A);
		}
		
		cnt1++;
		while (i < j&&A[i].key < x.key) {//从前面找到第一个比中间元素大的元素
			i++;
			cnt1++;
		}
		if (i < j) {  //找到后，将其调到后面的空位，同时自身腾出空位
			A[j] = A[i];
			j--;
			cnt2++;
			//print_dy(A);
		}
	}
	A[i] = x;
	cutPoint = i;//将中间元素的位置回传
}


void quickSort(elementType A[], int s, int t) {
	//对A中的下标从s到t的元素组成的子表进行快速排序
	int i;
	if (s < t) {
		partition(A, s, t, i);
		quickSort(A, s, i - 1);
		quickSort(A, i + 1, t);
	}
}

void partition_dy(elementType A[], int s, int t, int &cutPoint) {
	elementType x = A[s]; //腾出空位
	int i = s, j = t; //初始化两端位置
	while (i != j) {  //当两端搜索位置未重合时
		cnt1++;
		while (i < j&&A[j].key > x.key) {//从后面找到第一个比中间元素小的元素
			j--;
			cnt1++;
		}
		if (i < j) {  //找到后，将其调到前面的空位，同时自身腾出空位
			A[i] = A[j];
			i++;
			cnt2++;
			print_dy(A);
		}

		cnt1++;
		while (i < j&&A[i].key < x.key) {//从前面找到第一个比中间元素大的元素
			i++;
			cnt1++;
		}
		if (i < j) {  //找到后，将其调到后面的空位，同时自身腾出空位
			A[j] = A[i];
			j--;
			cnt2++;
			print_dy(A);
		}
	}
	A[i] = x;
	cutPoint = i;//将中间元素的位置回传
}


void quickSort_dy(elementType A[], int s, int t) {
	//对A中的下标从s到t的元素组成的子表进行快速排序
	int i;
	if (s < t) {
		partition_dy(A, s, t, i);
		quickSort_dy(A, s, i - 1);
		quickSort_dy(A, i + 1, t);
	}
}


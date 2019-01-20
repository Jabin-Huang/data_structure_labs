#pragma once


void sift(elementType  A[], int k, int m) {
	//对数组中下标为1~n中的元素中的序号不大于m的以k为根的子序列调整
	//假设以2k和2k+1为根的左右子树均是堆
	elementType x = A[k]; //临时保存当前根值，空出位置，并设未结束标志
	bool finished = false;
	int i = k, j = 2 * i; //i指示空位，j先指左孩子结点
	while (j <= m && !finished) {
		cnt1++;
		if (j < m&&A[j].key < A[j + 1].key) {
			j = j + 1;//让j指向左右孩子中的最大者
		}
		cnt1++;
		if (x.key >= A[j].key) { //原根已为最大，可以结束筛选
			finished = true;
		}
		else {
			cnt2++;
			A[i] = A[j];//大的孩子往上移
			i = j; //继续往下筛选
			j = 2 * j;
		}
	}
	cnt2++;
	A[i] = x; //将原根值填充到最终合法位置

}

void heapSort(elementType A[], int n) {
	printf("开始建堆...\n");
	for (int i = n / 2; i >= 1; i--) {
		print_dy(A);
		sift(A, i, n); //建初始堆
	}
	printf("建堆完成！开始输出根...\n");
	for (int i = n; i >= 2; i--) {
		swap(A[i], A[1]); //输出根
		print_dy(A);
		sift(A,1,i-1);//调整子序列A[1]~A[i-1]为堆
		print_dy(A);
	}
}
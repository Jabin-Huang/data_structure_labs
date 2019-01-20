#pragma once

void shellSort(elementType A[], int dh) {
	//dh为初始步长，约定1<dh<=n/2
	while (dh >= 1) { //通过步长控制排序的执行过程,当步长为1时即最后一次的直接插入排序
		for (int i = dh + 1; i <= n; i++) { //依次插入元素到前面的有序表中
			elementType temp = A[i];	//腾出空位
			int j = i;					//j指示空位置
			cnt1++;
			while (j > dh&&temp.key < A[j - dh].key) {
				A[j] = A[j - dh]; //移动元素
				cnt2++;
				//print_dy(A);
				j = j - dh; //j前移
				cnt1++;
			}
			A[j] = temp; //插入元素
			cnt2++;
			//print_dy(A);
		}
		dh = dh / 2; //步长每次缩短一半
	}
}
	
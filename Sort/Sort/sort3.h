#pragma once
#include<algorithm>

void sort3(elementType A[], int s, int t) {
	int low = s, high = t; //保存首尾下标
	int p; //指向当前要就位的元素
	p = high;
	while (low<p) { //从前面开始将模3余2的元素筛到后面
		if (A[low].key % 3 == 2&&A[p].key%3!=2) { //若前面元素是模3余2，后面元素不符合规则，则两者交换，使后面符合规则
			swap(A[low], A[p]);
			p--; //A[p]已就位，则指向后面元素的指针往前挪一个
		}
		else if(A[p].key%3==2){//后面元素已符合规则，这个位置不需调整
			p--; //A[p]已就位，则指向后面元素的指针往前挪一个
			low--; //此时low不需移动，使low--与low++抵消
		}
		low++;
	}
	low = s; //将low恢复为表头下标
	high = p;//将hgih调整为未确定就位元素的最后一个
	p = low;
	while (p < high) {//从后面开始将3的倍数筛到前面
		if (A[high].key % 3 == 0&&A[p].key%3!=0) { //若后面的元素是3的倍数，前面元素不符合规则，则两者交换，使前面符合规则
			swap(A[high], A[p]);
			p++ ; //A[p]就位，则指向前面元素的指针往后挪一个
		}
		else if(A[p].key%3==0){ //前面元素已符合规则，这个位置不需调整
			p++; //A[p]已就位，则指向前面元素的指针往后挪一个
			high++; //此时high不需移动，使high--与high++抵消
		}
		high--;
	}
	//如此，经过将模3余2的元素筛到后面，将3的倍数筛到前面，剩下的元素就是模3余1的元素，自然在中间。
	//时间复杂度O（n）
}

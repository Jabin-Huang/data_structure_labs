#include"sort_ds.h"
elementType A[1000];
 
void initArray() {
	memset(A, 0, sizeof(A));
	int choose;
	cout << "选择测试方式：\n";
	cout << "1.手动输入数据。\n";
	cout << "2.随机生成数据。\n";
	cin >> choose;
	cin.get();
	if (choose == 1) {
		cout << "输入测试数据规模:";
		cin >> n;
		cin.get();
		for (int i = 1; i <= n; i++) {
			cin >> A[i].key;
		}
	}
	else {
		cout << "输入测试数据规模:";
		cin >> n;
		cin.get();
		for (int i = 1; i <= n; i++) {
			A[i].key = rand()%100000;
		}
		print(A);
	}
}

void test1() {
	
	cnt1 = 0; 
	cnt2 = 0;
	initArray();
	cout << "是否需要过程演示?" << endl;
	cout << "1.不需要\n";
	cout << "2.需要\n";
	int kase;
	cin >> kase;
	cin.get();
	if (kase == 1) {
		quickSort(A, 1, n);
		printf("排序后：\n");
		print(A);
	}
	else {
		quickSort_dy(A, 1, n);
	}
	printf("比较次数：%d\n", cnt1);
	printf("移动次数：%d\n", cnt2);
	cin.get();
	cin.get();
}
void test2() {
	 
	cnt1 = 0;
	cnt2 = 0;
	initArray();
	
	int dh;
	cout << "输入步长(1<dh<=n/2):";
	cin >> dh;
	cin.get();
	shellSort(A, dh);
	printf("排序后：\n");
	print(A);
	printf("比较次数：%d\n", cnt1);
	printf("移动次数：%d\n", cnt2);
	cin.get();
	cin.get();
}
void test3() {
	 
	cnt1 = 0;
	cnt2 = 0;
	initArray();
	heapSort(A, n);
	printf("排序后：\n");
	print(A);
	printf("比较次数：%d\n", cnt1);
	printf("移动次数：%d\n", cnt2);
	cin.get();
	cin.get();
}

void test4() {	 
	initArray();
	mergeSort(A, 1, n);
	printf("排序后：\n");
	print(A);
	cin.get();
	cin.get();
}

void test5() {
	initArray();
	sort3(A, 1, n);
	printf("调整后：\n");
	print(A);
	cin.get();
	cin.get();
}

int main() {
	int choose;
	srand(unsigned int(time(NULL)));
	while (true) {
		system("cls");
		cout << "1.快速排序演示\n\n";
		cout << "2.希尔排序演示\n\n";
		cout << "3.堆排序演示\n\n";
		cout << "4.归并排序演示\n\n";
		cout << "5.将一个整型数组调整为这样的数组：所有３的倍数在最左边，所有除以３余１的数在中间，而所有除以３余２的数在最右边。\n\n";
		cin >> choose;
		cin.get();
		switch (choose) {
		case 1:test1(); break;
		case 2:test2(); break;
		case 3:test3(); break;
		case 4:test4(); break;
		case 5:test5(); break;
		default:
			break;
		}
	}
	return 0;
}
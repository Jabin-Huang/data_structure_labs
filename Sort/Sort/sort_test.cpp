#include"sort_ds.h"
elementType A[1000];
 
void initArray() {
	memset(A, 0, sizeof(A));
	int choose;
	cout << "ѡ����Է�ʽ��\n";
	cout << "1.�ֶ��������ݡ�\n";
	cout << "2.����������ݡ�\n";
	cin >> choose;
	cin.get();
	if (choose == 1) {
		cout << "����������ݹ�ģ:";
		cin >> n;
		cin.get();
		for (int i = 1; i <= n; i++) {
			cin >> A[i].key;
		}
	}
	else {
		cout << "����������ݹ�ģ:";
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
	cout << "�Ƿ���Ҫ������ʾ?" << endl;
	cout << "1.����Ҫ\n";
	cout << "2.��Ҫ\n";
	int kase;
	cin >> kase;
	cin.get();
	if (kase == 1) {
		quickSort(A, 1, n);
		printf("�����\n");
		print(A);
	}
	else {
		quickSort_dy(A, 1, n);
	}
	printf("�Ƚϴ�����%d\n", cnt1);
	printf("�ƶ�������%d\n", cnt2);
	cin.get();
	cin.get();
}
void test2() {
	 
	cnt1 = 0;
	cnt2 = 0;
	initArray();
	
	int dh;
	cout << "���벽��(1<dh<=n/2):";
	cin >> dh;
	cin.get();
	shellSort(A, dh);
	printf("�����\n");
	print(A);
	printf("�Ƚϴ�����%d\n", cnt1);
	printf("�ƶ�������%d\n", cnt2);
	cin.get();
	cin.get();
}
void test3() {
	 
	cnt1 = 0;
	cnt2 = 0;
	initArray();
	heapSort(A, n);
	printf("�����\n");
	print(A);
	printf("�Ƚϴ�����%d\n", cnt1);
	printf("�ƶ�������%d\n", cnt2);
	cin.get();
	cin.get();
}

void test4() {	 
	initArray();
	mergeSort(A, 1, n);
	printf("�����\n");
	print(A);
	cin.get();
	cin.get();
}

void test5() {
	initArray();
	sort3(A, 1, n);
	printf("������\n");
	print(A);
	cin.get();
	cin.get();
}

int main() {
	int choose;
	srand(unsigned int(time(NULL)));
	while (true) {
		system("cls");
		cout << "1.����������ʾ\n\n";
		cout << "2.ϣ��������ʾ\n\n";
		cout << "3.��������ʾ\n\n";
		cout << "4.�鲢������ʾ\n\n";
		cout << "5.��һ�������������Ϊ���������飺���У��ı���������ߣ����г��ԣ��ࣱ�������м䣬�����г��ԣ��ࣲ���������ұߡ�\n\n";
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
#include"bin_search.h"
#include"BST.h"
#include<cstdio>
#include<iostream>
#include<cstdlib>

#define MAXLEN 10000
using namespace std;

elementType A[MAXLEN];
node *root;
node *AVL;
void test1() {
	cout << "�������ݣ���-999��������";
	keytype x;
	int i = 0;
	while (cin >> x && x != -999) {
		A[i++].key = x;
	}
	cout << "����Ҫ���ҵ�Ԫ�أ���-999��������";
	while (cin >> x && x != -999) {
		if (bin_search(A, i, x) == -1) {
			cout << "�����ڸ�Ԫ�أ�" << endl;
		}
	}
	cin.get();
}
void test2() {
	createBst(root);
	cout << "���������\n";
	printBST(root);
	cin.get();
}
void test3() {
	keytype x;
	cout << "����Ҫ���ҵ�Ԫ�أ���-999��������";
	while (cin >> x && x != -999) {
		node *addr=NULL;
		if (addr=BstSearch(root,x)) {
			cout << "��Ԫ�ص�ַΪ��" << addr << endl;
		}
		else {
			cout << "�����ڸ�Ԫ��!" << endl;
		}
	}
	cin.get();
}
void test4() {
	keytype x;
	cout << "ɾ��ǰ��\n";
	printBST(root);
	cout << "����Ҫɾ����Ԫ�أ���-999��������";
	while (cin >> x && x != -999) {
		remove(root, x);
		cout << "ɾ����" << endl;
		printBST(root);
	}
	cin.get();
}
void test5() {
	cout << "�������ݣ���-999��������";
	keytype x;
	while (cin >> x && x != -999) {
		AVLinsert(AVL, x);
	}
	cout << "�����ɹ���" << endl;
	printBST(AVL);
	cout << "������������߶ȣ�";
	if (AVL->lc) {
		cout << AVL->lc->height<<endl;
	}
	else cout << 0 << endl;
	cout << "������������߶ȣ�";
	if (AVL->rc) {
		cout << AVL->rc->height << endl;
	}
	else cout << 0 << endl;
	cin.get();
}

int main() {
	int choose;
	while (true) {
		system("CLS");
		cout << "(1) �Ը������ݱ����ö��ֲ����㷨ʵ�ֲ��ң��������ҹ����������Ƚϵ�Ԫ�أ����±꣩��" << "\n\n";
		cout << "(2) ���������й�������������" << "\n\n";
		cout << "(3) �ڶ����������в���ָ��ֵ�Ľ��" << "\n\n";
		cout << "(4) �ڶ�����������ɾ���ض�ֵ�Ľ�㡣" << "\n\n";
		cout << "(5) ����AVL��" << "\n\n";
		cout << "��������Բ��ԣ�" << "\n\n";
		cin >> choose;
		cin.get();
		switch (choose) {
		case 1:test1(); cin.get(); break;
		case 2:test2(); cin.get(); break;
		case 3:test3(); cin.get(); break;
		case 4:test4(); cin.get(); break;
		case 5:test5(); cin.get(); break;
		default:
			break;
		}
	}

	return 0;
}